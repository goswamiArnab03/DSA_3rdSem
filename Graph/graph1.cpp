/*
 with the help of adjacency matrix representation

*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(){
	FILE* fp;
	fp=fopen("ex.txt","r");
	if(fp==NULL){
		cout<<"Error to open file"<<endl;
		exit(1);
	}
	int n;
	fscanf(fp,"%d",&n);
	int graph[10][10];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	cout<<"The adjacency matrix is: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%3d",graph[i][j]);
		}
		cout<<endl;
	}
	int count;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]==1) count++;
		}
	}
	cout<<"The total degrees is: "<<count<<endl;
	cout<<"The no of edges  is: "<<count/2<<endl;
	//calculate adjacencies of a particular vertices
	int x;
	cout<<"Enter the vertex\n(Enter 0 for A\nEnter 1 for B\nEnter 2 for C\nEnter 3 for D)"<<endl;
	cin>>x;
	cout<<"The adjacences is: ";
	for(int i=0;i<n;i++){
		if(graph[x][i]==1){
			printf("%c",'A'+i);
		}
		printf(" ");
	}
	fclose(fp);
	return 0;
}
