//The Menu : New,Display,Exit
//Using Dynamic Memory Allocation
//Search for an employment by his name or by his code
#define Highlightattr 0x70
#define Normalattr 0x07
#define ENTER 13
#define HOME  71
#define END 79
#define ESC 27
#define UP 72
#define DOWN 80
#define New 0
#define Display 1
#define Exit 2
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
typedef struct employee
   {
    int checkFlag;
    int code;
    int age;
    char name [10];
   }emp;
//prototypes:
void display (struct employee *ptr,int i);
struct employee AddNew (emp *ptr,int number);
struct employee Delete(struct employee emp[],int del);
void displayAll(struct employee emp[],int size);
void empSearch(emp *ptr,char key1[]);

void main ()
{
  clrscr();
  flushall();
  emp emp[20];

  char key1[5]; //search key1 for name
  int key2;	//search key2 for code
  char ch;      //pressed key
  char y; 	//y for yes
  int Num; 	//number of employees
  int i; 	//for any loop
  int pos=0; 	//position variable
  int dis; 	//display choice
  int number=0; //number of Employmees required
  int num;	//specific employee to display
  employee *ptr;	//pointer to the memory required
  ptr = (employee*)malloc(number*sizeof(int*)); //DMA
  int terminated=0;		     //exit flag

  //Make all the checkFlags 0 to represent them as empty places.
  for(i=0;i<3;i++)
  {
   strcpy(emp[i].name,"EMPTY");
   emp[i].age=0;
   emp[i].code=0;
  }
  //End
 do
 {
  //Draw the MENU with the highlight.
  for(i=0;i<3;i++)
  {
	if(pos ==0)
	{
	    textattr(Normalattr);
	    gotoxy(37,5);
	    textattr(Highlightattr)   ;
	    cprintf("New");
	    gotoxy(37,6);
	    textattr(Normalattr);
	    cprintf("Display");
	    gotoxy(37,7);
	    textattr(Normalattr);
	    cprintf("Exit");
	}
	if(pos ==1)
	{
	    gotoxy(37,5);
	    textattr(Normalattr);
	    cprintf("New");
	    gotoxy(37,6);
	    textattr(Highlightattr);
	    cprintf("Display");
	    gotoxy(37,7);
	    textattr(Normalattr);
	    cprintf("Exit");
	}
	if(pos ==2)
	{
	    gotoxy(37,5);
	    textattr(Normalattr);
	    cprintf("New");
	    gotoxy(37,6);
	    textattr(Normalattr);
	    cprintf("Display");
	    gotoxy(37,7);
	    textattr(Highlightattr);
	    cprintf("Exit");
	}
  }
  //End of draw the MENU with the highlight.

  ch=getch();
  switch(ch)
  {
	case ESC:
	terminated=1;
	break;

	case ENTER: //To choose between New,Display,Exit
	switch(pos)
	{
		case New:
		clrscr();
		gotoxy(25,10);
		printf("Enter the number of employees = ");
		scanf("%d",&number);
		ptr = (employee *)malloc(number * sizeof(emp));
		{
			printf("Enter the data of employee no.%d",i+1);
			AddNew(ptr,number);
		}
		getch();
		clrscr();
		break;


		case Display:
		clrscr();
		gotoxy(30,10);
		printf("\nChoose (1)Display All or (2)Display Employee (3)Search ");
		scanf("%d",&dis);
		if(dis == 1)
		{
			printf("\t\t All The Employee .. ");
//			num = number;
			displayAll(ptr,number);
			printf("\n\t\tAll the Employees Are Displayed " );
			getch();
		}

		if(dis == 3)
		{
			 //search by name
			 printf("Enter the name: ");
			 scanf("%s",&key1);
			 empSearch( ptr,key1);
			//search by code
			// printf("Enter the code: ");
			// scanf("%d",&key2);
			//empSearch( ptr,key2);

		}
		if(dis == 2)
		{
			printf("Enter the required number to display: ");
			scanf("%d",&num);
			if(num>-1 && num<number) //control
			{
				display(ptr,num);
			}
			else
			{
				printf("\nThe number does not exist ");
			}
			getch();
		}
		clrscr();
		break;


		case Exit:
		terminated=1;
		break;

	}
	break;
	case NULL: //control the motion
	ch=getch(); //must getch again because they are extended buttons
	switch(ch)
	{
	//in case up button is pressed
		case UP:
		if(pos==0)
		{
			pos=2;
	     //"CIRCULTATYION"
		}
		else
		{
			pos--;
		}
		break;

		case DOWN:
		if(pos==2)
		{
			pos=0;
		//CIRCULATION"
		}
		else
		{
			pos++;
		}
		break;

		case END:

		pos=0;
		break;

		case HOME:

		pos=0;
		break;
	}
  }
 }while(!terminated);
}
//Function to display
void display (struct employee *ptr,int i)
		{
			printf("\nThe name: ");
			printf("%s",ptr[i].name);
			printf("\nThe code: ");
			printf("%d",ptr[i].code);
			printf("\nThe age: ");
			printf("%d",ptr[i].age);
		}
//Function to diplay all the elements
void displayAll(struct employee *ptr,int size)
{
 int i;
 for(i=0;i<size;i++)
 {
	printf("\nThe Employees %d Data is: ",i+1);
	printf("\nThe name: ");
	printf("%s",ptr[i].name);
	printf("\nThe code: ");
	printf("%d",ptr[i].code);
	printf("\nThe age: ");
	printf("%d",ptr[i].age);
	if(i == size)
	 {
		   printf("\n\t\tAll the employees are displayed");
		   printf(" .... ");
		   getch();
	 }
  }
}
//Function to add new employees
struct employee AddNew (employee *ptr,int number)
{
	struct employee emp;
	for(int i=0;i<number;i++)
	{
		printf("---------");
		ptr[i].checkFlag=1; //Not empty anymore
		printf("\nThe Employee number Data is: ",emp);
		flushall();
		printf("\nThe name: ");
		gets(ptr[i].name);
		printf("\nThe code: ");
		scanf("%d",&ptr[i].code);
		printf("\nThe age: ");
		scanf("%d",&ptr[i].age);
	}
	return emp;
}
//Function to search
void empSearch(emp *ptr,char key1[10])
{
  int Findex = -1;
  int i;
  for(i=0;i<3;i++)
  {
       //	if (ptr[i].code==key2)
	{
		if( !strcmp(ptr[i].name,key1) ) //strcmp send 0 if they are equal
		{
		       Findex=i;
		       break;
		}
	}
  }

  if(Findex>-1)
  {
	printf("\n Found in: %d",Findex);
  }
  else
  {
	printf("\n Not Found");
  }
  getch();
}

