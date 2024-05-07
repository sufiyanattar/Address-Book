#include "addressbook.h"

int edit_contact(char *fname)
{
    FILE *fptr = fopen(fname,"r+");

    if (fptr == NULL)
    {
	perror("fopen");
	fprintf(stderr,"ERROR: Unable to open the %s file\n",fname);
	return 0;
    }

    contacts contactInfo;
    contacts editInfo;

    char name_Edit[30];
    char phone_Edit[11];
    char emailId_Edit[30];

    int option,count = 0;

    printf("Search Contact to Edit by :\n1. Name\n2. Phone No\n3. Email Id\n\nPlease Select an Option: ");
    scanf("%d",&option);

    char ch;
    switch (option)
    {
	case 1:
	    printf("Enter the name which you want to edit: ");
	    scanf(" %[^\n]",name_Edit);

	    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (!(strcmp(contactInfo.name,name_Edit)))
		{
		    printf("##CONTACT FOUND##\n");
		    printf("Enter New Name: ");
		    scanf(" %[^\n]",editInfo.name);

		    printf("Do you ant to Edit the Phone No also?(y/n): ");
		    scanf(" %c",&ch);

		    if (ch == 'y')
		    {
			printf("Enter New Phone No: ");
			scanf(" %[^\n]",editInfo.phone);
		    }
		    else if (ch == 'n')
		    {
			printf("%s\n",contactInfo.phone);
			strcpy(editInfo.phone,contactInfo.phone);	
		    }
		    else
		    {
			printf("Invalid Option\n");
		    }

		    printf("Do you ant to Edit the Email Id also?(y/n): ");
		    scanf(" %c",&ch);

		    if (ch == 'y')
		    {
			printf("Enter New Email Id No: ");
			scanf(" %[^\n]",editInfo.emailId);
		    }
		    else if (ch == 'n')
		    {
			printf("%s\n",contactInfo.emailId);
			strcpy(editInfo.emailId,contactInfo.emailId);	
		    }
		    else
		    {
			printf("Invalid Option\n");
		    }
			

		    fseek(fptr, -sizeof(contactInfo), SEEK_CUR);
		    fwrite(&editInfo, sizeof(contactInfo), 1, fptr);
		    fclose(fptr);
		    count++;

		    break;

		}
	    }
	    break;
	case 2:
	    printf("Enter the Phone No which you want to edit: ");
	    scanf(" %[^\n]",phone_Edit);

	    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (!strcmp(contactInfo.phone,phone_Edit))
		{
		    printf("##CONTACT FOUND##\n");
		    printf("Enter New Phone No: ");
		    scanf(" %[^\n]",editInfo.phone);

		    printf("Do you ant to Edit the Name No also?(y/n): ");
		    scanf(" %c",&ch);

		    if (ch == 'y')
		    {
			printf("Enter New Name No: ");
			scanf(" %[^\n]",editInfo.name);
		    }
		    else if (ch == 'n')
		    {
			printf("%s\n",contactInfo.name);
			strcpy(editInfo.name,contactInfo.name);	
		    }
		    else
		    {
			printf("Invalid Option\n");
		    }

		    printf("Do you ant to Edit the Email Id also?(y/n): ");
		    scanf(" %c",&ch);

		    if (ch == 'y')
		    {
			printf("Enter New Email Id No: ");
			scanf(" %[^\n]",editInfo.emailId);
		    }
		    else if (ch == 'n')
		    {
			printf("%s\n",contactInfo.emailId);
			strcpy(editInfo.emailId,contactInfo.emailId);	
		    }
		    else
		    {
			printf("Invalid Option\n");
		    }

		    fseek(fptr,-(sizeof(contactInfo)),SEEK_CUR);
		    fwrite(&editInfo, sizeof(contactInfo), 1, fptr);
		    fclose(fptr);

		    count++;
		    break;

		}
	    }
	    break;
	case 3:
	    printf("Enter the Email Id which you want to edit: ");
	    scanf(" %[^\n]",emailId_Edit);

	    while ((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (!strcmp(contactInfo.emailId,emailId_Edit))
		{
		    printf("##CONTACT FOUND##\n");
		    printf("Enter New Email Id: ");
		    scanf(" %[^\n]",editInfo.emailId);

		    printf("Do you ant to Edit the name also?(y/n): ");
		    scanf(" %c",&ch);

		    if (ch == 'y')
		    {
			printf("Enter New name No: ");
			scanf(" %[^\n]",editInfo.name);
		    }
		    else if (ch == 'n')
		    {
			printf("%s\n",contactInfo.name);
			strcpy(editInfo.name,contactInfo.name);	
		    }
		    else
		    {
			printf("Invalid Option\n");
		    }

		    printf("Do you ant to Edit the Phone also?(y/n): ");
		    scanf(" %c",&ch);

		    if (ch == 'y')
		    {
			printf("Enter New Phone No: ");
			scanf(" %[^\n]",editInfo.phone);
		    }
		    else if (ch == 'n')
		    {
			printf("%s\n",contactInfo.phone);
			strcpy(editInfo.phone,contactInfo.phone);	
		    }
		    else
		    {
			printf("Invalid Option\n");
		    }

		    fseek(fptr,-(sizeof(contactInfo)),SEEK_CUR);
		    fwrite(&editInfo, sizeof(contactInfo), 1, fptr);
		    fclose(fptr);

		    count++;
		    break;

		}
	    }
	    break;

	default : 
	    printf("Invalid Option\n");
	    return 0;
    }

    if (count)
    {
	printf("Contact Details Edited Successfully\n");
    }
    else
    {
	printf("Data You Are Trying to Edit is Not Available\n");
	return 0;
    }
    return 1;

}
