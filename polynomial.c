#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int info;
struct node *link;
};
typedef struct node * N;
void insert_ra(int ,N );
int insert_mid(N );
void dis(N );
int main(){
    int a,iteam;
    char a_1;
    printf("enter the first elements in a linked list : ");
    scanf("%d",&a);
    N k,first=NULL;
    k=(N)malloc(sizeof(struct node));
     k->info=a;
     k->link=NULL;
     first=k;
     while(true){
          printf("would you like to insert an element : ");
        scanf(" %c",&a_1);
            if(a_1=='y'){
            printf("enter the element : ");
            scanf("%d",&iteam);
            insert_ra(iteam,first);
            }
            else{
                break;
            }
     }
     insert_mid(first);
     dis(first);
}
void insert_ra(int k,N first){
N j,l=first;
j=(N)malloc(sizeof(struct node));
j->info=k;
j->link=NULL;
while(l->link!=NULL){
    l=l->link;
}
l->link=j;
}
void dis(N l){
while(l!=NULL){
    printf("%d \n ",l->info);
    l=l->link;
}
}
int insert_mid(N first){
    N k,l=first,p=NULL;
    int k_1;
    printf("enter the element : ");
    scanf(" %d",&k_1);
    k=(N)malloc(sizeof(struct node));
    k->info=k_1;
    k->link=NULL;
    while(l->info < k->info){
    p=l;
    l=l->link;
    }
     k->link=l;
    p->link=k;
}
