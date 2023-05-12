#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE	100
#define ERROR		-1

int	stack_size;
int	stack[MAX_SIZE];

void	init() {
	stack_size = 0;
}

bool	empty() {
	if (stack_size == 0)
		return true;
	else
		return false;
}

int	top() {
	if (stack_size == 0)
		return ERROR;
	else
		return stack[stack_size - 1];
}

int	size() {
	return stack_size;
}

void	push(int element) {
	if (stack_size == MAX_SIZE)
		return;
	stack[stack_size] = element;
	stack_size++;
}

int	pop() {
	if (empty() == true) {
		return ERROR;
	} else {
		return stack[--stack_size];
	}
}

void	print() {
	if (empty() == true) {
		printf("STACK IS EMPTY\n\n");
		return;
	}

	printf("<CURRENT_STACK>\n");
	for (int i = stack_size - 1; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("\n");
}

int	main(void) {
	//test
	init();
	print();

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	print();

	printf("SIZE = %d\n\n", size());

	printf("EMPTY = %s\n\n", empty() ? "true" : "false");

	printf("TOP = %d\n\n", top());

	printf("POP = %d\n\n", pop());
	printf("POP = %d\n\n", pop());
	printf("POP = %d\n\n", pop());

	printf("SIZE = %d\n\n", size());

	push(-1);
	push(-2);
	push(-3);
	print();

	printf("SIZE = %d\n\n", size());

	printf("POP = %d\n\n", pop());
	printf("POP = %d\n\n", pop());
	printf("POP = %d\n\n", pop());
	printf("POP = %d\n\n", pop());
	printf("POP = %d\n\n", pop());

	printf("SIZE = %d\n\n", size());
	print();

	return 0;
}
