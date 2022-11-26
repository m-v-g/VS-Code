
//vstavka uzlov v spisok i udalenie iz nego
#include <stdio.h>
#include <stdlib.h>

//struktura ssilayushaya na samu sebya
struct listNode{
    char data;          //kajdaya struktura listNode soderjit simvol
    static listNode *nextPtr; //ukazatel na sleduyushy uzel
};

typedef static listNode ListNode; //sinonim dlya struct listNode
typedef ListNode *ListNodePtr;    //sinonim dlya ListNode*

//prototipi
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{
    ListNodePtr = NULL; //iznachalno spisok pust
    unsigned int choice; //vibor polzovatelya
    char item;           //simvol vvedenniy polzovatelem

    instructions(); //vivesti menu
    printf("%s", "? ");
    scanf("%u", &choice);

    //vipolnenie cikla, poka polzovatel ne viberit punkt
    while (choice != 3)
    {
        switch(choice){
            case 1:
                printf("%s", "Enter a character: ");
                scanf("\n%c", &item);
                insert(&startPtr, item); //vstavka elementa v spisok
                printList(startPtr);
                brake;
            case 2: //udalenie elementa
                if (!isEmpty(startPtr)) //esli spisok ne pust
                {
                    printf("%s", "Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    //esli simvol nayden, udalit ego iz spiska
                    if (delete(&startPtr, item)) //udalit element
                    {
                        printf("%c deleted.\n", item);
                        printList(startPtr);
                    }
                    else
                    {
                        printf("%c not found.\n\n", item);
                    }
                }
                else
                {
                    puts("List is empty.\n");
                }
                break;
                default:
                puts("Invalid choice.\n");
                instructions();
                break;
        } //konec switc
        printf("%s", "? ");
        scanf("%u", &choice);
    } //konec while
    puts("End of run.")
} //konec main

//vivod instrukcii po robote s programmoy
void instructions(void)
{
    puts("Enter your choice:\n"
       "  1 to insert an element into the list.\n"
       "  2 to delite an element from the list.\n"
       "  3 to end.");
} //konec funkcii instructions

//vstavlyaet novoe znachenie v spisok v poryadke sortirovki
void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr;       //ukozatel na novy uzel
    ListNodePtr previousPtr;  //ukozatel na prededushy uzel v spiske
    ListNodePtr currentPtr;   //ukozatel na tekushy uzel v spiske

    newPtr = malloc(sizeof(ListNode)); //sozdat uxel

    if (newPtr != NULL)           //esli pamyat videlena
    {
        newPtr -> data = value;   //zapisat znachenie v uzel
        newPtr -> nextPtr = NULL; //uzel poka ne svyazan s drugim uzlom

        previousPtr = NULL;
        currentPtr = *sPtr;

        //naiti mesto dlya vstavki novogo uzla
        while (currentPtr != NULL && value > currentPtr -> data)
        {
            previousPtr = currentPtr;          //pereiti k ....
            currentPtr = currentPtr -> nextPtr;//.... sledushy uzel
        } //konec while
        
        //vstavit novy uzel v nachalo spiska
        if (previousPtr == NULL)
        {
            newPtr -> nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else //vstavit novy uzel mejdu previousPtr i currentPtr
        {
            previousPtr -> nextPtr = newPtr;
            newPtr -> nextPtr = currentPtr;
        }
    } //konec if
    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
} //konec funkcii insert

//udalenie elementa iz spiska
char delete(ListNodePtr *sPtr, char value)
{
    ListNodePtr previousPtr; //ukozatel na prededushy uzel v spiske
    ListNodePtr currentPtr;  //ukozatel na tekushy uzel v spiske
    ListNodePtr tempPtr;     vremenny ukazatel na uzel

    //udalit pervy uzel
    if (value == (*sPtr) -> data)
    {
        tempPtr = *sPtr;     //soxranitt ukazatel na udalyaemy uzel
        *sPtr = (*sPtr) -> nextPtr; //iskluchit uzel iz spiska
        free(tempPtr); //osvobodit pamyat zanimaemuyu iskluchennim uzlom
        return value;
    }
    else
    {
        previousPtr = *sPtr;
        currentPtr = (*sPtr) -> nextPtr;

        //naiti element spiska s ukazannim simvolom
        while (currentPtr != NULL && currentPtr -> data != value)
        {
            previousPtr = currentPtr;  //pereiti k ...
            currentPtr = currentPtr -> nextPtr; //... sleduyushemu uzlu
        }
        
        //udalenie uzla currentPtr
        if (currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr -> nextPtr = currentPtr -> nextPtr;
            free(tempPtr);
            return value;
        } //konec if
    } //konec else
    return 0;
} //konec funkcii delite

//vozvrashaet 1 esli spisok pust 0 v protivnom sluchae
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
} //konec funkcii isEmpty

//vivod spiska
void printList(ListNodePtr currentPtr)
{
    if(isEmpty(currentPtr)) //esli spisok pust
    {
        puts("List is empty.\n");
    }
    else
    {
        puts("The list is:");

        //poka ne dostignut konec spiska
        while (currentPtr != NULL)
        {
            printf("%c -->", currentPtr -> data);
            currentPtr = currentPtr -> nextPtr;
        }
        puts("NULL\n");
    }
} //konec funkcii printlist