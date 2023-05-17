#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free with datv" << value << endl;
    }
};
void insertNode(Node* &tail,int data,int element){
    if(tail== NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* currNode = tail;
        while (currNode->data !=  element )
        {
            currNode = currNode->next;

        }
        Node* cNode = new Node(data);
        cNode->next = currNode->next;
        currNode->next = cNode;


        

    }
}
void print(Node* &tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp= temp->next;

    }
    while (temp!=tail);
    
    cout<<endl;
    
    
    
}
int main()
{
    Node* tail = NULL;
    insertNode(tail,5,2);
    print(tail);
    insertNode(tail,2,5);
    print(tail);
    insertNode(tail,4,2);
    print(tail);
    return 0;
}