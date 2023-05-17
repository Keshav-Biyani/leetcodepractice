#include<iostream>
using namespace std;
class Node {
public:
    int data ;
    Node* next;
    Node* prev;
    Node(int data){
        this->data= data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next!= NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free with data "<<val<<endl;

    }
};
void insertAttail(Node* &tail,Node* &head,int data){
     if(tail== NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}
void insertatHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{

    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}
void insertAtPostion(Node* &tail,Node* &head,int data,int postion){
   
      if(postion ==1){
        insertatHead(tail,head,data);
        return ;
    }
     Node* temp  = head;
    int cnt=1;
    while(cnt<postion-1){
        temp = temp->next;
        
        cnt++;
    }
    if(temp->next == NULL){
        insertAttail(tail,head,data);
        return ;
    }
     Node* temp1 = new Node(data);
    temp1->next = temp->next;
    temp1->next ->prev = temp1; 
    temp1->prev = temp;
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
int getLength(Node* &head){
    int len =0;
    Node* temp = head;
    while (temp != NULL)
    {
     len++;
       temp = temp->next;
    }
   
    return len;
}
void deleteAnode(Node* &tail,Node* &head ,int postion){
    Node* temp  = head;
    if(postion==1){
        head= head->next;
        head->prev = NULL;
        temp->next =NULL;
       delete temp;
       return ;
    }
    int cnt=1;
    while(cnt<postion-1){
        temp = temp->next;    
        cnt++;
    }
    Node* temp1 =temp->next;
    if(temp1->next == NULL){
        tail = temp;
        temp->next =NULL;
        delete temp1;
        return ;
    }
    temp->next=temp1->next;
    temp1->next->prev = temp;

     delete temp1;
}

int main()
{
    // Node* node1 = new Node(5);
    Node* head = NULL;
    Node* tail = NULL;
    insertatHead(tail,head,10);
    print(head);
    insertAttail(tail,head,15);
    print(head);
    insertAttail(tail,head,25);
    print(head);
    insertAtPostion(tail,head,27,4);
    print(head);
    cout<<getLength(head)<<endl;
    deleteAnode(tail,head,1);
    print(head);
    cout<<getLength(head)<<endl;
    cout<<endl;
    cout<<"Head"<<head->data<<endl;
    cout<<"Tail"<<tail->data<<endl;
    return 0;
}