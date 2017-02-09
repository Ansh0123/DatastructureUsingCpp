/*
  Author:
  Ashutosh Kumar
  @an_shuman777
  BST
*/

/*
  Segment tree implementation using array
  range Minimum Querry in segment tree
  array
*/
#include<bits/stdc++.h>
using namespace std;
const int Max = 1005;
int segTr[Max];

void constructSegmentTree(int inp[],int segTr[],int low,int high,int pos){
	if(low==high){
		segTr[pos]=inp[low];
		return;
	}
	int mid = (low+high)/2;
	constructSegmentTree(inp,segTr,low,mid,2*pos+1);
	constructSegmentTree(inp,segTr,mid+1,high,2*pos+2);
	segTr[pos]=min(segTr[2*pos+1],segTr[2*pos+2]);
}

int rangeMinQuerry(int segTr[],int ql,int qh,int low,int high,int pos){
	if(ql<=low and qh>=high){
		return segTr[pos];
	}
	if(qh<low || ql>high){
		return INT_MAX;
	}
	int mid=(low+high)/2;
	return min(rangeMinQuerry(segTr,ql,qh,low,mid,2*pos+1),
		rangeMinQuerry(segTr,ql,qh,mid+1,high,2*pos+2));
}

int main(void){
	int n;
	cin>>n;
	memset(segTr,INT_MAX,4*n);
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	constructSegmentTree(arr,segTr,0,n-1,0);

	/*Actual size of segment tree array*/
	int lmt;
	if(n&(n-1)){//If the orignal array size is not a power of 2
        for(int i=1;;i++){
            int k=n+i;
            if((k & (k-1)) == 0){
                lmt=k*2-1;
                break;
            }
        }
	}
	else{//if origanl size of array is power of 2
        lmt=n*2-1;
	}
	for(int i=0;i<lmt;i++){                
        cout<<segTr[i]<<" ";
	}
	cout<<endl;
	int mn = rangeMinQuerry(segTr,0,2,0,3,0);
	cout<<mn<<endl;
	return 0;
}
