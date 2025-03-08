#include<iostream>
#define size 10
using namespace std;
class Queu{
	private:
		int elements;
		int arr[size];
		int front;
		int rear;
	public:
		Queu(){
			elements=0;
			front = -1;
			rear = -1;
			for (int i = 0; i < size; i++) {
            arr[i] = 0;}}
		bool is_empty(){
			return (elements==0);}
		bool is_full(){
			return (elements==size);}
		void InsertRear(int d){
			if(is_full()){
				cout<<"Queu is full!"<<endl;}
			else{
				if(is_empty()){
					front = 0;
					rear = 0;}
				else{
					rear = (rear+1)%size;
					}
				arr[rear]=d;
				elements++;
				cout<<d<<" Inserted at Rear side of the queue."<<" Rear= "<<rear<<" Front= "<< front <<endl;}
		}
		void InsertFront(int d){
			if(is_full()){
				cout<<"Queu is full!"<<endl;}
			else{
				if(is_empty()){
					front = (front+size)%size;
					rear=0;}
				else{
					front = (front-1+size)%size;}
				arr[front]=d;
				elements++;
				cout<<d <<" Inserted at front side of the queue."<<" Rear= "<<rear<<" Front= "<<front<<endl;}
		}
		int RemoveFront(){
			if(is_empty()){
				cout<<"queu is empty!"<<endl;
				return 0;}
			else{
				int x = arr[front];
				front = (front+1)%size;
				cout<<x<<" is dequeud!"<<endl;
				elements--;
				return x;}
		}
		int RemoveRear(){
			if(is_empty()){
				cout<<"queu is empty!"<<endl;
				return 0;}
			else{
				int x = arr[rear];
				rear = (rear-1+size)%size;
				cout<<x<<" is dequeud!"<<endl;
				elements--;
				return x;}
		}
		int Front(){
			if(is_empty()){
				cout<<"queu is empty!"<<endl;
				return 0;}
			else{
				int x = arr[front];
				cout<<"front is "<<x<<endl;
				return x;}
		}
		void display(){
			if(is_empty()){
				cout<<"Queu is empty!"<<endl;}
			else{
				cout<<"Index    "<<"Values     "<<" Pointer"<<endl;
				for(int i=0; i<=size-1; i++){
					if(i==rear){
						cout<<i<<"         "<<arr[i]<<"          Rear"<<endl;}
					else if(i==front){
						cout<<i<<"         "<<arr[i]<<"           Front"<<endl;}
					else if(arr[i] == 0){
						cout<<i<<"         empty"<<endl;}
					else{
						cout<<i<<"         "<<arr[i]<<endl;}
				}
			}
		}
};
int main(){
	Queu q;
	int x, n;
	while(true){
		cout<<"Please enter a number representing an operation in the following list (-1 to quit):"<<endl;
		cout<<"1. InsertRear() \n2. InsertFront() \n3. RemoveRear() \n4. RemoveFront() \n5. Display()"<<endl;
		cout<<"User enters >> ";
		cin>>n;
		switch(n){
			case -1:
				exit(0);
			case 1:
				cout<<"Enter a value that you want to insert at Rear side: ";
				cin>>x;
				q.InsertRear(x);
				break;
			case 2:
				cout<<"Enter a value that you want to insert at left side: ";
				cin>>x;
				q.InsertFront(x);
				break;
			case 3:
				q.RemoveRear();
				break;
			case 4:
				q.RemoveFront();
				break;
			case 5:
				q.display();
				break;}
	}
	return 0;
}
