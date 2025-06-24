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
    }
}