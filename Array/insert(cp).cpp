#include<iostream>
using namespace std;

void input(int a[],int n){
	cout<<"enter the elements of array";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}


int insert(int a[],int n,int x,int k){//x=element k=position
	if(k>n||k<1)
	return -1;
	else{
		//n++;
		for(int i=n;i>=k;i--){
			a[i]=a[i-1];
		}
		a[k-1]=x;
		n++;
		return n;
	}
	
}

void display(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	
	}
}

int main(){
	int n,k,x;
	cout<<"Enter the no of elements";
	cin>>n;
	int a[n];
	input(a,n);
	cout<<"Enter the element";
	cin>>x;
	cout<<"Enter the position which have to delete";
	cin>>k;
	int j=insert(a,n,x,k);
	if(j>0){
		cout<<"The element deleted successfully"<<endl;
		display(a,j);
		
	}
	else
	cout<<"Please enter valid position"<<endl;
}
