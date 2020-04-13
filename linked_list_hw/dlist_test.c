//
//  dlist_test.c
//  linked_list
//
//  Created by William McCarthy on 094//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dlist.h"
#include "utils.h"

//-------------------------------------------------
static void dlist_check_frontback(dlist* list, int front, int back) {
  printf("assert front of list is: %d\n", front);
  assert(dlist_front(list) == front);
  printf("assert back of list is: %d\n", back);
  assert(dlist_back(list) == back);
}

//-------------------------------------------------
static void dlist_test_once(dlist* list, int start, int end, int step, void (*fp)(dlist*, int)) {
  for (int i = start; i < end; i += step) {
    fp(list, i);
  }
  dlist_print(list, "list is created and is...");
  printf("list size is: %zu\n", dlist_size(list));
  printf("list is empty? %s\n", yesorno(dlist_empty(list)));

  int firstadded = start;
  int lastadded = start;
  while (lastadded + step < end) {
    lastadded += step;
  }
  if (fp == dlist_pushback)  { dlist_check_frontback(list, firstadded, lastadded);  }
  if (fp == dlist_pushfront) { dlist_check_frontback(list, lastadded, firstadded ); }

  dlist_clear(list);
  printf("after clearing the list, is the list is now empty? %s\n\n", yesorno(dlist_empty(list)));
}

//-------------------------------------------------
void dlist_test() {
  printf("//===================== TESTING DLIST =========================\n\n");
  dlist* list = dlist_create();
  dlist_test_once(list, 10, 50, 10, dlist_pushfront);
  dlist_test_once(list, 10, 100, 20, dlist_pushback);
  dlist_test_once(list, 0, 100, 1, dlist_pushback);

  printf("      All Assertions passed!...\n");
  free(list);
  printf("//===================== END TESTING DLIST =========================\n\n");
}



