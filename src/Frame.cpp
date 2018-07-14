#include "Frame.h"

Frame::Frame(string name)//sets name of layout
{
	this->name=name;
}

void Frame::add(TUIObject* obj)//adds objects pointers to layout
{
	objects.push_back(obj);
	
	obj->setOrigin(0,0,getmaxx(stdscr), getmaxy(stdscr));
}

TUIObject* Frame::getObject(int num)//gets object pointer
{
	return objects[num];
}
int Frame::objCount()//gets objects list size
{
	return objects.size();
}
