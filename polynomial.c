#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
int cof_x;
int pow_x;
struct node * link;
};
typedef struct node * N;
void add_dis(N );
void dis(N ,N);
void insert_ra(int ,int , N);
N pol();
void add(N ,N );
N insert_fr(int ,int);
int main()
{
    int p;
    N p1,p2;
   // printf("enter the no of polynomials : ");
    // scanf("%d",&p);
    p1=pol();
    printf("you are entering the value of second polynomial  \n ");
    p2=pol();
    dis(p1,p2);
    add(p1,p2);
}
 N pol(){
     int p;
     N first=NULL;
         char a;
     while(true){
       int a_1,b;
       printf("would you like to add another element : y/n \n ");
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
    return first;
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
void dis (N p1,N p2){
N t=p1,t1=p2;
while(t!=NULL){
    printf("%d \n ",t->cof_x);
    t=t->link;
}
while(t1!=NULL){
    printf("%d \n ",t1->cof_x);
    t1=t1->link;
}
}
