#include "NCWindows.h"
#include "UTF8String.h"
#include <ncurses.h>
#include<locale.h>
NCWindows::NCWindows()
{
	setlocale(LC_ALL,"");//set default text encoding, it will take type of encoding
	initscr();//initialize screen
	noecho();//getch doesn't show what we've typed on screen
	curs_set(0);//turns off cursor
	//timeout(0);
	//nocbreak();
	keypad(stdscr,TRUE);//allows to use special keys like arrows
	addFrame("Main");
	setCurrentFrame(0);
	if(has_colors() == FALSE)
	{
		endwin();//close ncurses
		printf("Your terminal doesn't support colors!\n");//show message
		exit(1);//quit
	}
	if(can_change_color() == FALSE)
	{
		endwin();//close
		printf("Your terminal doesn't support rich colors!\n");
		//exit(1);
	}
	
	start_color();//ncurses function to start using colors
	cbreak();
}
NCWindows::~NCWindows()
{
	endwin();
}
void NCWindows::update()
{
	Frame l = getCurrentFrame();
	int mX,mY;
	getmaxyx(stdscr, mY, mX);
	for(int i=0; i<l.objCount(); i++)
	{
		TUIObject* obj=l.getObject(i);
		obj->setOrigin(0,0,mX,mY);
		obj->draw();
	}
	refresh();
}
void NCWindows::showTextOn(string str, int x, int y)
{
	mvaddstr(y, x, str.c_str());
}

char NCWindows::getChar()
{
	return getch();
}

void NCWindows::setCurrentFrame(int num)
{
	currentFrame=num;
}
Frame& NCWindows::addFrame(string name)
{
	Frame l = Frame(name);
	frames.push_back(l);
	return getFrame(frames.size()-1);
}
Frame& NCWindows::getFrame(int num)
{
	return frames[num];
}
Frame& NCWindows::getCurrentFrame()
{
	return getFrame(currentFrame);
}
int NCWindows::getMaxX()
{
	return getmaxx(stdscr);
}
int NCWindows::getMaxY()
{
	return getmaxy(stdscr);
}
