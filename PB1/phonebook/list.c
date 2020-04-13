#include "list.h"

void ListInitialize( List ** list ) {

    (*list) = malloc( sizeof(List));
    if ( (*list) == NULL ) {
        perror("malloc");
        return;
    }

    (*list)->count = 0;
    (*list)->head = NULL;

}

void ListDestroy( List * list ) {

    ListNode * currentNode = NULL;
    while ( list->count > 0 ) {
        currentNode = list->head;
        list->head = list->head->next;
        list->count--;
        free(currentNode);
    }

    free(list);


}

void ListInsert( List * list, char * name, char * number) {

    ListNode * listNode;
    listNode = malloc( sizeof(ListNode) );

    strcpy(listNode->name,name);
    strcpy(listNode->phone,number);
    listNode->next = list->head;

    list->head = listNode;
    list->count++;

}

void ListPrint( List * list, FILE * stream ) {

    if ( list->count == 0 ) printf("List is empty..\n");
    ListNode * listNode = list->head;
    for ( int i = 0; i < list->count; i++ ) {
        fprintf(stream,"%d. %s  %s\n", i+1, listNode->name, listNode->phone);
        listNode = listNode->next;
    }

}

void ListSearch( List * list, char * name ) {

    if ( list->count == 0 ) printf("List is empty..\n");
    ListNode * listNode = list->head;
    for ( int i = 0; i < list->count; i++ ) {
        if ( strcmp(listNode->name,name) == 0 ) {
            printf("%s found!\nPhone number is %s\n", name,  listNode->phone);
            return;
        }
        listNode = listNode->next;
    }
    printf("Name was not found\n");

}

void ListDelete( List * list , char * name ) {

    if( list->count == 0 ) return;

    ListNode * previousNode = NULL;
    ListNode * currentNode = list->head;
    for ( int i = 0; i < list->count; i++ ) {

        if ( strcmp(currentNode->name,name) == 0 ) {
            printf("Found %s! Now deleting...\n", name);
            if (previousNode == NULL ) {
                list->head = currentNode->next;
            } else { 
                previousNode->next = currentNode->next;
            }
            free(currentNode);
            list->count--;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;

    }
    printf("Deletion complete.\n");

}

