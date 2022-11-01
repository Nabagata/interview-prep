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

typedef struct Btnode{
	Btnode *left_child;
	char data;
	Btnode *right_child;
}*BT_ptr;

void insert(BT_ptr &T,char n)
{
	if(T==NULL)
	{
		T = new Btnode;
		T->data = n;
		T->left_child = NULL;
		T->right_child = NULL;
	}
	char ch;
	cout<<"Enter left child for "<<n<<" (. if none): ";
	cin>>ch;
	if(ch!='.')
		insert(T->left_child,ch);
	cout<<"Enter right child for "<<n<<" (. if none) :";
	cin>>ch;
	if(ch!='.')	
		insert(T->right_child,ch);
	else return;
}

queue<BT_ptr>q;
void levelPrint(BT_ptr T)
{
	BT_ptr temp = new Btnode;
	temp->data = '#';
	temp->left_child = NULL;
	temp->right_child = NULL;
	q.push(T);
	q.push(temp);
	while(q.size()!=1)
	{
		BT_ptr t = q.front();
		q.pop();
		if(t->data=='#')
		{
			cout<<"\n";
			q.push(temp);
		}
		else
		{
			cout<<t->data<<" ";
			if(t->left_child!=NULL)
				q.push(t->left_child);
			if(t->right_child!=NULL)
				q.push(t->right_child);
		}
	}
}

int main()
{
	BT_ptr T = NULL;
	char ch;
	cin>>ch;
	insert(T,ch);
	levelPrint(T);
}


