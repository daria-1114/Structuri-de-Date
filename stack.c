#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item; // item==int but can be changed later to another data type

typedef struct{
    Item *elements; // pointer to dynamically allocated array of items
    int capacity; //max number of elements
    int size; //current number of elements in the stack
}Stack;

void initStack(Stack *s, int maxSize){
    Item *newElem;
    newElem = (Item*)malloc(sizeof(Item)*maxSize);
    if(newElem == NULL){
        printf("eroare\n");
        exit(1);
    }
    s->size = 0;
    s->capacity = maxSize;
    s->elements = newElem;
}
bool isFull(Stack *s){
    return s->size == s->capacity;
}
bool isEmpty(Stack *s){
    return s->size == 0;
}

void push(Stack *s, Item elem){
    if(isFull(s)){
        printf("stack is full. cannot push to stack");
        exit(1);
    }
    s->elements[s->size++] = elem;
}
Item pop(Stack *s){
    if(isEmpty(s)){
        printf("stack is empty, cannot pop");
        exit(1);
    }
    s->size = s->size-1;
    return s->elements[s->size];
}
void destroyStack(Stack *s){
    free(s->elements);
    s->elements = NULL;
    s->size = 0;
    s->capacity = 0;
}
Item peek(Stack *s){
    if(isEmpty(s)){
        printf("cannot peek. stack is empty");
        exit(1);
    }
    return s->elements[s->size-1];
}
int main(){
    Stack s;
    initStack(&s, 5);
    push(&s,10);
    push(&s, 20);
    push(&s, 30);
    printf("%d\n", peek(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%s\n",isEmpty(&s)? "true":"false");
    pop(&s);
    printf("%s\n",isEmpty(&s) ?"true":"false");
    destroyStack(&s);
}