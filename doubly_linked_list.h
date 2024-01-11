#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H

struct dll_node {
	int data;
	struct dll_node *next;
	struct dll_node *prev;
};

typedef struct dll_node    NODE;
typedef struct dll_node *  PNODE;
typedef struct dll_node ** PPNODE;

/* Function to create a new node with data
 * and sets the next and prev pointer
 * Returns new node adddress
 */
PNODE create_node(int data, PNODE prev, PNODE next){
	PNODE new_node = (PNODE)malloc(sizeof(NODE));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->data = data;
	new_node->prev = prev;
	new_node->next = next;
	return new_node;
}

/* Function to add new node to beginning of list */
void list_add_at_beg(PPNODE HEAD, int data){
	PNODE temp = create_node(data, NULL, *HEAD);
	if (*HEAD != NULL)
		(*HEAD)->prev = temp;
	*HEAD = temp;
}

/* Function to append node to the end of list */
void list_add_at_end(PPNODE HEAD, int data){
	if (*HEAD == NULL){
		list_add_at_beg(HEAD, data);
		return;
	}
	
	PNODE temp = create_node(data, NULL, NULL);
	PNODE current = *HEAD;
	while(current->next){
		current = current->next;
	}
	current->next =  temp;
	temp->prev = current;
}

/* Function to add node to the list in sorted order */
void list_add_sorted(PPNODE HEAD, int data){

	// If it is the first node or the smallest number in list
	if (*HEAD == NULL || ((*HEAD)->data >= data)){
		list_add_at_beg(HEAD, data);
		return;
	}

	PNODE current = *HEAD;
	PNODE previos = *HEAD;
	while (current){
		if (current->data >= data){
			PNODE temp = create_node(data, NULL, NULL);
			previos->next = temp;
			current->prev = temp;
			temp->next = current;
			temp->prev = previos;
			return;
		}
		previos = current;
		current = current->next;
	}

	// If it is the largest number in list
	list_add_at_end(HEAD, data);
}

void list_delete(PPNODE HEAD){
	PNODE current = *HEAD;
	PNODE previos = *HEAD;
	if (*HEAD){
		while(current){
			previos = current;
			current = current->next;
			free(previos);
		}
		*HEAD = NULL;
	}
}

void list_del_by_key(PPNODE HEAD, int data){
	if (*HEAD){

		if (( (*HEAD)->data == data) && ((*HEAD)->next == NULL)){
			free(*HEAD);
			*HEAD = NULL;
			return;
		}

		// If first node to delete
		if ( (*HEAD)->data == data){
			PNODE temp = *HEAD;
			*HEAD = (*HEAD)->next;
			(*HEAD)->prev = NULL;
			free(temp);
			return;
		}

		PNODE current = (*HEAD)->next;
		PNODE previos = *HEAD;
		while(current){
			if (current->data == data){
				PNODE temp = current;
				if (current->next != NULL){
					previos->next = current->next;
					current->next->prev = previos;
				}
				else{
					previos->next = NULL;
				}
				free(temp);
				return;
			}
			previos = current;
			current = current->next;
		}
	}
}

void print_reverse(PNODE HEAD);

void print(PNODE HEAD){
	if (HEAD){
		PNODE current = HEAD;
		while(current->next){
			printf("%d ", current->data);
			current = current->next;
		}
		printf("%d ", current->data);
		printf("\n");
		print_reverse(current);
	}
}

void print_reverse(PNODE HEAD){
	if (HEAD){
		PNODE current = HEAD;
		while(current){
			printf("%d ", current->data);
			current = current->prev;
		}
		printf("\n");
	}
}
#endif
