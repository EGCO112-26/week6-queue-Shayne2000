#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int food ;
    int amount ;
    struct node * next ;
};

struct que {
    struct node * head ;
    struct node * tail ;
    int size ;
};

void add (struct que * , int ,int ) ;
void serve (struct que * ,int) ;


int main(int argc , char **argv) {

    struct que q ;
    q.head = NULL ;
    q.tail = NULL ;
    q.size = 0 ;

    int current_menu = -1 ;
    int id = 1 ;

    for (int i = 1 ; i < argc ; i ++) {
        
        if (strcmp(argv[i],"x") == 0) {
            serve(&q,id);
        }else{
            if (current_menu > 0) {
                // printf("amount of %d\n",atoi(argv[i]));
                add(&q,current_menu,atoi(argv[i]));
                current_menu = -1 ;
            }else if (current_menu == -1){
                printf("My order is %d\n",atoi(argv[i]));
                current_menu = atoi(argv[i]);
            }else {
                printf("sumnthing wrong");
            }
            
        }

    }

    printf("=====================================\n There are %d ppl left in the queue\n",q.size);

}


void add (struct que * q , int x , int y) {

    struct node * new_node ;
    new_node = (struct node *)malloc(sizeof(struct node)) ;
    new_node -> food = x ;
    new_node -> amount = y ;

    if (q -> head == NULL) {
        q -> head = new_node ;
        
    }else{
        q -> tail -> next = new_node ;
    }
    q -> tail = new_node ;
    q -> size ++ ;

    // printf("new menu %d n = %d\n",x,y);
}

void serve (struct que * q , int id) {

    struct node * dummy ;

    if (q -> size == 0) {
        printf("no more to serve");
    }else{
        printf("Cutomer no: %d\n",id);

        int to_pay ;

        switch (q -> head -> food) {
            case 1 : to_pay = q -> head -> amount * 100 ; printf("Ramen\nYou have to pay %d\n:",to_pay); break;
            case 2 : to_pay = q -> head -> amount * 100 ; printf("Sumething\nYou have to pay %d\n:",to_pay); break;
            case 3 : to_pay = q -> head -> amount * 50 ; printf("Fried Chicken\nYou have to pay %d\n:",to_pay); break;
            default : printf("sumnthing wrong"); break;
        }

        int money = -100 ;
        while (money < to_pay) {
            printf("Cash:");
            scanf("%d",&money);
        }
        q -> size -- ;
        dummy = q -> head ;
        q -> head = dummy -> next ;
        printf("Thank you\n");
        if (money > to_pay) {
            printf("Change is:%d\n",money-to_pay);
        }
        free(dummy);
    }
}