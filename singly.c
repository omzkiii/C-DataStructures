#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  void* next;
}Node;

int add_node(Node** head, char* name ){ 
  if(*head == NULL){
    *head = malloc(sizeof(Node));
    strcpy((*head)->name, name);
    (*head)->next = NULL;
    // printf("Add new node\n");
  }
  else{
    Node* new = malloc(sizeof(Node));
    strcpy(new->name, name);
    new->next = *head;
    *head = new;
   
  }
  return 0;
}

int print_list(Node* list){
  while(list != NULL){
    printf("%s\n", list->name);
    list = list->next;
  }

  return 0;
}


int main() {
  Node* List = NULL;
  add_node(&List, "Geomar");
  add_node(&List, "Santos");
  add_node(&List, "Hello");
  add_node(&List, "World");
//  printf("%s\n",List->name);
  
  print_list(List);

  return 0; 
}
