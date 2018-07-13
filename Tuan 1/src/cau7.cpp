#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
	int a,b,r,bc;
	int n1,n2;
	cout<<"Nhap vao 2 so can tinh: ";
	cin>>n1>>n2;
	if(n1>n2)
	{
		a=n1;
		b=n2;
	}
	else
	{
		a = n2;
		b = n1;
	}
	r = a%b;
	for(; r!=0 ; )
	{
		a=b;
		b=r;
		r = a%b;
	}
	cout<<"UCLN "<<n1<<" va "<<n2<<" la "<<b<< "\n";
	bc= n1 * n2 / b;
	cout<<"BCNN "<<bc;
  system("PAUSE");

}
