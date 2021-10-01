#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *leftChild, *rightChild;
    int height;
};

class avlTree {

public:
    Node* getNewNode(int data);
    int balanceFactor(Node *node);
    int height(Node *node);
    Node* leftRotate(Node *node);
    Node* rightRotate(Node *node);
    Node* Insert(Node *root, int data);
    void InOrderTraversal(Node *root);
    Node* Minimum(Node *node);
    Node* Remove(Node *root, int key);
};

// Function to create new node
Node *avlTree::getNewNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->height = 1;
    return newNode;
}

// Function to calculate balance factor of given node
int avlTree::balanceFactor(Node *node) {
    if (node == nullptr)
        return 0;
    return (height(node->leftChild) - height(node->rightChild));
}

// Function to return height of given node
int avlTree::height(Node *node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Function to left rotate around given node
Node *avlTree::leftRotate(Node *node) {

    Node *x = node->rightChild;
    Node *y = x->leftChild;

    // rotate
    x->leftChild = node;
    node->rightChild = y;

    // update height
    node->height = max(height(node->leftChild), height(node->rightChild)) + 1;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;

    // return new root
    return x;
}

// Function to right rotate around given node
Node *avlTree::rightRotate(Node *node) {

    Node *x = node->leftChild;
    Node *y = x->rightChild;

    // rotate
    x->rightChild = node;
    node->leftChild = y;

    // update height
    node->height = max(height(node->leftChild), height(node->rightChild)) + 1;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;

    // return new root
    return x;
}

// Function to insert new node in a tree
Node *avlTree::Insert(Node *root, int data) {

    // BST Insertion
    if (root == nullptr)
        return (getNewNode(data));
    else if (data < root->data)
        root->leftChild = Insert(root->leftChild, data);
    else if (data > root->data)
        root->rightChild = Insert(root->rightChild, data);
    else
        return root;

    // update the height
    root->height = max(height(root->leftChild), height(root->rightChild)) + 1;

    // balance factor (to check if the node is unbalanced)
    int b = balanceFactor(root);

    // left left case or left right case
    if (b > 1) {
        // left left case
        if (data < root->leftChild->data)
            return rightRotate(root);

        // left right case
        if (data > root->leftChild->data){
            root->leftChild = leftRotate(root->leftChild);
            return rightRotate(root);
        }
    }

    // right right case or right left case
    if (b < -1) {
        // right right case
        if (data > root->rightChild->data)
            return leftRotate(root);

        // right left case
        if (data < root->rightChild->data) {
            root->rightChild = rightRotate(root->rightChild);
            return leftRotate(root);
        }
    }

    return root;
}

// Inorder Traversal of tree
void avlTree::InOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    InOrderTraversal(root->leftChild);
    cout << root->data << " ";
    InOrderTraversal(root->rightChild);
}

// Function to find minimum-date node in given-node-rooted tree
Node *avlTree::Minimum(Node *node) {
    if (node == nullptr)
        return nullptr;
    while (node->leftChild != nullptr)
        node = node->leftChild;
    return node;
}

// Function to remove given key from tree
Node *avlTree::Remove(Node *root, int key) {

    // BST Deletion
    if (root == nullptr)
        return root;

    // if the key is less than root, search left subtree
    else if (key < root->data)
        root->leftChild = Remove(root->leftChild, key);

    // if the key is greater than root, search right subtree
    else if (key > root->data)
        root->rightChild = Remove(root->rightChild, key);

    // if the root data is same as key (i.e., root is to be deleted)
    else{
        // if the node has either one child or no child
        if (root->leftChild == nullptr || root->rightChild == nullptr) {
            Node* temp = root->leftChild ? root->leftChild : root->rightChild;

            // no child case
            if (temp == nullptr){
                temp = root;
                root = nullptr;
            }
            // one child
            else {
                *root = *temp;
            }
            free(temp);
        }
        // if the node has two children
        else {

            // get the successor of the node (minimum value in the right subtree)
            Node *temp = Minimum(root->rightChild);

            // copy the successor's value in the root's value
            root->data = temp->data;

            // delete the successor
            root->rightChild = Remove(root->rightChild, temp->data);
        }
    }

    // if the tree had only one node initially, i.e., current root is null
    if (root == nullptr)
        return root;

    // Update height
    root->height = max(height(root->leftChild), height(root->rightChild)) + 1;

    // Balance factor to check if the node is unbalanced
    int b1 = balanceFactor(root);

    // left left case or left right case
    if (b1 > 1) {
        // balance factor of left subtree
        int b2 = balanceFactor(root->leftChild);

        // left left case
        if (b2 >= 0)
            return rightRotate(root);

        // left right case
        if (b2 < 0) {
            root->leftChild = leftRotate(root->leftChild);
            return rightRotate(root);
        }
    }

    // right right case or right left case
    if (b1 < -1) {
        // balance factor of right subtree
        int b2 = balanceFactor(root->rightChild);

        // right right case
        if (b2 <= 0)
            return leftRotate(root);

        // right left case
        if (b2 < 0) {
            root->rightChild = rightRotate(root->rightChild);
            return leftRotate(root);
        }
    }

    return root;
}

/********************************** DRIVER CODE **********************************/

int main() {
    Node *root = nullptr;
    avlTree tree;

    bool exit_status = false;
    while (!exit_status) {
        // MENU
        cout << "\nMENU: \n1. Insert element \n2. Delete Element \n3. Inorder Traversal \n4. Quit";
        cout << "\nEnter your choice : ";
        char choice;
        cin >> choice;

        switch (choice) {

            // Insert element
            case '1':
                cout << "Enter the value to be inserted : ";
                int data;
                cin >> data;
                root = tree.Insert(root, data);
                cout << "\nOperation performed!\n";
                break;

            // delete element
            case '2':
                cout << "Enter the key to be deleted : ";
                int key;
                cin >> key;
                root = tree.Remove(root, key);
                cout << "\nOperation performed!\n";
                break;

            // Inorder traversal
            case '3':
                cout << "\nInorder Traversal : \n";
                tree.InOrderTraversal(root);
                cout << endl;
                break;

            // exit
            case '4':
                exit_status = true;
                break;

            default:
                cout << "\nInvalid Input! Try Again.\n";
        }
    }
    return 0;
}
