#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED




#define STARTOFFIRSTCLASS 1
#define ENDOFFIRSTCLASS 50
#define STARTOFBUSNESSCLASS 51
#define ENDOFBUSNESSCLASS 100
#define STARTOFECONOMYCLASS 101
#define ENDOFECONOMYCLASS 250

typedef struct date
{
    int Day;
    int Month;
    int Year;
} DoB;



typedef struct client_data
{
    int phoneNo;
    int Seat_Number;
    int ID;
    DoB BirthDate;
    char Name[50];
    char Address[100];
    char Class[50];
}Client;

void flightprogram ();//function used to start the porgram
void Main_Menu();//function used to display main menu
void new_client();//function to insert new function
void free_seats();//function to display free seats in a selected class
void client_edit();//function used to edit a selected passenger data    
void delete_client();//function used to delete a selected passenger data
void PrintClientInfo();//print data of passenger
void PrintClientList();//print ppassenger list with out sorting
void SortAccordingToName();//function to display passenger list in alphabetical order
void Sort_Class(); //function to sort seats
void SortByClass();//function to choose which class you want to sort


#endif // HEADER_H_INCLUDED
