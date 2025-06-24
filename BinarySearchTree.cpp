#include <iostream>
using namespace std;

class Node
{
    public:
        int info;
        Node *leftchild;
        Node *rightchild;

        //constructor for the node class
        Node()
        {
            leftchild = nullptr; //initialize left child to null
            rightchild = nullptr; // initialize right child to null
        }
};

class BinaryTree
{
    public:
        Node *ROOT;

        BinaryTree()
        {
            ROOT = nullptr; //initializing ROOT to null
        }

    void insert()
    {
        int x;
        cout << "Masukan nilai: ";
        cin >> x;

        Node *newNode = new Node(); //alocate memory for the new node

        newNode->info = x; //assign value to the data field of new node

        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr; //make the left n right child of the new node point to null

        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode); //locate the new node which will be the parent of the node to be inserted

        if (parent == nullptr) // if parent is null (tree is empty)
        {
            ROOT = newNode; //mark te new node as root

            return; // exit
        }

        if (x < parent->info) // if the value in the data field of the new node is less than that of parent
        {
            parent->leftchild = newNode; // make the left child of parent point to the new node

            return; // exit
        }

        else if (x > parent->info) // if the value in the data field of the new node is greater than that of parent
        {
            parent->rightchild = newNode; // make the right child of parent point to the new node

            return; // exit
        }
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr && (currentNode->info != element)))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else 
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node *ptr)
    {
        if(isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }

    void preorder(Node *ptr)
    {
        if(isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postorder(Node *ptr)
    {
        if(isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

    bool isEmpty()
    {
        return ROOT == nullptr; // check if the tree is empty
    }
};