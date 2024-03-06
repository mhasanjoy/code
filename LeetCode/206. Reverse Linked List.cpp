#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
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

/*ListNode* reverseList(ListNode* head){
    ListNode *prev = NULL, *current = head, *next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}*/

ListNode* reverseList(ListNode* head){
    ListNode* temp1 = head;

    if(temp1 == NULL || temp1->next == NULL){
        return temp1;
    }

    head = reverseList(temp1->next);
    ListNode* temp2 = temp1->next;
    temp2->next = temp1;
    temp1->next = NULL;

    return head;
}

int main()
{
    ListNode *head = NULL;
    int n, x;

    cout<<"How many numbers?"<<endl;
    cin>>n;
    cout<<"Enter the numbers: ";
    for(int i = 0; i < n; i++){
        cin>>x;
        head = Insert(head, x);
    }

    cout<<"Forward List: ";
    Print(head);

    head = reverseList(head);
    cout<<"Reverse List: ";
    Print(head);

    return 0;
}
