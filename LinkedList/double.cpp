#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		Node(int value){
			data=value;
			prev=NULL;
			next=NULL;
		}
};

class DLL{
	Node* head;
	//Node* next;
	public:
		DLL(){
			head=NULL;
		}	
		void addEnd(int data){
			Node* curr=new Node(data);
			Node* temp=head;
			if(head==NULL){
				curr->prev=NULL;
				head=curr;
				return;
			}
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=curr;
			curr->prev=temp;
		
		
		}
		void display(){
			if(!head){
				cout<<"Empty"<<endl;
				return;
			}
			Node* temp=head;
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
		void addBeg(int data){
			Node* curr=new Node(data);
			curr->next=head;
			if(head){
				head->prev=curr;
			}
			head=curr;
		}
		/*void deleteItem(int item){
			if(!head){
				cout<<"Empty"<<endl;
				return;
			}
			if(head->data==item){
				Node* temp=head;
				head
			}
		}*/
		void delBeg(){
			if(!head){
				cout<<"Empty"<<endl;
				return;
			}
			Node* temp;
			temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
		void delEnd(){
			if(!head){
				cout<<"Empty"<<endl;
				return;
			}
			if(head->next==NULL){
				delete head;
				head=NULL;
				return;
			}
			Node* temp;
			temp=head;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
		}
};

int main(){
	DLL li;
	Node* head=NULL;
	//Node* prev=NULL;
	/*li.addEnd(5);
	li.addEnd(6);
	li.addEnd(7);*/
	li.addBeg(5);
	li.addBeg(6);
	li.addBeg(7);
	li.display();
	li.delBeg();
	li.display();
	li.delEnd();
	li.display();
}
