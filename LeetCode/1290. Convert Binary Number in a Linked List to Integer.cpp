#include<iostream>
#include<cmath>
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

int getDecimalValue(){
    Node* temp = head;
    int item = 0, value = 0;

    while(temp != NULL){
        item++;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        item--;
        value = value + temp->data * pow(2, item);
        temp = temp->next;
    }

    return value;
}

int main()
{
    head = NULL;

    int n, x;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x;
        Insert(x);
    }
    Print();

    int value = getDecimalValue();
    cout<<value<<endl;

    return 0;
}
