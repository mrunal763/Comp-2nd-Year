#include<iostream>
using namespace std;
struct node{
	int prn;
	char name[20];
	struct node *next;
};
class Pinnacle{
	public:struct node *start;
	Pinnacle(){
		start=NULL;
	}
	void insert();
	void del();
	void display();
	int total();
	void reverse(struct node*);
	void concat(Pinnacle);
};
void Pinnacle:: insert(){
	cout<<"Press:\n1.to insert in beginning\n2.to insert in end\n3.toinsert in middle\n";
	int ch;
	cin>>ch;
	struct node *temp;		
	temp=new node[sizeof(node)];
	struct node *ptr=start;
	switch(ch){
	case 1:cout<<"Enter name of president:\n";
		cin>>temp->name;
		cout<<"Enter PRN of President:\n";
		cin>>temp->prn;
		if(start==NULL)
		start=temp;
		else{
		temp->next=start;
		start=temp;
		}
		break;
	case 2:cout<<"Enter name of secretarty:\n";
		cin>>temp->name;
		cout<<"Enter PRN of secretary:\n";
		cin>>temp->prn;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=temp;
		temp->next=NULL;
		break;
	case 3:cout<<"Enter name of Member:\n";
		cin>>temp->name;
		cout<<"Enter PRN of Member:\n";
		cin>>temp->prn;
		temp->next=start->next;
		start->next=temp;
		break;
		default:cout<<"Wrong input\n";
	}
}
void Pinnacle:: del(){
	struct node *ptr=start;
	struct node *temp;
	if(start==NULL)
		cout<<"Empty list";
	else{
		cout<<"Enter the PRN no. of the member whose entry is to be deleted:\n";
		int k;
		cin>>k;
		while(ptr!=NULL){
			if(ptr->prn==k){
				if(ptr==start)
						start=ptr;
				else if(ptr->next==NULL)
						temp->next=NULL;						
				else
					temp->next=ptr->next;
				cout<<"Entry succesfully deleted.\n";
				temp=ptr;
				ptr=ptr->next;
			}
		}
	}
}
int Pinnacle:: total(){
	int k=0;
	struct node* ptr=start;
	while(ptr!=NULL){
		k++;
		ptr=ptr->next;
	}
	return k;
}
void Pinnacle:: concat(Pinnacle q){
	struct node* ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=q.start;
}
void Pinnacle:: display(){
	struct node *ptr=start;
	cout<<"The Details of Students are:\n";
	int k=1;
	while(ptr!=NULL){
		cout<<k<<".Name:"<<ptr->name<<"\n PNR: "<<ptr->prn<<"\n";
		k++;
		ptr=ptr->next;
	}
}
int main(){
	Pinnacle p,q;
	char in='y';
	while(in=='y'||in=='Y'){
		cout<<"Press\n1)Add and delete the members as well as president or even secretary.\n2)Compute total number of members of club\n";
		cout<<"3)Display members\n4)Two linked lists exists for two divisions.Concatenate two lists\n";
		int ch;
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"Press\n1.to insert\n2.to delete\n";
			int k,m;
			cin>>k;
			switch(k){
				case 1:cout<<"Enter no. of data to be entered:\n";
				cin>>m;
				for(int i=1;i<=m;i++)
					p.insert();
				break;
			case 2:p.del();
				break;
			default:cout<<"Wrong input.";
			}
		break;
		case 2:cout<<"Total number of entries are:"<<p.total()<<"\n";
			break;
		case 3:p.display();
			break;
		case 4:cout<<"Enter no. of entries in second list:\n";
			int f;
			cin>>f;
			for(int i=1;i<=f;i++)
				q.insert();
				p.concat(q);
				cout<<"List sucessfully concatenated";
				break;
		default:cout<<"wrong input";
		}
		cout<<"\ndo you want to continue?(y/n)";
		cin>>in;
	}
	return 0;
}

