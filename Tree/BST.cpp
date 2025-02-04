#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
	public:
		int data;
		Node* lchild;
		Node* rchild;
		Node(int value){
			data=value;
			lchild=NULL;
			rchild=NULL;
		}
		
};

class BST{
	Node* root;
	public:
		BST(){
			root=NULL;
		}
		Node* getRoot(){
			return root;
		}
		void insert(int value){// insert function works perfectly
			Node* curr=new Node(value);
			if(!root){
				root=curr;
				return;
			}
			else{
			
			Node* temp=root;
			Node* parent=NULL;
			while(temp!=NULL){
				parent=temp;
				if(value<temp->data){
					temp=temp->lchild;
					//cout<<"Entered 1"<<endl;
				}
				else if(value>temp->data){
					temp=temp->rchild;
					//cout<<"Entered 2"<<endl;
				}
				/*else{
					cout<<"Repeated data";
				}*/
			}
			if(value<parent->data){
				parent->lchild=curr;
				//cout<<"Entered 3"<<endl;
			}
			else{
				parent->rchild=curr;
				//cout<<"Entered 4"<<endl;
			}
			//cout<<"Entered"<<endl;
		}
			return;
		}
		void InOrder(Node* tree){//The function sucks
			
			if(tree!=NULL){
				InOrder(tree->lchild);
				cout<<tree->data<<"\t";
				InOrder(tree->rchild);
			}
		
		}
		void PreOrder(Node* tree){
			if(tree!=NULL){
				cout<<tree->data<<"\t";
				PreOrder(tree->lchild);
				PreOrder(tree->rchild);
			}
		}
		void PostOrder(Node* tree){
			if(tree!=NULL){
				PostOrder(tree->lchild);
				PostOrder(tree->rchild);
				cout<<tree->data<<"\t";
			}
		}
		bool search(int key){// search function works perfectly
			if(!root){
				return false;
			}
			Node* temp=root;
			while(temp){
				if(temp->data==key){
					//cout<<"Search 0"<<endl;
					return true;
				}
				else if(temp->data<key){
					temp=temp->rchild;
					//cout<<"Search 1"<<endl;
				}
				else{
					temp=temp->lchild;
					//cout<<"Search 2"<<endl;
				}
			}
			//cout<<"Search"<<endl;
			return false;
		}
		int totalNodes(Node* tree){
			if(!tree)return 0;
			else
				return(totalNodes(tree->lchild)+totalNodes(tree->rchild)+1);
		}
		int totalExternalnodes(Node* tree){
			if(!tree)return 0;
			else if(tree->lchild==NULL && tree->rchild==NULL)return 1;
			else
				return(totalExternalnodes(tree->lchild)+totalExternalnodes(tree->rchild));
		}
		int totalInternalnodes(Node* tree){
			if(!tree)return 0;
			else if(tree->lchild==NULL && tree->rchild==NULL)return 0;
			else
				return(totalInternalnodes(tree->lchild)+totalInternalnodes(tree->rchild)+1);
		}
		int Height(Node* tree){
			int lheight,rheight;
			if(!tree)return 0;
			else{
				lheight=Height(tree->lchild);
				rheight=Height(tree->rchild);
				if(lheight>rheight)return(lheight+1);
				else return(rheight+1);
			}
		}
		void remove(int key){
			if(!root){
				cout<<"Empty"<<endl;
				return;
			}
			Node* x=root;
			Node* parent=NULL;
			while(x!=NULL && x->data!=key){
				parent=x;
				if(x->data<key)x=x->rchild;
				else x=x->lchild;
			}
			if(!x){
				cout<<"The data is not present"<<endl;
				return;
			}
			if(x->lchild==NULL || x->rchild==NULL){
				Node* ptr;
				if(x->lchild==NULL)ptr=x->rchild;
				else ptr=x->lchild;
				if(!parent){
					delete root;
					root=ptr;
					return;
				}
				else{
					if(x==parent->lchild)parent->lchild=ptr;
					else parent->rchild=ptr;
					delete x;
					return;
				}
			}
			Node* succ=x->rchild;
			Node* psucc=NULL;
			while(succ->lchild){
				psucc=succ;
				succ=succ->lchild;
			}
			x->data=succ->data;
			if(!psucc) x->rchild=succ->rchild;
			else{
				psucc->lchild=succ->rchild;
				delete succ;
				return;
			}
		}
};

int main(){
	BST bt;
	Node *r;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for insert"<<endl;
	cout<<"Enter 2 for Inorder traversal"<<endl;
	cout<<"Enter 3 for Preorder traversal"<<endl;
	cout<<"Enter 4 for Postorder traversal"<<endl;
	cout<<"Enter 5 for search"<<endl;
	cout<<"Enter 6 for Total nodes"<<endl;
	cout<<"Enter 7 for Total internal nodes"<<endl;
	cout<<"Enter 8 for Total external nodes"<<endl;
	cout<<"Enter 9 for Height"<<endl;
	cout<<"Enter 10 for Delete an item"<<endl;
	while(1){
		cout<<"Enter your queary";
		int p;
		int key;
		cin>>p;
		switch(p){
			case 1:
				cout<<"Element";
				int data;
				cin>>data;
				bt.insert(data);
				break;
			case 2:
				r=bt.getRoot();
				bt.InOrder(r);
				cout<<endl;
				break;
			case 3:
				bt.PreOrder(bt.getRoot());
				cout<<endl;
				break;
			case 4:
				bt.PostOrder(bt.getRoot());
				cout<<endl;
				break;
			case 5:
				int item;
				cout<<"Enter item to search";
				cin>>item;
				if(bt.search(item)){
					cout<<"Found"<<endl;
				}
				else{
					cout<<"Not Found"<<endl;
				}
				break;
			case 6:
				cout<<"The total nodes are "<<bt.totalNodes(bt.getRoot());
				cout<<endl;
				break;
			case 7:
				cout<<"The total internal nodes are "<<bt.totalInternalnodes(bt.getRoot());
				cout<<endl;
				break;
			case 8:
				cout<<"The  total external nodes are "<<bt.totalExternalnodes(bt.getRoot());
				cout<<endl;
				break;
			case 9:
				cout<<"The  Height is "<<bt.Height(bt.getRoot());
				cout<<endl;
				break;
			case 10:
				cout<<"Element to delete ";
				cin>>key;
				bt.remove(key);
				break;
			case 0:
				exit(0);
		}
	}
	return 0;
}
