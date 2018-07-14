#ifndef __NCWINDOWS_H_INCLUDED__
#define __NCWINDOWS_H_INCLUDED__
#include<curses.h>
#include<ncurses.h>
#include<iostream>
#include<string>
#include<vector>
#include "Frame.h"
using namespace std;
class NCWindows{
	private:
		vector<Frame> frames;
		int currentFrame;
	protected:
	public:
		NCWindows();
		~NCWindows();
		void update();
		void showTextOn(string str, int cols, int rows);
		char getChar();
		void setCurrentFrame(int num);
		Frame& addFrame(string name);
		Frame& getFrame(int num);
		Frame& getCurrentFrame();
		int getMaxX();
		int getMaxY();
};

#endif
