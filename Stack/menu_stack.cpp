#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100

class Stack{
	int a[MAX];
	int top=-1;
	int item;
	public:
		int isFull(){//1
			if(top==MAX-1)
				return 1;
			
			return 0;
		}
		int isEmpty(){
			if(top==-1){//2
				return 1;
			}
			return 0;
		}
		void push(){//3
			if(top==MAX-1){
				cout<<"Sorry!Stack is Full"<<endl;  //push means enter an element in stack
				return;
			}
			cout<<"Enter your no.";
			cin>>item;
			a[++top]=item;
			cout<<"Item entered successfully"<<endl;
		}
		void pop(){//4
			if(top==-1){
				cout<<"Stack is empty!!"<<endl;    //pop means delete an element in stack
				return;
			}
			top--;
			cout<<"Element deleted successfully"<<endl;
		}
		
		void peek(){//5
			if(top==-1){
				cout<<"Stack is empty!!"<<endl;   //peek means display last an element in stack
				return;
			}
			cout<<"The last element is"<<a[top]<<endl;
			
		}
		
		void display(){//6
			if(top==-1){
				cout<<"Stack is empty!!"<<endl;
				return;
			}
			cout<<"The elements currently available in stack is"<<endl;
			for(int i=0;i<=top;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	Stack st;
	cout<<"Enter 0 to exit"<<endl;
	cout<<"Enter 1 to see if the stack is full or not"<<endl;
	cout<<"Enter 2 to see if the stack is empty or not"<<endl;
	cout<<"Enter 3 to store an element in stack"<<endl;
	cout<<"Enter 4 to delete an element in stack"<<endl;
	cout<<"Enter 5 to check last an element in stack"<<endl;
	cout<<"Enter 6 to see full stack"<<endl;
	while(1){
		int p;
		cout<<"Enter your no according to your quary: ";
		cin>>p;
		switch(p){
			case 1:
				if(st.isFull()){
					cout<<"Stack is full"<<endl;
				}
				else{
					cout<<"We have space,Not full yet"<<endl;
				}
				break;
			case 2:
				if(st.isEmpty()){
					cout<<"Stack is Empty"<<endl;
				}
				else{
					cout<<"Stack is Not Empty yet"<<endl;
				}
				break;
			case 3:
				st.push();
				break;
			case 4:
				st.pop();
				break;
			case 5:
				st.peek();
				break;
			case 6:
				st.display();
				break;
			case 0:
				exit(1);
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
	}
return 0;
}
