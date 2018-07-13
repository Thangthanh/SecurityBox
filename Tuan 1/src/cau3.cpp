#include <iostream>
#include <conio.h>
using namespace std; 
float tinh(float m) 
{
	if (m<=1000) return 10000;
	else
		if (m<=30000) return 10000+((m-1000)/200)*1500;
		else return 227500+((m-30000)/1000)*8000;
}
int main()
{
	float m,t;
	cout << "so km da di : ";
	cin >> m;
	t = tinh(m);
	cout << t << " VND\n";
	system("PAUSE"); 
    return EXIT_SUCCESS;
}