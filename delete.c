#include "addressbook.h"

int delete_contact(char *fname)
{
    contacts contactInfo;

    FILE *fptr,*ftemp;

    if ((fptr = fopen(fname,"r")) == NULL)
    {
	perror("fopen");
	fprintf(stderr,"Unable to open the %s file\n",fname);
	return 0;
    }

    else
    {
	ftemp = fopen("temp.txt","w");

	if (ftemp == NULL)
	{
	    perror("fopen");
	    fprintf(stderr,"Unable to open the %s file\n","temp.txt");
	    return 0;
	}

    }

    char name_Del[50];
    char phone_Del[11];
    char emailId_Del[50];

    int option;
    printf("Search Contact to Delete by :\n1. Name\n2. Phone No\n3. Email Id\n\nPlease Select an Option: ");

    scanf("%d",&option);

    int count=0,keepcount=0;

    switch (option)
    {
	case 1:
	    printf("Enter the name: ");
	    scanf(" %[^\n]",name_Del);

	    while((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (strcmp(name_Del,contactInfo.name))
		{
		    fwrite(&contactInfo,sizeof(contactInfo),1,ftemp);
		    count = 0;
		}
		else
		{
		    count++;
		    keepcount = count;

		}
	    }
	    break;


	case 2:
	    printf("Enter the Phone No: ");
	    scanf(" %s",phone_Del);

	    while((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (strcmp(phone_Del,contactInfo.phone))
		{
		    fwrite(&contactInfo,sizeof(contactInfo),1,ftemp);
		    count = 0;
		}
		else
		{
		    count++;
		    keepcount = count;

		}
	    }
	    break;


	case 3:
	    printf("Enter the Email Id: ");
	    scanf(" %s",emailId_Del);

	    while((fread(&contactInfo,sizeof(contactInfo),1,fptr)) == 1)
	    {
		if (strcmp(emailId_Del,contactInfo.emailId))
		{
		    fwrite(&contactInfo,sizeof(contactInfo),1,ftemp);
		    count = 0;
		}
		else
		{
		    count++;
		    keepcount = count;

		}
	    }
	    break;

	default:
	    printf("ERROR: Please Enter the Valid Option\n");
	    return 0;
    }

    fclose(fptr);
    fclose(ftemp);

    remove(fname);
    rename("temp.txt", fname);

    if (!keepcount)
    {
	printf("No specified Contact Detail Found\n");
	return 0;
    }
    else
    {
	printf("##Contact Details Deleted Successfully##\n");
    }

    return 1;
}
