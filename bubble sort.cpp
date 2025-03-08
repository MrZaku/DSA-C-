#include<iostream>
using namespace std;

void bubblesort(int arr[], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);}
		}
	}
}

void insert(int arr[], int n){
	for(int i=0; i<n; i++){
		cin>>arr[i];}
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"  ";}
		cout<<endl;
}

int main(){
	int n;
	cout<<"Enter the size of array; ";
	cin>>n;
	int arr[n];
	insert(arr, n);
	cout<<"\nBefore sorting; ";
	display(arr, n);
	bubblesort(arr, n);
	cout<<"\nAfter sorting; ";
	display(arr, n);
	return 0;
}