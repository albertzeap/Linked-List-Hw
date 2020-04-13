//
//  slist.h
//  linked_list
//
//  Created by William McCarthy on 084//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#ifndef slist_h
#define slist_h

#include <stdio.h>
#include <stdbool.h>


typedef struct snode snode;
struct snode {
  int data;
  snode* next;
};

typedef struct slist slist;
struct slist {
  snode* head;
  snode* tail;
  size_t size;
};

snode* snode_create(int data, snode* next);
slist* slist_create(void);

bool slist_empty(slist* list);
size_t slist_size(slist* list);

void slist_popfront(slist* list);
void slist_popback(slist* list);

void slist_pushfront(slist* list, int data);
void slist_pushback(slist* list, int data);

void slist_clear(slist* list);

void slist_print(slist* list, const char* msg);

int slist_front(slist* list);
int slist_back(slist* list);

void slist_test(void);


#endif /* slist_h */
