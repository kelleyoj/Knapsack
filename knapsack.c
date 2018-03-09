#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knapsack.h"


/*
* adds an item to a knapsack; must only update the "count" if the item already exist in the knapsack; "count" must be set to 1 for previously-nonexisting items
* @param knapsack: points to the first listitem in a knapsack; NULL if knapsack has not been created yet
* @param item: integer item to add
* @return pointer to the listitem added/updated; NULL if unsuccessful
*/
listitemptr KnapsackAdd(listitemptr knapsack, int item){
  unsigned int temp=0;
  listitemptr head, newNode,curr;
  head = malloc(sizeof(listitemptr));
  newNode = malloc(sizeof(listitemptr));
  curr = malloc(sizeof(listitemptr));

  //checking to see if the Memory was allocated
  if (head == NULL || newNode == NULL){
    printf("Memory allocation failed\n");
    exit(1);
  }
  curr=knapsack;
  head=knapsack;

  /*
  Adding the node to the list.
  first checking if the head is null.
  if it is then the newnode is set as the head.
  if it isn't the node is checked to see if the integer
  matches anything in the list. if it does the count
  is incremeted
  */
  if(head==NULL){
    newNode->item =item;
    head = newNode;
    head->next = NULL;
    head->count = 1;
    return head;
  }else{
    while(curr!=NULL){
      if(curr->item==item){
        temp =curr->count + 1 ;
        curr->count = temp;
        return head;
      }
      curr= curr->next;
    } //end while loop
    newNode->count = 1;
    newNode->item =item;
    newNode->next = head;
    head = newNode;
  }
  return head;
}//end KnapsackAdd function

/*
* removes a value from a knapsack; must update the "count" and delete the associated listitem when count becomes 0
* @param knapsack: points to the first listitem in a knapsack
* @param item: integer item to remove
* @return pointer to the first listitem in knapsack; NULL if knapsack becomes empty
*/
listitemptr KnapsackRemove(listitemptr knapsack, int item){
  listitemptr next,curr;
  curr = knapsack;
  /*
  recursive checking the list for the item.
  Once the item is found it decrement the counter.
  Once the counter hits zero the item is deleted
  */
  if(curr == NULL){
    printf("Number not Found\n");
    return NULL;
  }else if(curr->item ==item){
    //checking to see if the count = 1
    if(curr->count ==1){
      next = curr->next;
      return next;
    }else{
      //decrement the counter
      curr->count--;
      return curr;
    }
    //freeing the allocated space/deleting the node
    free(curr);
  }else{
    curr->next = KnapsackRemove(curr->next,item);
    return curr;
  }
}

/*
* prints elements and their counts in a knapsack
* @param knapsack: points to the first listitem in a knapsack
* @stdout: for example, "" (nothing) when knpsack==NULL, or "125 (4), -10 (1), 26 (2)" when items include four of 125, one of -10, and two of 26
* @return void
*/

void KnapsackPrint(listitemptr knapsack){
  unsigned int temp;
  //printing if the list is empty
  if(knapsack == NULL){
    printf(" \"\" (nothing)\n");
  }else{
    //iterating the list printing the numbers and their count
    while(knapsack!= NULL){
      printf("%d (%d),",knapsack->item,knapsack->count);
      knapsack= knapsack->next;
    }
    printf("\n");
  }
}

/*
* count the number of specific item in the knapsack
* @param knapsack: points to the first listitem in a knapsack
* @param item: integer item to search for
* @return item count, or 0 if it does not exist
*/
unsigned int KnapsackItemCount(listitemptr knapsack, int item){
  listitemptr curr;
  curr = knapsack;
  unsigned int count=0;
  /*
  iterating through the list
  if the item entered matchs anything in the list
  then count = the count of that item
  The count is then returned
  */
  while (curr != NULL) {
    if(curr->item == item){
      count = curr->count;
    }
    curr= curr->next;
  }
  return count;
}

unsigned int KnapsackSize(listitemptr knapsack){
  unsigned int count=0;
  listitemptr curr;
  curr = knapsack;
  /*
  iterating through the list
  adding the count of node item into count
  then returning the count
  */
  while (curr != NULL) {
    count+=curr ->count;
    curr= curr->next;
  }
  return count;
}
