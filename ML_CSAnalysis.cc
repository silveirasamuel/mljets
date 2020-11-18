//Samuel P P Silveira, Fundação Universidade Federal do ABC, 2020
#include "Pythia8/Pythia.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <cstdio>
#include <cmath>

using namespace std;
using namespace Pythia8;


int main (int argc, char* argv[]) {

	if(argc != 3){
		cout<<"Not enough parameters were passed!"<<endl;
		return 1;
	}

	string inputFile = argv[1];
	int nEvent = stoi(argv[2],NULL,10);

	//Initializing Pythia
	Pythia pythia("");
	pythia.readFile(inputFile);
	pythia.init();

	stringstream folder;
	folder<<"OUTPUT/"<<nEvent<<"/";
	mkdir((folder.str()).c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	
	stringstream header;
	header<<folder.str()<<nEvent;

	ofstream particles (header.str()+"_particles.out");
	int count;
	for(int iEvent = 0; iEvent < nEvent; ++iEvent){
	    if(!pythia.next()) continue;
		count = 0;
	    for(int i = 0;i < pythia.event.size(); ++i){
			//only final state particles			
			if(pythia.event[i].isFinal()){
	        	particles<<iEvent<<","<<pythia.event[i].id()<<","<<pythia.event[i].e()<<","<<pythia.event[i].px()<<","<<pythia.event[i].py()<<","<<pythia.event[i].pz()<<endl;	
				count ++;
			}      
	    }
		if (count == 0){
			cout<<"ERROR: EVENT WITHOUT FINAL PARTICLES"<<endl;
		}
	}

	particles.close();
	return 0;
} 
