#include "linearlist.h"

/*
 * Initilize a NULL sequence list
 * L: pointer which points to SqList
 * */
Status init_sq(SqList *L){
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	HANDLE_NULL(L->elem);
	L->length = LIST_INIT_SIZE;
	L->listsize = 0;
	return true;
}

// Destory a linear list
Status destory_sq(SqList *L){
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
	return true;
}

// Create a linear with random number
Status create_sq(SqList *L){
	// Initialization, should only be called once.
	// https://stackoverflow.com/questions/7343833/srand-why-call-it-only-once/
	int len = 5; /* choose one you like */
	srand(time(NULL));
	for(int i = 0; i < len; ++i){ 
		int r = rand();
		L->elem[i] = r;
		++L->length;
		++L->listsize;
	}
	return true;
}

/* 
 * Insert 'e' into the 'i'th of L
 * e: element to insert
 * i: index of inserting
 * */
Status insert_sq(SqList *L, int i, ElemType e){
	// check if 0 <= i <= length + 1 
	if(i < 0 || i > length + 1) exit(FALSE);
	// check if overflow
	if(L->length = L->listsize){
		ElemType *newbase = (ElemType *)relloac(L->elem,(LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
		HANDLE_NULL(newbase);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}

	int *ptr = &(L->elem[i]), *end = &(L->elem[L->length - 1]);	
	while(end >= ptr){
		*(end + 1) = *end;
		--end;
	}
	free(end);
	*ptr = e;
	++L->length;
	return true;	
}

Status delete_sq(SqList *L, int i, ElemType *e){}
Status locate_sq(SqList *L, ElemType e, Status(*compare)(ElemType, ElemType), int *index){}
Status search_sq(SqList *L, int i, ElemType *e){}


void print_sq(SqList *L){} 
Status mergelist_sq(SqList *A, SqList *B, SqList *C){}
Status union_sq(SqList *A, SqList *B){}
