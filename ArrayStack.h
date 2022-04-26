#pragma once

#include <stdlib.h>
#include <stdio.h>

//Stack LIFO: Last-in First-out
struct Stack
{
    int Size;
    int Top;
    int* S;
};

void Create(struct Stack* St)
{
    printf("Enter Size");
    scanf_s("%d ", &St->Size);
    St->Top = -1;
    St->S = (int*)malloc(St->Size * sizeof(int));
}

void Display(struct Stack St)
{
    int i;
    for (i = St.Top; i >= 0; i--)
    {
        printf("%d ", St.S[i]);
    }
    printf("\n");
}

void Push(struct Stack* St, int x)
{
    if (St->Top == St->Size - 1)
    {
        printf("Stack overflow\n ");
    }
    else
    {
        St->Top++;
        St->S[St->Top] = x;
    }
}

int Pop(struct Stack* St)
{
    int x = -1;
    if (St->Top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = St->S[St->Top--];

    }
    return x;
}

int Peek(struct Stack St, int Index)
{
    int x = -1;
    if (St.Top - Index + 1 < 0)
    {
        printf("Invalid Index \n ");
    }
    x = St.S[St.Top - Index + 1];

    return x;
}

int IsEmpty(struct Stack St)
{
    if (St.Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct Stack St)
{
    return St.Top == St.Size - 1;
}


int StackTop(struct Stack St)
{
    if (!IsEmpty(St))
    {
        return St.S[St.Top];

    }
    else
    {
        return -1;
    }
}



int main() 
{
    struct Stack St;
    Create(&St);

    Push(&St, 10);
    Push(&St, 20);
    Push(&St, 30);
    Push(&St, 40);

    printf("%d \n", Peek(St, 2));

    Display(St);

    return 0;
}
