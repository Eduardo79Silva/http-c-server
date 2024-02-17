#include "../include/routes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Route *init_route(char *key, char *value) {
  struct Route *temp = (struct Route *)malloc(sizeof(struct Route));

  temp->key = key;
  temp->value = value;

  temp->left = temp->right = NULL;

  return temp;
}

struct Route *add_route(struct Route *root, char *key, char *value) {
  if (root == NULL) {
    return init_route(key, value);
  }

  if (strcmp(key, root->key) == 0) {
    printf("The key of root is equal to the key passed in the parameter");
  } else if (strcmp(key, root->key) > 0) {
    root->right = add_route(root->right, key, value);
  } else {
    root->left = add_route(root->left, key, value);
  }

  return root;
}

struct Route *search(struct Route *root, char *key){
    if(root == NULL){
        return NULL;
    }

    int is_key = strcmp(key, root->key);

    if(is_key == 0){
        return root;
    } else if (is_key > 0) {
        return search(root->right, key);
    } else if (is_key < 0) {
        return search(root->left, key);
    } else {
        return NULL;
    }
}

void inorder(struct Route* root)
{

    if (root != NULL) {
        inorder(root->left);
        printf("%s -> %s \n", root->key, root->value);
        inorder(root->right);
    }
}
