#include <iostream>
using namespace std;

class bstNode {
public:
    int data;
    bstNode* leftChild;
    bstNode* rightChild;
    bstNode() {
        data = -1;
        leftChild = rightChild = nullptr;
    }
};

class BST {
    bstNode* rootNode;
public:
    BST();
    bstNode* getRootNode();
    bstNode* GetNewNode(int data);
    bstNode* Insert(bstNode* root, int data);
    bool search(bstNode* root, int data);
    void InorderTraversal(bstNode* root);
    void PreorderTraversal(bstNode* root);
    void PostorderTraversal(bstNode* root);
    bstNode* Minimum(bstNode* root);
    bstNode* Maximum(bstNode* root);
    void predecessor(bstNode* root, bstNode* &pred, int key);
    void successor(bstNode* root, bstNode* &succ, int key);
    bstNode* Remove(bstNode* root, int key);
};

BST :: BST() {
    rootNode = nullptr;
}

bstNode* BST :: getRootNode() {
    return rootNode;
}

bstNode* BST :: GetNewNode(int data) {
    auto* newNode = new bstNode();
    newNode->data = data;
    return newNode;
}

bstNode* BST :: Insert(bstNode* root, int data) {

    //if the tree is empty
    if (root == nullptr)
        root = GetNewNode(data);

    // if the value to be inserted is lesser that the data of root, insert in left subtree
    else if (data <= root->data)
        root->leftChild = Insert(root->leftChild, data);

    // else insert in right subtree
    else
        root->rightChild = Insert(root->rightChild, data);

    return root;
}

bool BST :: search(bstNode *root, int data) {

    // if the root is empty, return false
    if (root == nullptr)
        return false;

    // if the data is same as data at root, return true
    else if (root->data == data)
        return true;

    // if the value to be searched is less than the value at root, search left tree
    else if (data < root->data)
        return search(root->leftChild, data);

    // if the value to be searched is greater than the value at root, search right tree
    else
        return search(root->rightChild, data);
}

void BST :: InorderTraversal(bstNode *root) {

    if (root == nullptr)
        return;

    InorderTraversal(root->leftChild);
    cout<<root->data<<" ";
    InorderTraversal(root->rightChild);
}

void BST :: PreorderTraversal(bstNode *root) {
    if (root == nullptr)
        return;

    cout<<root->data<<" ";
    PreorderTraversal(root->leftChild);
    PreorderTraversal(root->rightChild);
}

void BST :: PostorderTraversal(bstNode *root) {
    if (root == nullptr)
        return;

    PostorderTraversal(root->leftChild);
    PostorderTraversal(root->rightChild);
    cout<<root->data<<" ";
}

bstNode* BST :: Minimum(bstNode *root) {
    while (root->leftChild != nullptr)
        root = root->leftChild;
    return root;
}

bstNode* BST :: Maximum(bstNode *root) {
    while(root->rightChild != nullptr)
        root = root->rightChild;
    return root;
}

void BST :: predecessor(bstNode *root, bstNode* &pred, int key) {

    if (root == nullptr) {
        pred = nullptr;
        return;
    }
    // if the node with given value is found, predecessor is the maximum value in left subtree of that node
    else if (root->data == key) {
        if (root->leftChild)
            pred = Maximum(root->leftChild);
    }

    // if given value is less than value at root node, look in the left subtree
    else if (key < root->data) {
        predecessor(root->leftChild, pred, key);
    }

    // if given value is greater than value at root node, look in the right subtree
    else {
        pred = root; // update the predecessor as current node
        predecessor(root->rightChild, pred, key);
    }
}

void BST::successor(bstNode *root, bstNode *&succ, int key) {
    if (root == nullptr) {
        succ = nullptr;
        return;
    }

    // if the node with given value is found, successor is the minimum value in right subtree of that node
    else if (root->data == key) {
        if (root->rightChild)
            succ = Minimum(root->rightChild);
    }

    // if given value is less than value at root node, look in the left subtree
    else if (key < root->data) {
        succ = root; // update the successor as current node
        successor(root->leftChild, succ, key);
    }

    // if given value is greater than value at root node, look in the right subtree
    else {
        successor(root->rightChild, succ, key);
    }
}

bstNode *BST :: Remove(bstNode *root, int key) {

    // base case
    if (root == nullptr)
        return root;

    // if given value is less than value at root node, recur for left subtree
    else if (key < root->data) {
        root->leftChild = Remove(root->leftChild, key);
    }

    // if given value is greater than value at root node, recur for right subtree
    else if (key > root->data) {
        root->rightChild = Remove(root->rightChild, key);
    }

    // if the given key is same as the value at root node
    else {
        // if the left child is null
        // that mean the node has either only right child or no child
        if (root->leftChild == nullptr) {
            bstNode* temp = root->rightChild;
            free(root);
            return temp;
        }

        // if the right child is null
        // that mean the node has either only left child or no child
        else if (root->rightChild == nullptr) {
            bstNode* temp = root->leftChild;
            free(root);
            return temp;
        }

        // if the node has two children
        // get the successor of the node (minimum value in the right subtree)
        bstNode* temp = Minimum(root->rightChild);

        // copy the successor's value in the root's value
        root->data = temp->data;

        // delete the successor
        root->rightChild = Remove(root->rightChild, temp->data);
    }
    return root;
}


int main() {

    BST tree;
    bstNode* root = tree.getRootNode();

    while (true) {
        cout<<"\nMENU: \n1.Insert into Tree \n2.In-order Traversal \n3.Pre-order Traversal \n4.Post-order Traversal \n5.Search element \n6. Find Minimum element \n7.Find Maximum element \n8.Find Successor of any element \n9.Find Predecessor of any element \n10.Delete Element \n11.Quit.";
        cout<<"\nEnter your choice : ";
        int menu_choice;
        cin>>menu_choice;

        switch (menu_choice) {

            //Insert
            case 1:
                cout << "\nValues will be taken from random function to insert into tree!";
                cout << "\nHow many values do you want to insert? ";
                int n;
                cin >> n;
                while (n--) {
                    int value = rand()%1000;
                    root = tree.Insert(root, value);
                    cout << "Inserted "<<value<<"\n";
                }
                break;

            //Inorder Traversal
            case 2:
                cout << "In-order Traversal : \n";
                tree.InorderTraversal(root);
                cout << "\n";
                break;

            //Preorder Traversal
            case 3:
                cout << "Pre-order Traversal : \n";
                tree.PreorderTraversal(root);
                cout << "\n";
                break;
                
            //Postorder traversal
            case 4:
                cout << "Post-order Traversal : \n";
                tree.PostorderTraversal(root);
                cout << "\n";
                break;

            //search
            case 5: {
                cout << "Enter the element to be searched : ";
                int key;
                cin >> key;
                bool search_flag = tree.search(root, key);
                if (search_flag)
                    cout << key << " is present in Tree.\n";
                else
                    cout << key << " is not present in Tree.\n";
                break;
            }

            //minimum
            case 6: {
                bstNode* node = tree.Minimum(root);
                if (node) 
                    cout << "Minimum element in the Tree is : " << node->data << "\n";
                else
                    cout << "Tree is Empty!\n";
                break;
            }
                
            //maximum
            case 7: {
                bstNode* node = tree.Maximum(root);
                if (node)
                    cout << "Maximum element in the Tree is : " << node->data << "\n";
                else
                    cout << "Tree is Empty!\n";
                break;
            }

            //successor
            case 8: {
                cout << "Enter the element whose successor is to be searched : ";
                int key;
                cin >> key;
                bstNode* succ = nullptr;
                tree.successor(root, succ, key);
                
                if (succ != nullptr)
                    cout << "Successor of " << key << " is : " << succ->data << "\n";
                else
                    cout << "Successor not present. \n";
                break;
            }
                
            //predecessor
            case 9: {
                cout << "Enter the element whose predecessor is to be searched : ";
                int key;
                cin >> key;
                bstNode* pred = nullptr;
                tree.predecessor(root, pred, key);

                if (pred != nullptr)
                    cout << "Predecessor of " << key << " is : " << pred->data << "\n";
                else
                    cout << "Predecessor not present. \n";
                break;
            }

            //delete
            case 10: {
                cout << "Enter element to be deleted : ";
                int key;
                cin>>key;

                root = tree.Remove(root, key);
                break;
            }

            //quit
            case 11:
                return 0;

            default:
                cout << "Invalid Option! Try again. \n";
        }
    }
}
