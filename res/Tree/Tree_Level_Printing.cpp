/*
	Given a tree like this
	          A
	        /   \
	       B     C
	      / \   / \
	     F  G  H   I
	    /       \
	   J         K

	Level Printing:
	A
	B C
	F G H I
	J K
*/


#include<bits/stdc++.h>

using namespace std;

typedef struct btnode{
	btnode *lc;
	char data;
	btnode *rc;
}*btptr;

void insert(btptr &T,char n)
{
	if(T==NULL)
	{
		T = new btnode;
		T->data = n;
		T->lc = NULL;
		T->rc = NULL;
	}
	char ch;
	cout<<"Enter left child for "<<n<<" (. if none): ";
	cin>>ch;
	if(ch!='.')
		insert(T->lc,ch);
	cout<<"Enter right child for "<<n<<" (. if none) :";
	cin>>ch;
	if(ch!='.')	
		insert(T->rc,ch);
	else return;
}

queue<btptr>q;
void level(btptr T)
{
	btptr temp = new btnode;
	temp->data = '#';
	temp->lc = NULL;
	temp->rc = NULL;
	q.push(T);
	q.push(temp);
	while(q.size()!=1)
	{
		btptr t = q.front();
		q.pop();
		if(t->data=='#')
		{
			cout<<"\n";
			q.push(temp);
		}
		else
		{
			cout<<t->data<<" ";
			if(t->lc!=NULL)
				q.push(t->lc);
			if(t->rc!=NULL)
				q.push(t->rc);
		}
	}
}

int main()
{
	btptr T = NULL;
	char ch;
	cin>>ch;
	insert(T,ch);
	level(T);
}


