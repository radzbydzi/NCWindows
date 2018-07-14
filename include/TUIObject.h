#ifndef __TUIOBJECT_H_INCLUDED__
#define __TUIOBJECT_H_INCLUDED__
#define PERCENT_UNIT 0
#define CHARACTER_UNIT 1
#include<string>
#include<vector>
#include<ncurses.h>
using namespace std;

class TUIObject{
	private:
		int x=0;
		int y=0;
		int w=1;
		int h=1;
		int unitX=CHARACTER_UNIT;
		int unitY=CHARACTER_UNIT;
		int unitW=CHARACTER_UNIT;
		int unitH=CHARACTER_UNIT;
		string name;
		bool focus=false;
		bool border=false;
		string colorPair;
		//BORDERS
		string horBor="─";
		string vertBor="│";
		string leftUpperBor="┌";
		string rightUpperBor="┐";
		string leftLowerBor="└";
		string rightLowerBor="┘";
	protected:		
		int originX;
		int originY;
		int originW;
		int originH;
	public:		
		TUIObject();
		virtual ~TUIObject();
		//-------------------
		void setX(int x,unsigned int p);
		void setY(int y, unsigned int p);
		void setW(int w, unsigned int p);
		void setH(int h, unsigned int p);
		void setXYWH(int x, int y, int w, int h, unsigned int p);
		//-------------------
		void setUnitX(unsigned int unit);
		void setUnitY(unsigned int unit);
		void setUnitW(unsigned int unit);
		void setUnitH(unsigned int unit);
		//-------------------
		int getX();
		int getY();
		int getW();
		int getH();
		int getXChU();//in character unit
		int getYChU();
		int getWChU();
		int getHChU();
		//--------------------
		unsigned int getUnitX();
		unsigned int getUnitY();
		unsigned int getUnitW();
		unsigned int getUnitH();
		//--------------------
		bool getFocus();
		void setFocus(bool focus);
		void setColorPair(string name);
		string getColorPair();
		void setBorderChars(string hor, string vert, string uppleft, string uppright, string lowleft, string lowright);
		void setBorder(bool b);
		bool getBorder();
		virtual void draw()=0;
		void showTextOn(string str, int x, int y);
		void showTextOn(string str, int x, int y, bool ignoreBorder);
		void showTextOn(string str, int x, int y, chtype attributes, bool ignoreBorder);
		void showTextOn(string str, int x, int y,string colPair, bool ignoreBorder);
		void showTextOn(string str, int x, int y,string colPair, chtype attributes, bool ignoreBorder);
		void drawBorder();
		void drawBackground();
		void drawShadow();
		void setOrigin(int oX, int oY, int oW, int oH);
};

#endif

