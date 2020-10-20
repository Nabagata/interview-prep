/*
	A program to find the least common ancestor of two nodes in BST
	Time Complexity : O(logn) where n is size of tree

	Algorithm : As BST follows a specific order where each of the value in right subtree is more than parent node and left sub tree is smaller than parent node
	So the concept here used is whenever there is an divergence of value the given node is Least Common Ancestor.
	Before that all are common ancestor. 
*/

#include<bits/stdc++.h>

using namespace std;

typedef struct bstnode{
	bstnode *lchild;
	int data;
	bstnode *rchild;
}*bstptr;

void insert(bstptr &T,int n)
{
	if(T==NULL)
	{
		T=new(bstnode);
		T->data=n;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else
	{
		if(T->data>n)
		insert(T->lchild,n);
		else
		insert(T->rchild,n);
	}
}

int searchLCA(bstptr B,int m,int M)
{
	if(n<B->data && b>B->data)
	return B->data;
	if(B->data>n)
	searchLCA(B->lchild,n,b);
	else if(B->data < n)
	searchLCA(B->rchild,n,b);
}

int main()
{
	bstptr T;
	T=new(bstnode);
	T=NULL;
	int n;
	cin>>n;
	while(n!=-1)
	{
		insert(T,n);
		cin>>n;
	}
	int a,b,m,M;
	cin>>a>>b;	
	m = min(a,b), M = max(a,b);
	cout<<searchLCA(T,m,M);
}
