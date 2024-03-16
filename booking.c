#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "linkedlist.h"

void flightprogram(void)
{
    // This Program is to made to be called in the main menu and show the main menu then ask for the process that the user want to make and call it's function
    /* Function Creations */
    LinkedList Passenger_List; // Create School List
    int In;                    // int variable to take the input of the user of the process that he wants to make
    char flag = 1;             // variable to loop the or terminate it
    int x;
    /* Function Code */
    Main_Menu(&Passenger_List); // send the School List to Make it a linked list
    while (flag)

    {
        /* print the main menu screen */
        printf("\n\n");
        printf("\t\t\t\t      ******************************\n");
        printf("\t\t\t\t      |          Main Menu         |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   1. Add New Passenger     |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   2. Show Passengers List  |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   3. Delete Passenger      |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   4. Edit Passenger Info   |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   5. Display Free Seats    |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   6. Print Unsorted List   |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |   7. Show Sorted Classes   |\n");
        printf("\t\t\t\t      |============================|\n");
        printf("\t\t\t\t      |   8. Exit                  |\n");
        printf("\t\t\t\t      ******************************\n\n");
        scanf("%d", &In); // Scan the user's input of the process then switch it to the function of the process
        fflush(stdin);
        switch (In)
        {
        case 1:
            new_client(&Passenger_List); // add new client
            break;
        case 2:
            SortAccordingToName(&Passenger_List); //sort alphabetically 
            break;
        case 3:
            delete_client(&Passenger_List); //delete client
            break;
        case 4:
            client_edit(&Passenger_List); // update client info
            break;
        case 5:
            free_seats(&Passenger_List); // display free seats
            break;
        case 6:
            PrintClientList(&Passenger_List); // display client list
            break;
        case 7:
            SortByClass(&Passenger_List);
            break;
        case 8:
            flag = 0;
        default:
            printf("invalid option\n");
            break;
        }
        printf("\nPress Enter to Continue\n");
        fflush(stdin);
        getchar(); // Wait for the user to press enter to clear the screen and loop again from the beginning
        system("cls");
    }
    system("cls");
    printf("Press Enter to Shutdown"); // shutting down screen
}

void Main_Menu(LinkedList *Pll)
{

    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t      *******************************************************\n");
    printf("\t\t\t      *                                                     *\n");
    printf("\t\t\t      *                 Flight Booking System               *\n");
    printf("\t\t\t      *                                                     *\n");
    printf("\t\t\t      *******************************************************\n");

    CreateLinkedList(Pll); // create the clients list
}

void new_client(LinkedList *Pll)
{
    system("color Cf");

    system("cls"); // System Clear screen

    /* Function DataTypes Creations */
    char choice;        // char for entering the answer of any choice with Y/N
    int seat_number;    // int for getting the score and check if it is correct or not first before saving to the Passenger info
    LLEntry clientInfo; // LLEntry type to save the Passenger info on it first then send it to the list
    int BirthDateInfo;  // Int for getting the birthdate info and check if it is correct or not first before saving the to Passenger info
    int x;
    LLNode *Ptemp;
    /* Function Code */
    // request and scan the Passenger name
    printf("Enter The Passenger data : \n");
    printf("1. Name : ");
    fflush(stdin);
    gets(&clientInfo.Name);
    // request and scan the Passenger address
    printf("2. Address : ");
    gets(&clientInfo.Address);
    // request and scan then check Birthdate of the Passenger
    /* There is no BirthDate Checking yet */
    printf("3. BirthDate : \n");

    // request and scan the year
    do
    {
        printf("   year  : ");
        scanf("%d", &clientInfo.BirthDate.Year);
        fflush(stdin);
    } while (clientInfo.BirthDate.Year < 1922 || clientInfo.BirthDate.Year > 2004);

    // request and scan then check the month
    do
    {
        printf("   Month : ");
        scanf("%d", &BirthDateInfo);
        fflush(stdin);
    } while (BirthDateInfo > 12 || BirthDateInfo <= 0);
    clientInfo.BirthDate.Month = BirthDateInfo; // Add the Month info entered to the cient info
    BirthDateInfo = 0;                          // Reset BirthDateInfo

    // request and scan then check the day
    do // DoWhile loop to check if the month is 31 day or not and the day is in range or not
    {
        BirthDateInfo = 0; // Reset BirthDateInfo
        do                 // DoWhile loop to scan the day input and check if it is in range 1->31 or not
        {
            printf("   Day   : ");
            scanf("%d", &BirthDateInfo);
            fflush(stdin);
            if (clientInfo.BirthDate.Month == 2 && BirthDateInfo > 29)
                BirthDateInfo = 0;
        } while (BirthDateInfo > 31 || BirthDateInfo <= 0);                                                   // Check if the day is in range or not (1->31)
    } while (((clientInfo.BirthDate.Month / 8) + clientInfo.BirthDate.Month) % 2 == 0 && BirthDateInfo > 30); // check if the day is in range relative to the month
    clientInfo.BirthDate.Day = BirthDateInfo;                                                                 // Save the day info to the passenger day info
    BirthDateInfo = 0;                                                                                        // reset BirthDateInfo

    printf("Enter the Phone number (+20)");
    scanf("%d", &clientInfo.phoneNo);
    fflush(stdin);

    printf("Choose Your Class\n");
    printf("to Choose First Class Choose a Seat Number From 1->50\n");
    printf("to Choose Business Class Choose a Seat Number From 51->100\n");
    printf("to Choose Economy Class Choose a Seat Number From 101->250\n");
    do
    {
        scanf("%d", &clientInfo.Seat_Number);
        fflush(stdin);
        if (clientInfo.Seat_Number >= 1 && clientInfo.Seat_Number <= 250)
        {
            if (Pll->seats[clientInfo.Seat_Number] == 0)
            {
                if ((1 <= (clientInfo.Seat_Number) && (clientInfo.Seat_Number) <= 50))
                {
                    Pll->seats[clientInfo.Seat_Number] = 1;
                    strcpy(&clientInfo.Class, "First Class");
                    printf("your class is first\n");
                }
                else if (51 <= (clientInfo.Seat_Number) && (clientInfo.Seat_Number) <= 100)
                {
                    Pll->seats[clientInfo.Seat_Number] = 1;
                    printf("your class is business\n");
                    strcpy(&clientInfo.Class, "Business Class");
                }
                else if (101 <= (clientInfo.Seat_Number) && (clientInfo.Seat_Number) <= 250)
                {
                    Pll->seats[clientInfo.Seat_Number] = 1;
                    strcpy(&clientInfo.Class, "Economy Class");
                    printf("your class is economy\n");
                }
            }
            else
            {
                clientInfo.Seat_Number = 0;
                printf("Seat is Taken\n\n");
                printf("Please pick another seat\n");
            }
        }
        else
        {
            clientInfo.Seat_Number = 0;
            printf("Invalid Seat Number\n\n");
            printf("Please pick another seat\n");
        }
    } while ((1 > clientInfo.Seat_Number) || (clientInfo.Seat_Number > 250));

    Pll->LastID++;               // Increament the last ID first
    clientInfo.ID = Pll->LastID; // then give the new ID to that new passnger
    LastNode(clientInfo, Pll);   // Send The Entered passenger's Data to the LinkedList DataBase
}

void PrintClientList(LinkedList *Pll)
{
    system("color Ff");
    // Function to print the Passenger list
    fflush(stdin);
    system("cls");
    int Iteration;
    LLNode *Ptemp;
    printf("print function = %d\n", Pll->top->data.Seat_Number);
    Ptemp = Pll->top;
    /* int x=1; */
    printf("*********************\n");
    printf("The Passnger List is :\n");
    printf("*********************\n\n");
    printf("*************************************\n");
    // printf("Client Info :\nName : %s\n",Ptemp->data.Name);
    if (Ptemp != NULL)
    {
        // check if the list is not empty
        for (Iteration = Pll->SIZE; Iteration > 0; Iteration--)
        {
            // loop over the whole list
            PrintClientInfo(&Ptemp->data); // print the Passenger info
            Ptemp = Ptemp->Prev;
        }
    }
    else
    {
        printf("Nothing in here\n");
    }
    printf("\n");
}

void PrintClientInfo(Client *Pn)
{
    // function that take pointer to node and print it's data

    // check if the ID is valid
    /* Printing The Clients Data */
    printf("*************************************\n");
    printf("Client Info :\nName : %s\n", Pn->Name);
    printf("ID : %d\n", Pn->ID);
    printf("Adress : %s\n", Pn->Address);
    printf("Phone Number : (+20)%d\n", Pn->phoneNo);
    printf("Date of Birth : %d/%d/%d\n\n", Pn->BirthDate.Day, Pn->BirthDate.Month, Pn->BirthDate.Year);
    printf("Class : %s\n", Pn->Class);
    printf("Seat Number : %d\n", Pn->Seat_Number);
    printf("*************************************\n\n");
}

void free_seats(LinkedList *Pll)
{
    int i;
    int choice;
    printf("which class you want to check its free seats?\n");
    printf("1-First Class\n");
    printf("2-Business Class\n");
    printf("3-Economy Class\n");
    printf("4-All Classes\n");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice)
    {
    case 1:
    {
        printf("Empty seats in First class\n");
        for (i = 1; i < 51; i++)
        {
            if (Pll->seats[i] == 0)
            {
                printf(" %d ", i);
            }
            /* else
            {
            } */
        }
        printf("\n\n");
        break;
    }
    case 2:
    {
        printf("Empty seats in business class\n");
        for (i = 51; i < 101; i++)
        {
            if (Pll->seats[i] == 0)
            {
                printf(" %d ", i);
            }
            /* else
            {
            } */
        }
        printf("\n\n");
        break;
    }
    case 3:
    {
        printf("Empty seats in Economy class\n");
        for (i = 101; i < 251; i++)
        {
            if (Pll->seats[i] == 0)
            {
                printf(" %d ", i);
            }
            /* else
            {
            } */
        }
        break;
    }
    case 4:
    {
        int i;
        printf("Empty seats in First class\n");
        for (i = 1; i < 51; i++)
        {
            if (Pll->seats[i] == 0)
            {
                printf(" %d ", i);
            }
            /* else
            {
            } */
        }
        printf("\n\n");

        printf("Empty seats in Business class\n");
        for (i = 51; i < 101; i++)
        {
            if (Pll->seats[i] == 0)
            {
                printf(" %d ", i);
            }
            /* else
            {
            } */
        }
        printf("\n\n");
        printf("Empty seats in Economy class\n");
        for (i = 101; i < 251; i++)
        {
            if (Pll->seats[i] == 0)
            {
                printf(" %d ", i);
            }
            /* else
            {
            } */
        }
        break;
    }
    default:
    {
        printf("invalid option");
        break;
    }
    }
}

void SortAccordingToName(LinkedList *Pll)
{
    system("color Cf");
    // Function sort and print Passengers list according to their names using bubble sort
    system("cls");
    int Iteration;
    int j;
    printf("im in the function\n");
    if (Pll->SIZE)
    {
        // check if the list is not empty
        LLNode *P1 = Pll->top;
        // LLNode *P2 = Pll->top;
        for (Iteration = 1; Iteration < Pll->SIZE; Iteration++)
        {
            printf("ana hna f for loop 1\n");
            for (j = Pll->SIZE; j > (1); j--)
            {
                printf("hi");
                fflush(stdin);
                // stringcomp=strcmp(P1->data.Name,P2->Next->data.Name);
                fflush(stdin);
                printf("ana hna f for loop2\n");
                if (strcmp(&P1->data.Name, &P1->Prev->data.Name) > 0)
                {
                    printf("ana hna f if loop 3\n");
                    printf("%d\n", strcmp(P1->data.Name, P1->Prev->data.Name));
                    printf("P1->data ; %s 2:%s", P1->data.Name, P1->Prev->data.Name);
                    Swap(P1, P1->Prev);
                }
                else
                {
                    printf("ana hna  loop 1");
                    P1 = P1->Prev;
                }
                printf("ana hna  loop 2");
            }
            P1 = Pll->top;
        }
        printf("Exit\n");
    }
    printf("list empty");
    PrintClientList(Pll);
}

void client_edit(LinkedList *Pll)
{
    if (Pll->SIZE) // check if the client is in the list or not
    {
        LLNode *EditData = PassngerNode(Pll); // creating EditData with passenger data type to copy the node data
        int choice;                           // Variable to get the users choice
        int BirthDateInfo;                    // to recieve clients birth date
        if (EditData)
        {
            PrintClientInfo(&EditData->data);
            do
            {
                printf("what do you want to edit:\n");
                printf("1- Name :\n");
                printf("2- Address:\n");
                printf("3- Phone Number:\n");
                printf("4- Birth Day:\n");
                printf("5- Class & Seat Number:\n");
                printf("6- Exit the Process\n");
                printf("Choice :\n");
                scanf("%d", &choice);
                fflush(stdin);
                if (choice > 6 || choice == 0) // if the choice is not in the list
                {
                    printf("\nThis i snot in the list\n\n");
                }
            } while (choice > 6 || choice == 0);

            switch (choice) // switch case to access the required data
            {
            case 1:

                printf("enter the new name:\n ");
                fflush(stdin);
                gets(EditData->data.Name);
                fflush(stdin);
                break;

            case 2:
                printf("Enter the new Address:\n");
                fflush(stdin);
                gets(EditData->data.Address);
                fflush(stdin);
                break;

            case 3:
                printf("Enter the new Phone number:\n");
                fflush(stdin);
                scanf("%d", &EditData->data.phoneNo);
                fflush(stdin);
                break;

            case 4:
                printf("please enter the new Birthdate :");
                do
                {
                    printf("   year  : \n");
                    scanf("%d", &BirthDateInfo);
                    fflush(stdin);
                } while (BirthDateInfo < 1922 || BirthDateInfo > 2004);
                EditData->data.BirthDate.Year = BirthDateInfo;
                BirthDateInfo = 0;

                do // request and scan then check the month
                {
                    printf("   Month : \n");
                    scanf("%d", &BirthDateInfo);
                    fflush(stdin);
                } while (BirthDateInfo > 12 || BirthDateInfo <= 0);
                EditData->data.BirthDate.Month = BirthDateInfo; // Add the Month info entered to the cient info
                BirthDateInfo = 0;                              // Reset BirthDateInfo

                // request and scan then check the day
                do // DoWhile loop to check if the month is 31 day or not and the day is in range or not
                {
                    do // DoWhile loop to scan the day input and check if it is in range 1->31 or not
                    {
                        printf("   Day   : \n");
                        scanf("%d", &BirthDateInfo);
                        fflush(stdin);
                        if (EditData->data.BirthDate.Month == 2 && BirthDateInfo > 29)
                            BirthDateInfo = 0;
                    } while (BirthDateInfo > 31 || BirthDateInfo <= 0);                                                           // Check if the day is in range or not (1->31)
                } while (((EditData->data.BirthDate.Month / 8) + EditData->data.BirthDate.Month) % 2 == 0 && BirthDateInfo > 30); // check if the day is in range relative to the month
                EditData->data.BirthDate.Day = BirthDateInfo;                                                                     // Save the day info to the passenger day info
                BirthDateInfo = 0;                                                                                                // reset BirthDateInfo

                break;

            case 5:

                printf("Choose Your Class\n");
                printf("to Choose First Class Choose a Seat Number From 1->50\n");
                printf("to Choose Business Class Choose a Seat Number From 51->100\n");
                printf("to Choose Economy Class Choose a Seat Number From 101->250\n");
                do
                {
                    scanf("%d", &EditData->data.Seat_Number);
                    fflush(stdin);
                    if (EditData->data.Seat_Number >= 1 && EditData->data.Seat_Number <= 250)
                    {
                        if (Pll->seats[EditData->data.Seat_Number] == 0)
                        {
                            if ((1 <= (EditData->data.Seat_Number) && (EditData->data.Seat_Number) <= 50))
                            {
                                Pll->seats[EditData->data.Seat_Number] = 1;
                                strcpy(&EditData->data.Class, "First Class");
                                printf("your class is first\n");
                            }
                            else if (51 <= (EditData->data.Seat_Number) && (EditData->data.Seat_Number) <= 100)
                            {
                                Pll->seats[EditData->data.Seat_Number] = 1;
                                printf("your class is business\n");
                                strcpy(&EditData->data.Class, "Business Class");
                            }
                            else if (101 <= (EditData->data.Seat_Number) && (EditData->data.Seat_Number) <= 250)
                            {
                                Pll->seats[EditData->data.Seat_Number] = 1;
                                strcpy(&EditData->data.Class, "Economy Class");
                                printf("your class is economy\n");
                            }
                        }
                        else
                        {
                            EditData->data.Seat_Number = 0;
                            printf("Seat is Taken\n\n");
                            printf("Please pick another seat\n");
                        }
                    }
                    else
                    {
                        EditData->data.Seat_Number = 0;
                        printf("Invalid Seat Number\n\n");
                        printf("Please pick another seat\n");
                    }
                } while ((1 > EditData->data.Seat_Number) || (EditData->data.Seat_Number > 250));
                break;

            case 6:
                printf("Exit \n");
                break;

            default:
                break;
            } // end of while loop

            printf("\n");

        } // End of second IF condition
        else
        {
            printf("\n nothing has been done\n");
        }

    } // End of first IF condition

    else
    {
        printf("\n the list is empty .. add passengers first");
    }
} // end of function

void delete_client(LinkedList *Pll)
{
    LLNode *node = PassngerNode(Pll);
    if (node == NULL) // Check if the List is empty or invalid ID
    {
        printf("The List is Empty or Invalid ID");
        return;
    }
    else if ((node->Prev == NULL) && (node->Next == NULL)) // Check if only one node exist
    {
        Pll->seats[node->data.Seat_Number] = 0;
        Pll->top = NULL;
        free(node);
        Pll->SIZE--;
    }
    else if (node == Pll->top) // check if the node is the top node
    {
        Pll->seats[node->data.Seat_Number] = 0;
        Pll->top = Pll->top->Prev;
        free(node);
        Pll->top->Next = NULL;
        Pll->SIZE--;
    }
    else if (node->Prev == NULL) // check if the node is the first node
    {
        Pll->seats[node->data.Seat_Number] = 0;
        node->Next->Prev = NULL;
        free(node);
        Pll->SIZE--;
    }
    else // if the node is in the middle
    {
        Pll->seats[node->data.Seat_Number] = 0;
        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
        free(node);
        Pll->SIZE--;
    }
}

void Sort_Class(LinkedList *Pll)
{
    // Function sort and print Passengers *Classes* according to their Seat Number using bubble sort
    system("cls");
    int Iteration;
    int j;
    if (Pll->SIZE)
    {
        // check if the list is not empty
        LLNode *P1 = Pll->top;
        // LLNode *P2 = Pll->top;
        for (Iteration = 1; Iteration < Pll->SIZE; Iteration++)
        {
            for (j = Pll->SIZE; j > (1); j--)
            {
                if ((P1->data.Seat_Number > P1->Prev->data.Seat_Number))
                {
                    Swap(P1, P1->Prev);
                }
                else
                {
                    P1 = P1->Prev;
                }
            }
            P1 = Pll->top;
        }
    }
}

void SortByClass(LinkedList *Pll)
{
    system("color 9f");
    Sort_Class(Pll);
    LLNode *Pc = Pll->top;
    int classType = 0;
    int foundFlag = 0;
    printf("Choose The Class you want to list:\n");
    printf("1-First Class\n");
    printf("2-Business Class\n");
    printf("3-Economy Class\n");
    printf("4-Exit\n");
    do
    {
        Pc = Pll->top;
        fflush(stdin);
        scanf("%d", &classType);
        fflush(stdin);
        int i = 0;
        if (classType == 1) // to print passengers in first class
        {
            for (i = STARTOFFIRSTCLASS; i <= ENDOFFIRSTCLASS; i++)
            {
                if (Pll->seats[i] == 1)
                {
                    foundFlag = 1;
                    break;
                }
            }
            if (foundFlag)
            {
                printf("\t\t\t      *******************************************************\n");
                printf("\t\t\t      *               First Class Passengers                *\n");
                printf("\t\t\t      *******************************************************\n");
                while (Pc)
                {
                    if (Pc->data.Seat_Number >= STARTOFFIRSTCLASS && Pc->data.Seat_Number <= ENDOFFIRSTCLASS)
                        PrintClientInfo(&Pc->data);
                    Pc = Pc->Prev;
                }
            }
            else
            {
                printf("This class is empty\n");
            }
        }
        else if (classType == 2) // to print passengers in the business class
        {
            for (i = STARTOFBUSNESSCLASS; i <= ENDOFBUSNESSCLASS; i++)
            {
                if (Pll->seats[i] == 1) // marking every seat taken with one
                {
                    foundFlag = 1;
                    break;
                }
            }
            if (foundFlag) // checking for all the ones in the seats array
            {
                printf("\t\t\t      *******************************************************\n");
                printf("\t\t\t      *              Business Class Passengers              *\n");
                printf("\t\t\t      *******************************************************\n");
                while (Pc) // printing seats
                {
                    if (Pc->data.Seat_Number >= STARTOFBUSNESSCLASS && Pc->data.Seat_Number <= ENDOFBUSNESSCLASS)
                        PrintClientInfo(&Pc->data);
                    Pc = Pc->Prev;
                }
            }
            else
            {
                printf("This class is empty\n");
            }
        }
        else if (classType == 3) // to print passengers in the Economy
        {
            for (i = STARTOFECONOMYCLASS; i <= ENDOFECONOMYCLASS; i++)
            {
                if (Pll->seats[i] == 1)
                {
                    foundFlag = 1;
                    break;
                }
            }
            if (foundFlag)
            {
                 printf("\t\t\t      *******************************************************\n");
                 printf("\t\t\t      *               Economy Class Passengers              *\n");
                printf("\t\t\t       *******************************************************\n");
                while (Pc)
                {
                    if (Pc->data.Seat_Number >= STARTOFECONOMYCLASS && Pc->data.Seat_Number <= ENDOFECONOMYCLASS)
                        PrintClientInfo(&Pc->data);
                    Pc = Pc->Prev;
                }
            }
            else
            {
                printf("This class is empty\n");
            }
        }
        else
        {
            printf("Exiting The Function\n");
        }
        foundFlag = 0;
    } while (classType < 4);
}