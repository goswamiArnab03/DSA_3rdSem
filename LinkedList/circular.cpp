#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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

class CLL{
	Node* last;
	public:
		CLL(){
			last=NULL;
			
		}
		void addBeg(int data){
			Node* curr = new Node(data);
			if(!last){
				curr->next=curr;
				last=curr;
				cout<<"Inserted at Beg"<<endl;
				return;
			}
			curr->next=last->next;
			last->next=curr;
			cout<<"Inserted at Beg"<<endl;
		}
		
		void addEnd(int data){
			Node* curr = new Node(data);
			if(!last){
				curr->next=curr;
				last=curr;
				cout<<"Inserted at End"<<endl;
				return;
			}
			curr->next=last->next;
			last->next=curr;
			last=curr;
			cout<<"Inserted at End"<<endl;
		}
		
		void display(){
			if(!last){
				cout<<"Empty list"<<endl;
				return;
			}
			Node* temp=last->next;
			while(temp!=last){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<" "<<endl;
		}
		int search(int value){
			if(!last){
				//cout<<"Empty list"<<endl;
				return 0;
			}
			if(last->data==value){
				return 1;
			}
			Node* temp=last->next;
			while(temp!=last){
				if(temp->data==value){
					return 1;
				}
				temp=temp->next;
			}
			return 0;
		}
		void deleteItem(int item){
			if(!last){
				cout<<"Empty list"<<endl;
				return;
			}
			if(last->data==item){
				Node* temp=last;
				last=last->next;
				while(last->next!=temp){
					last=last->next;
				}
				last->next=temp->next;
				delete temp;
				cout<<"Deleted"<<endl;
				return;
			}
			if(last->next->data==item){
				Node* temp=last->next;
				last->next=temp->next;
				delete temp;
				cout<<"Deleted"<<endl;
				return;
			}
			Node* curr=last->next;
			while(curr->next!=last && curr->next->data!=item){
				curr=curr->next;
			}
			if(curr->next!=last){
				Node* temp=curr->next;
				curr->next=curr->next->next;
				delete temp;
				cout<<"Deleted"<<endl;
				return;
			}
			cout<<"Item not found"<<endl;
			
		}
};

int main(){
	CLL li;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for add Begining"<<endl;
	cout<<"Enter 2 for add End"<<endl;
	cout<<"Enter 3 for display"<<endl;
	cout<<"Enter 4 for search item"<<endl;
	cout<<"Enter 5 for delete item"<<endl;
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
			case 5:
				int x;
				cout<<"Enter item to delete";
				cin>>x;
				li.deleteItem(x);
				break;
			case 0:
				exit(0);
			default:
				cout<<"Invalid input"<<endl;
				break;
		}
	}
	return 0;


}
