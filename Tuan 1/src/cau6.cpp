#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;

void chuahoa(char s[500])
{
	int i,j;
	strlwr(s);
	while (s[0]==' ' || s[0]=='.' || s[0]==',') {
		for ( i=0 ; i<strlen(s) ; i++)
			s[i]=s[i+1];
	}
	 i=0;
	while (i<strlen(s))
	{
		while((s[i]==' ' && s[i+1]==' ') || (s[i]=='.' && s[i+1]=='.') || (s[i]==',' && s[i+1]==','))
		{
			for ( j=i ; j<strlen(s) ; j++)
					s[j]=s[j+1];
		}
		i++;
	}
	
	i=0;
	while (i<strlen(s))
	{
		if(s[i]==',' || s[i]=='.')
		{
			if(s[i-1]==' ')
			{
				s[i-1] = s[i];
				s[i]=' ';
			}
			if(s[i+1] != ' ')
			{
				for (j=strlen(s) ; j>i+1 ; j--)
					s[j] = s[j-1];
				s[i+1]=' ';
			}
			if(s[i]==' ' && s[i+1]==' ')
				for ( j=i ; j<strlen(s) ; j++)
					s[j]=s[j+1];
		}
		i++;
	}
	i=0;
	while (i<strlen(s))
	{
		while((s[i]=='.' && s[i+1]=='.') || (s[i]==',' && s[i+1]==','))
		{
			for ( j=i ; j<strlen(s) ; j++)
					s[j]=s[j+1];
		}
		i++;
	}
	for (i=0 ; i<strlen(s) ; i++)
		if (s[i]=='.') s[i+2]=toupper(s[i+2]);
	s[0] = toupper(s[0]);	
	if (s[strlen(s)-1]==' ' || s[strlen(s)-1]==',') s[strlen(s)-1]='\0';  
}	

	int main()
{
	char s[500];
	cout << "nhap vao xau:";
	gets(s);
	chuahoa(s);
	cout << "sau chuyen hoa: " << s;
	system("PAUSE");
	return 0;
}