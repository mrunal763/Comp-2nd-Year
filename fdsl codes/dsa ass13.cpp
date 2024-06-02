#include<iostream>
#include<cstdlib>
using namespace std;
class Pizza{
	int q[5], f, itemno, r;
 	public:
		Pizza(){
 			f=r=-1;
 		}
		void recieve();
		void deliver();
		void display();
};
void Pizza::recieve()
{ 
 	cout<<"\nEnter order to be recieved: ";
 		cin>>itemno;
 	if(((f==0)&&(r==4))||(f==r+1))
	{
 		cout<<"\n\nOverflow\n";
 	}
	else{
 		if(r==-1) 
		{
 			r=f=0; 
 		}
 		else if(r==4) 
		{
 			r=0; 
 		}
 		else{
 			r=r+1; 
 		}	 
 		q[r]=itemno; 
		cout<<"Order Recieved\n";
 	}
}
void Pizza:: deliver()
{
	if((f==-1)&&(r==0)) 
		cout<<"\nUnderflow\n";
	else{
		cout<<"Order No. "<<q[f]<<" Delivered\n";
		if(f==4) 
			f=-1; 
		else if(f==r) 
			f=r=-1; 
		else
			f=f+1;
	}
}
void Pizza:: display(){
	if(f==-1)
		cout<<"No Orders\n";
	else{
		if(r>=f){
			cout<<"\nOrders are:\n";
			for(int i=f;i<=r;i++)
				cout<<q[i]<<"\n";
		}	
		else{
			cout<<"\nOrders are:\n";
			for(int i=f;i<=4;i++)
				cout<<q[i]<<"\n";
			for(int j=0;j<=r;j++)
				cout<<q[j]<<"\n";
		}
	}
}
int main(){
	int n,i, no;
	Pizza p;
	do{
		cout<<"\nPress:\n1.Recieve an order\n2.Deliever an order\n3.Display Order Queue\n4.EXIT\n";
		cin>>no;
		switch(no){
			case 1:p.recieve();
			break;
			case 2:p.deliver();
			break;
			case 3:p.display();
			break;
			case 4:cout<<"\nEXITING....\n";
				exit(1);
			break;
			default:cout<<"\nINVALID CHOICE!!!!";
		}
	}while(1);
	return 0;
}

