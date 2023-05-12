#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	node_t {
	void			*content;
	struct node_t	*next;
	struct node_t	*prev;
}	Node;

typedef struct	 queue_t {
	//dummy head / tail node
	Node	*head;
	Node	*tail;
	int		size;
}	Queue;

Node	*create_node(void *content) {
	Node	*new_node;

	new_node = (Node *)calloc(1, sizeof(Node));
	new_node->content = content;

	return new_node;
}

void	init(Queue *queue) {
	//init queue size
	queue->size = 0;

	//init head / tail dummy node
	queue->head = create_node(NULL);
	queue->tail = create_node(NULL);
	queue->head->next = queue->tail;
	queue->tail->prev = queue->head;
}

bool	empty(Queue *queue) {
	if (queue->size == 0) {
		return true;
	} else {
		return false;
	}
}

int	size(Queue *queue) {
	return queue->size;
}

void	*front(Queue *queue) {
	if (empty(queue) == true)
		return NULL;

	Node	*front_node = queue->head->next;

	return front_node->content;
}

void	*back(Queue *queue) {
	if (empty(queue) == true)
		return NULL;

	Node	*back_node = queue->tail->prev;

	return back_node->content;
}

void	push(Queue *queue, void *content) {
	Node	*new_node = create_node(content);
	Node	*back_node = queue->tail->prev;

	/*
	 * back_node -> tail
	 *
	 * back_node -> new_node -> tail
	 */

	back_node->next = new_node;
	new_node->next = queue->tail;
	new_node->prev = back_node;
	queue->tail->prev = new_node;

	queue->size++;
}

void	*pop(Queue *queue) {
	if (empty(queue) == true)
		return NULL;

	Node	*front_node = queue->head->next;
	Node	*second_node = front_node->next;
	void	*content = front_node->content;

	/*
	 * head -> front_node -> second_node
	 *
	 * head -> second_node
	 */

	queue->head->next = second_node;
	second_node->prev = queue->head;

	free(front_node);
	queue->size--;

	return content;
}

void	clear(Queue *queue) {
	while (!empty(queue))
		pop(queue);

	free(queue->head);
	free(queue->tail);
}

void	print(Queue *queue) {
	if (empty(queue) == true) {
		printf("QUEUE IS EMPTY\n\n");
		return;
	}

	Node	*current_node = queue->tail->prev;

	printf("<CURRENT_QUEUE>\n");
	while (current_node->prev != NULL) {
		printf("%d\n", *((int *)current_node->content));
		current_node = current_node->prev;
	}
	printf("\n");
}

int	main(void) {
	Queue	queue;
	int		arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	init(&queue);

	push(&queue, &arr[0]);
	push(&queue, &arr[1]);
	push(&queue, &arr[2]);
	push(&queue, &arr[3]);
	push(&queue, &arr[4]);

	printf("SIZE = %d\n\n", size(&queue));

	print(&queue);

	printf("POP = %d\n", *((int *)pop(&queue)));
	printf("POP = %d\n", *((int *)pop(&queue)));
	printf("POP = %d\n", *((int *)pop(&queue)));
	printf("\n");

	printf("SIZE = %d\n\n", size(&queue));

	print(&queue);

	push(&queue, &arr[9]);
	push(&queue, &arr[8]);
	push(&queue, &arr[7]);

	printf("SIZE = %d\n\n", size(&queue));

	print(&queue);

	while (!empty(&queue)) {
		printf("POP = %d\n", *((int *)pop(&queue)));
	}
	printf("\n");

	print(&queue);

	clear(&queue);

	system("leaks a.out");
	return 0;
}
