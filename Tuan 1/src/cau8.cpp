#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    char Chuoi[255],*s;
    cout<<"Nhap chuoi: ";
    gets(Chuoi);
    s=strrev(Chuoi) ;
    cout<<"\nChuoi chu hoa: ";
    cout << s;
    system("PAUSE");
    return 0;
}