#include<iostream>
using namespace std;
class Node
{
	public:
		int key;
		Node *ln,*rn;
};

class Tree
{
	public:
		Node*root;
		Node *createTree(int key)
		{
			root=new Node();
			root->key=key;
			root->ln=NULL;
			root->rn=NULL;
			return root;
		}
		
		void insertNode(int key,Node*root)
		{
			Node *node=new Node();
			node->key=key;
			if(root->key>key){
				if(root->ln==NULL)
				{
					root->ln=node;
				}
				else{
					insertNode(key,root->ln);
				}
			}
			else if(root->key<key)
			{
				if(root->rn==NULL){
					root->rn=node;
				}
				else{
					insertNode(key,root->rn);
				}
			}
			else{
				cout<<"No Duplicate Keys are allowed!!";
			}
		}
		
		void display(Node *root)
		{
			if(root!=NULL)
			{
				display(root->ln);
				cout<<root->key<<"\n";
				display(root->rn);
			}
		}
		
		void searchNode(int searchkey,Node *root){
			if(root->key==searchkey){
				cout<<"Node Found!!";
			}
			else if(root->key>searchkey){
				if(root->ln==NULL){
				cout<<"Key is not Present in the Tree!!";
				}
				else{
					searchNode(searchkey,root->ln);
				}
			}
			else if(root->key<searchkey){
				if(root->rn==NULL){
					cout<<"Key is not Present in the Tree!!";
				}
				else{
					searchNode(searchkey,root->rn);
				}
			}
			else{
				cout<<"No Tree Present!!";
			}
		}
		
		int longestPath(Node *root)
		{
			if(root==NULL){
				return 0;
			}
			int Lstree=longestPath(root->ln);
			int Rstree=longestPath(root->rn);
			if(Lstree>Rstree){
				return (Lstree+1);
			}
			else{
				return (Rstree+1);
			}
		}
		
		void displayMin(Node *root)
		{
			while(root->ln!=NULL){
				root=root->ln;
			}
			cout<<"Minimum data value present in the tree is:"<<root->key;
		}
		
		Node *swapNodes(Node *root){
			Node *temp;
			if(root==NULL){
				return NULL;
			}
			temp=root->ln;
			root->ln=root->rn;
			root->rn=temp;
			swapNodes(root->ln);
			swapNodes(root->rn);
		}
};

int main()
{
	int choice,order,flag=0;
	int key,searchkey;
	Tree t1;
	Node *root;
	do{
		cout<<"\n---------MENU------";
		cout<<"\n1.Enter a number(New node value)";
		cout<<"\n2.Display Tree(Inorder Traversal)";
		cout<<"\n3.Display Minimum Data Value in the Tree";
		cout<<"\n4.Display no. nodes in longest path";
		cout<<"\n5.Swap left and right nodes";
		cout<<"\n6.Search for Value in Tree";
		cout<<"\n7.Exit";
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\n\nEnter the number:";
				cin>>key;
				if(flag==0){
					root=t1.createTree(key);
					flag=1;
				}
				else{
					t1.insertNode(key,root);
				}
				cout<<"\nNode inserted into the Tree!";
				break;
			case 2:
				t1.display(root);
				break;
			case 3:
				t1.displayMin(root);
				break;
			case 4:
				cout<<"\n\nThe number of nodes in the longest path is:"<<t1.longestPath(root);
				break;
			case 5:
				t1.swapNodes(root);
				cout<<"\n\nSwapped!! The new list is:";
				t1.display(root);
				break;
			case 6:
				cout<<"\n\nEnter the value to be searched:";
				cin>>searchkey;
				t1.searchNode(searchkey,root);
				break;
			case 7:
				exit(0);
		}
	}
	while(choice!=7);
	return 0;
}

