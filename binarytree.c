#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node { 
  char *data;
  struct Node *left;
  struct Node *right;
};

Node *createNode(char *data){
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void addNode(Node *node, char *data){
  if(strcmp(node->data, data) > 0){
    if(node->left == NULL){
      Node *newNode = createNode(data);
      node->left = newNode;
    }
    else {
      addNode(node->left, data);
    }
  }
  else if (strcmp(node->data, data) < 0) {
    if(node->right == NULL){
      Node *newNode = createNode(data);
      node->right = newNode;
    }
    else {
      addNode(node->right, data);
    }
  }
}

// traverse in left->root-right
void inorder(Node *node){
  if (node != NULL) {
    inorder(node->left);
    printf("%s\n", node->data);
    inorder(node->right);
  }
}

int main() {
  Node *node = createNode("hello");
  addNode(node, "there");
  addNode(node, "the");
  addNode(node, "angel");
  addNode(node, "from");
  addNode(node, "my");
  addNode(node, "nightmare");
  addNode(node, "the");
  addNode(node, "shadow");
  addNode(node, "in");
  addNode(node, "the");
  addNode(node, "background");
  addNode(node, "of");
  addNode(node, "the");
  addNode(node, "morgue");
  inorder(node);
  


  return 0;
}
