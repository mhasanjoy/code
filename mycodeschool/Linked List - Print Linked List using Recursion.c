#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Insert(struct Node* head, int data){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if(head == NULL){
        head = temp1;
    }
    else{
        struct Node* temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }

    return head;
};

void Print(struct Node* head){
    if(head == NULL){
        return;
    }
    printf("%d ", head->data);
    Print(head->next);
}

void ReversePrint(struct Node* head){
    if(head == NULL){
        return;
    }
    ReversePrint(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node* head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    printf("\n");
    ReversePrint(head);
    printf("\n");

    return 0;
}
