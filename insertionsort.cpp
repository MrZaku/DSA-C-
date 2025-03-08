#include<iostream>
#include <cstdlib>
#include<chrono>
using namespace std;

void Insertionsort(int n, int arr[]){
    for(int i=1; i<=n-1; i++){
		int temp = arr[i];
		int j=i-1;
		while(j>=0 && temp<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;}
}

void Display(int n, int arr[]){
        for(int i=0; i<=n-1; i++){
		cout<<arr[i]<<"  ";
        }
        cout<<endl;
}
int main(){
	int n=100;
	int arr[n];
	for(int i=0; i<=n; i++){
		int a=rand()%500;
		arr[i]=a;
	}
    Display(n, arr);
	auto start = chrono::high_resolution_clock::now();
	Insertionsort(n, arr);
	auto end = chrono::high_resolution_clock::now();
    Display(n, arr);
    auto time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
	cout<<"\nTime taken; "<<time<<"  nanoseconds";
	return 0;
}