#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

int n,m,u,v;
int mat[100][100];

void dijkstra(int start, int finish);
void printpath(int start, int finish, int back[]);

void main()
{
	int i,x,y;
	ifstream infile;
	infile.open("input.txt");
	infile >> n >> m >> u >> v;
	for (i=0 ; i<m ; i++)
	{
		infile >> x >>y;
		mat[x][y]=1;
	}
	infile.close();
	dijkstra(1,7);
	system("PAUSE");
}

void dijkstra(int start, int finish)
{
	int back[100],
		weight[100],
		mark[100];
	int i;
	for (i=1 ; i<=n ; i++)
	{
		back[i]=-1;
		mark[i]=0;
		weight[i]=INT_MAX;
	}
	back[start]=0;
	weight[start]=0;
	int connect;
	do
	{
		connect=-1;
		int min = INT_MAX;
		for (int j=1 ; j<=n ; j++)
			if (mark[j] == 0)
			{
				if (mat[start][j]!=0 && weight[j]>weight[start]+mat[start][j])
				{
					weight[j] = weight[start] + mat[start][j];
					back[j] = start;
				}
				if (min > weight[j])
				{
					min = weight[j];
					connect = j;
				}	
			}
		start = connect;
		mark[start] = 1;
	}while(connect!=-1 && start!=finish);
	printpath(u,finish,back);
	cout <<"\n";
}

void printpath(int start, int finish, int back[])
{
	if (start == finish)
		cout << finish << " -> ";
	else 
	{
		printpath(start,back[finish],back);
		if (finish == v) cout << finish;
		else
			cout << finish << " -> ";
	}
}