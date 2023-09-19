//
// Created by nava on 18/09/23.
//
#include <stdio.h>

#include "CircularQueue.h"

// Variables
int cqQueue[CQ_SIZE];
int cqStart = CQ_ARRAY_START;
int cqEnd = CQ_ARRAY_START;
BOOLEAN isEmpty = TRUE;

BOOLEAN isFull()
{
    return cqStart == cqEnd;
}

BOOLEAN arrayEnd(int who)
{
    return who == CQ_SIZE;
}

BOOLEAN deletedAll()
{
    return cqStart == cqEnd;
}

BOOLEAN Add(int value)
{
    if(!isEmpty)
    {
        if(isFull())
        {
            return FALSE;
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

    return TRUE;
}

BOOLEAN Remove(int *value)
{
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

    return TRUE;
}

void printQueue()
{
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
