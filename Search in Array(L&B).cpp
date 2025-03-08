#include <iostream>
using namespace std;

int arr[10]={5,10,15,20,25,30,35,40};

void linearsearch(int key){
	cout<<"You are searching for "<<key<<" in array!"<<endl;
	for(int i = 0; i<10; i++){
		if(arr[i] == key){
			cout<<"Value found at position; "<<i+1<<endl<<endl;
			return;
		}
		}
		cout<<"value not found!"<<endl<<endl;
	}
void insert(int po, int key){
	cout<<"Inserting "<<key<<" at position "<<po<<endl<<endl;
	po=po-1;
	for(int i=10; i>po; i--){
		arr[i]= arr[i-1];
	}
	arr[po]=key;
}

void print(){
	for (int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
}

void binarySearch(int key) {
	cout<<"You are searching for "<<key<<" in array!"<<endl;
    int low = 0, high = 9;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key){
            cout<<"Value found at postion; "<<mid+1<<endl;
			return;} 
        else if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    cout<<"Value not found!"<<endl;
    return; 
}


int main(){
	print();

	insert(3,12);
	print();
	
	insert(10, 50);
	print();
	
	linearsearch(12);
	binarySearch(12);
	binarySearch(33);
	return 0;
}
