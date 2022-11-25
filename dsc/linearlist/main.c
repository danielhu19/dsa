#include "linearlist.h"

int main(int argc, char **argv) {
  // SqList S;
   int i;
  // init_sq(&S);
  // create_sq(&S);
  // insert_sq(&S, 5, 1);
  // delete_sq(&S, 5, &i);
  // print_sq(&S);
  LinkList L;
  init_lk(&L);
  create_lk(&L);
  insert_lk(&L, 6, 100);
  delete_lk(&L, 1, &i);
  printf("%d\n",i); 
  print_lk(&L);
  locate_lk(&L,100,compare,&i);
  printf("%d\n",i); 
  search_lk(&L,5,&i);	
  printf("%d\n",i); 
  return 0;
}
