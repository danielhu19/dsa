#include "linearlist.h"

/* ****************** SqList ****************** */
/*
 * Initialize a NULL sequence list
 * L: pointer which points to SqList
 * */
Status init_sq(SqList *L) {
  L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
  assert(L->elem);
  L->length = 0;
  L->listsize = LIST_INIT_SIZE;
  return EXIT_SUCCESS;
}

// Destory a linear list
Status destory_sq(SqList *L) {
  free(L->elem);
  L->elem = NULL;
  L->length = 0;
  L->listsize = 0;
  return EXIT_SUCCESS;
}

// Create a linear with random number
Status create_sq(SqList *L) {
  // Initialization, should only be called once.
  int len = 5; /* choose one you like */
  // https://stackoverflow.com/questions/7343833/srand-why-call-it-only-once/
  srand(time(0));
  for (int i = 0; i < len; ++i) {
    int r = rand();
    L->elem[i] = r;
    ++L->length;
    ++L->listsize;
  }
  return EXIT_SUCCESS;
}

/**
 * @brief Insert 'e' into the 'i'th of L
 *
 * @param L ptr points to the pointer of SqList
 * @param i index of inserting
 * @param e element to insert
 * @return Status
 */
Status insert_sq(SqList *L, int i, ElemType e) {
  assert(L);
  /* 0 <= i <= length + 1 */
  assert(i >= 0 && i < L->length + 1);
  /* reallocate if overflow */
  if (L->length == L->listsize) {
    ElemType *newbase = (ElemType *)realloc(
        L->elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
    assert(newbase);
    L->elem = newbase;
    L->listsize += LISTINCREMENT;
  }

  int *ptr = &(L->elem[i]), *end = &(L->elem[L->length - 1]);
  while (end > ptr) {
    *(end + 1) = *end;
    --end;
  }
  *(end + 1) = *end;
  /**
   * Note for free(): https://en.cppreference.com/w/c/memory/free
   * The behavior is undefined if the value of ptr does not equal a value
   * returned earlier by malloc(), calloc(), realloc(), or aligned_alloc()
   */
  // free(end);
  *ptr = e;
  ++L->length;
  return EXIT_SUCCESS;
}

/**
 * @brief Delete the 'i'th element in SqList, return to e
 *
 * @param L
 * @param i index of deleting
 * @param e element to delete
 * @return Status
 */
Status delete_sq(SqList *L, int i, ElemType *e) {
  assert(L);
  assert(i >= 0 && i < L->length);
  *e = L->elem[i];
  ElemType *ptr = &(L->elem[i]), *end = &(L->elem[L->length - 1]);
  while (ptr < end) {
    *ptr = *(ptr + 1);
    ptr++;
  }
  L->length--;
  return EXIT_SUCCESS;
}

Status compare(ElemType x, ElemType y) { return x == y; }

/**
 * @brief Locate an element by given value, return its index(1st) to 'index'
 *
 * @param L
 * @param e given value to find
 * @param compare function pointer
 * @param index return index of element which equals to e
 * @return Status
 */
Status locate_sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType),
                 int *index) {
  assert(L);
  bool flag;
  for (int i = 0; i < L->length; i++) {
    if (compare(L->elem[i], e)) {
      printf("Found %d in %d", e, i);
      *index = i;
      flag = true;
    }
  }
  if (flag)
    return EXIT_SUCCESS;
  else {
    printf("NOT FOUND!");
    return EXIT_SUCCESS;
  }
}

/**
 * @brief Search element by given index, return value to e
 *
 * @param L
 * @param i given index
 * @param e receiver
 * @return Status
 */
Status search_sq(SqList *L, int i, ElemType *e) {
  assert(L);
  assert(i >= 0 && i <= L->length);
  *e = L->elem[i];
  return EXIT_SUCCESS;
}

// print the SqList
void print_sq(SqList *L) {
  assert(L);
  for (int i = 0; i < L->length; ++i) printf("%d ", L->elem[i]);
  printf("\n");
}

/* ****************** SingleLinkedList ****************** */

/**
 * @brief Construct a NULL SingleLinkedList
 *
 * @param L Head Pointer
 * @return status
 */
Status init_lk(LinkList *L) {
  *L = (LinkList)malloc(sizeof(LNode));
  assert(*L);
  (*L)->next = NULL;
  return EXIT_SUCCESS;
}

Status destory_lk(LinkList *L) {
  assert(*L);
  LinkList *q = NULL;
  while (*L) {
    *q = (*L)->next;
    free(*L);
    *L = *q;
  }
  return EXIT_SUCCESS;
}

/**
 * @brief Create a SingleLinkedList which contains 5 LNodes
 * Inverse Order!
 * @param L
 * @return Status
 */
// Status create_lk(LinkList *L) {
//   assert(*L);
//   int length = 5;
//   srand(time(0));
//   for (int i = length; i > 0; i--) {
//     LinkList new = (LinkList)malloc(sizeof(LNode));
//     assert(new);
//     new->data = rand();
//     new->next = (*L)->next;
//     (*L)->next = new;
//   }
//   return EXIT_SUCCESS;
// }

/**
 * @brief Create a SingleLinkedList which contains 5 LNodes
 * Seriate Order!
 * @param L
 * @return Status
 */
Status create_lk(LinkList *L) {
  assert(*L);
  int length = 5;
  srand(time(0));
  LinkList end = *L;
  for (int i = 0; i < length; i++) {
    LinkList new = (LinkList)malloc(sizeof(LNode));
    assert(new);
    new->data = rand();
    new->next = NULL;
    end->next = new;
    end = end->next;
  }
  return EXIT_SUCCESS;
}

void print_lk(LinkList *L) {
  assert(*L);
  LinkList *ptr = L;
  while ((*ptr)->next) {
    printf("%d ", (*ptr)->next->data);
    ptr = &((*ptr)->next);  // not human readable hahahahahaha
  }
  printf("\n");
}

/* return the length of sg linked list */
int GetLen(LinkList *L) {
  int len = 0;
  assert(*L);
  LinkList *ptr = L;
  while ((*ptr)->next) {
    ++len;
    ptr = &((*ptr)->next);
  }
  return len;
}

/**
 * @brief Insert a LNode before the 'i'th of SingleLinkedList
 *
 * @param L
 * @param i index to insert
 * @param e value to insert
 * @return Status
 */
Status insert_lk(LinkList *L, int i, ElemType e) {
  assert(*L);
  assert(i >= 1 && i <= GetLen(L) + 1);
  LinkList new = (LinkList)malloc(sizeof(LNode));
  assert(new);
  new->data = e;
  LinkList ptr = *L;
  for (int j = 0; j < i - 1; j++) ptr = ptr->next;  // find the 'i-1'the LNode
  new->next = (*ptr).next;
  (*ptr).next = new;
  return EXIT_SUCCESS;
}

/**
 * @brief  Delete the 'i'th LNode
 *
 * @param L
 * @param i index to delete
 * @param e receiver
 * @return Status
 */
Status delete_lk(LinkList *L, int i, ElemType *e) {
  assert(*L);
  assert(i >= 1 && i <= GetLen(L));
  int j = 0;
  LinkList p = *L;
  // find the 'i-1'the LNode
  while (p->next && j < i - 1) {
    p = p->next;
    j++;
  }
  LinkList q = p->next;
  p->next = q->next;
  q->next = NULL;
  *e = q->data;
  free(q);
  return EXIT_SUCCESS;
}

/**
 * @brief Locate the index of given element 'e'
 *
 * @param L
 * @param e given element
 * @param compare function pointer
 * @param index receiver
 * @return Status
 */
Status locate_lk(LinkList *L, ElemType e, Status compare(ElemType, ElemType),
                 int *index) {
  assert(*L);
  LinkList ptr = (*L)->next;
  int i = 0;
  while (ptr) {
    i++;
    if (compare(e, ptr->data)) {
      *index = i;
      return EXIT_SUCCESS;
    }
    ptr = ptr->next;
  }
  printf("Not Found!\n");
  return EXIT_FAILURE;
}

/**
 * @brief Search element of the 'i'th index, return to e
 *
 * @param L
 * @param i index to search
 * @param e receiver
 * @return Status
 */
Status search_lk(LinkList *L, int i, ElemType *e) {
  assert(*L);
  assert(i >= 1 && i <= GetLen(L));
  LinkList ptr = *L;
  while (i) {
    i--;
    ptr = ptr->next;
  }
  *e = ptr->data;
  return EXIT_SUCCESS;
}