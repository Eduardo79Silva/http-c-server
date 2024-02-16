#include "../include/routes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Route *init_route(char *key, char *value) {
  struct Route *temp = (struct Route *)malloc(sizeof(struct Route));

  temp->key = key;
  temp->value = value;

  temp->left = temp->right = NULL;

  return temp;
}

struct Route * add_route(struct Route *root, char *key, char *value) {
  if (root == NULL) {
    init_route(key, value);
  }

  if(strcmp(key, root->key) == 0){
    printf("The key of root is equal to the key passed in the parameter");
  }
}
