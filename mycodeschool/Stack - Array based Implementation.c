#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE], top = -1;

void Push(int x){
    if(top == MAX_SIZE - 1){
        printf("Error: stack overflow.\n");
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        printf("Error: No element to pop.\n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void Print(){
    int i;
    printf("Stack:");
    for(i = 0; i <= top; i++){
        printf(" %d", A[i]);
    }
    printf("\n");
}

int main()
{
    Push(2);
    Push(5);
    Push(10);
    Pop();
    Push(12);
    Print();

    return 0;
}
