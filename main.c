#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"


int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
   NodePtr tailPtr=NULL;

   struct que q ;
   q.head = NULL;
   q.tail = NULL;
  
   int i,x;
   

 for( i=1 ; i < argc ; i++ ){
        if(strcmp(argv[i],"x")==0){
            x=dequeue(&q);
            printf("dequeing %d\n",x);
        }
        else {
           enqueue(&q,atoi(argv[i]));
          //  printf("add %d\n",atoi(argv[i]));
        }
 }

 showq(&q);

  return 0;
}
