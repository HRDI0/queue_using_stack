#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef int element;

typedef struct {
	element data[MAX];
	int top;
}Stacktype;

// 스택 초기화 함수
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(Stacktype* s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(Stacktype * s)
{
	return (s->top == (MAX - 1));
}

//삽입함수
void push(Stacktype * s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "포화상태입니다.\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//삭제 함수
element pop(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "공백상태입니다.\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
//피크 함수
element peek(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "공백상태입니다.\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main() {
	Stacktype front;
	Stacktype rear;
	init_stack(&front);
	init_stack(&rear);
	
	int choice = 0;
	int num = 0;
	int i = 0;

	printf("메뉴\n \n1 : En_Q \n2 : De_Q \n3 : Peek_Q \n4 : EXIT\n \n");
	while (1){
		scanf_s("%d", &choice);
		switch (choice)
		{
		case(1): {
			printf("정수를 입력하세요.\n");
			scanf_s("%d", &num);
			push(&front, num);
			printf("입력완료.\n");
			break;
		}
		case(2): {
			if (is_empty(&rear)) {
				while (front.top != -1) {
					push(&rear, pop(&front));
				}
			}
			printf("삭제완료.\n");
			pop(&rear);
			break;
		}
		case(3): {
			if (is_empty(&rear)) {
				while (front.top != -1) {
					push(&rear, pop(&front));
				}
			}
			printf("%d\n", peek(&rear));
			break;
		}
		case(4): {
			exit(1);
		}
		}
	}
}