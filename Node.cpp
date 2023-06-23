#include <iostream>
#include<map>
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
        head = head->next; // 5->6.NULL
        temp->next = NULL;
        delete temp;
    }
    else
    {
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
        temp->next = temp1->next; // 6-next=7-next
        temp1->next = NULL;
        delete temp1;
    }
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
int getLength(Node* head){
    Node *temp = head;
    int cnt =0;
    while (temp != NULL){
        temp= temp->next;
        cnt++;
    }
    return cnt;


}

Node *findMiddle(Node *head) {
    // Write your code here
    int len =getLength(head);
    int mid = len/2;
    Node *temp = head;
    int cnt =0;
    while(cnt<mid){
        temp = temp->next;
        cnt++;
    }

    return temp;
}
 Node * middle(Node * head){
        Node *slow = head;
        Node * fast = head->next;
        while(fast-> next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL){
                fast= fast->next;
            }
        }
        cout<<slow->next->data;
        return slow;
    }
    Node * reverse(Node* curr,Node* prev){
        
        
        Node * next1 = NULL;
        while(curr->next != NULL){
        next1= curr->next;
        curr-> next =prev;
        prev = curr;
        curr = next1;
        }

        return curr;
    }
    //Function to check whet
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node * mid =middle(head);
        mid->next =reverse( mid->next,NULL);
        Node* pre = mid->next;
        Node * curr = head;
        while(pre  != NULL){
            if(curr->data != pre-> data){
                return false;
                
            }else{
                curr = curr->next;
                pre = pre->next;
            }
        }
        return true;
        
    }
Node *removeDuplicates(Node *head)
{
    // Write your code here
    map<int,bool> visited;
    Node * curr =head ;
    Node * prev = NULL;
    
    while(curr !=NULL){
        if(   visited[curr->data] == true){
            prev->next = curr->next;
            cout<<"prev "<<prev->data<<endl;
        }
        else{
            visited[curr->data]= true;
            prev =curr;
        }
        curr = prev->next;
    }

    return head;

}
int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl
         << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    // insertAtHead(head,12);
insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    print(head);
      insertAtTail(tail, 14);
        insertAtTail(tail, 14);
    insertAtTail(tail, 12);
    insertAtTail(tail, 11);
  insertAtTail(tail, 10);
    print(head);
    //insertAtPosition(tail, head, 14, 2);
    print(head);

    // deleteAnode(tail, head, 4);

    // deleteAnode(tail, head, 1);
    print(head);
    cout<<isPalindrome(head)<<endl;
    Node * middle = findMiddle(head);
    cout<<"Middle "<<middle->data<<endl;
       print(head);
    removeDuplicates(head);
    print(head);

    cout << "Head = " << head->data << endl;
    cout << "Tail = " << tail->data << endl;
    return 0;
}