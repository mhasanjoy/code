#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;

void Insert(int x){
    Node* temp1 = new Node();
    temp1->data = x;
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

    cout<<"List is:";
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    head = NULL;

    int n, x;
    cout<<"How many numbers?"<<endl;
    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<"Enter the number: ";
        cin>>x;
        Insert(x);
        Print();
    }

    return 0;
}
