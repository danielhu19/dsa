#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT_SIZE 10
#define Status int
#define SUCCESS 1
#define FAILED 0
#define STACKOVERFLOW 2
#define INFEASIBLE -1

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

/**
 * @brief Initialize a NULL SqList
 *
 * @param s ptr to a SqList
 * @return Status TRUE if successful, FALSE if malloc failed
 */
Status InitList_Sq(SqList *s)
{
    s->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (!s->elem)
        return FAILED;
    s->length = 0;
    s->listsize = LIST_INIT_SIZE;
    return SUCCESS;
}

/**
 * @brief Insert e into before i th place of SqList
 *
 * @param s ptr to SqList
 * @param i inserting place
 * @param e inserting element
 * @return Status
 */
Status Insert_Sq(SqList *s, int i, ElemType e)
{
    /* check if i is legal */
    if (i <= 0 || i > s->length + 1)
        return INFEASIBLE;
    /* Realloc if Overflow */
    if (s->length >= s->listsize)
    {
        ElemType *newbase = (ElemType *)realloc(s->elem, sizeof(ElemType) * LIST_INCREMENT_SIZE + s->listsize);
        if (!newbase)
            return FAILED;
        s->elem = newbase;
        s->listsize += LIST_INCREMENT_SIZE;
    }

    ElemType *ptr1 = &(s->elem[i]);
    for (ElemType *ptr2 = &(s->elem[s->length - 1]); ptr2 >= ptr1; --ptr2)
        *(ptr2 + 1) = *ptr2;
    s->elem[i] = e;
    s->length++;
    return SUCCESS;
}

/**
 * @brief  Delete the ith element from the SqList and returned to e
 *
 * @param s ptr to the SqList
 * @param i place to delete
 * @param e return deleting element to e
 * @return Status
 */
Status Dele_Sq(SqList *s, int i, ElemType *e)
{
    if (i <= 0 || i > s->length)
        return INFEASIBLE;
}
