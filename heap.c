#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if ( pq->size == 0){
    return NULL;
  }
  else{
    return pq->heapArray[0].data;
  }
}

void heap_push(Heap* pq, void* data, int priority){
  //Heap* aux = pq;
  if ( pq->size == pq->capac){
    pq->heapArray = realloc( sizeof( heapElem) * 2;
  }
  pq->heapArray[size]->data = data;
  pq->heapArray[size]->priority = priority;
  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* dato = malloc( sizeof(Heap));
  dato->heapArray = malloc( sizeof(Heap) * 3);
  dato->size = 0;
  dato->capac = 3;

   return dato;
}
