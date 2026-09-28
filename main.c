#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
#include "file.h"

int main()
{
    int choice;
    AddressBook addressBook;

    initialize(&addressBook);

    do
    {
        system("clear");

        printf("+======================================================================+\n");
        printf("|                   ADDRESS BOOK MANAGEMENT SYSTEM                     |\n");
        printf("|                                 BY                                   |\n");
        printf("|                             S O H A N                                |\n");
        printf("+======================================================================+\n");
        printf("|           [1] Create contact                                         |\n");
        printf("|           [2] Search contact                                         |\n");
        printf("|           [3] Edit contact                                           |\n");
        printf("|           [4] Delete contact                                         |\n");
        printf("|           [5] List all contacts                                      |\n");
        printf("|           [6] Exit                                                   |\n");
        printf("+----------------------------------------------------------------------+\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                createContact(&addressBook);
                break;

            case 2:
                searchContact(&addressBook);
                break;

            case 3:
                editContact(&addressBook);
                break;

            case 4:
                deleteContact(&addressBook);
                break;

            case 5:
                listContacts(&addressBook);
                break;

            case 6:
                printf("\nSaving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        if (choice != 6)
        {
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }

    } while (choice != 6);

    return 0;
}