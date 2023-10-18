//
// Created by nava on 18/09/23.
//
#include <stdio.h>
#include <stdlib.h>

#include "CircularQueue.h"

// Variables
int *cqQueue = NULL;
size_t cqSize = 0;
size_t cqElementsNumber = 0;
int cqStart = CQ_ARRAY_START;
int cqEnd = CQ_ARRAY_START;
BOOLEAN isEmpty = TRUE;

void Create(size_t initialSize)
{
    cqSize = initialSize;

    cqQueue = malloc(cqSize * sizeof(int));
    if(!cqQueue)
    {
        printf("Out of memory!");
        exit(-1);
    }
}

void Destroy()
{
    free(cqQueue);
    cqQueue = NULL;
}

BOOLEAN isFull()
{
    return cqStart == cqEnd;
}

BOOLEAN arrayEnd(int who)
{
    return who == cqSize;
}

BOOLEAN deletedAll()
{
    return cqStart == cqEnd;
}

BOOLEAN Add(int value)
{
    if(cqQueue == NULL)
    {
        printf("Queue not initialized!\n");
        exit(-1);
    }
    if(!isEmpty)
    {
        if(isFull())
        {
            ExpandQueue();
            return Add(value);
        }
    }
    else
    {
        isEmpty = FALSE;
    }
    cqQueue[cqEnd] = value;
    cqEnd++;
    if(arrayEnd(cqEnd))
    {
        cqEnd = CQ_ARRAY_START;
    }
    cqElementsNumber++;

    return TRUE;
}

BOOLEAN Remove(int *value)
{
    if(cqQueue == NULL)
    {
        printf("Queue not initialized!\n");
        exit(-1);
    }
    if(isEmpty)
    {
        return FALSE;
    }
    *value = cqQueue[cqStart];
    cqStart++;
    if(arrayEnd(cqStart))
    {
        cqStart = CQ_ARRAY_START;
    }
    if(deletedAll())
    {
        isEmpty = TRUE;
    }
    cqElementsNumber--;

    return TRUE;
}

void printQueue()
{
    if(cqQueue == NULL)
    {
        printf("Queue not initialized!\n");
        exit(-1);
    }

    int i = cqStart;

    if(isEmpty)
    {
        printf("[ ]\n");
    }
    else
    {
        printf("[ ");
        do {
            if(i != cqStart)
            {
                printf(", ");
            }
            printf("%d", cqQueue[i]);
            i++;
            if(arrayEnd(i))
            {
                i = CQ_ARRAY_START;
            }
        } while(i != cqEnd);
        printf(" ]\n");
    }
}

void ExpandQueue()
{
    printf("Expanding...\n");

    size_t newSize = cqSize + 5;
    int *newQueue = NULL;

    newQueue = malloc(newSize * sizeof(int));
    if(!newQueue)
    {
        printf("Out of memory!\n");
        exit(-1);
    }

    for(int i = 0, j = cqStart; i < cqSize; i++)
    {
        newQueue[i] = cqQueue[j];
        j++;
        if(arrayEnd(j))
        {
            j = CQ_ARRAY_START;
        }
    }

    free(cqQueue);
    cqQueue = newQueue;
    cqStart = CQ_ARRAY_START;
    cqEnd = cqSize;
    cqSize = newSize;
}

void ShrinkQueue()
{
    size_t newSize = cqElementsNumber;
    int *newQueue = NULL;

    newQueue = malloc(newSize * sizeof(int));
    if(!newQueue)
    {
        printf("Out of memory!\n");
        exit(-1);
    }

    for(int i = 0, j = cqStart; i < cqElementsNumber; i++)
    {
        newQueue[i] = cqQueue[j];
        j++;
        if(arrayEnd(j))
        {
            j = CQ_ARRAY_START;
        }
    }

    free(cqQueue);
    cqQueue = newQueue;
    cqStart = CQ_ARRAY_START;
    cqEnd = CQ_ARRAY_START;
    cqSize = newSize;
}