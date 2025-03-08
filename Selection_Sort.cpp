#include<iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n=10;
	int arr[n];
	for(int i=0; i<n; i++){
		int a=rand()/100;
		arr[i]=a;
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"  ";
	}	
	cout<<endl;
	
	//selection sort
	for(int i=0; i<n; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if (arr[j]<arr[min]){
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"  ";
	}
	
	return 0;
}
