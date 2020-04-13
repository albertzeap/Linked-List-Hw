//Albert Paez
#include <stdlib.h>
#include "dlist.h"

dnode* dnode_create(int data, dnode* prev, dnode* next){
    dnode* p = (dnode*)malloc(sizeof(dnode));
    p->data = data;
    p->next = next;
    p->prev = prev;
    return p;
}

//-----------------------------------------------------------------------

dlist* dlist_create(void){
    dlist* p = (dlist*)malloc(sizeof(dlist));
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    return p;
}

//-----------------------------------------------------------------------

bool dlist_empty(dlist* list){
    return list->size == 0;
}

//-----------------------------------------------------------------------

size_t dlist_size(dlist* list){
    return list->size;
}

//-----------------------------------------------------------------------

void dlist_popfront(dlist* list){
   if(dlist_empty(list)) { 
        fprintf(stderr, "Underflow error\n"); 
        exit(1);
    }
    dnode* p = list->head->next;

    free(list->head);
    list->head = p;
    --list->size;
}

//-----------------------------------------------------------------------

void dlist_popback(dlist* list){
    if (dlist_empty(list)) { 
        fprintf(stderr, "Underflow error\n"); 
        exit(1); 
    }
    dnode* p = list->head;
    while (p->next != list->tail) { p = p->next; }

    p->next = NULL;
    free(list->tail);
    list->tail = p;
    --list->size;
}

//-----------------------------------------------------------------------

void dlist_pushfront_node(dlist* list, dnode* no){
    //if empty
    //if one
    //if 2 or more
    no->next = list->head;
    list->head = no;
    if (list->size == 0 ) { list->tail = no; }
    ++list->size;
}

//-----------------------------------------------------------------------

void dlist_pushfront(dlist* list, int data){
    dlist_pushfront_node(list,dnode_create(data, NULL, list->head));
}

//-----------------------------------------------------------------------

void dlist_pushback_node(dlist* list, dnode* no){
    if (list->size == 0) { 
        dlist_pushfront_node(list, no); 
        return;
    }
    no->next = NULL;
    list->tail->next = no;
    list->tail = no;

    ++list->size;
}

//-----------------------------------------------------------------------

void dlist_pushback(dlist* list, int data){
    dlist_pushback_node(list, dnode_create(data,list->tail, NULL));
}

//-----------------------------------------------------------------------

void dlist_clear(dlist* list){
    while(!dlist_empty(list)){
        dlist_popfront(list);
    }
}

//-----------------------------------------------------------------------

void dlist_print(dlist* list, const char* msg){
     printf("%s \n" , msg);
    dnode* p = list->head;
    while(p != NULL){
        printf("%p <--%d (%p) --> %p\n" , p->prev, p->data, p, p->next);
        p = p->next;
    }
}

//-----------------------------------------------------------------------

int dlist_front(dlist* list){
    return list->head->data;
}

//-----------------------------------------------------------------------

int dlist_back(dlist* list){
    return list->tail->data;
}
