#include "addressbook.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
	char res;
	do
	{
	    char *fname = argv[1];

	    printf("============================\n");
	    printf("\tADDRESS BOOK\n");
	    printf("============================\n");
	    printf("####### Features:\n\n");

	    printf("0. Exit\n1. Add Contact\n2. Search Contact\n3. Edit Contact\n4. Delete Contact\n5. List Contacts\n");

	    printf("---------------------------\n");

	    int option;
	    printf("Please Select an Option : ");
	    scanf("%d",&option);

	    printf("---------------------------\n");
	
	    switch (option)
	    {
		case 0:
		    return 0;

		case 1 : 
		    add_contact(fname);
		    break;

		case 2 : 
		    search_contact(fname);
		    break;

		case 3 : 
		    edit_contact(fname);
		    break;

		case 4 : 
		    delete_contact(fname);
		    break;

		case 5 : 
		    list_contacts(fname);
		    break;

		default :
		    printf("ERROR: Enter the Valid Choice\n");

	    }

	    printf("do you want to continue? y/n: ");
	    scanf(" %c",&res);

	} while(res == 'y');
    }
}
