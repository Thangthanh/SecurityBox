#include <iostream>
#include <conio.h>
using namespace std; 

int main()
{
  long n;
  int l,i,j,tg;
  int a[10];
  cout << "nhap n = "; 
  cin >> n ;
  l=0;
  do{ 
        a[l] = n % 10;
		n/=10;
		if (n==0) break;
		l++;
     }while(n>0);  
  for (i=0 ; i<l ; i++ )
	  for (j=i ; j<=l ; j++ )
		  if (a[i]<a[j])
		  {
			tg = a[i];
			a[i] = a[j];
			a[j] = tg;
		  }
  cout << "thu tu giam dan \n";
  for (i=0 ; i<=l ; i++)
	  cout <<a[i]<<" ";
  
  getch();
  return 0;
}