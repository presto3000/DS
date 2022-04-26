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
void RecursiveDisplay(struct Node* NodePtr)
{
    if (NodePtr != nullptr)
    {
        RecursiveDisplay(NodePtr->NextPtr);
        printf("%d ", NodePtr->Data);
    }
}


int Count(struct Node* NodePtr)
{
    int l = 0;
    while (NodePtr)
    {
        l++;
        NodePtr = NodePtr->NextPtr;
    }
    return l;
}
int RCount(struct Node* NodePtr)
{
    if (NodePtr)
        return RCount(NodePtr->NextPtr) + 1;
    else
        return 0;
};

int Sum(struct Node* NodePtr)
{
    int s = 0;
    while (NodePtr)
    {
        s += NodePtr->Data;
        NodePtr = NodePtr->NextPtr;

    }
    return s;
}
int RSum(struct Node* NodePtr)
{
    if (NodePtr == nullptr)
    {
        return 0;
    }
    else
        return RSum(NodePtr->NextPtr) + NodePtr->Data;
}

int Max(struct Node* NodePtr)
{
    int Max = 0;

    while (NodePtr)
    {
        if (NodePtr->Data > Max)
        {
            Max = NodePtr->Data;
        }
        NodePtr = NodePtr->NextPtr;
    }
    return Max;
}

int RMax(struct Node* NodePtr)
{
    int X = 0;
    if (NodePtr == nullptr)
    {
        return SHRT_MIN;
    }
    X = RMax(NodePtr->NextPtr);
    if (X > NodePtr->Data)
    {
        return X;
    }
    else
    {
        return NodePtr->Data;
    }
}
int main() 
{
    // Create Array
    int A[] = { 3, 5, 7, 10, 15 };

    // Create LinkList
    Create(A, 5);

    //Display(First);
    //RecursiveDisplay(First);
    //printf("Legth is %d", RCount(First));
    //printf(" Sum is %d\n\n", RSum(First));
    printf(" Max is %d\n\n", RMax(First));

    return 0;
}
