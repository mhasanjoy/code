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

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* temp1 = head;
    int sz = 0, flag = 0;

    while(temp1 != NULL){
        sz++;
        temp1 = temp1->next;
    }

    temp1 = head;
    while(1){
        if(n == sz){
            head = temp1->next;
            delete temp1;
            break;
        }
        else{
            flag++;
            if(flag == sz - n){
                ListNode* temp2 = temp1->next;
                temp1->next = temp2->next;
                delete temp2;
                break;
            }
            temp1 = temp1->next;
        }
    }

    return head;
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

    head = removeNthFromEnd(head, 1);
    Print(head);

    return 0;
}
