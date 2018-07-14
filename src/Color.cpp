#include "Color.h"

Color::Color()
{
	Color(false);
}
Color::Color(string name, int r, int g, int b)
{
	Color(name,r,g,b,false);
}
Color::Color(bool def)
{
	this->def = def;
}
Color::Color(string name, int r, int g, int b, bool def)
{
	setName(name);
	setR(r);
	setG(g);
	setB(b);
	this->def = def;
}
Color::~Color()
{
}
void Color::setName(string name)
{
	this->name=name;
}
void Color::setR(int r)
{
	this->r=r;
}
void Color::setG(int g)
{
	this->g=g;
}
void Color::setB(int b)
{
	this->b=b;
}
void Color::setId(int id)
{
	this->id=id;
}
string Color::getName()
{
	return name;
}
int Color::getR()
{
	return r;
}
int Color::getG()
{
	return g;
}
int Color::getB()
{
	return b;
}
int Color::getId()
{
	return id;
}
bool Color::getDefaultValue()
{
	return def;
}
