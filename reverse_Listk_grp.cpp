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
};

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
void deleteAnode(Node *&tail, Node *&head, int postion)
{
    Node *temp = head;
    if (postion == 1)
    {
        head = head->next;
        delete temp;
    }
    int cnt = 1;
    while (cnt < postion - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *temp1 = temp->next;
    if (temp1->next == NULL)
    {
        tail = temp;
    }
    temp->next = temp1->next;
    delete temp1;
}
void insertAtPosition(Node *&tail, Node *&head, int data, int postion)
{
    if (postion == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < postion - 1)
    {
        temp = temp->next;

        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
    }
    Node *temp1 = new Node(data);
    temp1->next = temp->next;
    temp->next = temp1;
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
void reverse_list(Node *&head, Node *&tail, Node *&curr, Node *&prev,Node *&next2)
{

    // curr->next= head;
    // next1->next= curr;
    // head->next=NULL;
    // head = next1;
    if (curr == NULL ||  next2== curr )
    {
        // cout<<next2->data<<endl;
        tail = head;
        head = prev;
        cout<<"1"<<endl;
        print(head);
        return;
    }
    
    Node *next1 = curr->next;
    curr->next = prev;
    reverse_list(head, tail, next1, curr,next2);
}



Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head == NULL ||head->next == NULL){
        return head;
    }
    Node* tail = head;
    int cnt =1;
    while(cnt<k && tail->next!= NULL){
        tail = tail->next;
        cnt++;
    }
    cout<<tail->data<<endl;
    Node *curr = head;
    Node *prev = NULL;
    Node *next2 = tail->next;
    
    reverse_list(head, tail, curr, prev,next2 );
    Node *chotalist = kReverse(next2 ,k);
    tail->next= chotalist;
    return head;

}
int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
   // Node *tail = node1;ff
    insertAtHead(head, 12);

    insertAtHead(head, 15);
    print(head);
    insertAtHead(head, 16);
     insertAtHead(head, 17);
    print(head);
    Node *curr = head;
    Node *prev = NULL;
    Node * p = kReverse(head,3);
    cout << "reverse list ";
    print(p);

    // cout << "Head = " << head->data << endl;
    // cout << "Tail = " << tail->data << endl;
    return 0;
}