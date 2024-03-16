#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void CreateLinkedList(LinkedList *Pll)
{
    int i;
    Pll->top = NULL;    //initialize top pointer with NULL
    Pll->SIZE = 0;      //Initialize Size with 0 Nodes
    Pll->LastID =0;    //Initialize the last ID with 0;
    //memset (Pll->seats,0,251);
    for(i=1;i<MAXSEATS;i++)
    {
        Pll->seats[i]=0;
    }
    /*for(i=1;i<400;i++)
    {
        Pll->ID[i]=0;
    }*/
}

void CreatNode(LLEntry data,LinkedList *Pll, int Position)
{

       // printf("first node\n");
    //Add node with position
    LLNode *Pn = (LLNode*)malloc(sizeof(LLNode));  //Creation of Node
    Pn->Next = NULL;
    Pn->Prev = NULL;
    LLNode *P1 = Pll->top;
    /* strcpy(Pn->data.Name, data.Name);
    Pn->data.phoneNo = data.phoneNo;
    if(Pll->top == NULL)  //if it was the first node
    {
        Pll->top = Pn;
        Pn->Next = NULL;
    }
    else
    {
        Pll->top->Next = Pn;
        Pn->Prev = Pll->top;
        Pll->top = Pn;
    }*/
    if(Position < Pll->SIZE && Position > 0)        //a condition to check whether the condition is valid or not
    {
        printf("if\n");
        int i;
        for(i= Pll->SIZE - Position ; i>0; i--) //for loop to shift Pl to the right position
        {
            P1= P1->Next;
        }
        Pn->Next = P1->Next;
        Pn->Prev = P1;
        P1->Next = Pn;
        if(Pn->Next)    //If there is Next
        {
            Pn->Next->Prev = Pn;
        }
        Pn->data.phoneNo = data.phoneNo;
        Pn->data.ID= Pll->LastID;
        Pn->data.Seat_Number = data.Seat_Number;
        Pn->data.BirthDate.Day = data.BirthDate.Day;
        Pn->data.BirthDate.Month = data.BirthDate.Month;
        Pn->data.BirthDate.Year = data.BirthDate.Year;
        strcpy(Pn->data.Class, data.Class);
        strcpy(Pn->data.Address, data.Address);
        strcpy(Pn->data.Name, data.Name);
        Pll->SIZE++;
    }
    else if(Position == Pll->SIZE+1)    //If condition for the special case which is the position is the top Node
    {
        Position = Pll->SIZE+1;
        Pll->top = Pn;
        Pn->Prev = P1;
        Pn->Next = NULL;
        if(Pn->Next)    //if there is only the top node in the list and there is no next node
            P1->Prev = Pn;
        Pn->data.phoneNo = data.phoneNo;
        Pn->data.ID= Pll->LastID;
        Pn->data.Seat_Number = data.Seat_Number;
        Pn->data.BirthDate.Day = data.BirthDate.Day;
        Pn->data.BirthDate.Month = data.BirthDate.Month;
        Pn->data.BirthDate.Year = data.BirthDate.Year;
        strcpy(Pn->data.Class,data.Class);
        strcpy(Pn->data.Address,data.Address);
        strcpy(Pn->data.Name,data.Name);
        Pll->SIZE++;
    }
    else    //if the position not valid
    {
        printf("this element is not in the List");
    }
}

void LastNode(LLEntry data,LinkedList *Pll)
{
    CreatNode(data,Pll, Pll->SIZE+1);
}

void RemoveNode(LLEntry *data,LinkedList *Pll, int Position)
{
    //removing node with position
    LLNode *P1;
    //LLNode *ptemp;
    P1== Pll->top;     //Create P1 pointer to move with
    if(Pll->SIZE >0)
    {
        //there is nodes in the list
        if(Position <=Pll->SIZE && Position > 0)
        {
            //If Condition to check if the position either valid or not
            int i;
            for(i= Pll->SIZE - Position ; i>0; i--)
            {
                //Shift P1 to the right position
                P1 = P1->Next;
            }
            if(P1->Prev)    //if it is the First node
                P1->Prev->Next = P1->Next;
            else        //if it is not the First node
                Pll->top = P1->Next;
            if(P1->Next)    //if it is the last node
                P1->Next->Prev = P1->Prev;
            *data = P1->data;   //Copy data to send it out
            Pll->SIZE--;    //decrement the size by 1 as there is element in the list removed
            free(P1);       //Then free the P1 : the node that needs to be deleted
        }
        else
        {
            //if the position is not in the list
            printf("Invalid Position");
        }
    }
    else
    {
        //if there is no elements in the list
        printf("The List is empty\n");
    }
}

char ListFull(LinkedList *Pll)
{
    //return 1 if the list is full or return 0 if the list is not full
    return 0;       //return 0 as the heap is always big enough
}

int ListSize(LinkedList *Pll)
{
    //return the size of the list
    return Pll->SIZE;
}

void ClearList(LinkedList *Pll)
{
    //function to clear the whole list at once
    LLNode *Pn = NULL;  //create a pointer to save the node in before swapping to free it, Initialize it with NULL to prevent wild pointer
    while(Pll->top)
    {
        //while Pll->Top point to a node keep freeing
        Pn = Pll->top;
        Pll->top = Pn->Next;
        free(Pn);
    }
}

LLNode* PassngerNode(LinkedList *Pll)
{
    //function to search for a passenger using ID
    if(Pll->SIZE)
    {
        int FoundFlag = 0;
        LLNode *P1=Pll->top;
        int ID;
        printf("Enter the ID : ");
        scanf("%d",&ID);
        while(P1)
        {
            if(ID == P1->data.ID)
            {
                FoundFlag=1;
                break;
            }
            P1=P1->Prev;
        }
        if(FoundFlag == 1)
        {
            return P1;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}



void Swap(LLNode *node1, LLNode *node2)
{
    Client clientTemp;
    clientTemp.ID = node1->data.ID;
    clientTemp.BirthDate.Day = node1->data.BirthDate.Day;
    clientTemp.BirthDate.Month = node1->data.BirthDate.Month;
    clientTemp.BirthDate.Year = node1->data.BirthDate.Year;
    clientTemp.phoneNo = node1->data.phoneNo;
    clientTemp.Seat_Number = node1->data.Seat_Number;
    strcpy(clientTemp.Class, node1->data.Class);
    strcpy(clientTemp.Name, node1->data.Name);
    strcpy(clientTemp.Address, node1->data.Address);
    /***********************************/
    node1->data.ID = node2->data.ID;
    node1->data.BirthDate.Day = node2->data.BirthDate.Day;
    node1->data.BirthDate.Month = node2->data.BirthDate.Month;
    node1->data.BirthDate.Year = node2->data.BirthDate.Year;
    node1->data.phoneNo = node2->data.phoneNo;
    node1->data.Seat_Number = node2->data.Seat_Number;
    strcpy(node1->data.Class, node2->data.Class);
    strcpy(node1->data.Name, node2->data.Name);
    strcpy(node1->data.Address, node2->data.Address);
    /********************************/
    node2->data.ID = clientTemp.ID;
    node2->data.BirthDate.Day = clientTemp.BirthDate.Day;
    node2->data.BirthDate.Month = clientTemp.BirthDate.Month;
    node2->data.BirthDate.Year = clientTemp.BirthDate.Year;
    node2->data.phoneNo = clientTemp.phoneNo;
    node2->data.Seat_Number = clientTemp.Seat_Number;
    strcpy(node2->data.Class, clientTemp.Class);
    strcpy(node2->data.Name, clientTemp.Name);
    strcpy(node2->data.Address, clientTemp.Address);
}