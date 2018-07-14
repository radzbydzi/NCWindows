#include "TUIObj/Panel.h"

Panel::Panel()
{
	
}
Panel::~Panel()
{
	
}
void Panel::add(TUIObject* obj)
{
	objects.push_back(obj);//adds objects pointers to list
	
	int newOrX=getXChU()+originX;
	int newOrY=getYChU()+originY;
	obj->setOrigin(newOrX,newOrY,getWChU(), getHChU());
}
TUIObject* Panel::getObject(int num)
{
	return objects[num];//returns element from list
}
int Panel::objCount()
{
	return objects.size();//returns size of list
}
void Panel::draw()
{
	drawShadow();
	drawBackground();
	int border=0;
	if(getBorder()==true)
	{
		drawBorder();
		border=1;
	}
	for(int i=0; i<objCount(); i++)
	{
		TUIObject* obj=getObject(i);
		/*
		origin means value we add to local x y w h of our object
		thanks to it we can operate on local not global coordinates
		*/
		int newOrX=getXChU()+originX+border;
		int newOrY=getYChU()+originY+border;
		obj->setOrigin(newOrX,newOrY,getWChU()-border, getHChU()-border);
		obj->draw();
	}
}
