#include<iostream>
using namespace std;
//SUB-FUNCTION >> Merge function
void merge(int *arr, int s, int e){
	int mid = (s+e)/2;
	int len1 = mid - s+1;
	int len2 = e - mid;
	
	int *first = new int[len1];
	int *second = new int[len2];
	int k = s;
	for(int i=0; i<len1; i++){
		first[i]=arr[k++];
	}
	
	k=mid+1;
	for(int i=0; i<len2; i++){
		second[i]=arr[k++];
	}
	
	int index1 = 0;
	int index2 = 0;
	k=s;
	while(index1 < len1 && index2 < len2){
		if(first[index1]<second[index2]){
			arr[k++]=first[index1++];
		}
		else{
			arr[k++]=second[index2++];
		}
	}
	while(index1<len1){
		arr[k++]=first[index1++];
	}
	while(index2<len2){
		arr[k++]=second[index2++];
	}
}

//Main mergeSort function
void mergeSort(int *arr, int s, int e){
	if (s>=e){
		return;
	}
	
	int mid = (s+e)/2;
	
	mergeSort(arr, s, mid);
	mergeSort(arr, mid+1, e);
	
	merge(arr, s, e);
}
int main(){
	int arry[5]={1,9,7,3,5};
	for(int i=0; i<5; i++){
		cout<<arry[i]<<"  ";
	}
	cout<<endl;
	mergeSort(arry, 0, 4);
	for(int i=0; i<5; i++){
		cout<<arry[i]<<"  ";
	}
	
	return 0;
}
