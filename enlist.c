#include <stdio.h>
#include <stdlib.h>
#include "enlist.h"

void print_list(struct node * n){
  while(n != NULL){
    printf("%d\n",n->i);
    n = n->next;
  }
}


struct node * insert_front(struct node *n, int j){
  struct node *new = malloc(sizeof(struct node));
  new -> i = j;
  new -> next = n;
  return new;
}


struct node * free_list(struct node * n){
  while(n != NULL){
    struct node *curr = n;
    n = n -> next;
    free(curr);
  }
  return n;
}

int main(){
  struct node *a = malloc(sizeof(struct node));
  struct node *b = malloc(sizeof(struct node));
  struct node *c = malloc(sizeof(struct node));
  struct node *d = malloc(sizeof(struct node));
  a -> i = 1;
  a -> next = b;
  b -> i = 2;
  b -> next = c;
  c -> i = 3;
  c -> next = d;
  d -> i = 4;
  d -> next = NULL;
  printf("print_list:\n");
  print_list(a);
  printf("\n");
  printf("insert_front:\n");
  struct node *front = insert_front(a,0);
  print_list(front);
  printf("\n");
  printf("free_list:\n");
  front = free_list(front);
  print_list(front);
  printf("\n");
}


