#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
// #include "populate.h"

int validateName(char name[])
{
    int i;

    for (i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
        {
            printf("INVALID NAME! ENTER NAME AGAIN..!\n");
            return 0;
        }
    }

    return 1;
}

int validatePhone(char phone[], AddressBook *addressBook, int currentIndex)
{
    int i;

    if (strlen(phone) != 10)
    {
        printf("INVALID NUMBER, ENTER EXACTLY 10 DIGITS\n");
        return 0;
    }

    for (i = 0; phone[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)phone[i]))
        {
            printf("INVALID PHONE NUMBER! ENTER NUMBER AGAIN..!\n");
            return 0;
        }
    }

    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (i != currentIndex &&
            strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            printf("PHONE NUMBER ALREADY EXISTS!\n");
            printf("ENTER ANOTHER NUMBER\n");
            return 0;
        }
    }

    return 1;
}

int validateEmail(char email[])
{
    char *at;
    char *dot;
    int i;

    at = strchr(email, '@');
    dot = strchr(email, '.');

    if (at == NULL || dot == NULL)
    {
        printf("INVALID EMAIL. '@' OR '.' IS MISSING.\n");
        return 0;
    }

    if (strchr(email, ' ') != NULL)
    {
        printf("INVALID EMAIL. SPACES ARE NOT ALLOWED.\n");
        return 0;
    }

    if (at == email)
    {
        printf("INVALID EMAIL. ENTER SOMETHING BEFORE '@'.\n");
        return 0;
    }

    if (dot <= at + 1)
    {
        printf("INVALID EMAIL. ENTER VALID TEXT BETWEEN '@' AND '.'.\n");
        return 0;
    }

    if (dot[1] == '\0')
    {
        printf("INVALID EMAIL. ENTER SOMETHING AFTER '.'.\n");
        return 0;
    }

    for (i = 0; email[i] != '\0'; i++)
    {
        if (isupper((unsigned char)email[i]))
        {
            printf("ENTER EMAIL IN LOWER CASE ONLY.\n");
            return 0;
        }
    }

    return 1;
}

void listContacts(AddressBook *addressBook)
{
    int i;

    printf("=========================ALL AVAILABLE CONTACTS=========================\n");
    printf("%-10s %-25s %-15s %-25s\n",
           "NO", "NAME", "PHONE", "EMAIL");
    printf("========================================================================\n");

    for (i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-10d %-25s %-15s %-25s\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("========================================================================\n");
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS);
}

void createContact(AddressBook *addressBook)
{
    char add_name[50];
    char add_phone[20];
    char add_email[50];

    printf("----------------------ENTER NEW CONTACT DETAILS.------------------------\n");

    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("ADDRESS BOOK IS FULL!\n");
        return;
    }

    do
    {
        printf("NAME : ");
        scanf(" %49[^\n]", add_name);
    } while (!validateName(add_name));

    do
    {
        printf("PHONE NO. : ");
        scanf(" %19[^\n]", add_phone);
    } while (!validatePhone(add_phone, addressBook, -1));

    do
    {
        printf("EMAIL : ");
        scanf(" %49[^\n]", add_email);
    } while (!validateEmail(add_email));

    strcpy(addressBook->contacts[addressBook->contactCount].name, add_name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, add_phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, add_email);

    addressBook->contactCount++;

    printf("CONTACT DETAILS ADDED SUCCESSFULLY..!\n");
}

void printContact(Contact *contact, int i)
{
    printf("%-10d %-25s %-15s %-25s\n",
           i + 1,
           contact->name,
           contact->phone,
           contact->email);
}

void searchContact(AddressBook *addressBook)
{
    int n;

    printf("------------------------------------------------------------------------\n");
    printf("1. NAME\n");
    printf("2. NUMBER\n");
    printf("3. EMAIL\n");
    printf("WHAT DO YOU HAVE ? ENTER SERIAL NO : ");
    scanf("%d", &n);

    switch (n)
    {
        case 1:
        {
            int i;
            int flag = 0;
            char s_name[50];

            printf("ENTER THE NAME : ");
            scanf(" %49[^\n]", s_name);

            for (i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(s_name, addressBook->contacts[i].name) == 0)
                {
                    if (flag == 0)
                    {
                        printf("=============================CONTACT DETAILS============================\n");
                        printf("%-10s %-25s %-15s %-25s\n",
                               "NO", "NAME", "PHONE", "EMAIL");
                        printf("------------------------------------------------------------------------\n");
                    }

                    printContact(&addressBook->contacts[i], i);
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                printf("NO CONTACT AVAILABLE..TRY AGAIN.!\n");
            }

            break;
        }

        case 2:
        {
            int i;
            int flag = 0;
            char num[20];

            printf("ENTER THE PHONE NUMBER : ");
            scanf(" %19[^\n]", num);

            for (i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(num, addressBook->contacts[i].phone) == 0)
                {
                    printf("=============================CONTACT DETAILS============================\n");
                    printf("%-10s %-25s %-15s %-25s\n",
                           "NO", "NAME", "PHONE", "EMAIL");
                    printf("------------------------------------------------------------------------\n");

                    printContact(&addressBook->contacts[i], i);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                printf("NO CONTACT AVAILABLE..TRY AGAIN.!\n");
            }

            break;
        }

        case 3:
        {
            int i;
            int flag = 0;
            char s_email[50];

            printf("ENTER THE EMAIL : ");
            scanf(" %49[^\n]", s_email);

            for (i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(s_email, addressBook->contacts[i].email) == 0)
                {
                    printf("=============================CONTACT DETAILS============================\n");
                    printf("%-10s %-25s %-15s %-25s\n",
                           "NO", "NAME", "PHONE", "EMAIL");
                    printf("------------------------------------------------------------------------\n");

                    printContact(&addressBook->contacts[i], i);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                printf("NO CONTACT AVAILABLE..TRY AGAIN.!\n");
            }

            break;
        }

        default:
            printf("INVALID CHOICE.\n");
            break;
    }
}

void editContact(AddressBook *addressBook)
{
    int choice;
    int index;

    char edit_name[50];
    char edit_phone[20];
    char edit_email[50];

    searchContact(addressBook);

    printf("\nENTER SERIAL NO. OF CONTACT YOU WANT TO EDIT : ");
    scanf("%d", &index);

    index--;

    if (index < 0 || index >= addressBook->contactCount)
    {
        printf("INVALID SERIAL NUMBER!\n");
        return;
    }

    printf("------------------------------------------------------------------------\n");
    printf("WHAT DO YOU WANT TO EDIT :\n");
    printf("1. NAME\n");
    printf("2. NUMBER\n");
    printf("3. EMAIL\n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            do
            {
                printf("NAME : ");
                scanf(" %49[^\n]", edit_name);
            } while (!validateName(edit_name));

            strcpy(addressBook->contacts[index].name, edit_name);

            printf("NAME UPDATED SUCCESSFULLY!\n");
            break;

        case 2:
            do
            {
                printf("PHONE NO. : ");
                scanf(" %19[^\n]", edit_phone);
            } while (!validatePhone(edit_phone, addressBook, index));

            strcpy(addressBook->contacts[index].phone, edit_phone);

            printf("PHONE NUMBER UPDATED SUCCESSFULLY!\n");
            break;

        case 3:
            do
            {
                printf("EMAIL : ");
                scanf(" %49[^\n]", edit_email);
            } while (!validateEmail(edit_email));

            strcpy(addressBook->contacts[index].email, edit_email);

            printf("EMAIL UPDATED SUCCESSFULLY!\n");
            break;

        default:
            printf("INVALID CHOICE!\n");
            break;
    }
}

void deleteContact(AddressBook *addressBook)
{
    int index;
    int i;
    char confirm;

    searchContact(addressBook);

    printf("WHICH CONTACT DO YOU WANT TO DELETE : ");
    scanf("%d", &index);

    index--;

    if (index < 0 || index >= addressBook->contactCount)
    {
        printf("INVALID SERIAL NO. NUMBER!\n");
        return;
    }

    printf("ARE YOU SURE YOU WANT TO DELETE : %s? (Y/N): ",
           addressBook->contacts[index].name);

    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        for (i = index; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }

        addressBook->contactCount--;

        printf("CONTACT DELETED SUCCESSFULLY!\n");
    }
    else
    {
        printf("DELETE OPERATION CANCELLED.\n");
    }
}