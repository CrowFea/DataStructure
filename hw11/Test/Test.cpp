#include<iostream>
#include<time.h>
#include<fstream>
#include<windows.h>

#include<stdio.h>
#include<stdlib.h>
using namespace std;



int main()
{
	UINT RandomArray[100000];
	UINT size=32,n=0;
	ofstream file;
	file.open("data.txt",ios::out);
	time_t t;
	
	time_t t;
	init_genrand((unsigned)time(&t));
	if (RandomArray == NULL)
	{
		return false;
	}
	for (UINT i = 0; i<size; i++)
	{
		RandomArray[i] = genrand_int32();
	}
	return true;

	return 0;
}
