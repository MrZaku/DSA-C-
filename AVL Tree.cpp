#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	int height;
};

//FUNCTION TO FIND MINIMUM NODE
Node* find_min(Node* node){
	if(node->left==NULL)
		return node;
	else
		return find_min(node->left);
}

//FUNCTION TO FIND HEIGHT OF NODE
int get_height(Node* node){
	if(node==NULL)
		return 0;
	else
		return node->height;
}

//FUNCTION TO UPDATE HEIGHT OF NODE
void update_height(Node* node){
	node->height = max(get_height(node->left), get_height(node->right)) + 1;
}

//FUNCTION TO GET BALANCE_FACTOR OF A NODE 
int get_balancefactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

//FUNCTION FOR LEFT ROTATE
Node* left_rotate(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    update_height(node);
    update_height(temp);
    return temp;
}

//FUNCTION FOR RIGHT ROTATE
Node* right_rotate(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    update_height(node);
    update_height(temp);
    return temp;
}

//FUNCTION TO BALANCE THE AVL TREE
Node* rebalance(Node* node) {
    int balanceFactor = get_balancefactor(node);
    if (balanceFactor > 1) {
        if (get_height(node->left->left) >= get_height(node->left->right)) {
            node = right_rotate(node);
        } else {
            node->left = left_rotate(node->left);
            node = right_rotate(node);
         }
    } else if (balanceFactor < -1) {
        if (get_height(node->right->right) >= get_height(node->right->left)) {
            node = left_rotate(node);
        } else {
            node->right = right_rotate(node->right);
            node = left_rotate(node);
        }
    }
    return node;
}

//FUNCTION TO INSERT NODE IN AVL TREE
Node* insertNode(Node* node, int key) {
    if (node == NULL) {
        Node* newNode = new Node();
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->data) {
        node->left = insertNode(node->left, key);
    } else if (key > node->data) {
        node->right = insertNode(node->right, key);
    } else {
        return node;
    }
    
    //CALLING FUNCTION FOR BALANCING
    update_height(node);
    return rebalance(node);
}

//FUNCTION TO DELETE NODE FROM AVL TREE
Node* deleteNode(Node* node, int key) {
    if (node == NULL) {
        return node;
    }

    if (key < node->data) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->data) {
        node->right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else if(node->left!=NULL && node->right!=NULL){
        	Node* temp = find_min(node->right);
        	node->data = temp->data;
        	node->right = deleteNode(node->right, temp->data);
		}
        
    }
    //FUNCTION TO BALANCE AVL TREE
    update_height(node);
    return rebalance(node);
}

//FUNCTION TO DISPLAY AVL TREE IN INORDER
void inOrderTraversal(Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}



int main(){
	Node* root = NULL;

    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    
    root = deleteNode(root, 7);
    
	cout << "\nIn-order traversal: ";
    inOrderTraversal(root);

	return 0;
}