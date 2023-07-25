#include<stdio.h>
#include<malloc.h>
#include<windows.h>
// check if being compiled for windows or posix (linux/bsd/mac)
#ifdef _WIN32
    // include minimal windows headers
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    // include posix headers
    #include <time.h>
#endif

void milli_sleep(unsigned int milliseconds);
void delay_print(char* str, unsigned int milliseconds);
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
void insert();
void del();
void edit();
void search();
void display();
struct student
{
    int roll;
    char name[20];
    char Class[20];
    char branch[20];
    char address[300];
    struct student *next;
};
typedef struct student node;
node *start;
int main()
{
    int ch1;
    start=NULL;
    system("cls");


    do{
           delay_print( ANSI_COLOR_CYAN"\n\t\t\t\tWELCOME TO THE STUDENT RECORD MANAGEMENT SYSTEM \n\n" ANSI_COLOR_RESET,40);
           printf("\t\tPress...\n\n");
    printf(ANSI_COLOR_GREEN"\n\t\t\t\t 1. INSERT A RECORD ");
    printf("\n\t\t\t\t 2. SEARCH A STUDENT  ");
    printf("\n\t\t\t\t 3. EDIT A RECORD ");
    printf("\n\t\t\t\t 4. DELETE A RECORD ");
    printf("\n\t\t\t\t 5. DISPLAY ALL RECORDS  ");
    printf("\n\t\t\t\t 6. EXIT  " ANSI_COLOR_RESET);

    printf("\n\n\t\t Enter your choice= ");
    scanf("%d",&ch1);
    switch(ch1)
    {
    case 1:
        insert();break;
    case 2:
       search();break;
    case 3:
        edit();break;
    case 4:
        del();break;
    case 5:
        display();break;
    case 6:
       printf("\nEnd of application!!\n !THANK YOU!\n");break;
    default:
        printf(ANSI_COLOR_RED"INVALID CHOICE!"ANSI_COLOR_RESET);
    }
    }while(ch1!=6);


    }
void insert()
{  printf(ANSI_COLOR_YELLOW"              ==============================================================================="ANSI_COLOR_RESET) ;
    printf(ANSI_COLOR_GREEN"\n\t\t\t\t\t\tINSERT RECORD \n\n"ANSI_COLOR_RESET);
    char ch;
    do{
    node *temp=(node *)malloc(sizeof(node));
    printf("\nEnter the Roll No: ");
    scanf("%d",&temp->roll);
    printf("Enter the Name: ");
    fflush(stdin);
    scanf("%[^\n]s",temp->name);
    printf("Enter the class: ");
    fflush(stdin);
    scanf("%[^\n]s",temp->Class);;
     printf("Enter the Branch: ");
    fflush(stdin);
    scanf("%[^\n]s",temp->branch);;
    printf("Enter the Address: ");
    fflush(stdin);
    scanf("%[^\n]s",temp->address);;

    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;

    }else{
    node *temp1=start;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    }
  printf(ANSI_COLOR_MAGENTA"\n\t\tRecord added successfully\n\n"ANSI_COLOR_RESET);
  printf("\t\tWant to add more records, if yes press 'y' otherwise 'n' : ");
  fflush(stdin);
  scanf("%c",&ch);
    }while(ch=='y');
}
void search()
{
    printf(ANSI_COLOR_YELLOW"               =============================================================================="ANSI_COLOR_RESET) ;
    printf(ANSI_COLOR_GREEN"\n\t\t\t\t\t\tSEARCH RECORD \n\n"ANSI_COLOR_RESET);
    if(start==NULL)
    {
        printf(ANSI_COLOR_RED"\t\tNo record exist !"ANSI_COLOR_RESET);
        return;
    }
    char str[20];
    printf("Enter the name of the student that you want to search: ");
    fflush(stdin);
    scanf("%[^\n]s",str);
    node *temp=start;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,str)==0)
        {   printf(ANSI_COLOR_RED"\n\t\t\t\t\tRecord Found!!\n"ANSI_COLOR_RESET);
         printf("\t\t ________________________________________________________________________________________\n");
    printf(ANSI_COLOR_MAGENTA "\t\t |     Roll No      |");
    printf("        Name        |");
    printf("    class    |");
    printf("    Branch    |");
    printf("     Address     |\n"ANSI_COLOR_RESET);
    printf("\t\t ----------------------------------------------------------------------------------------\n");
             printf("\t\t         %-17d",temp->roll);

             printf("%-20s",temp->name);

             printf("%-15s",temp->Class);

             printf("%-15s",temp->branch);

             printf("%-20s\n",temp->address);
              printf("\t\t ----------------------------------------------------------------------------------------\n");

            return;
        }
        temp=temp->next;
    }
    printf(ANSI_COLOR_RED"\n\t\tRecord Not found! please enter the correct details..\n"ANSI_COLOR_RESET);
    return;
}
void del()
{
    printf(ANSI_COLOR_YELLOW"               =============================================================================="ANSI_COLOR_RESET) ;
    printf(ANSI_COLOR_GREEN"\n\t\t\t\t\tDELETE RECORD \n\n"ANSI_COLOR_RESET);
    if(start==NULL)
    {
        printf(ANSI_COLOR_RED"No record exist !"ANSI_COLOR_RESET);
        return;
    }
    char str[20];
    printf("Enter the name of the student that record you want to delete: ");
    fflush(stdin);
    scanf("%[^\n]s",str);
    node *temp=start;
    node *temp2=temp;
    while(temp!=NULL)
    {
        temp2=temp;
        if(strcmp(temp->name,str)==0)
        {
            break;
        }

        temp=temp->next;
    }
    if(temp==NULL)
    {
         printf(ANSI_COLOR_RED"\nRecord Not found! please enter the correct details..\n"ANSI_COLOR_RESET);
        return;
    }
    if(temp==start)
        start=start->next;
    else
    temp2->next=temp->next;
    free(temp);
    printf(ANSI_COLOR_MAGENTA"\t\tRecord deleted successfully ! \n"ANSI_COLOR_RESET);
}
void edit()
{   printf(ANSI_COLOR_YELLOW"               =============================================================================="ANSI_COLOR_RESET) ;
    printf(ANSI_COLOR_GREEN"\n\t\t\t\t\tEDIT RECORD \n\n"ANSI_COLOR_RESET);
     if(start==NULL)
    {
        printf(ANSI_COLOR_RED"No record exist !"ANSI_COLOR_RESET);
        return;
    }
    int n;
    printf("Enter the roll no of record that you want to edit: ");
    scanf("%d",&n);
    node *temp=start;
    while(temp!=NULL)
    {
        if(temp->roll==n)
        {
            printf("Enter y if you want to edit the section: ");
            char ch;
            printf("1.Name ?\n");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='y')
            {
                char str[20];
                printf("Enter the new name: ");
                fflush(stdin);
                fgets(str,20,stdin);
                strcpy(temp->name,str);
            }
            printf("2.Branch ?\n");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='y')
            {
                char str1[20];
                printf("Enter the new branch: ");
                fflush(stdin);
                fgets(str1,20,stdin);
                strcpy(temp->branch,str1);
            }
            printf("3.class ?\n");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='y')
            {
                char str2[20];
                printf("Enter the new class: ");
                fflush(stdin);
                fgets(str2,20,stdin);
                strcpy(temp->branch,str2);
            }
            printf("4. Address ?\n");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='y')
            {
                char str3[300];
                printf("Enter the new branch: ");
                fflush(stdin);
                fgets(str3,300,stdin);
                strcpy(temp->address,str3);
            }
            printf(ANSI_COLOR_YELLOW"\t\tRecord Edited successfully!"ANSI_COLOR_RESET);
            return;
        } temp=temp->next;
    } if(temp==NULL)
    {
         printf(ANSI_COLOR_RED"\nRecord Not found! please enter the correct roll no..\n"ANSI_COLOR_RESET);
        return;
    }
}
void display()
{
    node *temp=start;
    if(start==NULL)
    {
        printf(ANSI_COLOR_RED"\nNo record exist! plz insert the record to display..\n"ANSI_COLOR_RESET);
        return;
    }
    printf(ANSI_COLOR_YELLOW"               =============================================================================="ANSI_COLOR_RESET) ;
   printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\t ALL RECORDS \n\n"ANSI_COLOR_RESET);
   printf("\t\t ________________________________________________________________________________________\n");
    printf(ANSI_COLOR_MAGENTA "\t\t |     Roll No      |");
    printf("        Name        |");
    printf("    class    |");
    printf("    Branch    |");
    printf("     Address     |\n"ANSI_COLOR_RESET);
    printf("\t\t ----------------------------------------------------------------------------------------\n");
    while(temp!=NULL)
    {

             printf("\t\t         %-17d",temp->roll);

             printf("%-20s",temp->name);

             printf("%-15s",temp->Class);

             printf("%-15s",temp->branch);

             printf("%-20s\n",temp->address);

            temp=temp->next;
            printf("\t\t ----------------------------------------------------------------------------------------\n");
    }
}

void delay_print(char* str, unsigned int milliseconds)
{
    for (; *str; str++) {
        putchar(*str);
        fflush(stdout);
        milli_sleep(milliseconds);
    }
}

void milli_sleep(unsigned int milliseconds)
{
#ifdef _WIN32
    // use windos Sleep function, sleeps for a number of milliseconds
    Sleep(milliseconds);
#else
    // use posix nanosleep function, sleeps for a number of nanoseconds
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

