//MAGIC BOX Assignment.
#include <stdio.h>
#include <conio.h>

 void main ()
{
 clrscr();
 int order;//order of the magicbox
 int currentNumber=1;
 int row;
 int column;
 printf("Enter the order: ");
 scanf("%d",&order);

//SO, The number is odd so we can make our MAGICBOX.
 if(order%2 != 0)
  {
    printf("Our MAGIC BOX is: %d x %d ",order,order);
    printf("\nPress Enter to display the MAGIC BOX");
    getch();
    clrscr();
//We still in the else.
//FIRST: we print the 1 in the middle of the first row.
    row=1;
    column=(order/2)+1;
    gotoxy(5*column,2*row);
    printf("1");
//Start the test to decide the place of the next number.
    currentNumber=1;
    while(currentNumber < (order * order))
     {
//Case1: when the number can't be devided by the order.
       if (currentNumber%order !=0)
	 {
	   column=column-1;
	   row=row-1;
//circulation takes place here after 1
	   if(column == 0)
	     {
	       column=order;
	     }
	   if(row ==0)
	     {
	       row=order;
	     }
	 }
       else
//Case2 : when the number could be deivided by the order.
//currentNumber%order == 0.
	 {
	   row=row+1;
//Circulation takes place here at the order number.
	   if(row>order)
	     {
	       row=1;
	     }
	 }
//Multiply the column,row by 4 to prevent overlapping between the numbers.
       gotoxy(5*column,2*row);
       printf("%d",currentNumber+1);
//Then increment the currentNumber to test the next number.
       currentNumber++;
     }
   }
   else
  {
    printf("Magic box can't be done");
  }
 getch();
}
