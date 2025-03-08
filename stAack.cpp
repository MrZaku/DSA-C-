#include<iostream>
#define size 10
using namespace std;
class Stack{
    public:
        int top;
        int arr[size];
        Stack(){
            top =-1;
        }
        bool is_empty(){
            return top<=-1;
        }
        bool is_full(){
            return top>=size-1;
        }
        bool push(int d){
            if(is_full()){
                cout<<"Waleed ke nor na zee"<<endl;
                return false;
            }
            else{
                top++;
                arr[top]=d;
                cout<<d<<" waleed ke laro"<<endl;
                return true;
            }
        }
        int pop(){
            if(is_empty()){
                cout<<"Waleed ke ess nishta"<<endl;
                return 0;
            }
            else{
                int temp= arr[top];
                top--;
                cout<<temp<<" Waleed na owato"<<endl;
                return temp;
            }
        }
        int Top(){
            if(is_empty()){
                cout<<"Waleed ke ess nishta"<<endl;
                return 0;
            }
            else{
                cout<<"Waleed ke "<<arr[top]<<" de"<<endl;
                return arr[top];
            }
        }
        void display(){
            if (is_empty()){
                cout<<"stack is empty"<<endl;
            }
            else{
                for(int i = top; i>=0; i--){
                    cout<<arr[i]<<"  ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Stack s;
    s.display();
    s.pop();
    s.push(10);
    s.push(90);
    s.push(20);
    s.push(13);
    s.display();
    return 0;
}