
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack{
int arr[MAX];
int top;
};
void initializestack(struct stack*stack);
int isfull(struct stack*stack);
int isempty(struct stack*stack);
void push(struct stack*stack,int element);
int pop(struct stack*stack);
void displaystack(struct stack*stack);
int main(){
struct stack stack;
int choice,element;
initializestack(&stack);
while(1){
printf("\nstack operations menu:\n");
printf("1.push\n");
printf("2.pop\n");
printf("3.display\n");
printf("4.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("enter element to push:");
scanf("%d",&element);
push(&stack,element);
break;
case 2:
element=pop(&stack);
if(element!=-1)
printf("popped element:%d\n",element);
break;
case 3:
displaystack(&stack);
break;
case 4:
exit(0);
default:
printf("invalid choice!please enter a valid option.\n");
}}
return 0;
}
void initializestack(struct stack*stack){
stack->top=-1;
}
int isfull(struct stack*stack){
return stack->top==MAX-1;
}
int isempty(struct stack*stack){
return stack->top==-1;
}
void push(struct stack*stack,int element){
if(isfull(stack)){
printf("error:stack overflow.cannot push element.\n");
return;
}
stack->arr[++stack->top]=element;
printf("element pushed:%d\n",element);
}
int pop(struct stack*stack){
if(isempty(stack)){
printf("error:stack underflow.cannot pop element.\n");
return -1;
}
return stack->arr[stack->top--];
}
void displaystack(struct stack*stack){
if(isempty(stack)){
printf("stack is empty.\n");
return;
}
printf("stack elements:");
for(int i=stack->top;i>=0;i--){
printf("%d",stack->arr[i]);
}
printf("\n");
}

