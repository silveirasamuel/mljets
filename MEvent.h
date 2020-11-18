#ifndef M_EVENT_H
#define M_EVENT_H
#include "TObject.h"

class MEvent : public TObject {
	public:
        Int_t event;
        Int_t begin;
        Int_t end;
	
	ClassDef(MEvent,1);
};
#endif
