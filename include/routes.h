#include <stdlib.h>
#include <string.h>

struct Route {
  char *key;
  char *value;

  struct Route *left, *right;
};

struct Route *init_route(char *key, char *value);

struct Route *add_route(struct Route *root, char *key, char *value);

struct Route *search(struct Route *root, char *key);

void inorder(struct Route *root);
