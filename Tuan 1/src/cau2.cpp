#include <cstdlib> 
#include <iostream> 
#include <ctype.h>  
#include <conio.h>
using namespace std; 
  
int main() 
{ 
	char name[255];
	int i,up,dow;
	up = 0;
	dow = 0;
    cout<<"Nhap xau ky tu:"<< endl;
	gets_s(name);
	
	for (i=0 ; i < strlen(name) ; i++)
	{
		if (islower(name[i])) dow++;
		if (isupper(name[i])) up++;
	}
    
	cout << "so ky tu hoa : " <<up<<"\n";
	cout << "so ky tu thuong : " <<dow<<"\n";
    system("PAUSE"); 
    return EXIT_SUCCESS; 
} 