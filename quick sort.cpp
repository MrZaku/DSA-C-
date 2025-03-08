#include <iostream>
using namespace std;

//SUB-FUNCTION >> Partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);}
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);}


//MAIN-FUNCTION >> QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
    	
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);}
}

//DISPLAY FUNCTION
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";}
    cout << endl;
}

int main() {
	int n=10;
    int arr[n]={4,1,8,9,44,6,2,77,90,10};
    display(arr, n);

    quickSort(arr, 0, n-1 );

    display(arr, n);

    return 0;
}
