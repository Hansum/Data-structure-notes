#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int array[5];
   int i;
   
   for(i=0;i<5;i++){
       array[i] = i+1;
   }
   
   printf("Array populated");
   getch();
   
   for(i=0;i<5;i++){
       printf("%d ", array[i]);
   }
   
   getch();
   return 0;
}
