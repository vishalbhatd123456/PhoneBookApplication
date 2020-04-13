#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE2 64

typedef struct ListNode {
    char name[BUFFERSIZE2];
    char phone[BUFFERSIZE2];
    struct ListNode * next;
} ListNode;

typedef struct List {
    int count;
    ListNode * head;
} List;

 void ListInitialize( List ** );
 void ListDestroy( List * );
 void ListInsert( List *, char *, char *);
 void ListSearch( List *, char *);
 void ListDelete( List *, char *);
void ListPrint( List *, FILE * );
