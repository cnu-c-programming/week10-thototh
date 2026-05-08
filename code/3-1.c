#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char name[10];
    int score;
    struct Node *next;
};

int main() {
    char oder[10];
    char name[10];
    int score;
    struct Node *head = NULL;
    struct Node *newNode = NULL;
    struct Node *tail;

    while(1){
        scanf("%s", oder);

        if(strcmp(oder, "add") == 0){
            scanf("%s %d",name, &score);
            newNode = malloc(sizeof(struct Node));
            strcpy(newNode->name, name);
            newNode -> score = score;
            newNode -> next = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail -> next = newNode;
                tail = newNode;
                
            }
        }else if(strcmp(oder, "print") == 0){
            struct Node *p;
            for( p = head; p != NULL; p = p->next){
                printf("%s %d\n", p->name, p->score);
            }
        }else{
            scanf("%s", name);
            struct Node *p;
            if(strcmp(head->name, name)==0){
                head = head->next;
            }
            for(p = head; p != NULL; p = p->next){
                if(strcmp((p->next)->name, name)==0){
                    p->next = (p->next)->next; 
                }
            }
        }
    }
    return 0;
}
