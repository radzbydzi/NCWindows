#include "TUIObj/Label.h"
Label::Label()
{
}
Label::Label(string value, string color, int attr)
{
	setValue(value);
	setAttributes(attr);
	setColorPair(color);
}
Label::~Label()
{
}
void Label::draw()
{
	showTextOn(value,0,0,getColorPair(),attr);
}

	
void Label::setValue(string value)
{
	this->value=value;
}
void Label::setAttributes(int attr)
{
	this->attr=attr;
}

string Label::getValue()
{
	return value;
}
int Label::getAttributes()
{
	return attr;
}
		
