#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};


void insertAtHead(Node* &head,int d){

  //New node create
  Node* temp = new Node(d);
  temp -> next=head; 
  head = temp;
}
void insertAtTail(Node* &tail,int d){

  //New node create
  Node* temp = new Node(d);
  tail -> next = temp; 
  tail = temp;
}

void print(Node* &head){
    Node* temp=head;
    while (temp!=NULL){
    cout << temp -> data << " ";
    temp =temp->next;
    }
    cout << endl;

}

void insertAtPosition(Node* &head,int position, int data){
    if (position==1)
    {
        insertAtHead(head,data);
        return;
    }
    Node* temp =head;
    int cnt=1;
    while (cnt<position-1){
    temp = temp->next;
    cnt++;}
    //creating new node 
    Node* nodeToInsert= new Node(data);

    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

int main(){
    //creating new node
    Node* head1=new Node(50000);
    cout << head1->data<<endl;
    cout << head1->next<<endl;

    //changing head
    Node* head=head1; 
    insertAtHead(head,100000);
    print(head);
    
    Node* tail=head1;
    insertAtTail(tail,100000);
    insertAtTail(tail,200000);
    insertAtTail(tail,400000);
    insertAtTail(tail,800000);
    insertAtTail(tail,1600000);
    insertAtTail(tail,3200000);
    print(head1);

   insertAtPosition(head1,1,25000);
   print(head1);




}