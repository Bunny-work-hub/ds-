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
