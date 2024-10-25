#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
int cof_x;
int pow_x;
struct node * link;
};
typedef struct node * N;
void dis(N );
void insert_ra(int ,int , N);
N insert_fr(int ,int);
int main()
{
    int p;
    char a;
    N first=NULL;
    while(true){
       int a_1,b;
       printf("would you like to add another polynomial : y/n \n ");
       scanf(" %c",&a);
       if(a=='y'){
            while(true){
                    printf("p=1 : go to next power p=2 : stop");
            scanf("%d",&p);
            if (p==1){
       if (first==NULL){
         printf("enter the power of x : ");
       scanf("%d",&b);
       printf("enter the cofficient of above power : ");
       scanf("%d",&a_1);
       first=insert_fr(a_1,b);
       }
       else{
       printf("enter the power of x : ");
       scanf("%d",&b);
       printf("enter the cofficient of above power : ");
       scanf("%d",&a_1);
       insert_ra(a_1,b,first);
       }
            }
            else{
                break;
            }
            }
    }
    else{
        break;
    }
    }
    dis(first);
}
void insert_ra(int k,int k_1,N first){
 N t,l=first;
 t=(N)malloc(sizeof(struct node));
 t->cof_x=k;
 t->pow_x=k_1;
 t->link=NULL;
 while(l->link!=NULL){
    l=l->link;
 }
 l->link=t;
}
N insert_fr(int k,int k_1){
N t;
t=(N)malloc(sizeof(struct node));
t->cof_x=k;
t->pow_x=k_1;
t->link=NULL;
return t;
}
void dis (N first){
N t=first;
while(t!=NULL){
    printf("%d",t->cof_x);
    t=t->link;
}
}
