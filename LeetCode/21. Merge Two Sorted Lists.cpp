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
    while(temp != NULL){
        cout<<" "<<temp->val;
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode *head = NULL, *temp1 = NULL, *temp2 = NULL;

    if(list1 != NULL && list2 != NULL){
        if(list1->val <= list2-> val){
            head = list1;
            temp1 = list1;
            temp2 = list2;
        }
        else{
            head = list2;
            temp1 = list2;
            temp2 = list1;
        }

        while(1){
            if(temp1->next == NULL){
                temp1->next = temp2;
                break;
            }
            if(temp2 == NULL){
                break;
            }

            if(temp1->next->val > temp2->val){
                ListNode* temp3 = temp2->next;
                temp2->next = temp1->next;
                temp1->next = temp2;
                temp1 = temp2;
                temp2 = temp3;
            }
            else{
                temp1 = temp1->next;
            }
        }
    }
    else if(list1 != NULL){
        head = list1;
    }
    else if(list2 != NULL){
        head = list2;
    }

    return head;
}

int main()
{
    ListNode *list1 = NULL, *list2 = NULL;

    list1 = Insert(list1, 1);
    list1 = Insert(list1, 2);
    list1 = Insert(list1, 4);
    cout<<"List 1:";
    Print(list1);

    list2 = Insert(list2, 1);
    list2 = Insert(list2, 3);
    list2 = Insert(list2, 4);
    cout<<"List 2:";
    Print(list2);

    ListNode* head = mergeTwoLists(list1, list2);
    cout<<"Merged List:";
    Print(head);

    return 0;
}
