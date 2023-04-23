#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[50];

int precedence(char oper){
	switch (oper){
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '^':return 3;
		default : return 0;
	}
}

int isEmpty(){
	return top == -1;
}

char peek(){
	return stack[top];
}

char pop(){
	char a = "$";
	if(isEmpty()){
		return a;
	}else{
		char a = peek();
		top -=1;
		return a;
	}
}

void push(char a){
	top += 1;
	stack[top] = a;
}

int checkPrecedence(char oper1){
	if(!isalpha(oper1) && !isalpha(peek())){
		return precedence(oper1) <= precedence(peek());
	}else{
		return 0;
	}
}

char* infixToPostfix(char* exp){
	int i=0,j=0;
	int len = strlen(exp);
	char *output = (char *)malloc((len+2)*sizeof(char));
	while(exp[i]!='\0'){
        if(isalpha(exp[i]))
            output[j++] = exp[i];
        else if(exp[i]=='(')
        	push('(');
        else if(exp[i]==')'){
    		while(!isEmpty() && peek() != '(')
    			output[j++] = pop();
			if(!isEmpty() && peek() != '(')
				return -1;
			else
				pop();
		}else{
            while(!isEmpty() && checkPrecedence(exp[i]))
                output[j++] = pop();
            push(exp[i]);
        }
        i++;
    }
    while(!isEmpty())
        output[j++] = pop();
    output[j] = '\0';
    return output;
}

int main(){
	char expression[50];
	printf("Enter Expression in infix form: ");
	gets(expression);
	char* postfix = infixToPostfix(expression);
	int len = strlen(postfix);
	int i = 0, j = 0;
	char arr_stack[50];
	int x = 1;
	printf("\n");
	
	printf("op\t|      arg1\t|      arg2\t|      result\n");

	while(postfix[i] != '\0'){
		if(isalpha(postfix[i])){
			arr_stack[j++] = postfix[i];
		}
		else if(postfix[i] == '-'){
			char op1 = arr_stack[j-1];
			j--;
			arr_stack[j++] = x + 48;
			printf("%c\t|\t%c\t|\t-\t|\tt(%d)\n",postfix[i],op1,x);
			x++;
		}
		else if(postfix[i] == '='){
			char op1 = arr_stack[j-1];
			char op2 = arr_stack[j-2];
			j-=2;
			if(isdigit(op1) && isdigit(op2)){
				char str_op1[] = {'t','(',op1,')','\0'};
				char str_op2[] = {'t','(',op2,')','\0'};
				printf("%c\t|\t%s\t|\t-\t|\t%c\n",postfix[i],str_op2,str_op1);
			}
			else if(isdigit(op1)){
				char str_op1[] = {'t','(',op1,')','\0'};
				printf("%c\t|\t%s\t|\t-\t|\t%c\n",postfix[i],str_op1,op2);
			}
			else if(isdigit(op2)){
				char str_op2[] = {'t','(',op2,')','\0'};
				printf("%c\t|\t%s\t|\t-\t|\t%c\n",postfix[i],str_op2,op1);
			}else{
				printf("%c\t|\t%c\t|\t-\t|\t%c\n",postfix[i],op2,op1);	
			}
		}
		else{
			char op1 = arr_stack[j-1];
			char op2 = arr_stack[j-2];
			j-=2;
			if(isdigit(op1) && isdigit(op2)){
				char str_op1[] = {'t','(',op1,')','\0'};
				char str_op2[] = {'t','(',op2,')','\0'};
				printf("%c\t|\t%s\t|\t%s\t|\tt(%d)\n",postfix[i],str_op2,str_op1,x);
			}
			else if(isdigit(op1)){
				char str_op1[] = {'t','(',op1,')','\0'};
				printf("%c\t|\t%c\t|\t%s\t|\tt(%d)\n",postfix[i],op2,str_op1,x);
			}
			else if(isdigit(op2)){
				char str_op2[] = {'t','(',op2,')','\0'};
				printf("%c\t|\t%s\t|\t%c\t|\tt(%d)\n",postfix[i],str_op2,op1,x);
			}else{
				printf("%c\t|\t%c\t|\t%c\t|\tt(%d)\n",postfix[i],op2,op1,x);
			}
			arr_stack[j++] = x + 48;
			x++;
		}
		i++;
	}
	return 0;
}

