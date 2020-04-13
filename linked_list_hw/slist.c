//Albert Paez
#include <stdlib.h>
#include "slist.h"

snode* snode_create(int data, snode* next){
    snode *p = (snode*)malloc(sizeof(snode));
    p->data = data;
    p->next = next;
    return p;
}

//---------------------------------------------------------------------------

slist* slist_create(void){
    slist* p = (slist*)malloc(sizeof(slist));
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;
    return p;
}

//---------------------------------------------------------------------------

bool slist_empty(slist* list){
    return list->size == 0;
}

//---------------------------------------------------------------------------

size_t slist_size(slist* list){
    return list->size;
}

//---------------------------------------------------------------------------

void slist_popfront(slist* list){
    if(slist_empty(list)) { 
        fprintf(stderr, "Underflow error\n"); 
        exit(1);
    }
    snode* p = list->head->next;

    free(list->head);
    list->head = p;
    --list->size;
}

//---------------------------------------------------------------------------

void slist_popback(slist* list){
    if (slist_empty(list)) { 
        fprintf(stderr, "Underflow error\n"); 
        exit(1); 
    }
    snode* p = list->head;
    while (p->next != list->tail) { p = p->next; }

    p->next = NULL;
    free(list->tail);
    list->tail = p;
    --list->size;
}

//---------------------------------------------------------------------------

void slist_pushfront_node(slist* list, snode* no){
    //if empty
    //if one
    //if 2 or more
    no->next = list->head;
    list->head = no;
    if (list->size == 0 ) { list->tail = no; }
    ++list->size;
}

//---------------------------------------------------------------------------

void slist_pushfront(slist* list, int data){
    slist_pushfront_node(list, snode_create(data, list->head));

}

//---------------------------------------------------------------------------

void slist_pushback_node(slist* list, snode* no){
    if (list->size == 0) { 
        slist_pushfront_node(list, no); 
        return;
    }
    no->next = NULL;
    list->tail->next = no;
    list->tail = no;
    ++list->size;
}

//---------------------------------------------------------------------------

void slist_pushback(slist* list, int data){
    slist_pushback_node(list, snode_create(data, NULL));
}

//---------------------------------------------------------------------------

void slist_clear(slist* list){
    while (!slist_empty(list)) {
        slist_popfront(list);
    }
}

//---------------------------------------------------------------------------

void slist_print(slist* list, const char* msg){
    printf("%s \n" , msg);
    snode* p = list->head;
    while(p != NULL){
        printf("%d --> %p\n" , p->data, p->next);
        p = p->next;
    }
}

//---------------------------------------------------------------------------

int slist_front(slist* list){
    return list->head->data;
}

//---------------------------------------------------------------------------

int slist_back(slist* list){
    return list->tail->data;
}



