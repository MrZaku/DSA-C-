#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

class Linkedlist{
	private:
		Node* head;
	public:
		Linkedlist(){
			head = NULL;
		}
		//add node at end
		void append(int value){
			Node* newnode = new Node;
			newnode -> data = value;
			newnode -> next = NULL;
			if (head == NULL){
				head = newnode;
			}
			else{
				Node* temp = head;
				while(temp -> next != NULL){
					temp = temp->next;
				}
				temp -> next = newnode;
			}
		}
		//insert node at the beggining
		void insert(int value){
			Node* newnode = new Node;
			newnode->data = value;
			newnode->next = head;
			head = newnode;
		}
		//add node at position
		void Insertatpostion(int po, int value){
			if(po==1){
				Node* newnode = new Node;
				newnode->data = value;
				newnode->next = head;
				head = newnode;
				return;
			}
			Node* newnode = new Node;
			newnode->data = value;
			int cnt= 1;
			Node* temp = head;
			while(cnt <  po-1){
				temp = temp->next;
				cnt++;
			}
			newnode ->next = temp->next;
			temp->next=newnode; 
		}
		//reverse the linkedlist
		void reverse(){
			
			Node* prev = NULL;
			Node* curr = head;
			Node* farw = NULL;
			while(curr != NULL){
				farw = curr->next;
				curr->next = prev;
				prev = curr;
				curr = farw;
			}
			head = prev;
		}
		//search node in linkedlist through data
		void search(int key){
			Node* temp = head;
			while(temp!=NULL){
				if(head->data==key){
					cout<<"Value found!"<<endl;
					return;
				}
				temp = temp->next;
			}
			cout<<"Value not found!"<<endl;
			
		}
		//count nodes in linkelist 
		void countnodes(){
			int count=0;
			Node* temp = head;
			if(temp==NULL){
				cout<<"List is empty!"<<endl;
			}
			else{
				while(temp!=NULL){
					count++;
					temp= temp->next;
				}
				cout<<"Total Nodes are; "<<count<<endl;
	}
		}
		//delete nodes from linkedlist
		void deletenode(int value){
			Node* temp = head;
			Node* prev = NULL;
			if(temp->data==value){
				head = temp->next;
				delete temp;
				return;
			}
			while(temp!= NULL){
				if(temp->data == value){
					prev->next = temp->next;
					delete temp;
					return;
				}
				
				prev = temp;
				temp = temp->next;
			}
		}
		//print or display the linkedlist / traverse
		void print(){
			Node* temp = head;
			if (head == NULL){
				cout<<"Linkedlist is Empty!"<<endl<<endl;
			}
			else{
				while(temp != NULL){
					cout<<temp->data<<" -> ";
					temp = temp->next;
				}
				cout<<"NULL"<<endl<<endl;
			}
		}
		
		//to insert a node on the basis of sort
		void insertsort(int key){
			Node* neWnode = new Node;
			neWnode->data=key;
			if(head == NULL){
				head = neWnode;
				neWnode->next = NULL;
			}
			else if(head->data > key){
				neWnode->next = head;
				head = neWnode;
			}
			else{
				Node* temp = head;
				Node* prev = NULL;
				while(temp->next !=NULL){
					if(temp->data < key){
						prev = temp;
						temp= temp->next;
					}
					else{
						prev->next = neWnode;
						neWnode->next = temp;
						return;
					}
				}
				temp->next = neWnode;
				neWnode->next = NULL;
			}
		}
		
		~Linkedlist(){
			Node* temp = head;
			while(temp!=NULL){
				Node* next = temp->next;
				delete temp;
				temp = next;
			}
			cout<<"Memory Freed!"<<endl;
			
		}
		
};

int main(){
	Linkedlist list;
	int n, a, b;
	while(true){
	cout<<"[1] Add node at head"<<endl;
	cout<<"[2] Add node at END"<<endl;
	cout<<"[3] Add node at Position"<<endl;
	cout<<"[4] Add node through sort"<<endl;
	cout<<"[5] Reverse the list"<<endl;
	cout<<"[6] Delete node from the list"<<endl;
	cout<<"[7] Count number of nodes in list"<<endl;
	cout<<"[8] Search node in list"<<endl;
	cout<<"[9] Display the list"<<endl;
	cout<<"Chose the operation; ";
	cin>>n;	
	switch (n){
		case 1:
			cout<<"Enter a value; ";
			cin>>a;
			list.insert(a);
			break;
		case 2:
			cout<<"Enter a value; ";
			cin>>a;
			list.append(a);
			break;
		case 3:
			cout<<"Enter a value; ";
			cin>>a;
			cout<<"Enter position; ";
			cin>>b;
			list.Insertatpostion(b, a);
			break;
		case 4:
			cout<<"Enter a value; ";
			cin>>a;
			list.insertsort(a);
			break;
		case 5:
			list.reverse();
			cout<<"List reversed successfully!"<<endl;
			break;
		case 6:
			cout<<"Enter a value; ";
			cin>>a;
			list.deletenode(a);
			break;
		case 7:
			list.countnodes();
			break;
		case 8:
			cout<<"Enter a value; ";
			cin>>a;
			list.search(a);
			break;
		case 9:
			list.print();
			break;
	}
}
	return 0;
}
