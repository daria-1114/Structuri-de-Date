#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rect
{
    int length;
    int width;
}Rect;

typedef struct Node
{
    Rect rect;
    struct Node* next;
}Node;


Node* insertNode(Node* list, Rect data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->rect = data;
    newNode->next = list;
    return newNode;
}
Node* insertAtEnd(Node *head, Rect data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->rect = data;
    newNode->next = NULL;
    Node* last = head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return head;
}
void parseList(Node *list){
    Node *t = list;
    while (t!=NULL){
        printf("%d %d\n", t->rect.length, t->rect.width);
        t = t->next;
    }
}

Node *deleteNodePosition(Node *list, unsigned short int pos){
    if(list != NULL){
        if(pos == 1){
            Node *t = list;    //temporary, to delete the memory addr of the first node
            list = list ->next;
            free(t);
        }else{
            Node *p = list;
            unsigned short int count = 2; //starting from second node
            while(p->next && count < pos){
                p = p ->next;
                count ++;
            }
            if(p->next != NULL){
                Node *t = p->next;
                p->next = t->next;
                free(t);
            }
        }
    }
    return list;
}
Node* deleteFromEnd(Node *list){
    if(list !=NULL){
        Node *last = list;
        while(last->next->next != NULL){
            last = last->next;
        }
        free(last->next);
        last->next = NULL;
    }
    return list;
}
int main(){
    FILE *f;
    f = fopen("rect.txt","r");

    Node *head  = NULL;
    char buffer[256];
    char sep_list[] =",\n";

    while(fgets(buffer,sizeof(buffer),f)){
        Rect r;
        char *token = strtok(buffer, sep_list);  // identifies substrings
        
        r.length = atoi(token); //ASCII to integer
        token = strtok(NULL, sep_list);
        r.width = atoi(token);
        head = insertNode(head, r); 
    }
    fclose(f);
    parseList(head);
    Rect r1 = {111,222};
    insertAtEnd(head, r1);
    deleteFromEnd(head);
    parseList(head);
}