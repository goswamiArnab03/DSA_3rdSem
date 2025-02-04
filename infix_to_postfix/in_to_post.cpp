#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 100
using namespace std;
class Stack{
	char items[MAX];
	int top=-1;
	public:
		void pop(){//4
			top--;
		}
		void push(char y){//3
			top=top+1;
			items[top]=y;
			//cout<<"Item entered successfully"<<endl;
		}
		char peek(){
			return items[top];
		}
		int isEmpty(){
			if(top==-1){//2
				return 1;
			}
			return 0;
		}
};

int presidance(char x){
	if(x=='^')
		return 3;
	if (x=='*' || x=='/')
		return 2;
	if (x=='+' || x=='-')
		return 1;
	
	return -1;
}

int isOperand(char x){
	return ((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9'));
}

string infixtopostfix(string s){
	int i;
	string output;
	Stack st;
	while(s[i]!='\0'){
		if(isOperand(s[i])){
			output += s[i];
			i++;
		}
		else if (s[i]=='('){
			st.push(s[i]);
			i++;
		}
		else if (s[i]==')'){
			while(st.peek()!='('){
				output += st.peek();
				st.pop();
			}
			st.pop();
			i++;
		}
		else{
			while ((!st.isEmpty()) && (st.peek()!='(' )&&( presidance(s[i])<=presidance(st.peek()))){
				output += st.peek();
				st.pop();
			}
			st.push(s[i]);
			i++;
		}
		
		
	}
	//int j=i;
	while (!(st.isEmpty())){
		output +=st.peek();
		st.pop();
	}
	return output;
}

int main(){
	string input;
	cout<<"Enter your string: ";
	cin>>input;
	string str=infixtopostfix(input);
	cout<<"The final expression is: "<<str<<endl;
	
	
	
return 0;
}
