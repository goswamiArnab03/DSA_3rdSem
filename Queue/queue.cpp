//Queue practice
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define MAX 100
using namespace std;

class Queue{
	int a[MAX],front=-1,rear=-1;
	public:
		int is_full(){//1
			return (rear==MAX-1);
		}
		int is_empty(){//2
			return (front==rear);
		}
		void en_queue(){//we have to insert 1 value at a time in quene
			if(rear==MAX-1){
				cout<<"The queue is full"<<endl;//3
				return;
			}
			int item;
			cin>>item;
			a[++rear]=item;
		}
		void de_quene(){//4
			if(rear==front){
				cout<<"The queue is empty"<<endl;
				return;
			}
			front++;
			cout<<"The element deleted successfully"<<endl;
		}
		void display(){//5
			if(rear==front){
				cout<<"The queue is empty"<<endl;
				return;
			}
			cout<<"The elements currently available in Queue is ";
			for(int i=front+1;i<=rear;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;

		}
};

int main(){
	Queue q;
	cout<<"Enter 0 to exit"<<endl;
	cout<<"Enter 1 to see if the queue is full or not"<<endl;
	cout<<"Enter 2 to see if the queue is empty or not"<<endl;
	cout<<"Enter 3 to store an element in queue"<<endl;
	cout<<"Enter 4 to delete an element in Queue"<<endl;
	//cout<<"Enter 5 to check last an element in stack"<<endl;
	cout<<"Enter 5 to see full Queue"<<endl;
	while(1){
		int p;
		cout<<"Enter your no according to your quary: ";
		cin>>p;
		switch(p){
			case 1:
				if(q.is_full()){
					cout<<"Queue is full"<<endl;
				}
				else{
					cout<<"We have space,Not full yet"<<endl;
				}
				break;
			case 2:
				if(q.is_empty()){
					cout<<"Queue is Empty"<<endl;
				}
				else{
					cout<<"Queue is Not Empty yet"<<endl;
				}
				break;
			case 3:
				q.en_queue();
				break;
			case 4:
				q.de_quene();
				break;
			/*case 5:
				st.peek();
				break;*/
			case 5:
				q.display();
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
