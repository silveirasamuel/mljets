#ifndef M_PARTICLE_H
#define M_PARTICLE_H
#include "TObject.h"

class MParticle : public TObject {
	public:
        Int_t event;
        Int_t flavor;
        TLorentzVector lv;
	
	ClassDef(MParticle,1);
};
#endif
