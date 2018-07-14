#ifndef __PANEL_H_INCLUDED__
#define __PANEL_H_INCLUDED__
#include<ncurses.h>
#include "TUIObject.h"
using namespace std;
class Panel : public TUIObject{
	private:
		bool scrollable=false;
		vector<TUIObject*> objects;
	protected:
	public:			
		Panel();
		~Panel();
		void draw() override;
		void add(TUIObject* obj);
		TUIObject* getObject(int num);
		int objCount();
};

#endif


