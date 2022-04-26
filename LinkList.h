#pragma once

#include <stdlib.h>
#include <stdio.h>

//LinkList
struct Node
{
    int Data;
    struct Node* NextPtr;
}*First; // Global Pointer

void Create(int A[], int N)
{
    int i;
    struct Node* T, *Last;

    First = (struct Node*)malloc(sizeof(struct Node));
    First->Data = A[0];
    First->NextPtr = nullptr;
    Last = First; // Last point points at First

    for (i = 1; i < N; i++)
    {
        T = (struct Node*)malloc(sizeof(struct Node));
        T->Data = A[i];
        T->NextPtr = nullptr; // no Next node yet
        Last->NextPtr = T; // Last Node should point at T
        Last = T; // Last become a new T
    }
}

void Display(struct Node* NodePtr)
{
    while (NodePtr != nullptr)
    {
        printf("%d ", NodePtr->Data);
        NodePtr = NodePtr->NextPtr;
    }
}

int main() 
{
    // Create Array
    int A[] = { 3, 5, 7, 10, 15 };

    // Create LinkList
    Create(A, 5);

    Display(First);

    return 0;
}
