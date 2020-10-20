/*
Targets - Print all targets ( paths ) from start node 1.﻿

The nodes are numbered (with data values) from 1 to 18.

The output is needed to print the path from 1 to 16  and from 3 to 12



The test case input sequence is  node's data value number of links it has 

test case input ( cin >> )  : 1 1 2 1 3 2 4 1 5 2 6 1 7 0 8 1 9 0 10 3 11 1 12 0 14 1 15 1 16 0 17 1 18 0

input ( source point s, target point t )  ( cin >> s , cin >> t )  :  1 16

print path ( cout << )

input ( source point s, target point t )  ( cin >> s, cin >> t )  :  3 12

print path ( cout << )



test case output :  1 2 3 10 14 15 16

test case output : 3 10 11 12

Note -> 0 means u have to return in stack i.e. it is a leaf.
*/

#include <iostream>
#include <vector>
using namespace std;

class tnode
{
public:
	int child,data;
	tnode** arr;
	tnode (int s) 
	{
		child = s;
		arr = new tnode* [s];
	}
};


void printstk(vector <tnode*> stk)
{
	for (int i=0;i<stk.size();++i)
	{
		cout<<stk[i]->data<<" ";
	}
	cout<<endl;
}

void inputLL(tnode* tmp)
{
	int a,dir;
	
	if (tmp->child==0)
	{
		return;
	}

	for (int i=0;i<tmp->child;++i)
	{
		cin>>a>>dir;
		tmp->arr[i] = new tnode(dir);
		tmp->arr[i]->data = a;
		inputLL(tmp->arr[i]);
	}
}

void prinTgt(tnode* tmp,vector<tnode*>stk)
{
	stk.push_back(tmp);
	if (tmp->child==0)
	{
		printstk(stk);
		cout<<endl;
		return;
	}

	for (int i=0;i< (tmp->child); ++i)
	{
		prinTgt(tmp->arr[i],stk);
	}
}

int main()
{
	int a,dir;
	cin>>a>>dir;
	tnode* head = new tnode(dir);
	head->data = a;
	vector<tnode*> stk;
	inputLL(head);
	prinTgt(head,stk);

	return 0;
}	
