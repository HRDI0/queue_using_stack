#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef int element;

typedef struct {
	element data[MAX];
	int top;
}Stacktype;

// ���� �ʱ�ȭ �Լ�
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(Stacktype* s)
{
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(Stacktype * s)
{
	return (s->top == (MAX - 1));
}

//�����Լ�
void push(Stacktype * s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "��ȭ�����Դϴ�.\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//���� �Լ�
element pop(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "��������Դϴ�.\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
//��ũ �Լ�
element peek(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "��������Դϴ�.\n");
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

	printf("�޴�\n \n1 : En_Q \n2 : De_Q \n3 : Peek_Q \n4 : EXIT\n \n");
	while (1){
		scanf_s("%d", &choice);
		switch (choice)
		{
		case(1): {
			printf("������ �Է��ϼ���.\n");
			scanf_s("%d", &num);
			push(&front, num);
			printf("�Է¿Ϸ�.\n");
			break;
		}
		case(2): {
			if (is_empty(&rear)) {
				while (front.top != -1) {
					push(&rear, pop(&front));
				}
			}
			printf("�����Ϸ�.\n");
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