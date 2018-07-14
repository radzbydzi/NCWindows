#include "Colors.h"
vector<Color*> Colors::colors;
vector<ColorPair*> Colors::colorpairs;
void Colors::addColor(string name, int r, int g, int b)
{
	addColor(name,r,g,b,false);
}
void Colors::addColor(string name, int r, int g, int b, bool isDefault)
{
	Color* color = new Color(name,r,g,b,isDefault);
	int id=getNextColorId();
	if(id==-1)
		return;
	color->setId(id);
	colors.push_back(color);
	init_color(id, r, g, b);	
}
void Colors::addColorPair(string name,string fg, string bg)
{
	Color* foreground=getColor(fg);
	Color* background=getColor(bg);
	if(foreground==NULL || background==NULL)
		return;
		
	int id=getNextColorPairId();
	if(id==-1)
		return;
	ColorPair* colorpair=new ColorPair(name,foreground,background,false);
	colorpair->setId(id);
	colorpairs.push_back(colorpair);
	init_pair(id, foreground->getId(), background->getId());
}
void Colors::addColorPair(string name,int fg, int bg)
{
	int id=getNextColorPairId();
	if(id==-1)
		return;
	ColorPair* colorpair=new ColorPair(name,NULL,NULL,false);
	colorpair->setId(id);
	colorpairs.push_back(colorpair);
	init_pair(id, fg, bg);
}
int Colors::getColorPairId(string name)
{
	for(unsigned int i=0; i<colorpairs.size(); i++)
	{
		if(colorpairs[i]->getName()==name)
			return colorpairs[i]->getId();
	}
	return 1;
}
int Colors::getColorId(string name)
{
	for(unsigned int i=0; i<colors.size(); i++)
	{
		if(colors[i]->getName()==name)
			return colors[i]->getId();
	}
	return 0;
}
void Colors::delColor(string name)
{
	delColor(name,false);
}
void Colors::delColor(string name, bool defaultChange)
{
	Color* color = getColor(name);
	if(color->getDefaultValue()==true && defaultChange==false)
		return;
	
	for(unsigned int i=0; i<colors.size(); i++)
	{
		if(colors[i]==color)
		{
			colors.erase(colors.begin()+i);
		}
	}
	delete color;
}
void Colors::delColorPair(string name)
{
	delColor(name,false);
}
void Colors::delColorPair(string name, bool defaultChange)
{
	ColorPair* colorpair = getColorPair(name);
	if(colorpair->getDefaultValue()==true && defaultChange==false)
		return;
	
	for(unsigned int i=0; i<colorpairs.size(); i++)
	{
		if(colorpairs[i]==colorpair)
		{
			colorpairs.erase(colorpairs.begin()+i);
		}
	}
	delete colorpair;
}
Color* Colors::getColor(string name)
{
	for(unsigned int i=0; i<colors.size(); i++)
	{
		if(colors[i]->getName()==name)
		{
			return colors[i];
		}
	}
	return NULL;
}
ColorPair* Colors::getColorPair(string name)
{
	for(unsigned int i=0; i<colorpairs.size(); i++)
	{
		if(colorpairs[i]->getName()==name)
		{
			return colorpairs[i];
		}
	}
	return NULL;
}
int Colors::getNextColorId()
{
	for(int i=0;i<COLORS; i++)
	{
		bool occured=false;
		for(unsigned int j=0;j<colors.size(); j++)
		{
			if(colors[j]->getId()==i)
				occured=true;
		} 
		if(occured==false)
			return i;
	} 
	return -1;
}
int Colors::getNextColorPairId()
{
	for(int i=1;i<COLOR_PAIRS; i++)
	{
		bool occured=false;
		for(unsigned int j=0;j<colorpairs.size(); j++)
		{
			if(colorpairs[j]->getId()==i)
				occured=true;
		} 
		if(occured==false)
			return i;
	} 
	return -1;
}
void Colors::setDefaultColors()
{
	Colors::addColor("black",0,0,0,false);
	Colors::addColor("red",1000,1000,1000,false);
	Colors::addColor("green",1000,0,0,false);
	Colors::addColor("yellow",0,1000,0,false);
	Colors::addColor("blue",0,0,1000,false);
	Colors::addColor("magenta",0,0,1000,false);
	Colors::addColor("cyan",0,0,1000,false);
	Colors::addColor("white",0,0,1000,false);
}
