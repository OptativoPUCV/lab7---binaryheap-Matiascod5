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
    pq->capac = ((pq->capac * 2) +1);
    pq->heapArray = realloc( pq->heapArray, sizeof( heapElem) * (pq->capac ));
    
  }
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  int i = pq->size;
  while ( i > 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority){
    heapElem aux;
    aux = pq->heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = pq->heapArray[i];
    pq->heapArray[i] = aux;
    i = (i-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){
  heapElem aux;
  aux = pq->heapArray[pq->size - 1];
  pq->heapArray[0] = aux;
  for ( int i = 0 ; i < pq->capac ; i++){
    int izq = 2i + 1;
    int der = 2i + 2;
    if ( pq->heapArray[izq].priority > pq->heapArray[der].priority){
      aux = pq->heapArray[0];
      pq->heapArray[0] = pq->heapArray[izq];
      pq->heapArray[izq] = aux;
    }
    else{
      aux = pq->heapArray[0];
      pq->heapArray[0] = pq->heapArray[der];
      pq->heapArray[der] = aux;
    }
  }
  
  
}

Heap* createHeap(){
  Heap* dato = malloc( sizeof(Heap));
  dato->heapArray = malloc( sizeof(Heap) * 3);
  dato->size = 0;
  dato->capac = 3;

   return dato;
}
