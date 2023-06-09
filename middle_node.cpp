#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
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
Node *getMiddle(Node * &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head->next;// for 2 nodes it will be chose second as middle
    }
    Node * fast = head->next;
    Node  * slow = head;
    while(fast != NULL){
        fast =  fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;

}
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
     Node *node1 = new Node(10);
    cout << node1->data << endl
         << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    // insertAtHead(head,12);

    insertAtTail(tail, 15);
    print(head);
    insertAtTail(tail, 16);
    insertAtTail(tail, 17);
     insertAtTail(tail, 18);
    print(head);
    cout<<"Middle of Linded list "<<getMiddle(head)->data<<endl;
    print(head);
return 0;
}