%{
int Upper=0;
int Lower=0;
%}

%%
[A-Z] {printf("Uppercase\t\n");Upper++;}
[a-z] {printf("Lowercase\t\n");Lower++;}
%%

int yywrap() {}
int main()
{
printf("Enter a	string\n");
yylex();
printf("Uppercase=%d and Lowercase=%d",Upper,Lower);

return 0;
}