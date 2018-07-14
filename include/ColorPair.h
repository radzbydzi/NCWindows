#ifndef __COLORPAIR_H_INCLUDED__
#define __COLORPAIR_H_INCLUDED__
#include<string>
#include "Color.h"
using namespace std;
class ColorPair{
	private:
		int id;
		string name;
		bool def;
		Color* foreground;
		Color* background;
	protected:
	public:
		ColorPair();
		ColorPair(string name, Color* fg, Color* bg);
		ColorPair(bool def);
		ColorPair(string name, Color* fg, Color* bg, bool def);
		~ColorPair();
		void setName(string name);
		void setBackground(Color* bg);
		void setForeground(Color* fg);
		void setId(int id);
		string getName();
		Color* getBackground();
		Color* getForeground();
		int getId();
		bool getDefaultValue();
};

#endif




