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
	for(int i=0; i<objCount(); i++)
	{
		TUIObject* obj=getObject(i);
		/*
		origin means value we add to local x y w h of our object
		thanks to it we can operate on local not global coordinates
		*/
		int borderW=0;
		int borderH=0;
		if(getBorderLeft()==true)
		{
			borderW++;
		}
		if(getBorderRight()==true)
		{
			borderW++;
		}
		if(getBorderTop()==true)
		{
			borderH++;
		}
		if(getBorderBottom()==true)
		{
			borderH++;
		}
		
		int newOrX=getXChU()+originX+borderW;
		int newOrY=getYChU()+originY+borderH;
		obj->setOrigin(newOrX,newOrY,getWChU()-borderW, getHChU()-borderH);
		obj->draw();
	}
}
