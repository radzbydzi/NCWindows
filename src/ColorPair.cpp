#include "ColorPair.h"

ColorPair::ColorPair(bool def)
{
	this->def=def;
}
ColorPair::ColorPair(string name, Color* fg, Color* bg,bool def)
{
	this->def=def;
	setName(name);
	setForeground(fg);
	setBackground(bg);
}
ColorPair::ColorPair()
{
	ColorPair(false);
}
ColorPair::ColorPair(string name, Color* fg, Color* bg)
{
	ColorPair(name,fg,bg,false);
}
ColorPair::~ColorPair()
{
	
}
void ColorPair::setName(string name)
{
	this->name=name;
	
	//printf("<%s>",this->name.c_str());
}
void ColorPair::setBackground(Color* bg)
{
	background=bg;
}
void ColorPair::setForeground(Color* fg)
{
	foreground=fg;
}
void ColorPair::setId(int id)
{
	this->id=id;
}
string ColorPair::getName()
{
	return name;
}
Color* ColorPair::getBackground()
{
	return background;
}
Color* ColorPair::getForeground()
{
	return foreground;
}
int ColorPair::getId()
{
	return id;
}
bool ColorPair::getDefaultValue()
{
	return def;
}
