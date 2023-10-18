//
// Created by nava on 18/09/23.
//

#ifndef DAYNAMICCIRCULARQUEUE_CIRCULARQUEUE_H
#define DAYNAMICCIRCULARQUEUE_CIRCULARQUEUE_H

#include "Boolean.h"

// Constants
enum {
    CQ_ARRAY_START = 0
};

// Variables
extern int *cqQueue;
extern size_t cqSize;
extern size_t cqElementsNumber;
extern int cqStart;
extern int cqEnd;
extern BOOLEAN isEmpty;

// Prototypes
void Create(size_t initialSize);
void Destroy();
BOOLEAN Add(int value);
BOOLEAN Remove(int *value);
BOOLEAN isFull();
BOOLEAN arrayEnd(int who);
BOOLEAN deletedAll();
void printQueue();
void ExpandQueue();
void ShrinkQueue();

#endif //DAYNAMICCIRCULARQUEUE_CIRCULARQUEUE_H
