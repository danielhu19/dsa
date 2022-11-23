#include "linearlist.h"

int main(int argc, char **argv) {
  SqList S;
  int i;
  init_sq(&S);
  create_sq(&S);
  insert_sq(&S, 5, 1);
  delete_sq(&S, 5, &i);
  print_sq(&S);
  return 0;
}
