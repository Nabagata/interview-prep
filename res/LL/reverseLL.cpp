#include <iostream>

using namespace std;

class node
{
public:
	int dt;
	node* next = NULL;
};

void reverse(node* head,node* tmp,node* prev)
{
	if (tmp->next == NULL)
	{
		tmp->next = prev;
		return ;
	}

	reverse(head,tmp->next,tmp);
	tmp->next = prev;
}


int main()
{
	int n;//number of elements
	cin>>n;
	node* head = NULL;
	int a;cin>>a;
	head = new node();
	head->dt = a;
	node * tmp; node* prev = head;
	while(true)	
	{
		cin>>a;
		if (a==-1) break;
		else
		{
			tmp = new node();
			tmp->dt = a;
			prev->next = tmp;
			prev = tmp;
		}
	}


	node* tail =  tmp; //new head
	if (head->next==NULL)
	{
		cout<<head->dt;
	}
	else{
		reverse(head,head->next,head);
		head->next = NULL;

		node* tmp1 = tail;
		while(tmp1!=NULL)
		{	
			cout<<tmp1->dt<<" ";
			tmp1 = tmp1->next;
		}
	}
	
	return 0;
}