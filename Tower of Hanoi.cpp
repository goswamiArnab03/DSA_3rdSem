#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void TOH(int n,char s,char h,char d){
	if(n==1){
		printf("Move %d form %c to %c\n",n,s,d);
		return;
	}
	
	TOH(n-1,s,d,h);
	printf("Move %d from %c to %c\n",n,s,d);
	TOH(n-1,h,s,d);
	
}

int main(){
	int n=3;
	char source='S',help='H',destiny='D';
	TOH(n,source,help,destiny);
	return 0;
}
