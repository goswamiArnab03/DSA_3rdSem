//This is called as menu driven programme 
#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;

class Array{
 	int a[MAX],n,k,x;//x=element k=position
 	public:
 		void input(){
			cout<<"Enter the no of elements in array";
			cin>>n;
			cout<<"Enter the elements of array";
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			
		}
		int Delete(){// the user will input which position have to delete
			cout<<"Enter the position which have to delete";
			cin>>k;
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
		int search(){
			cout<<"Enter the  value which have to search";
			cin>>x;
			for(int i=0;i<n;i++){
				if(a[i]==x)
				return i+1;
			}
			return -1;
		}
		int insert(){//x=element k=position
			cout<<"Enter the element";
			cin>>x;
			cout<<"Enter the position where have to insert";
			cin>>k;
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
		

		
		int update(){
			cout<<"Enter the position where have to update";
			cin>>k;
			cout<<"Enter the element";
			cin>>x;
			if(k>n || k<1)
			return -1;
			else{
				a[k-1]=x;
				return 1;
			}
		}
		
		void display(){
			cout<<"The elements of array is"<<endl;
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";
			
			cout<<endl;
		}
 };
 
 int main(){
 	Array ar;
 	ar.input();
 	cout<<"Enter 0 for displaying the elements in array"<<endl;
 	cout<<"Enter 1 for search an element in array"<<endl;
 	cout<<"Enter 2 for insert an element in  array"<<endl;
 	cout<<"Enter 3 for delete an element in array"<<endl;
 	cout<<"Enter 4 for update an element in array"<<endl;
 	cout<<"Enter 5 for exit"<<endl;
 	
 	while(1){
 		int p,j,m,n,b;
 		cin>>p;
 		switch(p){
 			case 0:
 				ar.display();
 				break;
 			case 1:
 				j=ar.search();
 				if(j>0){
 					cout<<"The element found at position"<<j<<endl;
				 }
				 else
				 	cout<<"Sorry the requested element not found"<<endl;
				 	
				break;
			case 2:
				m=ar.insert();
				if(m>0){
					cout<<"The element inserted at the position successfully"<<endl;
				}
				else{
					cout<<"Please enter a valid position"<<endl;
				}
				break;
			case 3:
				n=ar.Delete();
				if(n>0){
					cout<<"The element deleted successfully"<<endl;
				}
				else{
					cout<<"Please enter a valid position"<<endl;
				}
				break;
			case 4:
				b=ar.update();
				if(b>0){
					cout<<"The element updated successfully"<<endl;
				}
				else{
					cout<<"Please enter a valid position"<<endl;
				}
				break;
			case 5:
				exit(1);
			
			default:
				cout<<"Invalid input"<<endl;
				break;
			
				
		}
	}
return 0;
}
 
