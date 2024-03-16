#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "header.h"

/* Configurations */
#define LLEntry Client
#define MAXSEATS 401
/* LinkedList */
typedef struct linkedlistnode
{
    Client data;
    struct linkedlistnode *Next;
    struct linkedlistnode *Prev;
} LLNode;

typedef struct LINKEDLIST
{
    LLNode *top;
    int SIZE;
    int LastID;
    int seats[MAXSEATS];
} LinkedList;

void CreateLinkedList(LinkedList *Pll); // function to create the linkedlist

void CreatNode(LLEntry data, LinkedList *Pll, int Position); // function to create a node in the linked list

void LastNode(LLEntry data, LinkedList *Pll); // function to send node to bottom of the list

void RemoveNode(LLEntry *data, LinkedList *Pll, int Position); // function to remove node

char ListFull(LinkedList *Pll); // return 1 if the list is full or return 0 if the list is not full
                                // but will alwyas return 0 as the heap cant be full

int ListSize(LinkedList *Pll); // function to return size
                               //  not used in the program but was used for some test cases

void ClearList(LinkedList *Pll); // function to clear list

LLNode *PassngerNode(LinkedList *Pll); // function to search for a passenger using ID

void Swap(LLNode *node1, LLNode *node2); // function to swap nodes using third temporary pointer

#endif // LINKEDLIST_H_INCLUDED
