// Converting Binary Tree to Binary search tree without storing Inorder traversal in an array and again inserting to
// tree

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

class bstnode
{
public:
    bstnode* lchild;
    int data;
    bstnode* rchild;
    bool flg;
    bstnode()
    {
        flg = false;
        lchild = rchild = NULL;
    }
};

void printvec(vector<bstnode*>&vec)
{
    for (int i=0;i<vec.size();++i)
    {
        cout<<vec[i]->data<<" ";
    }
    cout<<endl;
}

void ino(bstnode* &T,vector<bstnode*> &in)
{
    if (T==NULL) return;

    if (T->lchild !=NULL )
    {
        ino(T->lchild,in);
    }

    in.push_back(T);

    if (T->rchild != NULL)
    {
        ino(T->rchild,in);
    }
}

void Kmin(bstnode*&T,bstnode*&m)
{
    if (T==NULL)
    {
        return;
    }

    if (T->lchild!=NULL)
    { 
        Kmin(T->lchild,m);
    }
    
    if (T->data < m->data && T->flg == false)
    {
        m = T;
    }

    if (T->rchild!=NULL)
    {
        Kmin(T->rchild,m);
    }
}

void inorder(bstnode* &T)
{
    if (T==NULL) return;

    if (T->lchild !=NULL )
    {
        inorder(T->lchild);
    }
    cout<<T->data<<" ";
    if (T->rchild != NULL)
    {
        inorder(T->rchild);
    }
}

void swap(bstnode*& a,bstnode* &b)
{
    int tmp;
    tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

int main()
{
    int a;
    bstnode* T = new bstnode(),*tmp;
    //Input 1
    /*
    T->data = 7; 
    tmp = new bstnode();tmp->data = 9;
    T->lchild = tmp;
    tmp = new bstnode();tmp->data = 6;
    T->rchild = tmp;
    tmp = new bstnode();tmp->data = 2;
    T->lchild->lchild = tmp;
    tmp = new bstnode();tmp->data = 4;
    T->lchild->rchild = tmp;
    tmp = new bstnode();tmp->data = 1;
    T->rchild->lchild = tmp;
    tmp = new bstnode();tmp->data = 3;
    T->rchild->rchild = tmp;
    tmp = new bstnode();tmp->data = 8;
    T->lchild->lchild->lchild = tmp;
    tmp = new bstnode();tmp->data = 11;
    T->lchild->lchild->rchild = tmp;
    */


    //Input 2
    
    T->data = 5;
    tmp = new bstnode();tmp->data = 8;
    T->lchild =tmp;
    tmp = new bstnode();tmp->data = 11;
    T->rchild = tmp;
    tmp = new bstnode();tmp->data = 2;
    T->rchild->lchild = tmp;
    tmp = new bstnode();tmp->data = 4;
    T->rchild->rchild = tmp;
    tmp = new bstnode();tmp->data = 1;
    T->rchild->lchild->lchild = tmp;
    tmp = new bstnode();tmp->data = 10;
    T->rchild->lchild->rchild = tmp;
    tmp = new bstnode();tmp->data = 6;
    T->rchild->lchild->lchild->lchild =tmp;
    
    vector<bstnode*> in;
    ino(T,in);
    printvec(in);
    
    bstnode* tmpn,*m;
    for (int i=0;i<in.size();++i)
    {
        tmpn = in[i];
        m = new bstnode();
        m->data = INT_MAX;
        Kmin(T,m);
        tmpn->flg = true;
    
        swap(tmpn->data,m->data);
    }
    cout<<"Inorder Traversal of tree : \n";
    inorder(T);

    return 0;
}