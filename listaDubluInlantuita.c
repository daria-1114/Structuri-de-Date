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
    struct Node *next, *prev;
}Node;

typedef struct DList{
Node *head, *tail;
}DList;

DList insertNodeD(DList list, Rect data){
    Node* newNode = malloc(sizeof(Node));
    newNode->rect = data;
    newNode->prev = NULL; //insertie la inceput; primul nod nu are prev
    newNode->next = list.head; // nodul nou preia adresa veche de inceput a listei in membrul next al nodului inserat

    if(list.head == NULL){
        list.head = list.tail = newNode;
    } // if the list is empty, then we just add the new node
    else{
        list.head->prev =newNode; // the list is updated with the new node, meaning the previously first node will have a prev address of the newly added node
        list.head = newNode;
    }
    return list;
}

Rect deleteNode(DList *list, unsigned char pos){
   Rect result;
   if(list->head != NULL){
    unsigned char counter = 1;
    Node *t = list->head;
    while((t!=NULL)&&counter<pos){
        t=t->next;
        counter++;
    }
    if(t!=NULL){
        Node *p,*q; //p is the node before t, q the node after
        p = t->prev;
        q = t->next;
        if(p!=NULL && q!=NULL){//if there are neighbours before and after the deleted element
            p->next = q;
            q->prev = p; //linking the neighbours
        }else{
            if(p ==NULL && q==NULL){ // list with a single element
                list->head = list->tail =NULL;
            }else{
                if(p == NULL){ // the deleted element was the first of the list
                    q->prev =p;
                    list->head = q;
                }else //the deleted element was the last
                {
                    p->next = q;
                    list->tail = p;
                }
            }
        }
        result = t->rect;
        free(t);
    }
   }
   return result;
}

void parsingList(DList list){
    Node *t = list.head;
    while( t != NULL){ // head to tail
        printf("%d %d \n", t->rect.length, t->rect.width);
        t = t->next;
    }
    t = list.tail;
    while(t != NULL){
        printf("%d %d \n", t->rect.length, t->rect.width);
        t=t->prev;
    }
}
int main(){
    FILE *f;
    f=fopen("rect.txt", "r");
    char buffer[256];
    char list_sep[]=",\n";
    DList double_list;
    double_list.head = double_list.tail = NULL;
    while(fgets(buffer, sizeof(buffer),f)){
        Rect temp;
        char* token = strtok(buffer,list_sep);
        temp.length = atoi(token);
        token = strtok(NULL, list_sep);
        temp.width = atoi(token);
        double_list=insertNodeD(double_list, temp);
    }
    fclose(f);
    parsingList(double_list);
    deleteNode(&double_list, 2);
    printf("\n");
    parsingList(double_list);
}