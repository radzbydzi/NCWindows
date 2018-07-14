#ifndef __TEXTFIELD_H_INCLUDED__
#define __TEXTFIELD_H_INCLUDED__
#include "TUIObject.h"
using namespace std;
class TextField : public TUIObject{
	private:
		string text;
		unsigned int caretPosition=0;
		int startFrom=0;
	protected:
	public:			
		TextField();
		TextField(string text);
		~TextField();
		void draw() override;
		
		void setText(string text);
		string getText();
		void setCaretPosition(unsigned int caretPosition);
		int getCaretPosition();
		void putCharacter(char ch);
		void putString(string str);
		void eraseCharacter();
		void moveCaretLeft();
		void moveCaretRight();
		void setCaretPositionAtTheEnd();
};

#endif



