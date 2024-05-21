#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;

};

void traverse(struct node *head){
  while(head != NULL){
     printf("%d" ,head -> data);
     head = head-> next;
     printf(" -> ");

  }
}
int main(){
   struct  node *head;
   struct  node *first;
   struct  node *second;
   struct node *third;


    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    printf("Enter the first: ");
    scanf("%d", &(first->data));

    printf("Enter the second: ");
    scanf("%d", &(second->data));

    printf("Enter the third: ");
    scanf("%d", &(third->data));

  
   first -> next = second;
   second -> next= third;
   third -> next = NULL;
   head = first;
   
   traverse(head);






   


}