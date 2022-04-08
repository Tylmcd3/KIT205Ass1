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
	ListNodePtr new_node = malloc(sizeof *new_node);
	String string = malloc((strlen(data) * sizeof * string) + 1);
	strcpy_s(string, strlen(data) + 1, data);

	new_node->students = new_bst();
	new_node->unit_code = string;
	new_node->next = NULL;

	while (current != NULL && strcmp(current->unit_code, data) < 0) {
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

ListNodePtr find_node(UnitList *self, String unit){
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;


	while (current != NULL && strcmp(current->unit_code, unit) != 0) {
		prev = current;
		current = current->next;
	}

	return current;


}

void enrol_student(UnitList* self, String unit, long id) {
	ListNodePtr node = find_node(self, unit);

	if (node != NULL) {
		insert_bst(&(node->students), id);
	}
	else {
		printf("The Unit doesnt exist, please check the unit code and try again.\n");
	}

}

void unenrol_student(UnitList* self, String unit, long id) {
	ListNodePtr node = find_node(self, unit);

	if (node != NULL) {
		delete_bst(&(node->students), id);
	}
	else {
		printf("The Unit doesnt exist, please check the unit code and try again.\n");
	}
}

void unit_summary(UnitList* self, String unit){
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		printf("\n%s: %d\n", current->unit_code, count_bst(&current->students));
		prev = current;
		current = current->next;
	}
}

void print_students(UnitList* self, String unit) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	StudentBST tree;

	while (current != NULL && strcmp(current->unit_code, unit)!= 0)  {
		prev = current;
		current = current->next;
	}
	if (current != NULL) {
		tree = current->students;
		print_in_order_bst(&tree);
	}
	else {
		printf("Invalid Unit Code");
	}
	
}

void find_student_classes(UnitList* self, long id) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;
	printf("\n----------------------------------------------\nThe courses student %ld is enrolled in are:\n", id);
	while (current != NULL) {
		if (find_bst(&(current->students), id))
			printf("%s\n", current->unit_code);
		prev = current;
		current = current->next;
	}
	printf("\n");
}
