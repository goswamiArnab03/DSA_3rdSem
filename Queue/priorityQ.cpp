#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		int priority;
		Node* next;
		Node(int value,int p){
			data=value;
			priority=p;
			next=NULL;
		}
};

class PriorityQ{
	Node* front;
	public:
		PriorityQ(){
			front=NULL;
		}
		void insert(int value,int p){
			Node* curr=new Node(value,p);
			if(front==NULL || p<front->priority){
				curr->next=front;
				front=curr;
				return;
			}
			Node* temp=front;
			while(temp->next!=NULL && temp->priority<=p){
				temp=temp->next;
			}
			curr->next=temp->next;
			temp->next=curr;
		}
		void display(){
			if(!front){
				cout<<"Empty"<<endl;
				return;
			}
			Node* temp=front;
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		void remove(){
			if(!front){
				cout<<"Empty"<<endl;
				return;
			}
			Node* temp=front;
			front=front->next;
			delete temp;
			return;
		}
		bool isEmpty(){
			return front==NULL;
		}
	
};

int main(){
	PriorityQ pq;
	pq.insert(5,2);
	pq.insert(6,3);
	pq.insert(7,4);
	pq.insert(8,1);
	pq.display();
	pq.remove();
	pq.display();
	return 0;
}
