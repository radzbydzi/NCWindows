#ifndef __LAYOUT_H_INCLUDED__
#define __LAYOUT_H_INCLUDED__
#include<ncurses.h>
#include<vector>
#include<string>
#include "TUIObject.h"
using namespace std;
class Frame{
	private:
		string name;
		vector<TUIObject*> objects;
	protected:
	public:
		Frame(string name);
		void add(TUIObject* obj);
		TUIObject* getObject(int num);
		int objCount();
		
};

#endif



