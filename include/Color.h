#ifndef __COLOR_H_INCLUDED__
#define __COLOR_H_INCLUDED__
#include<string>
using namespace std;
class Color{
	private:
		int id;
		string name;
		bool def=false;//default indicator
		int r;
		int g;
		int b;
	protected:
	public:
		Color();
		Color(string name, int r, int g, int b);
		Color(bool def);
		Color(string name, int r, int g, int b,bool def);
		~Color();
		void setName(string name);
		void setR(int r);
		void setG(int g);
		void setB(int b);
		void setId(int id);
		string getName();
		int getR();
		int getG();
		int getB();
		int getId();
		bool getDefaultValue();
		
};

#endif




