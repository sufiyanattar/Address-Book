#include "addressbook.h"

int add_contact(char *fname)
{
    contacts contactInfo;

    FILE *fptr = fopen(fname,"a+");

    if (fptr == NULL)
    {
	perror("fopen");
	fprintf(stderr,"Unable to open the %s file\n",fname);
	return 0;
    }
    int checkPhone = 0,checkEmail= 0;

    printf("Enter Name: ");
    scanf(" %[^\n]",contactInfo.name);

    printf("Enter Phone No.: ");
    scanf(" %s",contactInfo.phone);


    for (int i=0 ;i<strlen(contactInfo.phone); i++)
    {
	if((strlen(contactInfo.phone) < 10) || contactInfo.phone[i] < '0' || contactInfo.phone[i] > '9')
	{
	    checkPhone = 1;
	}
    }

    printf("Enter Email ID: ");
    scanf(" %[^\n]",contactInfo.emailId);

    for (int i=0 ;i<strlen(contactInfo.emailId); i++)
    {
	if (contactInfo.emailId[i] == '@' || contactInfo.emailId[i] == '.')
	{
	    checkEmail++;
	}
    }

    if (checkPhone == 1 || checkEmail != 2)
    {
	printf("ERROR: Please Enter the Valid Phone Number or email ID\n");
	return 0;
    }

    fseek(fptr,0,SEEK_END);

    int add = fwrite(&contactInfo,sizeof(contactInfo),1,fptr);

    if (add)
    {
	printf("##Contact Details Successfully Added##\n");
	printf("---------------------------\n");
    }

    fclose(fptr);

    return 1;

}
