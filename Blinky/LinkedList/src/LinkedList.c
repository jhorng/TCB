#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

listElement *initElement(int value){
  listElement *element = malloc(sizeof(listElement));
  element->next = NULL;
  element->value = value;
  return element;
}

linkedList *initLinkedList(){
  linkedList *list = malloc(sizeof(linkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void addElementToBack(linkedList *list, listElement *element){
  if(list->head == NULL && list->tail == NULL){
    list->head = element;
    list->tail = element;
  }
  else{
    list->tail->next = element;
    list->tail = element;
  }
}

listElement *removeElementFromFront(linkedList *list){
  listElement *currentElement;
  
  if(list->head == NULL){
    currentElement = NULL;
  }
  else{
    currentElement = list->head; 
    if(list->head->next == NULL){
      list->head = NULL;
      list->tail = NULL;
    }
    else{
      list->head = list->head->next;
      currentElement->next = NULL;
    }
  }
  
  return currentElement;
}

listElement *peepFront(linkedList *list){
  listElement *currentElement;
  
  currentElement = list->head;
  
  return currentElement;
}




