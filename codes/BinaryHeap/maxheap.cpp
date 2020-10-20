#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int parent(int i)
{
	return (i/2);
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

void siftUp(vector<int>&H,int &i,int &size)
{
	while(i>1 && H[parent(i)] < H[i])
	{
		swap(&H[parent(i)],&H[i]);
		i = parent(i);
	}
}

void siftDown(vector<int>&H,int i, int &size)
{
	int maxind = i;
	int l = left(i);
	if (l<=size && H[l]>H[maxind])
	{
		maxind = l;
	}

	int r = right(i);

	if (r<=size && H[r]>H[maxind])
	{
		maxind = r;
	}

	if (maxind != i)
	{
		swap(&H[i],&H[maxind]);
		siftDown(H,maxind,size);
	}
}

void insert(vector<int> &H,int p,int&size)
{
	if (size==H.size())
		return;
	size++;
	H.push_back(p);
	siftUp(H,size,size);
}

int ExtractMax(vector<int>&H,int&size)
{
	int result = H[1];
	H[1] = H[size];
	size--;
	siftDown(H,1,size);
	return result;
}

void remove(vector<int> &H,int i,int &size)
{
	H[i] = INT_MAX;
	siftUp(H,i,size);
	ExtractMax(H,size);
}

void changePriority(vector<int>&H,int i,int p,int &size)
{
	int oldp = H[i];
	H[i] = p;
	if (p>oldp)
	{
		siftUp(H,i,size);
	}
	else
	{
		siftDown(H,i,size);
	}
}

void buildHeap(vector<int>&H)
{
	int siz = H.size();
	siz--;
	for (int i=siz/2;i>=1;--i)
	{
		siftDown(H,i,siz);
	}
}

int main()
{
	vector<int> H{INT_MIN,34,4,21,543,62,2,26,7,2,65,9,64,6778,12,54};
	buildHeap(H);
	for (int i=1;i<H.size();++i)
	{
		cout<<H[i]<<" ";
	}
	cout<<"\n";
	int size = H.size()-1;
	//cout<<"size is : "<<size<<endl;
	vector<int> HeapSort;
	while(size>0)
	{
		HeapSort.push_back(ExtractMax(H,size));
	}

	for (int i=0;i<HeapSort.size();++i)
	{
		cout<<HeapSort[i]<<endl;
	}
	
	return 0;
}