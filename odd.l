%{
#include<stdio.h>
int num;
%}
%%
[0-9]+ {num=atoi(yytext); 
	if(num%2==0) {
	printf("Entered Number is Even "); 
	}
	else{
	 printf("Entered Number is Odd ");
	}
	}
%%

int yywrap(){
return 1;
}

int main()
{
printf("Enter the number : ");
yylex();
}

