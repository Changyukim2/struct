#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 10

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stacktype;

void init_stack(Stacktype* s) {

	s->top = -1;
}

int is_empty(Stacktype* s) {

	return (s->top == -1);

}
int is_full(Stacktype* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}


void push(Stacktype* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;

}

element pop(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(Stacktype* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void) {
	Stacktype s;
	init_stack(&s);

	printf("--------Using struct---------\n");
	srand(time(NULL));
	int rand_num = rand() % 100;

	for (int i = 1; i <= 30; i++) {
		int rand_num = rand() % 99 + 1;
		push(&s, rand_num);
		if (rand_num % 2 == 0) {

			printf("�ݺ���:%d  push %d\n", i, pop(&s));
		}
		else {
			printf("�ݺ���: %d  pop %d\n", i, pop(&s));
		}
	}
}
















