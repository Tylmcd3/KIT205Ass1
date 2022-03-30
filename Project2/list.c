#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

UnitList new_list() {
	UnitList temp;
	temp.head = NULL;
	return temp;
}

// after changing to char*:
// -- need to change printf for string
void print_list(UnitList* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%s", current->unit_code);
		print_in_order_bst(&(current->students));
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

void insert_in_order(UnitList* self, String data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;
	ListNodePtr new_node = malloc(sizeof * new_node);
	String string = malloc((strlen(data) * sizeof * string) + 1);
	strcpy(string, data);

	new_node->students = new_bst();
	new_node->unit_code = string;
	new_node->next = NULL;

	while (current != NULL && current->unit_code < data) {
		prev = current;
		current = current->next;
	}
	if (new_node != NULL) {
		if (prev == NULL) {
			new_node->next = current;
			self->head = new_node;
		}
		else {
			new_node->next = current;
			prev->next = new_node;
		}
	}
}
// after changing to char*:
// -- change test in if statement to string compare (strcmp)
// -- free current->data (memory allocated for string) before freeing current
void delete_from_list(UnitList* self, String data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (!strcmp(data, current->unit_code)) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current->unit_code);
				destroy_bst(&(current->students));
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current->unit_code);
				destroy_bst(&(current->students));
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

// after changing to char*:
// -- need to free memory allocated for string before freeing node
void destroy_list(UnitList* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free->unit_code);
		destroy_bst(&(to_free->students));
		free(to_free);
	}
	self->head = NULL;
}

void enrol_student(UnitList* self, String unit, long id) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	String string = malloc((strlen(unit) * sizeof * string) + 1);
	strcpy(string, unit);


	while (current != NULL && !strcmp(current->unit_code, string)) {
		prev = current;
		current = current->next;
	}

	if (current != NULL) {
		insert_bst(&(current->students), id);
	}
	else {
		printf("The Unit doesnt exist, please check the unit code and try again.\n");
	}

}
