//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2566 BE.
//
#ifndef Node_h
#define Node_h

struct node
{
    int data;
    struct node *nextPtr;
};

struct que {
    struct node * head ;
    struct node * tail ;
};

typedef struct node Node;
typedef struct node* NodePtr;


void enqueue(struct que * q, int x){
  struct node * new_node ;
  new_node = (struct node *)malloc(sizeof(struct node)) ;

  new_node -> data = x ;
if(q -> head == NULL){ 
    q -> head = new_node ;
 }else {
  q -> tail -> nextPtr = new_node ;
 }
 q -> tail = new_node ;

}


int dequeue(struct que * q){

  struct node * dummy ;
  int x ;

   if(q -> head != NULL){
    dummy = q -> head ;
    x = dummy -> data ;
    q -> head = dummy -> nextPtr ;
    free(dummy);
    printf("dequeing %d\n",x);
   return x;
   }
   printf("Empty queue\n");
   return 0;
}


void showq (struct que * q) {
  struct node * dummy ;
  dummy = q -> head ;
  while (dummy) {
    printf("%d\n",dummy -> data) ;
    dummy = dummy -> nextPtr ;
  }
}

#endif
