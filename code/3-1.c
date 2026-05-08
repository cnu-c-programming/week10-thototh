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
    struct Node *tail = NULL;

    while(1){
        scanf("%s", oder);

        if(strcmp(oder, "add") == 0){
            scanf("%s %d",name, &score);
            newNode = (struct Node*)malloc(sizeof(struct Node));
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
        }else if(strcmp(oder, "delete")==0){
            scanf("%s", name);

            if(head == NULL) continue;


            if(strcmp(head->name, name) == 0){
                struct Node *temp = head;
                head = head->next;
                if(head == NULL) tail = NULL;
                free(temp);
                continue;
            }

            struct Node *p = head;
            while(p->next != NULL){
                if(strcmp(p->next->name, name) == 0){
                    struct Node *temp = p->next;
                    p->next = temp->next;
                    if(temp == tail) tail = p;
                    free(temp);
                    break;
                }
                p = p->next;
            }
        
        }else{
            struct Node *p = head;
            struct Node *temp = NULL;
            while(p!=NULL){
                temp = p->next;
                free(p);
                p = temp;
            }
        }
    return 0;
    }
}
