#ifndef __UTF8STRING_H_INCLUDED__
#define __UTF8STRING_H_INCLUDED__
#include<string>
#include<locale>

using namespace std;
class UTF8String{
	public:
		static long unsigned int size(string s)
		{
			unsigned int count=0;
			for(unsigned int i=0; i<s.size(); i++)
			{				
				int ebc=estimatedByteCount(s.at(i));
				if(ebc>0)
				{
					count+=ebc;
					i+=ebc-1;
				}
				else
				{
					count+=1;
				}
			}
			return count;
		}
		static string* charTable(string s)
		{
			string* str= new string[size(s)];
			int currentChar=0;
			for(unsigned int i=0; i<s.size(); i++)
			{
				unsigned int bytecount=estimatedByteCount(s.at(i));
				if(bytecount>0)
				{
					str[currentChar] = composeString(bytecount,s,i);
					i+=bytecount-1;
				}
				else
				{
					str[currentChar]="?";
				}
				if(str[currentChar].size()>1 && !isUTF8Available())
					str[currentChar]="?";
					
				currentChar+=1;
			}
			return str;
		}
		static string safeString(string str)
		{
			string* ch = charTable(str);
			unsigned int s = size(str);
			string res="";
			for(unsigned int i=0; i<s; i++)
			{
				res+=ch[i];
			}
			return res;
		}
		static string at(string s, int num)
		{
			return charTable(s)[num];
		}
		static unsigned int estimatedByteCount(char c)
		{
			if((c&0b10000000) == 0b00000000)
				{
					//onebyte character
					return 1;
				}else if((c&0b11100000) == 0b11000000)
				{
					//2byte character
					return 2;
				}else if((c&0b11110000) == 0b11100000)
				{
					//3byte character
					return 3;
				}
				else if((c&0b11111000) == 0b11110000)
				{
					//4byte character
					return 4;
				}
				else if((c&0b11111100) == 0b11111000)
				{
					//5byte character
					return 5;
				}
				else if((c&0b11111110) == 0b11111100)
				{
					//6byte character
					return 6;
				}
				else
				{
					return 0;//when char is not first byte of its sequence or is invalid
				}
		}
		static string bitRepr(unsigned long int ch)
		{
			string res="";
			while(ch!=0)
			{
				int r=ch%2;
				ch=ch/2;
				res=to_string(r)+res;
			}
			return res;
		}
		static bool isUTF8Available()
		{
			locale l("");
			string name=l.name();
			string opcje[] = {"UTF8","UTF-8","utf8", "utf-8"};
			for(int i=0; i<4; i++)
			{
				std::size_t found = name.find(opcje[i]);
				if(found!=std::string::npos)
					return true;
			}
			return false;
				
		}
	private:
		static string composeString(int bytecount, string s, int i)
		{
			string res="";
			bool fail=false;
			for(int j=0; j<bytecount; j++)
			{
				res+=s.at(i+j);
				if(j!=0)
					if(estimatedByteCount(s.at(i+j))!=0)
						fail=true;
			}
				
			if(fail==true)
				res="?";
			
			return res;
		}
		
};

#endif
