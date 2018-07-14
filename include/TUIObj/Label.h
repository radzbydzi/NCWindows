#ifndef __LABEL_H_INCLUDED__
#define __LABEL_H_INCLUDED__
#include "TUIObject.h"
using namespace std;
class Label : public TUIObject{
	private:
		string value;
		int attr=0;
		string color;
	protected:
	public:			
		Label();
		Label(string value, string color, int attr);
		~Label();
		void draw() override;
		
		void setValue(string value);
		void setAttributes(int attr);
		
		string getValue();
		int getAttributes();
		
		
};

#endif



