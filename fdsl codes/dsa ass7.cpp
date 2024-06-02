#include<iostream>
using namespace std;
class Stack{
	public:
		const static int size=100;
		char array[size];
		int top=-1;
		
		void push(char x){
			if(top == size-1){
				cout<<"Stack Overflow!!";
				return;
		}
			array[++top]=x;
		}
		char pop(){
			if(top == -1){
				cout<<"Stack is empty!" ;
					return -1;
			}
			return array[top--];
		}
		
		void display(){
			if (top == -1){
				cout<<"Stack is Empty";
			}
			cout<<"Stack contains:";
			for(int i=0;i<=top;i++){
				cout<<array[i]<<" ";
			}
		}
};
int main(){
	Stack s;
	string user_input;
	cout<<"Enter a string:";
	getline(cin,user_input);
	
	string org_str ="";
	
	for(int i=0;i<user_input.size();i++){
		char ch = user_input[i];
		
		if(ch >='a' and ch<='z'){
			ch=(char)(ch - 'a' + 'A');
		}	
		if(ch>='A' and ch<='Z'){
		s.push(ch);
		org_str.push_back(ch);
		}
	}
	
	cout<<"\nOriginal string:"<<org_str<<endl;

	string rev_str ="";
	while(s.top != -1){
		rev_str.push_back(s.pop());
	}
	cout<<"Reversed string:"<<rev_str<<endl;
	if(org_str == rev_str){
		cout<<user_input<<" is a palindrome."<<endl;
	}else{  
        cout<<user_input<<" is not palindrome."<<endl;
    }	
}




















