#include "addressbook.h"

int list_contacts(char *fname)
{
    contacts contactInfo;

    FILE *fptr = fopen(fname,"r");

    if(fptr == NULL)
    {
	perror("fopen");
	fprintf(stderr,"ERROR: Unable to Open the %s file\n",fname);
	return 0;
    }

    int contact_Count=0;

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("| %s |\t%-25s |\t%-15s |\t%-30s |\n","SR NO","NAME","PHONE NO.","EMAIL ID");
    printf("--------------------------------------------------------------------------------------------------------\n");

    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
    {
	contact_Count++;
	printf("|%4d\t|\t%-25s |\t%-15s |\t%-30s |\n",contact_Count,contactInfo.name,contactInfo.phone,contactInfo.emailId);
	printf("--------------------------------------------------------------------------------------------------------\n");
    }

    if(!contact_Count)
    {
	printf("No Contacts in file\n");
	return 0;
    }

    fclose(fptr);

    return 1;


}
