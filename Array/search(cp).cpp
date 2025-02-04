#include<iostream>
using namespace std;
class linearsearch{
	int a[20],n,key;
	public:
		void input(){
			cout<<"Enter the no of elements in array";
			cin>>n;
			cout<<"Enter the elements of array";
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			cout<<"Enter the key value which have to search";
			cin>>key;
		}
		
		int search(){
			for(int i=0;i<n;i++){
				if(a[i]==key)
				return i+1;
			}
			return -1;
		}
};

int main(){
	linearsearch sc;
	//sc.elinput();
	sc.input();
	int index=sc.search();
	if(index>0)
	cout<<"The element found at position "<<index<<endl;
	else
	cout<<"Sorry the requested element not found "<<endl;
	
return 0;
}
