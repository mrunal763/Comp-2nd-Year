#include<iostream>
using namespace std;
struct node{
    char name[20];
    int count ;
    struct node *child[10];
}*root;
class tree
    {
    public:
      tree()
      {
        root=NULL;
      }
      void create()
      {
        root=new node();
        cout<<"\nEnter the name of book:";
        cin>>root->name;
        cout<<"Enter the no of chapters:";
        cin>>root->count;
        for(int i=0;i<root->count;i++)
        {
            root->child[i]=new node();
            cout<<"Enter the name of chapter:";
            cin>>root->child[i]->name;
            cout<<"Enter the no of sections:";
            cin>>root->child[i]->count;
            for(int j=0;j<root->child[i]->count;j++)
            {
                root->child[i]->child[j]=new node();
                cout<<"\nEnter the name of sections:";
                cin>>root->child[i]->child[j]->name;
                cout<<"Enter the number of subsections:";
                cin>>root->child[i]->child[j]->count;
                for(int k=0;k<root->child[i]->child[j]->count;k++)
                {
                     root->child[i]->child[j]->child[k]=new node();
                     cout<<"\nEnter the name of subsections:";
                     cin>>root->child[i]->child[j]->child[k]->name;
                }
            } 
        }
    }
    void display()
    {
        if(root!=NULL)
        {
            cout<<"\t-----INFORMATION OF BOOKS-----";
            cout<<"\n#Name of book: "<<root->name;
            for(int i=0;i<root->count;i++)
            {
                cout<<"\n\tName of chapters "<<i+1<<":"<<root->child[i]->name;
                for(int j=0;j<root->child[i]->count;j++)
                {
                    cout<<"\n\t\tName of sections "<<j+1<<":"<<root->child[i]->child[j]->name;
                    for(int k=0;k<root->child[i]->child[j]->count;k++)
                    {
                        cout<<"\n\t\t\tName of subsection "<<k+1<<":"<<root->child[i]->child[j]->child[k]->name;
                    }
                }
            }
        }
    }
};
int main()
{
    tree t;
    int ch;
    do
    {
        cout<<"\t\t\tMENU"<<endl;
        cout<<"1.create\n2.display\n3.exit"<<endl;
        cout<<"\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.create();
                break;
            case 2:
                t.display();
                break;
            case 3:
            	cout<<"Thanks for using this program!!";
                exit(0);
            default:
            	cout<<"Wrong choice"<<endl;
        }
    }while(ch!=4);
    return 0;
}
