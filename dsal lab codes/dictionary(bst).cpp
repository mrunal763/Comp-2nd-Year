#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Node
{
		public:
			char word[50],meaning[100];
			Node *left;
			Node *right;
};
class BST
{
		public:
			Node* root;
			Node* create(char w[],char m[])
			{
					Node* temp=new Node();
					strcpy(temp->word,w);
					strcpy(temp->meaning,m);
					temp->left=temp->right=NULL;
					return temp;
			}
			void insert(char w[],char m[],Node *root)
			{
					Node* temp=new Node;
					temp=create(w,m);
					if(strcmp(temp->word,root->word)<0)
					{
						if(root->left==NULL)
						{
							root->left=temp;
						}
						else
						{
							insert(w,m,root->left);
						}	
					}
					else
					{
						if(root->right==NULL)
						{
							root->right=temp;
						}
						else
						{
							insert(w,m,root->right);	
						}
					}
			}
			void inorder(Node *root)
			{
				if(root==NULL)
					return;
				inorder(root->left);
				cout<<root->word<<" "<<root->meaning<<endl;
				inorder(root->right);
			}
			void mirror_BST(Node* root)
			{
				Node* temp;
				if(root==NULL){
					return;
				}
				temp=root->left;
				root->left=root->right;
				root->right=temp;
				mirror_BST(root->left);
				mirror_BST(root->right);
			}
			void in_rev(Node* root)
			{
				mirror_BST(root);
				inorder(root);
				mirror_BST(root);
			}
			void search(Node *root,char key[],int &counter)
			{
				counter++;
				if(root!=NULL)
				{
					if(strcmp(root->word,key)==0)
					{
						cout<<"\nSearch Successful\n";
						cout<<"\nWoord:"<<root->word;
						cout<<"\nMeaning:"<<root->meaning;
					}
					else if(strcmp(root->word,key)!=0)
					{
						if(strcmp(root->word,key)<0)
						{
							search(root->right,key,counter);
						}
						else if(strcmp(root->word,key)>0)
						{
							search(root->left,key,counter);
						}
					}	
				}
				else
				{
					cout<<"Word Not Found"<<endl;
				}
			}
			void modify(Node *root,char key[])
			{
				if(root!=NULL)
				{
					if(strcmp(root->word,key)==0)
					{
						cout<<"\nWord Found\n";
						cout<<"\nEnter new Meaning for the Word:";
						cin>>root->meaning;
						cout<<endl;
					}
					else if(strcmp(root->word,key)!=0)
					{
						if(strcmp(root->word,key)>0)
						{
							modify(root->left,key);
						}
						else if(strcmp(root->word,key)<0)
						{
							modify(root->right,key);
						}
					}
				}
				else
				{
					cout<<"Word not Found"<<endl;
				}
			}
			Node* helper(Node* root)
			{
				if(root->left==NULL)
				{
					return root->right;
				}
				else if(root->right==NULL)
				{
					return root->left;
				}
				Node* rightChild=root->right;
				Node* lastRight=findLastRight(root->left);
				lastRight->right=rightChild;
				return root->left;
			}
			Node* findLastRight(Node* root)
			{
				if(root->right==NULL)
				{
					return root;
				}
				return findLastRight(root->right);
			}
			Node* delete_Node(Node* root,char key[])
			{
				if(root==NULL)
				{
					return NULL;
				}
				if(strcmp(root->word,key)==0)
				{
					return helper(root);
				}
			
			Node *dummy=root;
			while((strcmp(root->word,key)!=0))
			{
				if(strcmp(root->word,key)>0)
				{
					if(root->left!=NULL && root->left->word==key)
					{
						root->left=helper(root->left);
						break;
					}
					else{
						root=root->left;
					}
				}
				else if(strcmp(root->word,key)<0)
				{
					if(root->right!=NULL && root->right->word==key)
					{
						root->right=helper(root->right);
						break;
					}
					else{
						root=root->right;
					}
				}
			}
			return dummy;
		}			
};
int main()
{
	int choice;
	int flag=0;
	int swaps=0;
	char w[50],m[100];
	BST t;
	Node* root;
	do{
		cout<<"1.Insert a node"<<endl;
		cout<<"2.Display BST(Asending Order)"<<endl;
		cout<<"3.Display BST(Desending Order)"<<endl;
		cout<<"4.Search a Node in BST"<<endl;
		cout<<"5.Modify Meaning of a word"<<endl;
		cout<<"6.Delete a Record"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"\nEnter your Choice:-"<<endl;
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				char ind;
				do{
					cout<<"Enter a Word-";
					cin>>w;
					cout<<"Enter a meaning-";
					cin>>m;
					if(flag==0)
					{
						root=t.create(w,m);
						flag=1;
					}
					else{
						t.insert(w,m,root);
					}
					cout<<"Do you want to continue:-(y/n)";
					cin>>ind;
					}while(ind=='y' or ind=='Y');
					break;
			case 2:
				cout<<endl<<"The BST in Asending Order"<<endl;
				t.inorder(root);
				cout<<endl<<endl;
			break;
			case 3:
				cout<<endl<<"The BST in Desending Order"<<endl;
				t.in_rev(root);
				cout<<endl<<endl;
			break;
			case 4:
				cout<<"Enter the Word you want to search:-";
				char sr_key[1000];
				cin>>sr_key;
				cout<<endl;
				t.search(root,sr_key,swaps);
				cout<<endl<<"Number of comparisons done are:-"<<swaps<<endl;
				cout<<endl;
				swaps=0;
			break;
			case 5:
				cout<<"Enter the word you want to modify:-";
				char c[100];
				cin>>c;
				t.modify(root,c);
				cout<<endl;
			break;
			case 6:
				char temp[50];
				cout<<"Enter a Word that you want to Delete:-";
				cin>>temp;
				root=t.delete_Node(root,temp);
				cout<<endl<<"Deleting a Node went Successful"<<endl;
				cout<<endl;
			break;	
 		}
	}while(choice<=6);
	cout<<"Performed all the Operations Successfully"<<endl;
	return 0;
}
















