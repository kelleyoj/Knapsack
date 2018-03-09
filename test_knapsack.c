#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knapsack.h"

/* pointer to linked list node data structure */


int main(){

  //used to store size and count of the entered number
  unsigned int temp,temp2;

  //creating the two knapsacks
  listitemptr k1= malloc(sizeof(listitemptr));
  listitemptr k2 = malloc(sizeof(listitemptr));

  //setting k2 to null and count and item to 0
  k2->count = 0;
  k2->item = 0;
  k2 = NULL;

  //setting k2 to null and count and item to 0
  k1->count =0;
  k1->item =0;
  k1 = NULL;

  //inserting into k2
  k2 =KnapsackAdd(k2,0);
  k2 =KnapsackAdd(k2,4);
  k2 =KnapsackAdd(k2,5);
  k2 =KnapsackAdd(k2,7);
  k2 =KnapsackAdd(k2,9);
  k2 =KnapsackAdd(k2,0);
  k2 =KnapsackAdd(k2,10);

  //inserting into k1
  k1 =KnapsackAdd(k1,5);
  k1 =KnapsackAdd(k1,2);
  k1 =KnapsackAdd(k1,5);
  k1 =KnapsackAdd(k1,10);
  k1 =KnapsackAdd(k1,5);
  k1 =KnapsackAdd(k1,10);
  k1 =KnapsackAdd(k1,2);

  //removing from k2
  k2 =KnapsackRemove(k2,4);
  k2 =KnapsackRemove(k2,0);

  //removing from k1
  k1 =KnapsackRemove(k1,5);
  k1 =KnapsackRemove(k1,10);

  //getting size and item count of 2 for k1
  temp = KnapsackSize(k1);
  temp2 = KnapsackItemCount(k1,5);

  //printing both k1 and k2
  printf("\nThe first Knapsack\n");
  KnapsackPrint(k1);

  printf("\nThe second Knapsack\n");
  KnapsackPrint(k2);


  //printing the amount of times the entered node appeared
  printf("\nThe amount of times 5 appears is: %d\n",temp2 );

 //printing the size of the linked list
  printf("The size of the first list is: %d\n",temp);

}
