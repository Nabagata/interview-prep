/*
Flatten the Multi level list to a Singly Linked List:

Example :

Input : ML:       3 – 4 – 7 – 18 – 45 – 36

                      |     |                    |

                      8    5                 6

                      |                         |  

                      9                       2

 

 

 

Input ( cin >>) : 3 1 8 9 -1 4 1 5 -1 7 0 18 0 45 1 6 2 -1 36 0 -2 

 

( 1 – indication of down link,  0 – no down link

  -1 – termination of down LL ,  -2 termination of  ML

 

Output (cout <<) :  ( 3 8 9 ) ( 4 5 ) ( 7 ) (18 ) ( 45 6 2 ) ( 36 ) 
*/



#include <iostream>
#include <climits>
using namespace std;

class mlnode
{
public:
	int data;
	bool eod;
	mlnode* next;mlnode* dlink;
	mlnode()
	{
		data = INT_MIN;
		next = NULL;
		dlink = NULL;
		eod = false;
	}

};

int main()
{
	int a,drctn,k;

	mlnode* head = new mlnode();
	mlnode* tmp;
	mlnode* tmp_up;
	mlnode *prev;
	mlnode *tmp_cur_d;
	cin>>a;
	head->data = a;
	tmp = head;

	cin>>drctn; 

	
	if (drctn == 1)
	{
		tmp_up = tmp;
		while(true)
		{
			cin>>k;
			if (k==-1) 
				{
					tmp_cur_d->eod = true;	
					break;
				}
			tmp_cur_d = new mlnode();
			tmp_cur_d->data = k;
			tmp_up->dlink = tmp_cur_d;
			tmp_up = tmp_cur_d;
		}
	}

	prev = head;
	tmp = head;

	int lmp;

	while(true)
	{
		cin>>a;
		if (a == -2 ) break;
		cin>>drctn;
		tmp = new mlnode();
		tmp->data = a;
	
		prev->next = tmp;

		
		if (drctn == 1)
		{
			tmp_up = tmp;
			while(true)
			{
				cin>>k;

				if (k==-1) 
				{	
					tmp_cur_d->eod = true;	
					break;
				}

				tmp_cur_d = new mlnode();
				tmp_cur_d->data = k;
				tmp_up->dlink = tmp_cur_d;
				tmp_up = tmp_cur_d;
			}
		}
		else if (drctn==0) 
		{
			tmp->eod = true;
			prev = tmp;
			continue;
		}

		prev = tmp;
	}

	//cout<<"INPUT COMPLETE\n";

	tmp = head;

	while(tmp!=NULL)
	{
		if (tmp->next != NULL || tmp->dlink!=NULL){
			if (tmp->dlink!=NULL)
			{
				tmp_cur_d = tmp;
				while(tmp_cur_d->dlink!=NULL)
				{
					//cout<<tmp_cur_d->data<<"\n";
					tmp_cur_d = tmp_cur_d->dlink;
				}
				tmp_cur_d->next = tmp->next;
				tmp->next = NULL;
				tmp = tmp_cur_d->next;
			}
			else
			{
				
				tmp=tmp->next;
			}
		}
		else
			break;
	}

	//cout<<"Step 2 COMPLETE\n";
	//Now our converted linked list has either dlink or next != NULL; if both NULL it means we 
	//have reached tail of linked list
	tmp = head;
	cout<<"( ";
	while(tmp!=NULL)
	{

		if (tmp->next!=NULL)
		{
			cout<<tmp->data<<" ";
			if (tmp->eod) cout<<") (";
			tmp=tmp->next;
		}

		else if (tmp->dlink!=NULL)
		{
			cout<<tmp->data<<" ";
			if (tmp->eod) cout<<") (";
			tmp=tmp->dlink;
		}
		else if (tmp->next == NULL && tmp->dlink == NULL)
		{
			if (tmp->data>INT_MIN)
			{
				cout<<tmp->data<<" ) \n";
			}
			break;
		}
	}

	return 0;
}



