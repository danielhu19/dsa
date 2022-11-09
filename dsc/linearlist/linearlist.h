// https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
#ifndef LINEARLIST_H_
#define LINEARLIST_H_

// https://stackoverflow.com/questions/1921539/using-boolean-values-in-c
// https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdbool.h.html
#include <stdbool.h>
#include <stdlib.h>
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c/39475626#39475626
#include <time.h>

#define Status int 
#define FALSE -1
#define ElemType int 

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

#define HANDLE_NULL(X) \
	if(!X) exit(FALSE);

// SqList
Status init_sq(SqList *L);
Status destory_sq(SqList *L); 
Status create_sq(SqList *L);
Status insert_sq(SqList *L, int i, ElemType e);
Status delete_sq(SqList *L, int i, ElemType *e);
Status locate_sq(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType), int *index);
Status search_sq(SqList *L, int i, ElemType *e);


void print_sq(SqList *L); 
Status mergelist_sq(SqList *A, SqList *B, SqList *C);
Status union_sq(SqList *A, SqList *B);

// LinkedLIst


#endif
