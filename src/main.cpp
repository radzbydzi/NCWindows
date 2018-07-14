#include <ncurses.h>
#include "NCWindows.h"
#include<string>
#include "TUIObj/Panel.h"
#include "TUIObj/Label.h"
#include "TUIObj/TextField.h"
#include "UTF8String.h"
#include "Colors.h"
#include <unistd.h>

void setColors()
{
	//Colors::setDefaultColors();
								
	for(int i=0; i<COLORS; i++)
	{
		string s = to_string(i);
		Colors::addColorPair(s,0,i);
	}
	
}
int main()
{
	NCWindows* tui= new NCWindows();
	setColors();	
	Frame* lay = &tui->getCurrentFrame();
	
	Panel* panel = new Panel();	
	panel->setXYWH(0,0,20,100,PERCENT_UNIT);
	panel->setColorPair("1");
	panel->setBorder(true);
	panel->setBorderChars("-","|","+","+","+","+");
	
	Panel* panel2 = new Panel();	
	panel2->setXYWH(20,0,80,100,PERCENT_UNIT);
	panel2->setColorPair("2");
	panel2->setBorder(true);
	
	TextField* tf = new TextField("q");
	tf->setX(0,CHARACTER_UNIT);
	tf->setY(0,CHARACTER_UNIT);
	tf->setW(100,PERCENT_UNIT);
	tf->setH(5,CHARACTER_UNIT);
	tf->setColorPair("3");
	
	Label* label = new Label();
	label->setValue("Zażółć gęślą jeźń ß ™ 简体中文, 繁體中文, فارسی, Ελληνικά, 日本語, 한국어, Русский, Українська");
	label->setXYWH(0,10,100,5,PERCENT_UNIT);
	label->setColorPair("3");
	
	panel->add(tf);
	//panel2->add(tf);
	panel2->add(label);
	lay->add(panel);
	lay->add(panel2);
	
	 long int ch;
     nodelay(stdscr, TRUE);
     bool noexit = true;
     
     string gather="";
     unsigned int bytecount = 0;
     while(noexit) {
		ch = getch(); 
		if(ch==KEY_UP)
		{
			noexit=false;
		}
		else if(ch==KEY_BACKSPACE)
		{
			tf->eraseCharacter();
		}
		else if(ch==KEY_LEFT)
		{
			tf->moveCaretLeft();
		}
		else if(ch==KEY_RIGHT)
		{
			tf->moveCaretRight();
		}
		else
		{
			if(ch!=-1)
			{								
				if(bytecount<=0)
				{
					bytecount=UTF8String::estimatedByteCount(ch);
				}
				if(bytecount>0)
				{
					gather+=ch;
					bytecount--;
					if(bytecount<=0)
					{
						tf->putString(gather);
						gather="";
					}						
				}
			}
				 	
		}
			 
          tui->update();
     }
	delete tui;
	return 0;	
}
