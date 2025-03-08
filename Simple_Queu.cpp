#include<iostream>
#define size 10
using namespace std;
class Queu{
    private:
        int arr[size];
        int rear;
        int front;
        int elements;
    public:
        Queu(){
            rear = 0;
            front = -1;
            elements =0;}
        bool is_empty(){
            return (elements == 0);}
        bool is_full(){
            return (elements == size);}
        void enqueu(int d){
            if(is_full()){
                cout<<"Queue is full!"<<endl;}
            else{
                if(is_empty()){
                    front = (front+size)%size;}
                else{
                    front = (front-1)%size;}
                arr[front] = d;
                elements++;
                cout<<d<<" is enqueued!"<<endl;}
        }
        int dequeu(){
            if(is_empty()){
                cout<<"Queu is empty!"<<endl;}
            else{
                int x = arr[front];
                front=(front+1)%size;
                elements--;
                cout<<x<<" is dequeued!"<<endl;
                return x;}
        }
        int Front(){
            if(is_empty()){
                cout<<"Queu is empty!"<<endl;
                return 0;}
            else{
                cout<<"Front is "<<arr[front]<<endl;
                return arr[front];}
        }
};

int main(){
    Queu q;
    q.enqueu(10);
    q.enqueu(12);
    q.enqueu(45);
    q.dequeu();
    q.Front();
    return 0;
}