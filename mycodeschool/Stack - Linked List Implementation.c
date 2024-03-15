#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop(){
    struct Node* temp = top;
    if(top == NULL){
        return;
    }
    top = top->next;
    free(temp);
}

void Print(struct Node* temp){
    if(temp == NULL){
        return;
    }
    Print(temp->next);
    printf(" %d", temp->data);
}

int main()
{
    Push(2);
    Push(5);
    Push(10);
    Pop();
    Push(12);

    printf("Stack:");
    Print(top);
    printf("\n");

    return 0;
}
