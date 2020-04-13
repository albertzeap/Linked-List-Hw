//
//  dlist.h
//  linked_list
//
//  Created by William McCarthy on 084//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#ifndef dlist_h
#define dlist_h

#include <stdio.h>
#include <stdbool.h>


//-------------------------------------------------
typedef struct dnode dnode;
struct dnode {
  int data;
  dnode* prev;
  dnode* next;
};

typedef struct dlist dlist;
struct dlist {
  dnode* head;
  dnode* tail;
  size_t size;
};

//-------------------------------------------------
dnode* dnode_create(int data, dnode* prev, dnode* next);
dlist* dlist_create(void);

bool dlist_empty(dlist* list);
size_t dlist_size(dlist* list);

void dlist_popfront(dlist* list);
void dlist_popback(dlist* list);

void dlist_pushfront(dlist* list, int data);
void dlist_pushback(dlist* list, int data);

void dlist_clear(dlist* list);
void dlist_print(dlist* list, const char* msg);

int dlist_front(dlist* list);
int dlist_back(dlist* list);

void dlist_test(void);


#endif /* dlist_h */
