#include "TUIObj/TextField.h"
#include "UTF8String.h"
TextField::TextField()
{
	
}
TextField::TextField(string text)
{
	setText(text);
}
TextField::~TextField()
{
}
void TextField::draw()
{
	drawBackground();
	drawBorder();
	int y=0;
	int x=0;
	unsigned int position = 0;
	string* tab = UTF8String::charTable(text);
	for(unsigned int i=0; i<UTF8String::size(text); i++)
	{
		string ch = tab[i];
		chtype attr = A_REVERSE|A_BLINK;
		if(position==caretPosition)
			showTextOn(ch,x,y,attr,false);
		else
			showTextOn(ch,x,y);
		x++;	
		position++;
	}
}
	
void TextField::setText(string text)
{
	this->text=text;
	//setCaretPositionAtTheEnd();
}
		
string TextField::getText()
{
	return text;
}

void TextField::setCaretPosition(unsigned int caretPosition)
{
	this->caretPosition = caretPosition;
	if(caretPosition<0)
		caretPosition=0;
	
	if(caretPosition>text.length()+1)
		caretPosition=text.length()+1;
	
}
int TextField::getCaretPosition()
{
	return caretPosition;
}
void TextField::putCharacter(char ch)
{
	string character(1,ch);
	putString(character);
}
void TextField::putString(string str)
{
	string* chT= UTF8String::charTable(text);
	unsigned int size = UTF8String::size(text);
	text="";
	for(unsigned int i=0; i<size; i++)
	{
		
		if(i==caretPosition)
			text+=str;
		text+=chT[i];
	}
	if(caretPosition>=size)		
			text+=str;
	
	moveCaretRight();
}
void TextField::eraseCharacter()
{
	string* chT= UTF8String::charTable(text);
	unsigned int size = UTF8String::size(text);
	text="";
	for(unsigned int i=0; i<size; i++)
	{		
		if(i!=caretPosition)
			text+=chT[i];
	}
	moveCaretLeft();
	
}
void TextField::moveCaretLeft()
{
	setCaretPosition(caretPosition-1);
	if(caretPosition<0)
		setCaretPosition(0);
}
void TextField::moveCaretRight()
{
	setCaretPosition(caretPosition+1);
	if(caretPosition>UTF8String::size(text))
		setCaretPosition(UTF8String::size(text));
}

void TextField::setCaretPositionAtTheEnd()
{
	setCaretPosition(text.length());
}
