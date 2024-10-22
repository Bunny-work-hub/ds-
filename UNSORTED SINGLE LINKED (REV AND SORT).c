#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node * link;
};
typedef struct node * N;
int insert_ra(int ,N);
N rev(N );
int insert_ra_1(int ,N);
int merge(N ,N );
void dis(N);
int sort(N );
int main()
{
    int k,k_1,l_1,l_2,iteam;
    printf("enter the first linked list value and second linked list value : ");
    scanf("%d%d",&k,&k_1);
    N l,m,h1,h2;
    l=(N)malloc(sizeof(struct node));
    m=(N)malloc(sizeof(struct node));
    l->data=k;
    l->link=NULL;
    m->data=k_1;
    m->link=NULL;
    h1=l;
    h2=m;
    printf("Enter the no of node if first single linked list and second single linked list : ");
    scanf("%d%d",&l_1,&l_2);
    for (int i=0;i<=l_1-1;i++){
        printf("enter the value that you want to insertt");
        scanf("%d",&iteam);
        insert_ra(iteam,h1);
    }
    for (int j=0;j<=l_2-1;j++){
        printf("enter the value that you want to insertt");
        scanf("%d",&iteam);
        insert_ra_1(iteam,h2);
    }
    merge(h1,h2);
}
int insert_ra(int k,N h1){
N j,t=h1;
j=(N)malloc(sizeof(struct node));
j->data=k;
j->link=NULL;
while(t->link!=NULL){
    t=t->link;
}
t->link=j;
}
int insert_ra_1(int k,N h2){
N j,t=h2;
j=(N)malloc(sizeof(struct node));
j->data=k;
j->link=NULL;
while(t->link!=NULL){
    t=t->link;
}
t->link=j;
}
int merge(N h1,N h2){
    N k=h1,h_1;
    int o;
    while(k->link!=NULL){
        k=k->link;
    }
    k->link=h2;
        printf("1: reverse of liked list 2 : sort \n else exit ");
    scanf("%d",&o);
    if(o==1){
        h_1=rev(h1);
        dis(h_1);
    }
        else if(o==2){
        sort(h1);
    }
    else{
        dis(h1);
    }
}
N rev(N first){
    N h=NULL,p=first,k=NULL;
while(p!=NULL){
    k=p->link;
    p->link=h;
    h=p;
    p=k;
}
return (h);
}
void dis(N h1){
    N k=h1;
    while(k!=NULL){
        printf("%d \n ",k->data);
        k=k->link;
    }
}
int sort(N h1){
N c,h;
c=h1;
h=c->link;
int k;
while(c!=NULL){
    while(h!=NULL){
          if((c->data) > (h->data)){
            k=c->data;
            c->data=h->data;
            h->data=k;
            h=h->link;
          }
          else{
            h=h->link;
          }
    }
    h=c->link;
    c=c->link;
}
dis(h1);
}
