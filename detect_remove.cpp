/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
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
            
            return slow;
        }
    }
    return NULL;


}
Node *getPoint_intersect(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *fast = head;
    if (flauydeLoopdetect(head) == NULL) {
    return NULL;
    }
   Node *slow = flauydeLoopdetect(head);
    Node *p = NULL;
    while(fast != slow){
        if(fast->next == slow->next){
            p =slow;
        }
        fast = fast->next;
        slow= slow->next;

    }
    

    return p;
}
Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head == NULL ||  getPoint_intersect(head) == NULL){
        return head;
    }
    Node * intersection = getPoint_intersect(head);
    if(intersection != NULL){
        cout<<intersection->data;
        intersection->next = NULL;
    }
    return head;
}