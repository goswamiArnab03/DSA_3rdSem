#include<iostream>
using namespace std;

void input(int a[],int n){
	cout<<"enter the elements of array";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

int del(int a[],int n,int k){// the user will input which position have to delete
	if(k<1 || k>n)
	return -1;
	else{
		for(int i=k-1;i<n-1;i++){
			a[i]=a[i+1];
		}
		n--;
		return n;
	}
	
}

void display(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	
	}
}

int main(){
	int n,k;
	cout<<"Enter the no of elements";
	cin>>n;
	int a[n];
	input(a,n);
	cout<<"Enter the position which have to delete";
	cin>>k;
	int j=del(a,n,k);
	if(j>0){
		cout<<"The element deleted successfully"<<endl;
		display(a,j);
		
	}
	else
	cout<<"Please enter valid position"<<endl;
	
return 0;
}
