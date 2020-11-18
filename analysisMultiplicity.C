//Samuel P P Silveira, Universidade Federal do ABC, 2020
#include "MParticle.h"
#include "TLorentzVector.h"
//#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

void analysisMultiplicity(int n){

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

    TFile fout(("OUTPUT/Histograms_Output/"+folder+header+"_hresultsMultiplicity.root").c_str(),"recreate");
    TH1F *hEventsMultiplicity = new TH1F("em","Event Multiplicity;particles;counts",200,1,1);


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
    for (int i = 0;i < events.size(); i++){
        hEventsMultiplicity->Fill(events[i].size());
        cout<<"Evento "<<i<<":"<<events[i].size()<<endl;
    }

    particlesFile.close();

    hEventsMultiplicity->Write();
    
 

}
