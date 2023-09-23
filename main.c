#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);
  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        list_print(mylist);
        printf("list_add_to_front : FAILED\n");
  }
  else{
    printf("list_add_to_front : PASSED\n");
  }

  list_remove_at_index(mylist, 3);

  if(strcmp("100->90->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        list_print(mylist);
        printf("list_remove_at_index 1: FAILED\n");
  }
  else{
    printf("list_remove_at_index 1 : PASSED\n");
  }

  list_remove_at_index(mylist, 20);
  list_remove_at_index(mylist, 1);
  list_remove_at_index(mylist, 6);

  if(strcmp("90->70->60->50->40->20->10->NULL",listToString(mylist)) != 0)
  {
        list_print(mylist);
        printf("list_remove_at_index 2: FAILED\n");
  }
  else{
    printf("list_remove_at_index 2 : PASSED\n");
  }
 
  list_print(mylist);
  
  if(list_length(mylist) != 7){
    printf("list_length: FAILED\n");
  }
  else{
    printf("list_length : PASSED\n");
  }

  list_print(mylist);
  printf("The list length is %d\n", list_length(mylist));

  list_add_at_index(mylist, 21, 1);
  list_add_at_index(mylist, 65, 0);
  list_add_at_index(mylist, 10, 8);
  list_add_at_index(mylist, 22, 7);
  list_print(mylist);
  if(strcmp("21->90->70->60->50->40->22->20->10->10->NULL",listToString(mylist)) != 0)
  {
        list_print(mylist);
        printf("list_add_at_index : FAILED\n");
  }
  else{
    printf("list_add_at_index  : PASSED\n");
  }

  list_add_to_back(mylist, 37);
  list_add_to_back(mylist, 19);
  list_add_to_back(mylist, 53);
  list_add_to_back(mylist, 72);
  list_add_to_back(mylist, 7);
  if(strcmp("21->90->70->60->50->40->22->20->10->10->37->19->53->72->7->NULL",listToString(mylist)) != 0)
  {
        list_print(mylist);
        printf("list_add_to_back: FAILED\n");
  }
  else{
    printf("list_add_to_back  : PASSED\n");
  }
  
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_remove_from_back(mylist);
  list_remove_from_back(mylist);
  list_remove_at_index(mylist, 3);
  list_remove_at_index(mylist, 7);
  if(strcmp("70->60->40->22->20->10->37->19->53->NULL",listToString(mylist)) != 0)
  {
        list_print(mylist);
        printf("list_remove_from_back/list_remove_at_index: FAILED\n");
  }
  else{
    printf("list_removal : PASSED\n");
  }

  printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
  printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
