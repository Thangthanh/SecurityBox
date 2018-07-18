#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<sstream>

using namespace std;

string brackets;

void readFile();
string convert(int val);
int them(string brackets);
void truebracket(string brackets);

int main()
{
	readFile();
	truebracket(brackets);
	system("PAUSE");
	return 0;
}

void readFile()
{
	ifstream infile;
	infile.open("BRACKET_IN.txt");
	if (infile) 
	{
		infile >> brackets;
	}
	else 
		cout <<  " Can't read file";
	infile.close();
}

string convert(int val)
{
	stringstream ss;
	ss << val;
	string str = ss.str();
	return str;
}

int them(string brackets)
{
	int i,j,k;
	j=0;
	k=0;
	for (i=0 ; i<brackets.length() ; i++)
	{
		if (brackets[i]=='(')	
		{
			j++;
			k++;
		}
		if (brackets[i]==')')	
			if (k!=0)
			{
				j--;
				k--;
			}
			else j++;
	}
	return j;
}

void truebracket(string brackets)
{
	int i,tt,nmo;
	string data;
	tt=0;
	nmo=0;
	int t = them(brackets);
	ofstream outfile;
	outfile.open("BRACKET_OUT.txt", ios::app);
	data = convert(t);
	outfile << data << "\n";
	for (i=0; i<brackets.length() ; i++)
	{
		if (brackets[i]=='(') 
		{
			tt++;
			nmo++;
		}
		else
			if (nmo!=0)
			{
				tt++;
				nmo--;
			}
			else 
			{
				tt++;
				data = convert(tt);
				outfile << data << "  (\n";
				tt++;
			}
	}
	if (nmo!=0)
		for (i=0 ; i<nmo ; i++)
		{
		tt++;
		data = convert(tt);
		outfile << data << "  )\n";
		}
		outfile.close();
}