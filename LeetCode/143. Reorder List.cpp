#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* Insert(ListNode* head, int data){
    ListNode* temp1 = new ListNode();
    temp1->val = data;
    temp1->next = NULL;

    if(head == NULL){
        head = temp1;
    }
    else{
        ListNode* temp2 = head;

        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }

    return head;
}

void Print(ListNode* head){
    ListNode* temp = head;
    cout<<"List:";

    while(temp != NULL){
        cout<<" "<<temp->val;
        temp = temp->next;
    }
    cout<<endl;
}

void reorderList(ListNode* head){
    ListNode* temp1 = head;

    while(temp1->next != NULL && temp1->next->next != NULL){
        ListNode* temp2 = temp1->next;

        while(temp2->next->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next->next = temp1->next;
        temp1->next = temp2->next;
        temp2->next = NULL;
        temp1 = temp1->next->next;
    }
}

int main()
{
    ListNode* head = NULL;

    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    head = Insert(head, 5);
    Print(head);

    reorderList(head);
    Print(head);

    return 0;
}
