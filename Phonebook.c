#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>


typedef struct name
{
  char fname[20];
  char lname[20];
}NAM;

typedef struct contact
{
    char landline[12];
    char mobile[12];
}CON;

typedef struct phoneentry
{
    NAM pname;
    CON Pcontact;
}PENT;

void printfmenu()
{
    printf("\n*************************************");
    printf("\n 1. Press 1 to records in phone book :");
    printf("\n 2. Press 2 to delete a record : ");
    printf("\n 3. Press 3 to to list available records : ");
    printf("\n 4. Press 4 to search a record : ");
    printf("\n 5. Press 5 to exit : ");
    printf("\n*************************************");

}

void addrecord(PENT book[],int *count)
{
    char ch;
    system("cls");
    printf("\n          *************\n");
    printf("              ADD RECORDS\n");
    printf("            *************\n");
    fflush(stdin);
    printf("Enter the first name of the Person:\t");
    gets(book[*count].pname.fname);
    printf("Enter The Last Name of The Pername:\t");
    gets(book[*count].pname.lname);
    printf("Enter the landline number:\t");
    gets(book[*count].Pcontact.landline);
    printf("Enter The Mobile Number:\t");
    gets(book[*count].Pcontact.mobile);
    (*count)++;
    printf("Record Entered Successfully\n\n");
    //flushall();
    printf("You Want To Enter More Record(Y/N):\t ");
    scanf("%c",&ch);
    //flushall();
    if(ch=='Y'||ch=='y')
    {
        addrecord(book,count);
    }
    else
    {
        return;
    }
}

void listrecord(PENT book[],int count)
{
    int i=0;
    //clrscr();
	system("cls");
    printf("            *************\n");
    printf("            Listing Records\n");
    printf("            *************\n");
    printf("\n%-4s %-20s%-20s%-15s%-12s\n","S.no","First name","Last name","Landline No.","Mobile No.");
    printf("----------------------------------------------------------------\n");
    while(i<count)
    {
        printf("%4d.%-20s%-20s%-15s%-12s\n",i+1,book[i].pname.fname,book[i].pname.lname,book[i].Pcontact.landline,book[i].Pcontact.mobile);
        i++;
    }
    printf("----------------------------------------------------------------\n");
    printf("\n%d record(s) available\n",count);
    printf("Press any key to return to main menu...\n");
    getch();
}

void searchrecord(PENT book[],int count)
{
    int ch,i=0,found=0,no=0;
    char key[25];
    //clrscr();
	system("cls");

    printf("            ***************\n");
    printf("            Search Record\n");
    printf("            ***************\n");
    printf("\n1.Press 1 to search by first name : ");
    printf("\n2.Press 2 to search by last name : ");
    printf("\n3.Press 3 to search by mobile number : ");
    printf("\n4.Press any other key to return to main menu : ");
    //flushall();
    printf("\nEnter Your Choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        fflush(stdin);
        printf("\n\nEnter the first name of the person : ");
        //flushall();
        gets(key);
        while(i<count)
        {
            if(strcmp(book[i].pname.fname,key)==0)
            {
                if(no==0)
                {
                    printf("\n%-4s%-20s%-20s%-12s%-12s\n","S.No","First name","Last name","Landline No","Mobile No.");
                }
                found=1;
                no++;
                printf("%4d.%-20s%-20s%-12s %-12s\n",no,book[i].pname.fname,book[i].pname.lname,book[i].Pcontact.landline,book[i].Pcontact.mobile);

            }
            i++;
        }
        if(found==0)
        {
            printf("No Record found\n");
        }
        else
        {
            printf("\n%d record(s) found\n",no);
        }
        printf("Press any key to continue...\n");
        getch();
        break;

    case 2:
        fflush(stdin);
        printf("\n\nEnter The Last Name Of The Person\n");
        //flushall();
        gets(key);
        while(i<count)
        {
             if(strcmp(book[i].pname.lname,key)==0)
            {
                if(no==0)
                {
                    printf("\n%-4s%-20s%-20s%-12s%-12s\n","S.No","First name","Last name","Landline No","Mobile No.");
                }
                found=1;
                no++;
                printf("%4d.%-20s%-20s%-12s %-12s\n",no,book[i].pname.fname,book[i].pname.lname,book[i].Pcontact.landline,book[i].Pcontact.mobile);

            }
            i++;
        }
        if(found==0)
        {
            printf("No Record found\n");
        }
        else
        {
            printf("\n%d record(s) found\n",no);
        }
        printf("Press any key to continue...\n");
        getch();
        break;


    case 3:
        fflush(stdin);
        printf("\n\nEnter The mobile number O The Person\n");
        //flushall();
        gets(key);
        while(i<count)
        {
             if(strcmp(book[i].Pcontact.mobile,key)==0)
            {
                if(no==0)
                {
                    printf("\n%-4s%-20s%-20s%-12s%-12s\n","S.No","First name","Last name","Landline No","Mobile No.");
                }
                found=1;
                no++;
                printf("%4d.%-20s%-20s%-12s %-12s\n",no,book[i].pname.fname,book[i].pname.lname,book[i].Pcontact.landline,book[i].Pcontact.mobile);

            }
            i++;
        }
        if(found==0)
        {
            printf("No Record found\n");
        }
        else
        {
            printf("\n%d record(s) found\n",no);
        }


    }
    printf("Press any key to continue...\n");
    getch();
}

void deleterecord(PENT book[],int* count)
{
    int sno,i;
    //clrscr();
	system("cls");
    printf("            ********************\n");
    printf("             Record Deletion\n");
    printf("            ********************\n");
    printf("\n\nEnter The S.No of the record that you want to delete : ");
    scanf("%d",&sno);
    i=sno-1;
    if(sno<=0||sno>*count)
    {
        printf("\n Not a Valid");
    }
    else
    {
        while(i<*count)
        {
            book[i]=book[i+1];
            i++;
        }
        *count=*count-1;
        printf("\n Record deleted successfully");

    }
    printf("\n Press any key to return to main menu");
    getch();
}

int main()
{
    int ch,count=0;
    PENT book[50];
    //clrscr();
    system("cls");


    while(1)
    {
        printf("    Phone Book  \n");
        printfmenu();
        printf("\n\n Enter The choice : ");
        scanf("%d",&ch);
        //flushall();

        switch(ch)
        {
        case 1:
            addrecord(book,&count);
            break;

        case 2:
            deleterecord(book,&count);
            break;

        case 3:
            listrecord(book,count);
            break;

        case 4:
            searchrecord(book,count);
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("\n Invalid Option\n");
            getch();
            exit(1);
        }
        system("cls");
    }

}
