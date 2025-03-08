#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int value){
		this -> data = value;
		this -> left = NULL;
		this -> right = NULL;
	}
};

class BST{
	public:
		Node* root;
		
		BST(){
			root = NULL;
		}
		//INSERTION FUNCTION
		void insert(int d){
			Node* n = new Node(d);
			if(root == NULL){
				root = n;
			}
			else{
				Node* curr = root;
				Node* prev = NULL;
				while(curr != NULL){
					prev = curr;
					if(d < curr->data)
						curr = curr->left;
				
					else if(d==prev->data){
						cout<<d<<" already exists!"<<endl;
						return;}
				
					else
						curr = curr->right;
			}
				if(d < prev->data)
					prev->left = n;

				else
					prev->right = n;}
	}
		
		//INORDER DISPLAY
		void inorder(Node* root) {
    	stack<Node*> s;
    	Node* current = root;

	    while (current != NULL || !s.empty()) {
    	    while (current != NULL) {
    	        s.push(current);
   		        current = current->left;
			}
    	    current = s.top();
    	    s.pop();
    	    cout << current->data << " ";  
    	    current = current->right;}
	}
		
		//SEARCH FUNTION
		bool reSearchItem(Node* n, int d){
			if(n==NULL)
			return false;
			
			else if(d == n->data)
				return true;
				
			else if(d < n->data)
				return reSearchItem(n->left, d);
				
			else
				return reSearchItem(n->right, d);
		}
		
		//Populate function to full bst from random numbers
		void populateBST(int n){
		for(int i=0; i<=n; i++){
			int a = rand()%1000;
			insert(a);}
		}
};

int main(){
	BST t;
	int n;
	cout<<"\nEnter number of Nodes; ";
	cin>>n;
	t.populateBST(n);
	
	cout<<"\nInorder Traversel; ";
	t.inorder(t.root);
	int a;
	cout<<"\nEnter a data to search; ";
	cin>>a;
	bool x = t.reSearchItem(t.root, a);
	
	if(x==1)
		cout<<"\nData found!";
	else
		cout<<"\nData not found!";
	return 0;
}