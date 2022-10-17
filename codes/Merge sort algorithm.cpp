#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int s, int e){
	int mid= (s+e)/2;
	
	int i=s;
	int j= mid+1;
	int k=s;
	
	int  temp[100];
	
	while(i<=mid && j<=e){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}
		else{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=e){
		temp[k++]=a[j++];
	}
	
	//Finally we need to copy all elements in original array (O(n))
	for(int i=s;i<=e;++i){
		a[i]=temp[i];
	}
}

void mergeSort(int a[], int s, int e){
	//Base case - for 1 or 0 number of elements
	if(s>=e){
		return;
	}
	
	//Follow 3 steps
	//Step 1- Dvide
	int mid = (s+e)/2;
	
	//Step -2 - Recursively call the two arrays i.e from(start to mid) & from (mid+1 to end)
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);
	
	//Step-3 - Merge the two parts
	merge(a,s,e);
}

int main(){
	int a[100];
	int n; cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	mergeSort(a,0,n-1);
	
	for(int i=0;i<n;++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
