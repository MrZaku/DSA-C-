#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class Linkedlist{
	public:
		Node* head;
		
		Linkedlist(){
			head = NULL;
		}
		//insert At Head 
		void insert(int d){
			Node* neWnode = new Node;
			neWnode->data = d;
			neWnode->next = head;
			head = neWnode;
		}
		//Display the linkedlist
		void print(){
			if (head == NULL){
				cout<<"Linkedlist is empty!"<<endl;
			}
			else{
				Node* temp = head;
				while(temp != NULL){
					cout<<temp->data<<" -> ";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}
		//Reverse the linkedlist
		void reverse(Node* prev, Node* curr){
			if (curr == NULL){
				head = prev;
				return;
			}
			else{
				Node* farw = curr->next;
				reverse(curr, farw);
				curr -> next = prev;
			}
		}
};
int main(){
	Linkedlist list;
	list.insert(10);
	list.insert(9);
	list.insert(8);
	list.insert(7);
	list.insert(6);
	list.insert(5);
	list.insert(4);
	list.insert(3);
	list.insert(2);
	list.insert(1);
	list.print();
	Node* curr = list.head;
	Node* prev = NULL;
	list.reverse(prev, curr);
	list.print();
	return 0;
}
