#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
    bool valid;
    int value;
    int start;
    int end;
    char o;
} Expression;

bool judge(char *s,char *l){
    int op = 0;
    for (char *i=s; i<l; i++){
        if (*i == '+' || *i == '-' || *i == '*' || *i == '/') op++;
    }
    return op==1 && l-s>3; // if l-s<3 it is impossible to have 2 num and 1 operator
}

int operate(int a,char op,int b){
    switch(op){
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
    }
    return -1;
}
int compute(char *a,char *b){
    int l=0; 
    while (*a!='+' && *a!='-' && *a!='*' && *a!='/'){
        l = l*10 + (*a-'0');
        a++;
    }
    char op = *a; a++;
    int r=0;
    while (a!=b){
        r = r*10 + (*a-'0'); 
        a++;
    }
    return operate(l,op,r);
}
Expression check(char *line,int start,int end){
    Expression e;
    if (line[start]!='(' || line[end]!=')'){
        e.valid = false;
        return e;
    }
    e.start = start;
    if (line[start+1]=='('){
        Expression l = check(line,start+1, end);
        e.o = line[l.end+1];
		if (e.o != '+' && e.o != '-' && e.o != '*' && e.o != '/'){
			e.valid = false;
			return e;
		}
        Expression r = check(line,l.end+2,end);
        e.valid = l.valid && r.valid;
        e.value = operate(l.value, e.o ,r.value);
        e.end = r.end+1;
        e.valid &= line[e.end] == ')';
        return e;
    }
    e.end = strchr (line + start, ')') - line;
    e.valid = judge (line+start,line+e.end);
    if (e.valid) e.value = compute (line+start+1,line+e.end);
    return e;
}

int main(){
	char line[1000001];
	while (scanf("%s", line) != EOF){
		bool valid = true;
		Expression e = check(line, 0, strlen(line) - 1);
		if (e.valid && e.end == strlen(line) - 1) printf("%d\n", e.value);
		else printf("invalid\n");
		//if (e.value == 6 ) printf("%s\n", line);
	}
}