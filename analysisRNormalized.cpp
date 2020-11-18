//Samuel P P Silveira, Universidade Federal do ABC, 2020
#include "MParticle.h"
#include "TLorentzVector.h"
#include "TVector3.h"
//#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

void analysisRNormalized(int n){

    /*auto c1 = new TCanvas("c1","c1",1000,550);
    gStyle->SetOptStat("");

    gPad->SetGridy();
    gPad->SetTickx();
    gPad->SetTicky();*/
    
    stringstream folders;
    folders<<n<<"/";
    string folder = folders.str();
    stringstream headers;
    headers<<n;
    string header = headers.str();


    ifstream particlesFile("OUTPUT/"+folder+header+"_particles.out");

    MParticle* particle;
    vector<vector<MParticle*>> events;

    string line;
    string event, flavor, e, px, py, pz;
    stringstream ss;

    TFile fout(("OUTPUT/Histograms_Output/"+folder+header+"_hresultsRNormalized.root").c_str(),"recreate");
    TH1F *hresultsR= new TH1F("rd","r distribution;r;counts",10000,0,0.01);
    
    for (int i = 0; i < n; i++){
        vector<MParticle*> eventI;
        events.push_back(eventI);
    }

    if (particlesFile.is_open()){
        cout<<"Loading particles (1/1) ..."<<endl;
        while(getline(particlesFile,line)){
            particle = new MParticle(); 
            ss.str(line);           
            
            getline(ss,event,',');
            particle->event = atoi(event.c_str());
            getline(ss,flavor,',');   
            particle->flavor = atoi(flavor.c_str());
            getline(ss,e,',');
            getline(ss,px,',');
	        getline(ss,py,',');
            getline(ss,pz,',');
            particle->lv = TLorentzVector(atof(px.c_str()), atof(py.c_str()), atof(pz.c_str()), atof(e.c_str()));
            ss.clear();

            events[particle->event].push_back(particle);
        }
    }else{
        cout<<"ERROR: FILE NOT FOUND!"<<endl;
        return;
    }
    //Sorting particles by p

    for (int i = 0; i < events.size(); i++){
        sort(events[i].begin(), 
             events[i].end(),
             []( MParticle* lhs,  MParticle* rhs)
                {
                    TVector3 lhsp = lhs->lv.Vect();
                    TVector3 rhsp = rhs->lv.Vect();
                    return lhsp.Mag() > rhsp.Mag();
                });
    }
    double den, num, r;
    for (int i = 0; i < events.size(); i++ ){
        cout<<"\n\nEvent "<<i<<endl<<endl;
        //Loop over particles of an event
        for (int j = 0; j < events[i].size(); j++){
            TVector3 pJ = events[i][j]->lv.Vect();
            //cout << events[i][j]->event<<","<<events[i][j]->flavor<<","<<p.Mag()<<endl;
            den = 0;
            num = 0;
            r = 0;
            //calculating den
            for(int k = 0; k < events[i].size(); k++){
                if (j == k) continue;
                TVector3 pK = events[i][k]->lv.Vect();
                den += exp(pJ.Dot(pK));
            }

            den *= events[i].size();

            for (int x = 0; x < events[i].size(); x++){
                //calculating r
                if (j == x) continue;
                TVector3 pX = events[i][x]->lv.Vect();
                num = exp(pJ.Dot(pX));
                r = num/den;
                cout<<"R_"<<j<<","<<x<<" = "<<r<<endl;
                hresultsR->Fill(r);
            }
            
        }
    }

    particlesFile.close();

    hresultsR->Write();
    
 

}
