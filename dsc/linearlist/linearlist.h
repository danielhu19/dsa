// https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
#ifndef LINEARLIST_H_
#define LINEARLIST_H_

// https://stackoverflow.com/questions/1921539/using-boolean-values-in-c
#include <stdbool.h>
#include <stdlib.h> 

#define Status int 
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

// SqList
Status init_sq(SqList *L);
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
