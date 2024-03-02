#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void Insert(int data){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if(head == NULL){
        head = temp1;
    }
    else{
        Node* temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void Print(){
    Node* temp = head;
    cout<<"List:";
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

void Reverse(){
    Node *prev = NULL, *current = head, *next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();
    Reverse();
    Print();

    return 0;
}
