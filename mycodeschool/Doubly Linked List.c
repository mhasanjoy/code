#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;

struct Node* GetNewNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int data){
    struct Node* newNode = GetNewNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void InsertAtTail(int data){
    struct Node* newNode = GetNewNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void Print(){
    struct Node* temp = head;
    printf("Forward:");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint(){
    struct Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    printf("Reverse:");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    /*InsertAtHead(2);
    Print();
    ReversePrint();

    InsertAtHead(4);
    Print();
    ReversePrint();

    InsertAtHead(6);
    Print();
    ReversePrint();*/

    InsertAtTail(2);
    Print();
    ReversePrint();

    InsertAtTail(4);
    Print();
    ReversePrint();

    InsertAtTail(6);
    Print();
    ReversePrint();

    return 0;
}
