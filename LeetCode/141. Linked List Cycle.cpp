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

bool hasCycle(ListNode* head){
    if(head == NULL){
        return false;
    }
    else{
        ListNode* temp1 = head;

        while(temp1->next != NULL){
            if(temp1->next == temp1){
                return true;
            }
            else{
                temp1 = temp1->next;
                ListNode* temp2 = head;

                while(temp2 != temp1){
                    if(temp1->next == temp2){
                        break;
                    }
                    temp2 = temp2->next;
                }
                if(temp1 != temp2){
                    break;
                }
            }
        }

        if(temp1->next == NULL){
            return false;
        }
        else{
            return true;
        }
    }
}

int main()
{
    ListNode* head = NULL;

    int n, x;
    cout<<"How many numbers?"<<endl;
    cin>>n;
    cout<<"Enter the numbers: ";

    for(int i = 0; i < n; i++){
        cin>>x;
        head = Insert(head, x);
    }
    Print(head);

    bool cycle = hasCycle(head);
    cout<<"Has cycle: "<<cycle<<endl;

    return 0;
}
