#include "list.h"

#define BUFFERSIZE 512
#define DELIM " \n\t"


void loadData( FILE * file, List * list ) {
    char buffer[BUFFERSIZE];
    char * id, * name, * number;
    while ( fgets(buffer,BUFFERSIZE,file) != NULL ) {
        id = strtok(buffer,DELIM);
        name = strtok(NULL,DELIM);
        number = strtok(NULL,DELIM);
        ListInsert(list,name,number);
    }
}

void storeData( FILE * file, List * list, char * filename ) {
    file = fopen(filename,"w");
    ListPrint(list,file);
    fclose(file);
}

int main ( int argc, char ** argv ) {


    if ( argc < 2 ) {
        printf("Please execute the program like this\n");
        printf("./phonebook <filename>\n");
    }

    FILE * data = fopen(argv[1],"r+");

    char cmd[BUFFERSIZE];
    char * command;

    List * phoneBook;
    ListInitialize(&phoneBook);
    printf("Please enter a command\n");
    printf("1. exit - exit the application\n");
    printf("2. print - prints all the user contacts\n");
    printf("3. add <name> <number> - insert name and number on our list\n");
    printf("4. search <name> - prints the phone number of <name>\n");
    printf("5. delete <name> - deletes <name> from phonebook\n");
    printf("6. destroy - delete every number in the list\n");
    printf("7. help - shows the full command list\n");

    loadData(data,phoneBook);

    for(;;) { // command input

        fgets(cmd, BUFFERSIZE, stdin);
        if ( *cmd == '\n' || *cmd =='\t' || *cmd ==' ' ) continue;
        command = strtok(cmd,DELIM);

        if ( strcmp(command,"exit") == 0 ) {

            fclose(data);
            storeData(data,phoneBook,argv[1]);
            ListDestroy(phoneBook);
            break;

        } else if ( strcmp(command,"print") == 0 ) {

            ListPrint(phoneBook,stdout);

        } else if ( strcmp(command,"add") == 0 ) {

            char * name = strtok(NULL, DELIM);
            if ( name == NULL ) continue;
            char * number = strtok(NULL, DELIM);
            if ( number == NULL ) continue;
            printf("Adding %s with number %s\n", name, number);
            ListInsert(phoneBook, name, number);

        } else if ( strcmp(command,"search") == 0 ) {

            char * name = strtok(NULL, DELIM);
            if ( name == NULL ) continue;
            printf("Searching for %s...\n", name);
            ListSearch(phoneBook,name);
            
        } else if ( strcmp(command,"delete") == 0 ) {
            char * name = strtok(NULL, DELIM);
            if ( name == NULL ) continue;
            ListDelete(phoneBook,name);

        } else if ( strcmp(command,"destroy") == 0 ) {
            printf("Deleting the whole list...\n");
            ListDestroy(phoneBook);
        } else if ( strcmp(command,"help") == 0 ) {

            printf("1. exit - exit the application\n");
            printf("2. print - prints all the user contacts\n");
            printf("3. add <name> <number> - insert name and number on our list\n");
            printf("4. search <name> - prints the phone number of <name>\n");
            printf("5. delete <name> - deletes <name> from phonebook\n");
            printf("6. destroy - delete every number in the list\n");
            printf("7. help - shows the full command list\n");

        } else {
            printf("Unknown command, try again..\n");
            printf("Use help for full list of commands.\n");
        }

    }
    


}