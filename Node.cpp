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
void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    
    head = temp;


}
void insertAtTail(Node* &tail,int data){
    Node* temp  = new Node(data);
    tail->next = temp;
    tail = temp;


}
void deleteAnode(Node* &tail,Node* &head ,int postion){
    Node* temp  = head;
    if(postion==1){
        head= head->next;
       delete temp;
    }
    int cnt=1;
    while(cnt<postion-1){
        temp = temp->next;    
        cnt++;
    }
    Node* temp1 =temp->next;
    if(temp1->next == NULL){
        tail = temp;
    }
    temp->next=temp1->next;
     delete temp1;
}
void insertAtPosition(Node* &tail,Node* &head , int data,int postion){
    if(postion ==1){
        insertAtHead(head,data);
        return ;
    }
    Node* temp  = head;
    int cnt=1;
    while(cnt<postion-1){
        temp = temp->next;
        
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,data);

    }
    Node* temp1 = new Node(data);
    temp1->next = temp->next;
    temp->next = temp1;
    



}
void print(Node* &head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
       temp = temp->next;
    }
    cout<<endl;
    
}
int main()
{
    Node* node1 = new Node(10);
    cout<<node1->data<<endl<<node1->next<<endl;
    Node* head = node1;
    Node* tail = node1;
    //insertAtHead(head,12);
    
    insertAtTail(tail,15);
    print(head);
    insertAtTail(tail,16);
    print(head);
    insertAtPosition(tail,head,14,2);
    print(head);
   
    deleteAnode(tail,head,4);
    print(head);
    cout<<"Head = "<<head->data<<endl;
    cout<<"Tail = "<<tail->data<<endl;
    return 0;
}