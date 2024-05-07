#include "addressbook.h"

int search_contact(char *fname)
{
    FILE *fptr = fopen(fname,"r");

    if (fptr == NULL)
    {
	perror("fopen");
	fprintf(stderr,"ERROR: Unable to open the %s file\n",fname);
	return 0;
    }

    contacts contactInfo;

    char name_Search[50];
    char phone_Search[11];
    char emailId_Search[50];


    int option,count = 0;

    printf("Search Contact by :\n1. Name\n2. Phone No\n3. Email Id\n\nPlease Select an Option: ");
    scanf("%d",&option);

    switch (option)
    {
	case 1:
	    printf("Please Enter a Name to Search: ");
	    scanf(" %[^\n]",name_Search);

	    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (!(strcmp(contactInfo.name,name_Search)))
		{
		    printf("##CONTACT FOUND##\n");
		    printf("-------------------------------------------------------------------------------\n");
		    printf("NAME: %s | PHONE NO: %s | EMAIL ID: %s |\n",contactInfo.name,contactInfo.phone,contactInfo.emailId);
		    printf("-------------------------------------------------------------------------------\n");
		    count++;
		}	
	    }

	    break;

	case 2:
	    printf("Please Enter a Phone No to Search: ");
	    scanf(" %[^\n]",phone_Search);

	    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (!(strcmp(contactInfo.phone,phone_Search)))
		{
		    printf("##CONTACT FOUND##\n");
		    printf("-------------------------------------------------------------------------------\n");
		    printf("NAME: %s | PHONE NO: %s | EMAIL ID: %s |\n",contactInfo.name,contactInfo.phone,contactInfo.emailId);
		    printf("-------------------------------------------------------------------------------\n");
		    count++;
		}	
	    }
	    break;

	case 3:

	    printf("Please Enter a Name to Search: ");
	    scanf(" %[^\n]",emailId_Search);

	    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (!(strcmp(contactInfo.emailId,emailId_Search)))
		{
		    printf("##CONTACT FOUND##\n");
		    printf("-------------------------------------------------------------------------------\n");
		    printf("NAME: %s | PHONE NO: %s | EMAIL ID: %s |\n",contactInfo.name,contactInfo.phone,contactInfo.emailId);
		    printf("-------------------------------------------------------------------------------\n");
		    count++;
		}	
	    }
	    break;

	default :
	    printf("ERROR: Please Enter the Valid Option\n");
	    return 0;
    }

    if (!count)
    {
	printf("Contact Not Found\n");
    }
    else if (count > 1)
    {
	printf("WARNING: Contact Found either of Same Name/Phone No/Email ID\n");
    }

    fclose(fptr);

    return 1;

}

