/*
Print Level - Depth wise of a MLL.

Example MLL:

               10 – 5 – 12  –  7 – 18

                |                        |

               4 – 20 – 9         25 – 6

                      |      |            |

                     3     63         2 – 8 – 54

                             |            |

                           72          47 – 86

                                           |

                                          36



Input : 10 1 4 0 20 1 3 0 -1 9 1 63 1 72 0 -1 -1 -1 5 0 12 0 7 1 25 1 2 1 47 1 36 0 -1 86 0 -1 8 0 54 0 -1 6 0 -1 18 0 -1



( 1 for down link, 0 for no down link , -1 for end of next link )





Output1 : Level–wise : 10 5 12 7 18 4 20 9 25 6 3 63 2 8 54 72 47 86 36

Output 2 : Depth–wise: 10 4 20 3 9 63 72 5 12 7 25 2 47 36 86 8 54 6 18

 First cout << Level wise  ,               next  cour << Depth wise 

(Input : 10 1 4 0 20 1 3 0 -1 9 1 63 1 72 0 -1 -1 -1 5 0 12 0 7 1 25 1 2 1 47 1 36 0 -1 86 0 -1 8 0 54 0 -1 6 0 -1 18 0 -1 )
*/
#include <iostream>
#include <climits>
using namespace std;

class mlnode
{
public:
	int data;
	mlnode* next;mlnode* dlink;
	mlnode()
	{
		data = INT_MIN;
		next = NULL;
		dlink = NULL;
	}

};


void inputLL(mlnode* tmp)
{
	int a;cin>>a;
	if (a==-1) return;
	
	if (a==1)
	{
		cin>>a;
		mlnode* tmpn = new mlnode();
		tmpn->data = a;
		tmp->dlink = tmpn;
		inputLL(tmpn);
		//return k baad control yaha 
		cin>>a;
		if (a==-1) return;
		mlnode* tmpx = new mlnode();
		tmpx->data = a;
		tmp->next = tmpx;
		inputLL(tmpx);
	}
	else if (a==0)
	{
		cin>>a;
		if (a==-1) return;
		mlnode* tmpn = new mlnode();
		tmpn->data = a;
		tmp->next = tmpn;
		inputLL(tmpn);


	}
}

void printMLdepth(mlnode* tmp)
{
	//cout<<"executed\n";
	if (tmp->dlink==NULL && tmp->next==NULL)
	{
		cout<<tmp->data<<" ";
		return ;
	}

	cout<<tmp->data<<" ";

	if (tmp->dlink != NULL)
	{
		printMLdepth(tmp->dlink);
	}
	if (tmp->next != NULL)
		printMLdepth(tmp->next);
}

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

	inputLL(head);
	//cout<<"INPUT COMPLETE\n";

	printMLdepth(head);
	cout<<"\n";
	return 0;
}

//10 1 4 0 20 1 3 0 -1 9 1 63 1 72 0 -1 -1 -1 5 0 12 0 7 1 25 1 2 1 47 1 36 0 -1 86 0 -1 8 0 54 0 -1 6 0 -1 18 0 -1

