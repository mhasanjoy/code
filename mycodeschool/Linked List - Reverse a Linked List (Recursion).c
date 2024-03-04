#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

void Insert(int data){
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
}

void Print(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse(struct Node* p){
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);

    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    Reverse(head);
    Print();

    return 0;
}
