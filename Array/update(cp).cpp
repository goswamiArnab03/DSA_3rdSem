#include<iostream>
using namespace std;
class update_arr{
 	int a[20],n,k,x;//x=element k=position
 	public:
 		void input(){
			cout<<"Enter the no of elements in array";
			cin>>n;
			cout<<"Enter the elements of array";
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			cout<<"Enter the position where have to update";
			cin>>k;
			cout<<"Enter the element";
			cin>>x;
		}
		
		int update(){
			if(k>n || k<1)
			return -1;
			else{
				a[k-1]=x;
				return 1;
			}
		}
		
		void display(){
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";
		}
 };
 
 int main(){
 	update_arr up;
 	up.input();
 	int j=up.update();
 	if(j>0){
 		cout<<"The element updated successfully"<<endl;
 		up.display();
	 }
	 else
	 	cout<<"Please enter the valid position"<<endl;
	
return 0;
 }
