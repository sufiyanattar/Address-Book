#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
    char name[50];
    char phone[11];
    char emailId[50];
}contacts;

int add_contact(char *fname);

int search_contact(char *fname);

int edit_contact(char *fname);

int delete_contact(char *fname);

int list_contacts(char *fname);

#endif
