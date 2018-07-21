#include "TUIObject.h"
#include "UTF8String.h"
#include "Colors.h"
#include<iostream>
TUIObject::TUIObject()
{
	
}
TUIObject::~TUIObject()
{
	
}
//----------------
void TUIObject::setX(int x,unsigned int p)
{
	this->x=x;
	setUnitX(p);
}
void TUIObject::setY(int y, unsigned int p)
{
	this->y=y;
	setUnitY(p);
}
void TUIObject::setW(int w, unsigned int p)
{
	this->w=w;
	setUnitW(p);
}
void TUIObject::setH(int h, unsigned int p)
{
	this->h=h;
	setUnitH(p);
}
void TUIObject::setXYWH(int x, int y, int w, int h, unsigned int p)
{
	setX(x,p);
	setY(y,p);
	setW(w,p);
	setH(h,p);
}
//-----------
void TUIObject::setUnitX(unsigned int unit)
{
	unitX=unit;
}
void TUIObject::setUnitY(unsigned int unit)
{
	unitY=unit;
}
void TUIObject::setUnitW(unsigned int unit)
{
	unitW=unit;
}
void TUIObject::setUnitH(unsigned int unit)
{
	unitH=unit;
}
//-----------
int TUIObject::getX()//gets x
{
	return x;
}
int TUIObject::getY()//gets y
{
	return y;
}
int TUIObject::getW()//gets width
{
	return w;
}
int TUIObject::getH()//gets height
{
	return h;
}
int TUIObject::getXChU()//gets x in character units
{
	if(unitX==CHARACTER_UNIT)
		return x;
	else if(unitX ==PERCENT_UNIT)
		return (int)((float)x/100*(originX+originW));
	else
		return 0;
}
int TUIObject::getYChU()//gets y in character units
{
	if(unitY==CHARACTER_UNIT)
		return y;
	else if(unitY ==PERCENT_UNIT)
		return (int)((float)y/100*(originY+originH));
	else
		return 0;
}
int TUIObject::getWChU()//gets width in character units
{
	if(unitW==CHARACTER_UNIT)
		return w;
	else if(unitW ==PERCENT_UNIT)
		return (int)((float)w/100*(originX+originW));
	else
		return 0;
}
int TUIObject::getHChU()//gets height in character units
{
	if(unitH==CHARACTER_UNIT)
		return h;
	else if(unitH==PERCENT_UNIT)
		return (int)((float)h/100*(originY+originH));
	else
		return 0;
}
//-------------
unsigned int TUIObject::getUnitX()
{
	return unitX;
}
unsigned int TUIObject::getUnitY()
{
	return unitY;
}
unsigned int TUIObject::getUnitW()
{
	return unitW;
}
unsigned int TUIObject::getUnitH()
{
	return unitH;
}
//-------------
bool TUIObject::getFocus()//shows state of focus, if object focused returns true
{
	return focus;
}
void TUIObject::setFocus(bool focus)//sets focus from given bool
{
	this->focus=focus;
}	
//-------------
void TUIObject::setColorPair(string colorPair)//sets default color pair
{
	this->colorPair=colorPair;
}
string TUIObject::getColorPair()//gets default color pair
{
	return colorPair;
}
//-------------
void TUIObject::setBorderChars(string hor, string vert, string uppleft, string uppright, string lowleft, string lowright)
{
	horBor=hor;
	vertBor=vert;
	leftUpperBor=uppleft;
	rightUpperBor=uppright;
	leftLowerBor=lowleft;
	rightLowerBor=lowright;
}
void TUIObject::setBorder(bool b)
{
	if(b)
	{
		setBorderTop(true);
		setBorderBottom(true);
		setBorderLeft(true);
		setBorderRight(true);
	}else
	{
		setBorderTop(false);
		setBorderBottom(false);
		setBorderLeft(false);
		setBorderRight(false);
	}
	
}
void TUIObject::setBorderTop(bool b)
{
	borderTop=b;
}
void TUIObject::setBorderBottom(bool b)
{
	borderBottom=b;
}
void TUIObject::setBorderLeft(bool b)
{
	borderLeft=b;
}
void TUIObject::setBorderRight(bool b)
{
	borderRight=b;
}
//-------------
bool TUIObject::getBorderTop()
{
	return true;
	return borderTop;
}
bool TUIObject::getBorderBottom()
{
	return true;
	return borderBottom;
}
bool TUIObject::getBorderLeft()
{
	return true;
	return borderLeft;
}
bool TUIObject::getBorderRight()
{
	return true;
	return borderRight;
}
//-------------
void TUIObject::showTextOn(string str, int x, int y)//show string on local x,y
{
	showTextOn(str,x,y,false);
}
void TUIObject::showTextOn(string str, int x, int y, bool ignoreBorder)//show string on local x,y
{
	showTextOn(str,x,y,getColorPair(),0,ignoreBorder);
}
void TUIObject::showTextOn(string str, int x, int y, chtype attributes, bool ignoreBorder)//show string on local x,y
{
	showTextOn(str,x,y,getColorPair(),attributes,ignoreBorder);
}
void TUIObject::showTextOn(string str, int x, int y,string colPair, bool ignoreBorder)//show string on local x,y
{
	showTextOn(str,x,y,colPair,0,ignoreBorder);
}

void TUIObject::showTextOn(string str, int x, int y,string colPair, chtype attributes, bool ignoreBorder)//show string on local x,y
{
	int bTB=0;
	int bLR=0;
	
	
	if(getBorderTop())
	{
		bTB++;
	}
	if(getBorderBottom())
	{
		bTB++;
	}
	if(getBorderLeft())
	{
		bLR++;
	}
	if(getBorderRight())
	{
		bLR++;
	}
	if(x>getWChU()-1-bLR || y>getHChU()-1-bTB)
		return;
		
	int cpId=Colors::getColorPairId(colPair);
	attron(COLOR_PAIR(cpId)|attributes);
	str=UTF8String::safeString(str);
	mvaddstr(originY+getYChU()+y+bTB, originX+getXChU()+x+bLR, str.c_str());
	attroff(COLOR_PAIR(cpId)|attributes);	
}
void TUIObject::drawBorder()
{
	if(!UTF8String::isUTF8Available())
		setBorderChars("-","|","+","+","+","+");
	setBorder(true);
	int width = getWChU();
	int height = getHChU();
	
	if(width>originW)//if originx + width > originW (max value we can draw)
		width=originW;//width is lenght of horizontal origin
	if(height>originH)
		height=originH;//vertical origin
	
	for(int x=0; x<width; x++)
		{
			for(int y=0; y<height; y++)
			{
				string znak="";//sign we put letter to show
						
				if(y==0 && getBorderTop()==true)//if first row
				{
					
					if(x==0 && getBorderLeft()==true)//if first col and border left
						znak = leftUpperBor;
					else if(x==width-1 && getBorderRight()==true)//if last col and border right
						znak = rightUpperBor;
					else
						znak = horBor;		
							
				}
				else if(y==height-1 && getBorderBottom()==true)//if last row
				{
					if(x==0 && getBorderLeft()==true)//if first col
						znak = leftLowerBor;
					else if(x==width-1 && getBorderRight()==true)//if last col
						znak = rightLowerBor;
					else
						znak = horBor;	
				}
				else//any other lines
				{
					if( (x==0 && getBorderLeft()==true) || (x==width-1 && getBorderRight()==true) )//if first or last column
					{
						znak = vertBor;
					}
				}
				showTextOn(znak,x,y,true);
			}
		}
		
}
void TUIObject::drawBackground()
{
	int width = getWChU();//local x + local w = width
	int height = getHChU();//local y + loacal w = height 
	
	if(width>originW)//if originx + width > originW (max value we can draw)
		width=originW;//width is lenght of horizontal origin
	if(height>originH)
		height=originH;//vertical origin

	for(int x=0; x<width; x++)
	{
		for(int y=0; y<height; y++)
		{
			showTextOn(" ",x,y,true);
		}
	}
		
}
void TUIObject::drawShadow()
{
	const int offset=1;
	attron(COLOR_PAIR(10));//set color pair <ncurses function>
	//like in border
		
	int width = getWChU();//local x + local w = width
	int height = getHChU();//local y + loacal w = height 
	
	if(width>originW)//if originx + width > originW (max value we can draw)
		width=originW;//width is lenght of horizontal origin
	if(height>originH)
		height=originH;//vertical origin

	for(int x=offset; x<width+offset; x++)
	{
		for(int y=offset; y<height+offset; y++)
		{
			showTextOn(" ",x,y,true);
		}
	}
	
	attroff(COLOR_PAIR(10));//turn of color pair
}
void TUIObject::setOrigin(int oX, int oY, int oW, int oH)//sets origin
{
	originX=oX;
	originY=oY;
	originW=oW;
	originH=oH;
}
