#ifndef __COLORS_H_INCLUDED__
#define __COLORS_H_INCLUDED__
#include<string>
#include<vector>
#include<ncurses.h>
#include "Color.h"
#include "ColorPair.h"
using namespace std;
class Colors{
	private:
		Colors();
		virtual ~Colors();
		static vector<Color*> colors;
		static vector<ColorPair*> colorpairs;
		
	protected:
	public:
		static void addColor(string name, int r, int g, int b);
		static void addColor(string name, int r, int g, int b, bool isDefault);
		static void addColorPair(string name, string fg, string bg);
		static void addColorPair(string name, int fg, int bg);
		static int getColorPairId(string name);
		static int getColorId(string name);
		static void delColor(string name);
		static void delColor(string name, bool defaultChange);
		static void delColorPair(string name);
		static void delColorPair(string name, bool defaultChange);
		static Color* getColor(string name);
		static ColorPair* getColorPair(string name);
		static int getNextColorId();
		static int getNextColorPairId();
		static void setDefaultColors();
};

#endif





