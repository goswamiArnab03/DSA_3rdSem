#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
	public:
		int coefficient;
		int exponent;
		Node* next;
		Node(int coef,int ex){
			coefficient=coef;
			exponent=ex;
			next=NULL;
		}
};
class Poly{
	Node* head;
	public:
		//Public constructor
		Poly(){
			head=NULL;	
		}//Copy constructor
		Poly(const Poly &p){
			head=NULL;
			Node* temp=p.head;
			while(temp){
				insert(temp->coefficient,temp->exponent);
				temp=temp->next;
				
			}
		}
		//Destructor
		~Poly(){
			Node* curr=head;
			while(curr){
				Node* temp=curr;
				curr=curr->next;
				delete temp;
			}
			
		}
		void insert(int coeff,int exp){
			Node* curr=new Node(coeff,exp);
			if(!head){
				head=curr;
				return;
			}
			Node* temp=head;
			while(temp->next){
				temp=temp->next;
			}
			temp->next=curr;
			return;
		}
		//operator overloading =
		Poly operator=(const Poly &p){
			Node* temp=p.head;
			while(temp){
				insert(temp->coefficient,temp->exponent);
				temp=temp->next;
			}
			return(*this);
		}
		//operator overloading +
		Poly operator+(const Poly &p){
			Poly result;
			Node* p1=head;
			Node* p2=p.head;
			while(p1 && p2){
				if(p1->exponent==p2->exponent){
					result.insert(p1->coefficient+p2->coefficient,p1->exponent);
					p1=p1->next;
					p2=p2->next;
				}
				else if(p1->exponent>p2->exponent){
					result.insert(p1->coefficient,p1->exponent);
					p1=p1->next;
				}
				else{
					result.insert(p2->coefficient,p2->exponent);
					p2=p2->next;
				}
			}
			while(p1){
				result.insert(p1->coefficient,p1->exponent);
				p1=p1->next;
			}
			while(p2){
				result.insert(p2->coefficient,p2->exponent);
				p2=p2->next;
			}
			
			return result;
		}
		
		void display(){
			Node* curr=head;
			while(curr){
				if(curr->exponent==0)cout<<curr->coefficient;
				else{
					cout<<curr->coefficient<<"x^"<<curr->exponent;
				}
					curr=curr->next;	
				
					if(curr){
						if(curr->coefficient>0){
							cout<<"+";
						}
					}
				
			}
			cout<<endl;
		}
		
};

int main(){
	Poly p1,p2,p3;
	p1.insert(2,3);
	p1.insert(5,1);
	p1.insert(1,0);
	cout<<"The first polynomial is";
	p1.display();
	p2.insert(5,3);
	p2.insert(3,2);
	p2.insert(3,0);
	cout<<"The second polynomial is";
	p2.display();
	p3=p1+p2;
	cout<<"The result polynomial is";
	p3.display();
	return 0;
	
}
