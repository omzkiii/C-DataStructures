#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char data[20];
  void* prev;
  void* next;
} Node;

typedef struct{
  int length;
  void* start;
} List;

List initlist(){
  List list;
  list.start = NULL;
  list.length = 0;
  return list;
}

int push(List* list, char* data) {
  Node* node = malloc(sizeof(Node));
  strcpy(node->data, data);
  node->next = NULL;
  node->prev = NULL;
  if (list->length == 0) {
    list->start = &node;
    list->length++;
    return 0; 
  }
  node->next = list->start;
  list->start = &node;
  list->length++;
  return 0;
}

int freelist(const List* list) {
  Node* current = list->start;
  while(current != NULL) {
    Node* next = current->next;
    free(current);
    current = next;
  }
  return 0;
}

int traverse(List* list) {
  Node* node = list->start; 
  printf("%p\n", list->start);
  for (int i = 0; i < list->length; i++) {
    printf("%s\n", node->data);
    node = node->next; 
  }
  return 0;
}

int main() {
  List sample = initlist();  
  push(&sample, "Hello");
  // Node* node = sample.start;
  printf("%p\n", sample.start);
  traverse(&sample);
  // freelist(&sample);
}
