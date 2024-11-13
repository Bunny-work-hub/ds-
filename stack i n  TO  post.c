#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char stack[100];
char infix[100],postfix[100];
int top=-1;
int j=0;
void dis();
int push(char );
int pop();
int incon();
int prec(char );
int eval_po();
int main()
{
    printf("enter the infix exprerssion : ");
    gets(infix);
    incon();
    int res=eval_po();
    printf(" \n after evalution of post fix expression value is : %d ",res);

}
int incon(){

for (int i=0;i<strlen(infix);i++){
    char symbol;
    symbol=infix[i];
    switch(symbol){
case '(':
    push(symbol);
    break;
case ')' :{
    while(stack[top]!='('){
            pop();
            }
          top=top-1;
}
    break;
case '+':
case'-':
case'*':
case'/':
case'^':
     while (prec(stack[top])>=prec(symbol))
          {
          pop();
          }
          push(symbol);//IF TWO VALUES HAS SAME PRECEDENCE THEN WE NEED TO POP THOSE TWO ELEMENTS
          break;
default:
    postfix[j++]=symbol;
}
}
while(top!=-1){
    postfix[j++]=stack[top];
    top=top-1;
}
dis();
}
int push(char k){
if (top==99){
    printf("stack overflow ");
}
else{
    top=top+1;
    stack[top]=k;
}
}

int pop(){
    if (top==-1){
        printf("under flow ");
    }
    else{
    postfix[j++]=stack[top];
    top=top-1;
}
}
int prec(char k){
    switch(k){
case '+':
case'-':
    return (1);
case '*':
case '/':
    return 2;
case '^':
    return 3;
default :
    return 0;
    }
}
void dis(){
int k=0;
for(k=0;k<strlen(postfix);k++)
    printf("%c",postfix[k]);
}
int eval_po() {
    int i = 0, a, b;
    for (i = 0; i < strlen(postfix); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } else {
            a = pop_eval();
            b = pop_eval();
            switch (postfix[i]) {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
    }
    return pop_eval();
}
int pop_eval() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}


                                                THE ABOVE CODE IS FOR GLOBAL DECLARATION 

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct stack{
    int top;
    int capacity;
    char *array;
};
typedef struct stack * N;
int prece(char );
N create_stack(char i[])
{
    N stack;
    stack=(N)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->capacity=strlen(i);
    stack->array=(char * )malloc(stack->capacity * sizeof(char));
    return stack;
}
char pop(N stack)
{
    if (stack->top==-1)
        return -1;
    return(stack->array[stack->top--]);
}
void push(N stack,char iteam){
    if(stack->top == stack->capacity-1)
        printf("stack is full");
    stack->top=stack->top+1;
    stack->array[stack->top]=iteam;
}
char peek(N stack){
    return(stack->array[stack->top]);
}
int intopost(char i[],char p[],N stack){
    int j=0;
    char h;
    for (int k=0;k<strlen(i);k++){
        char symbol=i[k];
        switch(symbol){
        case '(':
            push(stack,symbol);
            break;
        case')':
            while(peek(stack)!='('){
                p[j++]=pop(stack);
            }
            pop(stack);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            h=peek(stack);
            while(prece(symbol) <= prece(h)){
                    p[j++]=pop(stack);
            }
            push(stack,symbol);
            break;
        default :
            p[j++]=symbol;
            break;
        }
    }
    while(stack->top !=-1){
        p[j++]=pop(stack);
    }
    p[j]='\0';
}
int prece(char k){
    switch(k){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int postfix(char p[],N stack){
    int k=0;
    int a,b;
    for (k=0;k<strlen(p);k++){
            char symbol=p[k];
        if (p[k]>='0' && p[k]<='9'){
            push(stack,p[k]-'0');
        }
        else{
                a = pop(stack);
            b = pop(stack);
            switch (p[k]) {
            case '+':
                push(stack,b + a);
                break;
            case '-':
                push(stack,b - a);
                break;
            case '*':
                push(stack,b * a);
                break;
            case '/':
                push(stack,b / a);
                break;
            case '^':
                push(stack,pow(b, a));
                break;
            }
        }

    }
    return pop(stack);
}
int main()
{
    char i[100],p[100];
    N stack;
    printf("enter the infix expression ");
    gets(i);
    stack=create_stack(i);
    intopost(i,p,stack);
    printf("%s",p);
    int res=postfix(p,stack);
    printf("\ result %d",res);
}
                                        ALL basic operations of linkes list 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node * link;
};
typedef struct node * N;
N insert_fr(N );
int insert_rear(N );
N del_fr(N);
int del_RARE (N);
int insert_mid(N );
int main()
{
    int iteam,n,i=0;
    N first=NULL,t;
    t=(N)malloc(sizeof(struct node));
    t->data=18;
    t->link=NULL;
    first=t;
    while(true){
            printf("n=1 : insert front \n n=2 : insert rare \n n=3 delete front \n n=4 delete rare \n n-5 insert mid \n n=6 : display \n");
        printf("enter your choice  : ");
        scanf("%d",&n);
        switch(n){
    case 1:
        first=insert_fr(first);
        break;
    case 2:
        insert_rear(first);
        break;
    case 3:
        first=del_fr(first);
        break;
    case 4:
        del_RARE(first);
        break;
    case 5:
        insert_mid(first);
        break;
    case 6:
        dis(first);
    default:
        break;;
        }
        i++;
    }
}
N insert_fr(N first){
N t;
int p;
printf("enter value : ");
scanf("%d",&p);
t=(N)malloc(sizeof(struct node));
t->data=p;
t->link=first;
return (t);
}
int insert_rear(N first){
N k,e=first;
int p;
printf("enter value : ");
scanf("%d",&p);
k=(N)malloc(sizeof(struct node));
k->data=p;
k->link=NULL;
while(true){
    if(e->link==NULL){
        e->link=k;
        break;
    }
    e=e->link;
}
}
N del_fr(N first){
    free(first);
    return(first->link);
}
int del_RARE(N first){
N k,p=NULL;
k=first;
while(k->link!=NULL){
        p=k;
    k=k->link;
}
p->link=NULL;
}
int insert_mid(N first){
int n,k,c=1;
printf("enter the value that you want to insert and enter its previous number: ");
scanf("%d ",&n);
scanf("%d",&k);
N l,m_1;
l=(N)malloc(sizeof(struct node));
l->data=n;
l->link=NULL;
m_1=first;
while(true){
    if (m_1->data==k){
        m_1->link=l->link;
        m_1->link=l;
        break;
    }
}
}
void dis(first){
N k;
k=first;
while(k!=NULL){
    printf("%d \n ",k->data);
    k=k->link;
}
}
                                                    unsorted list and reversing
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
