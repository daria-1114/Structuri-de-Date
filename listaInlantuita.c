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

void parseList(Node *list){
    Node *t = list;
    while (t!=NULL){
        printf("%d %d\n", t->rect.length, t->rect.width);
        t = t->next;
    }
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
}