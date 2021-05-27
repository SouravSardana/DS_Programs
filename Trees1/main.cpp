// Inoreder, Preorder, Postorder (with & without recursion)
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    int data;
    Node* right;
    Node(int k)
    {
        left = NULL;
        data = k;
        right = NULL;
    }
};
void inorder(Node* root)  //Inorder without recursion
{
    stack<Node *> s;
    Node* current = root;
    while(current!= NULL || s.empty()==false)
    {
        while(current!=NULL)
        {
            s.push(current);
            current = current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
}
void preorder(Node *root)
{
    stack<Node*> s;
    Node* current = root;
    while(current!= NULL || s.empty()==false)
    {
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            s.push(current);
            current = current->left;
        }
        current=s.top();
        s.pop();
        current=current->right;
    }
}
void postorder(Node* root)
{
    Node* current = root;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(current);
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
        if(current->left!=NULL)
            s1.push(current->left);
        if(current->right!=NULL)
            s1.push(current->right);
        if(!s1.empty())
            current=s1.top();
    }
    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
void preorder_rec(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder_rec(root->left);
    preorder_rec(root->right);
}
void inorder_rec(Node* root) //Inorder with recursion
{
    if(root==NULL)
        return;
    inorder_rec(root->left);
    cout<<root->data<<" ";
    inorder_rec(root->right);
}
void postorder_rec(Node* root)
{
    if(root==NULL)
        return;
    postorder_rec(root->left);
    postorder_rec(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right=new Node(50);
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->right= new Node(30);
    root->right->left= new Node(60);
    root->right->right = new Node(70);
    cout<<"INORDER: ";
    inorder(root);
    cout<<endl;
    cout<<"PREORDER: ";
    preorder(root);
    cout<<endl;
    cout<<"POSTORDER: ";
    postorder(root);
    cout<<endl;
    cout<<"PREORDER WITH RECURSION: ";
    preorder_rec(root);
    cout<<endl;
    cout<<"INORDER WITH RECURSION: ";
    inorder_rec(root);
    cout<<endl;
    cout<<"POSTORDER WITH RECURSION: ";
    postorder_rec(root);
    return 0;
}
