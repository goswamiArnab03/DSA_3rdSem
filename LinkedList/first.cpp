//This is for singly linked list
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int value){
			data =value;
			next =NULL;
		}
};

class LinkedList{
	Node* head;
	public:
		LinkedList(){
			head=NULL;
		}
		
		void addBeg(int value){//1
			
			Node* temp=new Node(value);
			temp->next=head;
			head=temp;
			
		}
		void addEnd(int value){
			Node* temp=new Node(value);
			if(head==NULL){
				head=temp;
				return;
			}
			Node* current=head;
			while(current->next!=NULL){//2
				current=current->next;
			}
			current->next=temp;
		}
		void display(){//3
			if(!head){
				cout<<"Empty"<<endl;
				return;
			}
			Node* curr=head;
			while(curr!=NULL){
				cout<<curr->data<<"  ";
				curr=curr->next;
			}
			cout<<endl;
		}
		void delBeg(){//4
			Node* temp;
			temp=head;
			if(!head){
				cout<<"Empty"<<endl;
				return;
			}
			head=head->next;
			delete temp;
			cout<<"Deleted from Begining"<<endl;
			
		}
		void delEnd(){//5
			if(head==NULL){
				cout<<"Empty"<<endl;
				return;
			}
			if(head->next==NULL){//head->next means there is only one node present
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
			cout<<"Deleted from End"<<endl;
		}
		int search(int item){//6
			if(head==NULL){
				//cout<<"Empty"<<endl;
				return 0;
			}
			Node* temp=head;
			while(temp!=NULL){
				if(temp->data==item){
					return 1;
				}
				temp=temp->next;
			}
				return 0;
			
		}
		void bubblesort(){//7
		if(head==NULL){
			cout<<"Empty"<<endl;
			return;
		}
			int swap;
			Node* curr;
			Node* last=NULL;
			do{
				curr=head;
				swap=0;
				while(curr->next!=last){
					if(curr->data > curr->next->data){
						int temp=curr->data;
						curr->data=curr->next->data;
						curr->next->data=temp;
						swap=1;
					}
					curr=curr->next;
				}
				last=curr;
			}while(swap);
		}
		void reverse(){
			Node *p=head,*q,*r=NULL;
			while(p){
				q=p;
				p=p->next;
				q->next=r;
				r=q;
			}
			head=q;
		}
		void deleteItem(int item){
			if(head==NULL){
				cout<<"Empty"<<endl;
				return;
			}
			if(head->data==item){
				Node* temp=head;
				head=head->next;
				delete temp;
				return;
			}
			Node* curr=head;
			while(curr->next!=NULL && curr->next->data!=item){
				curr=curr->next;
			}
			if(curr->next!=NULL){
				Node* temp=curr->next;
				curr->next=curr->next->next;
				delete temp;
			}
			else{
				cout<<"Item not found"<<endl;
			}
		}
		
};

int main(){
	LinkedList li;
	Node* head=NULL;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for add Begining"<<endl;
	cout<<"Enter 2 for add End"<<endl;
	cout<<"Enter 3 for display"<<endl;
	cout<<"Enter 4 for delete begining"<<endl;
	cout<<"Enter 5 for delete end"<<endl;
	cout<<"Enter 6 for search"<<endl;
	cout<<"Enter 7 for sort"<<endl;
	cout<<"Enter 8 for reverse"<<endl;
	cout<<"Enter 9 for delete any item"<<endl;
	while(1){
		cout<<"Enter your queary";
		int p;
		cin>>p;
		switch(p){
			case 1:
				cout<<"Element";
				int data;
				cin>>data;
				li.addBeg(data);
				break;
			case 2:
				cout<<"Element";
				int data1;
				cin>>data1;
				li.addEnd(data1);
				break;
			case 3:
				li.display();
				break;
			case 4:
				li.delBeg();
				break;
			case 5:
				li.delEnd();
				break;
			case 6:
				int item;
				cout<<"Enter item to search";
				cin>>item;
				if(li.search(item)){
					cout<<"Found"<<endl;
				}
				else{
					cout<<"Not Found"<<endl;
				}
				break;
			case 7:
				li.bubblesort();
				break;
			case 8:
				li.reverse();
				break;
			case 9:
				int a;
				cout<<"enter your item: ";
				cin>>a;
				li.deleteItem(a);
				break;
			
			case 0:
				exit(0);
		}
	}
return 0;
}
