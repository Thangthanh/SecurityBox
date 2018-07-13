#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
	 
int main()
{
	int d,m,y,c,n;
	cout << "nhap ngay thang nam ";
	cin >> d >> m >>y;
	c=0;n=0;
	if (y<=0) c=1;
	else 
		if (m<=0 || m>12) c=1;
		else
			switch(m)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
				if (d<=0 || d>31) c=1;
				break;
				case 4:
				case 6:
				case 9:
				case 11:
				if (d<=0 || d>30) c=1;
				break;
				case 2:
				if(y%4==0 && y%100!=0 || y%400==0)
				{
					n=1;
					if (d<=0 || d>29) c=1;
				}
				else
				{
					if (d<=0 || d>28) c=1;
				}
				break;
			}

	if (c==1) cout << "Khong hop le";
	else
		if (n==1) cout << "Nam nhuan";
		else cout << "Khong phai nam nhuan";
	system("PAUSE");
	return 0;
}