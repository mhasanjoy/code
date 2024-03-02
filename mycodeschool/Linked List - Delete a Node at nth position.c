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

void Delete(int n){
    struct Node* temp1 = head;

    if(n == 1){
        head = temp1->next;
        free(temp1); //delete temp1;
    }
    else{
        int i;
        for(i = 0; i < n - 2; i++){
            temp1 = temp1->next;
        }

        struct Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    head = NULL;

    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);

    Print();

    int n;
    printf("Enter a position: ");
    scanf("%d", &n);
    Delete(n);

    Print();

    return 0;
}
