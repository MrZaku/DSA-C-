#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prev; };
class linkedlist{
	public:
		Node* head;
		Node* tail;
//constructor
		linkedlist(){
			head=NULL;
			tail=NULL;}		
//insert new node at head
		void insert(int key){
			if (head == NULL){
				Node* newnode = new Node;
				newnode->data = key;
				head = newnode;
				return;
			}
			else{
				Node* newnode = new Node;
				newnode->data=key;
				Node* temp = head;
				head = newnode;
				newnode->next= temp;
				newnode->prev=NULL;
			}
}
//insert new node at end or append node			
		void append(int key){
			Node* newnode = new Node;
			newnode->data = key;
			newnode->next=NULL;
			Node* temp = head;
			if(temp==NULL){;
				newnode->prev=NULL;
				head=newnode;}
			while(temp->next!=NULL){
				temp= temp->next;}
			newnode->prev= temp;
			temp->next= newnode;
			}
//search data and return its position else return -1			
		int search(int key){
			int count=0;
			Node* temp = head;
			while(temp!=NULL){
				count++;
				if(temp->data==key){
					return count;}
				temp = temp->next;}
			return -1;}
//to print or display data in linkedlist			
		void print(){
			Node* temp= head;
			while(temp!=NULL){
				cout<<temp->data<<" -> ";
				temp = temp->next;}
			cout<<"NULL"<<endl;}
};
int main(){
	linkedlist list;
	list.insert(12);
	list.insert(13);
	list.append(11);
	list.append(10);
	list.print();
	return 0;}
