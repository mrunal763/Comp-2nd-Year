#include<iostream>
using namespace std;
class Graph
{
	public:
		int mat[10][10];
		string vertex[10];	
    	int n,m,c;
		int stack[10];
		int E;

	Graph()
	{
		for (int i=0;i<10;i++)
		{
			for (int j=0;j<10;j++)
			{
				mat[i][j]=0;
			}
		}
	}

	void create()
	{
		cout<<"Enter no of Nodes in Graph:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter the name of node "<<i+1<<" :";
			cin>>vertex[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j){
					mat[i][j]=0;
				}
				else if(mat[i][j]==0)
				{
					cout<<"Is there edge between vertex"<<vertex[i]<<"and vertex "<<vertex[j]<<"(If yes type 1 else 0)";
					cin>>mat[i][j];
					mat[j][i]=mat[i][j];
				}	
			}
		}
	}
	void Display_mat()
	{
		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			cout<<"\t"<<vertex[i];
		}
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<vertex[i];
			for(int j=0;j<n;j++)
			{
				cout<<"\t"<<mat[i][j];
			}
		}
	}
	void DFS()
	{
		int vis[n];
		int stack[2*n];
		int top=0;
		for(int i=0;i<n;i++)
		{
			vis[i]=0;
		}
		stack[top]=0;
		while(top!=-1)
		{
			int node=stack[top];
			top--;
			if(vis[node]==0)
			{
				cout<<vertex[node]<<" ";
				vis[node]=1;
				for(int i=0;i<n;i++)
				{
					if(mat[node][i]!=0)
					{
						top++;
						stack[top]=i;
					}
				}
			}
		}
		cout<<endl;
	}
	void BFS()
	{
		int vis[n];
		int queue[2*n];
		int front=0,rear=0;
		for(int i=0;i<n;i++)
		{
			vis[i]=0;
		}
		queue[rear]=0;
		vis[0]=1;
		rear++;
		while(front!=rear)
		{
			int size =rear+1;
			int node=queue[front];
			front++;
			cout<<vertex[node]<<" ";
			for(int i=0;i<n;i++){
				if(mat[node][i]==1 and vis[i]==0)
				{
					queue[rear]=i;
					rear++;
					vis[i]=1;
				}
			}	
		}	
		cout<<endl;
	}
};
int main()
{
	Graph g1;
	int ch;
	do
	{
		cout<<"\nMenu\n1.Create graph\n2.Display Adjacency Matrix\n3.DFS traversal\n4.BSF traversal\n";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g1.create();
				break;
			case 2:
				g1.Display_mat();
				break;
			case 3:
				g1.DFS();
				break;
			case 4:
				g1.BFS();
				break;
		}
	}while(ch!=5);
	return 0;
}
	


