#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    char data;
    struct node *nextnode;
}; 

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void instructions();
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
void printList(ListNodePtr currentPtr); 
bool isempty(ListNodePtr currentPtr);

int main(void){
    ListNodePtr startPtr = NULL;    
    unsigned int choice;
    char item;
    instructions();
    printf("%s", "    ?");
    scanf("%d",&choice);

    while( choice != 3 ){
        switch( choice ){
            case 1: 
                printf("%s\n", "Enter the character to insert: " );
                scanf("\n%c", &item);
                insert(&startPtr,item);
                printList(startPtr);
                break;
            case 2:
                printf("%s\n", "Enter the character to be deleted: ");
                scanf("\n%c", &item);
                delete(&startPtr,item);
                printList(startPtr);
                break;
            default:
                printf("%s\n", " Invalid Input ! ");
        }
        instructions();
        printf("%s", "    ?");
        scanf("%d",&choice);
    }
    return 0;
}

void insert(ListNodePtr *sPtr, char value ){
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc( sizeof(ListNode) );

    if( newPtr != NULL ){
        newPtr->data = value ;
        newPtr->nextnode = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while( (currentPtr != NULL ) && ( value > currentPtr->data ) ){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextnode;
        }
        if (previousPtr == NULL){
            newPtr->nextnode = currentPtr;
            (*sPtr) = newPtr;
        }
        else{
            previousPtr->nextnode = newPtr;
            newPtr->nextnode = currentPtr;
        }    
    }
    else {
        printf( "%s", "\nCannot insert no memory available !"  );
    }

}

bool isempty(ListNodePtr currentPtr){
    if ( currentPtr == NULL )return true;
    return false;
}

void printList(ListNodePtr currentPtr){
    if( isempty(currentPtr) ){
        puts ( "\nThe list is empty!" );
    }
    else {
        puts( "The list is :" );
        while(currentPtr != NULL){
            printf( "%c -->", currentPtr->data );
            currentPtr = currentPtr->nextnode;
        }
        puts( "NULL" );
    }
}

char delete( ListNodePtr *sPtr, char value ){
    ListNodePtr currentPtr;
    ListNodePtr previousPtr;
    ListNodePtr tempPtr;
    if((*sPtr) == NULL) return '\0';
    if ( (*sPtr)->data == value ){
        tempPtr = (*sPtr);
        (*sPtr) = (*sPtr)->nextnode;
        free(tempPtr);
        return value;
    }
    else{   
        printf("aa\n");
        currentPtr = (*sPtr)->nextnode;
        previousPtr = (*sPtr);
        while( ( currentPtr !=   NULL ) && ( currentPtr->data != value  ) ){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextnode;
        }

        if( currentPtr != NULL ){
            tempPtr = currentPtr;
            previousPtr->nextnode = currentPtr->nextnode;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

void instructions ( void ){
    puts("Enter your choice:\n"
    "    1 to enter element into the list.\n"
    "    2 to enter delete an element from the list.\n"
    "    3 to end.");
}