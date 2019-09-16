#include <stdio.h>
#include <stdlib.h>
    

struct node
{
    int data;
    struct node *link; 
};

typedef struct node NODE;
typedef NODE* nodePtr;


void menu();
void push(nodePtr *stack, int el);
int pop(nodePtr *stack);
void display(nodePtr stack);


    int main()
    {        
        char ch;
        int ele = 0;
        nodePtr S = NULL;
        menu();
        scanf("%c",&ch);

        while(1){
            switch (ch)
            {
            case '1' : 
                scanf("\n%d",&ele);
                push(&S,ele);
                display(S);
                break;
            case '2' :
                ele = pop(&S);    
                if(ele != -1) printf("%d\n",ele);
                display(S);
                //pop
                break;
            case '3' :
                display(S);
                break;
            default:
                exit(0);
                break;
            }
            menu();
            scanf("\n%c",&ch);               
        }
        return 0;
    }

void menu()
{
    printf ("\n\n1.push element\n"
            "2.pop element\n"
            "3.display\n"
            "4.exit\n");
}

void display(nodePtr stackPtr)
{
    printf("\nTOP--->");
    int t = 3;
    while(stackPtr)
    {
        printf("%d\n", stackPtr->data);
        stackPtr = stackPtr->link;
    }
    printf("--->NULL");
}

void push(nodePtr *stackPtr, int el)
{

    nodePtr newNode =  malloc( sizeof( NODE ) );
    newNode->data = el;
    newNode->link = NULL;
    
    if((*stackPtr) == NULL)
    {
        (*stackPtr) = newNode;
        return;
    }
    newNode->link = (*stackPtr);
    (*stackPtr) = newNode;
    
}

int pop( nodePtr  *stackPtr )
{
    int ret = 0;
    nodePtr dummy = NULL;
    if( (*stackPtr) == NULL )
    {
        printf ("\nEMPTY !\n");
        return -1;
    }
    ret = (*stackPtr)->data;
    dummy = (*stackPtr);
    *stackPtr = (*stackPtr)->link;
    free(dummy);


    return ret;
    
}

