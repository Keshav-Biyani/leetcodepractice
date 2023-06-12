#include <iostream>
#include <map>
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
bool detectLoop(Node *head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> visited;
    Node* temp = head;
    while (temp!= NULL)       
    {
        if(visited[temp] == true){
            return true;
        }
        visited[temp]= true;
        temp = temp->next;
    }
    return false;
    
}
Node *flauydeLoopdetect(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *fast = head;
    Node  *slow = head;
    while(fast !=NULL && slow != NULL){
        fast = fast->next;
        if(fast!= NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(fast == slow){
            cout<<"Loop found at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;


}
Node *getPoint_intersect(Node* &slow,Node *head,Node * &tail){
    if(head == NULL){
        return NULL;
    }
    Node *fast = head;
    Node *p = NULL;
    while(fast != slow){
        if(fast->next == slow->next){
            p =slow;
        }
        fast = fast->next;
        slow= slow->next;

    }
    tail =p;
    p->next =NULL;
    return fast ;
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
     
     tail->next = head->next->next;
     if(detectLoop(head)){
        cout<<"loop is present"<<endl;
     }
     if(flauydeLoopdetect(head)!= NULL){
        Node * slow = flauydeLoopdetect(head);
        cout<<"Loop is there"<<endl;
        cout<<getPoint_intersect(slow,head,tail)->data<<endl;
     }
     if(detectLoop(head)){
        cout<<"loop is present"<<endl;
     }else{
        cout<<"No Loop";
     }

print(head);
return 0;
}