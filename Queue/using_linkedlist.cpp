#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int value){
			data=value;
			next=NULL;
		}
};

class Queue{
	Node* front;
	Node* rear;
	public:
		Queue(){
			front=rear=NULL;
		}
		void enQ(int data){
			Node* newnode=new Node(data);
			if(!rear){
				rear=newnode;
				front=newnode;
				return;
			}
			rear->next=newnode;
			rear=newnode;
			return;
		}
		void deQ(){
			if(!front){
				cout<<"Empty Queue"<<endl;
				return;
			}
			Node* temp=front;
			front=front->next;
			delete(temp);
			if(!front){
				rear=NULL;
			}
			return;
		}
		void display(){
			if(!rear){
				cout<<"Empty Queue"<<endl;
				return;
			}
			Node* temp=front;
			while(temp!=rear){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
			return;
		}
	
};

int main(){
	Queue q;
	int p,key;
	cout<<"Enter 1 for insert a value"<<endl;
	cout<<"Enter 2 for delete a value"<<endl;
	cout<<"Enter 3 for display"<<endl;
	cout<<"Enter 0 for exit"<<endl;
	while(1){
		cout<<"Enter your choice ";
		cin>>p;
		switch(p){
			case 1:
				cout<<"Enter your value ";
				cin>>key;
				q.enQ(key);
				break;
			case 2:
				q.deQ();
				break;
			case 3:
				q.display();
				break;
			case 0:
				exit(0);
			default:
				cout<<"Invalid Input";
				break;
		}
	}
	return 0;
}
