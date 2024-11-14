#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Queue{
    int front;
    int rare;
    int capacity;
    int *array;
};
typedef struct Queue * N;
N cr_stack(int );
void insert(N );
void del_fr(N );
void del_ra(N );
void dis(N );
int main(){
    int n,l;
    char a;
    N k;
    printf("enter the capacity : ");
    scanf("%d",&l);
    k=cr_stack(l);
    while(true){
        printf("would you like to perform function ");
        scanf(" %c",&a);
        if(a=='y'){
        printf("\n insert rare  \n 2 : delete front \n 3 : delete rare");
        scanf("%d",&n);
            if (n==1){
                insert(k);
            }
            else if(n==2){
                del_fr(k);
            }
            else if (n==3){
                del_ra(k);
            }
            else{
                printf("sorry");
            }
        }
        else{
            break;
            }
    }
    dis(k);
}
N cr_stack(int k){
    N stack;
    stack=(N)malloc(sizeof(struct Queue));
    stack->front=-1;
    stack->rare=-1;
    stack->capacity=k;
    stack->array=(int *)malloc(stack->capacity * sizeof(int));
    return stack;
}
void insert(N k){
    int a;
    N stack;
    printf("enter the data : ");
    scanf(" %d",&a);
    if(stack->front == -1 && stack->rare == -1){
        stack->front++;
        stack->rare++;
        stack->array[stack->rare]=a;
    }
    else{
        if((stack->front == 0 )&& (stack->rare == stack->capacity -1)){
            printf("cant insert ");
        }
        else if(stack->rare != stack->capacity -1){
            stack->rare++;
            stack->array[stack->rare]=a;
        }
        else{
            if((stack->front !=0) && (stack->rare ==stack->capacity -1)){
                stack->rare=0;
            while(stack->front != stack->rare){
                stack->array[stack->rare]=a;
                stack->rare++;
            }
        }
        }
    }
}
void del_fr(N stack){
    if(stack->front == -1){
        printf("unable to delete");
    }
    else{
        stack->front++;
    }
}
void del_ra(N stack){
    if(stack->rare == -1){
        printf("unable to delete ");
    }
    else{
        stack->rare--;
    }
}
void dis(N k){
    N stack;
    if (stack->front == -1) {
        printf("Deque is empty\n");
    } else {
        int i = stack->front;
        printf("Elements in the deque: ");
        while (1) {
            printf("%d ", stack->array[i]);
            if (i == stack->rare) {
                break;
            }
            i = (i + 1) % stack->capacity;
        }
        printf("\n");
    }
}
