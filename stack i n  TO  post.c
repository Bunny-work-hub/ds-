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
