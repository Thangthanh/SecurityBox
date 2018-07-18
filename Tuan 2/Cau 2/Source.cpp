#include<iostream>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<string>
using namespace std;

ofstream outfile;

void search(string path);
void replace(string path);
void menu();

void main()
{
	string path;
	string str;
	
	
	outfile.open("output.txt");
	
	cout << "Nhap duong dan toi file: ";
	cin >> path;

	ifstream infile;
	infile.open(path);
	
	while (!infile.good())
    {
        cout << "\nDuong dan sai";
        cout << "\nNhap Lai Duong Dan Toi File: ";
        cin >> path;
        infile.open(path);
    }
	infile.close();
	outfile << "Input file : " << path << "\n";
	int choice;
	int ct=1;
	do{
        menu();
		cin >> choice;
        switch(choice){
            case 1:
                outfile << "\nContext "<< ct << ": Search keyword " ;
                ct++;
				search(path);
                break;
            case 2:
                outfile << "\nContext "<< ct << ": Replace by new keyword " ;
                ct++;
				replace(path);
                break;
            case 3:
                break;
            default:
               cout << "\r\n>> Chon 1, 2 hoac 3";
        }
        if (choice == 3) break;
    } while(true);

	outfile.close();
	system("PAUSE");
}

void menu()
{
	cout << "\n----------------------------------------------";
	cout << "\n              1. Search";
    cout << "\n              2. Replace";
    cout << "\n              3. Exit";
	cout << "\n----------------------------------------------\n";
}

void search(string path)
{
	string str,key;
	int line=0; // line number
	int appe=0; // Total appeared
	int found;
	
	ifstream infile;
	infile.open(path);
	cout << "\nEnter keyword: ";
	cin >> key;

	outfile << "\n       Keyword: "<< key;

	while (getline(infile,str))
	{
		line++;
		found=str.find(key);
		while(found!=std::string::npos)
		{
			appe++;
			cout << "\nLine " << line << ", Col " << found ;
            outfile << "\nLine " << line << ", Col " << found ;
			found=str.find(key,found+1);
		}
	}
	cout << "\nTotal appeared : "<< appe;
	outfile << "\nTotal appeared : "<< appe<< "\n";
	infile.close();
}
void replace(string path)
{
	string key,newkey;
	string str;
	int line=0; // line number
	int appe=0; // Total appeared
	int found;

	ifstream infile;
	infile.open(path);
	ofstream refile;
	refile.open("replace.txt");
	
	cout << "\nEnter Word: ";
    cin >> key;
	outfile << "\n         Keyword : "<< key;

	cout << "Enter new word: ";
    cin >> newkey;
	outfile << "\n         New Keyword : "<< newkey;

	while (getline(infile,str))
	{
		line++;
		found=str.find(key);
		while(found!=std::string::npos)
		{
			appe++;
			str.replace(found,key.length(),newkey);
			cout << "\nLine " << line << ", Col " << found ;
            outfile << "\nLine " << line << ", Col " << found ;
			found=str.find(key,found+1);
		}
		refile << str <<"\n";
	}
	refile.close();
	
	cout << "\nTotal appeared : "<< appe;
	outfile << "\nTotal appeared : "<< appe;
	cout << "\nReplace \""<< key <<"\" by \""<< newkey<< "\" successfuly\n";
	outfile << "\nReplace \""<< key <<"\" by \""<< newkey<< "\" successfuly\n";
	infile.close();
}