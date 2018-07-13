#include <stdio.h>
#include <iostream>
using namespace std; 
int main()
{
	int h,i,j;
	cout << "nhap h = "; cin >> h;
	for (i=1 ; i<=h ; i++)
	{
		for (j=1; j<=h-i; j++) cout << "  ";
		for (j=1; j<=((i*2)-1) ; j++) cout << " *" ;
		cout << "\n";
	}
	system("PAUSE"); 
    return EXIT_SUCCESS;
}