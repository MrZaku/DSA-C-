#include<iostream>
#include<cstdlib>
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
		int leafnode = 0, count=0, _1child = 0, _2child = 0;
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
					return;}
				
				else
					curr = curr->right;
			}
			if(d < prev->data)
				prev->left = n;

			else
				prev->right = n;
		}
	}

		//FUNCTION to find minimum node		
		Node* find_min(Node* temp) {
    		while (temp && temp->left != NULL) {
     		   temp = temp->left;}
    		return temp;
			}
		
		//Function TO delete node from BST
		void deleteNode(Node* &temp, int d) {
    		if (temp == NULL) {
    			count++;
       			return;}

   		if (d < temp->data)
        	deleteNode(temp->left, d);
	 	else if (d > temp->data)
        	deleteNode(temp->right, d);
		else {
        	if (temp->left != NULL && temp->right != NULL) {
				_2child++;
        	    Node* min = find_min(temp->right);
				if(min->right == NULL && min->left == NULL){
					leafnode--;
				}
				else if(min->right == NULL || min->left == NULL){
					_1child--;
				}
        	    temp->data = min->data; 
        	    deleteNode(temp->right, min->data);}
			else if(temp->left == NULL && temp->right == NULL){
				leafnode++;
        	    Node* tempNode = temp;
        	    temp = NULL;
        	    delete tempNode;	
			}
			else if (temp->left == NULL) {
				_1child++;
        	    Node* tempNode = temp;
        	    temp = temp->right;
        	    delete tempNode;} 
			else if (temp->right == NULL) {
				_1child++;
        	    Node* tempNode = temp;
        	    temp = temp->left;
        	    delete tempNode;}
    }
}
	
		//POPULATE function
		void populateTree(int n){
			for(int i=1; i<=n; i++){
			int a = rand()%1000;
			insert(a);}
		}
		
		//Function to delete Random number by calling delete function
		void deleteRandom(int n){
			for(int i=1; i<=n; i++){
			int a = rand()%1000;
			deleteNode(root, a);}
		}
};

int main(){
	BST t;
	int n=1000, a=20;;
	t.populateTree(n);
	t.deleteRandom(a);
	cout<<"\nRandom nodes tried for deletion  = "<<a<<endl;
	cout<<"No of Leaf nodes deleted         = "<<t.leafnode<<endl;
	cout<<"No of 1 child Nodes deleted      = "<<t._1child<<endl;
	cout<<"No of 2 child Nodes deleted      = "<<t._2child<<endl;
	cout<<"No of Nodes That does no founded = "<<t.count<<endl;
	return 0;
}