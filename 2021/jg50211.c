#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	bool valid;
	int value;
	int start;
	int end;
	char o;
}Expression;

bool cancompute(char *s, char *l){
	int o = 0;
	for (char *i = s; i < l; i++){
		if (*i == '+' || *i == '-' || *i == '*' || *i == '/'){
			o++;
		}
		//if (*i == '(') return false;
	}
	return o == 1 && l-s > 3;
}

int operate(int a, char o, int b){
	switch(o){
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '*':
			return a * b;
			break;
		case '/':
			return a / b;
			break;
	}
	return -1;
}

int compute(char *s, char *l){
	int i1 = 0;
	while (*s != '+' && *s != '-' && *s != '*' && *s != '/'){
		i1 = 10 * i1 + *s - '0';
		s++;
	}
	char o = *s;
	s++;
	int i2 = 0;
	while (s != l){
		i2 = 10 * i2 + *s -'0';
		s++;
	}
	return operate(i1, o, i2);
}
Expression check(char *l, int start, int end){
	Expression e;
	if (l[start] != '(' || l[end] != ')'){
		e.valid = false;
		return e;
	}
	e.start = start;
	if (l[start+1] == '('){
		Expression left = check(l, start+1, end);
		e.o = l[left.end + 1];
		if (e.o != '+' && e.o != '-' && e.o != '*' && e.o != '/'){
			e.valid = false;
			return e;
		}
		Expression right = check(l, left.end + 2, end);
		e.valid = left.valid && right.valid;
		e.value = operate(left.value, e.o, right.value);
		e.end = right.end + 1;
		e.valid &= l[e.end] == ')';
		return e;
	}
	e.end = strchr(l + start, ')') - l;
	e.valid = cancompute(l +start, l+e.end);
	if (e.valid) e.value = compute(l + start + 1, l + e.end);		
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