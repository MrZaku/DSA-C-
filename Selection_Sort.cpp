#include<iostream>
using namespace std;

void selectionsort(int arr[], int n){
	for(int i=0; i<n; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[min])
				min = j;}
		swap(arr[i], arr[min]);
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
	selectionsort(arr, n);
	cout<<"\nAfter sorting; ";
	display(arr, n);
	return 0;
}
