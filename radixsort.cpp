#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
//SUB-FUNCTION >> Count
void countSort(int arr[], int n, int exp){
    int count[10], output[n];
    for(int i=0; i<10; i++){
        count[i]=0;}
    for(int i=0; i<n; i++){
        count[(arr[i]/exp)%10]++;}
    for(int i=1; i<10; i++){
    for(int i=0; i<n; i++){   
        int index = (arr[i]/exp)%10;
        output[count[index]-1]=arr[i];
        count[index]--;}
    for(int i=0; i<n; i++){
        arr[i]=output[i];}
}

//MAIN-FUNCTION >> Radix Sort
void Radixsort(int n, int arr[]){
    int max = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];}
    }
    for(int exp=1; max/exp>0; exp*=10){
        countSort(arr, n, exp);}
}
void display(int n, int arr[]){
	for(int i=0; i<=n-1; i++){
		cout<<arr[i]<<"  ";}
	cout<<endl;
}
int main(){
    int n=1000;
    int arr[n];
    for(int i=0; i<n; i++){
        int a=rand()%1000;
        arr[i]=a;}
	auto start = chrono::high_resolution_clock::now();
	Radixsort(n, arr);
    auto end = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout<<"Time taken = "<<time<<" microseconds";
    return 0;
}