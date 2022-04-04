#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bst.h"

#define MAX_SIZE 100

int main() {
	UnitList units = new_list();
	int selection = 1;
	String buffer[MAX_SIZE];
	long id;
	while (selection) {
		printf("Make a selection\n1.Add unit\n2.Remove unit\n3.Enrol student in a unit\n4.Un-enrol student from a unit\n5.Print units with the total students in each unit\n6.Print all students enrolled in a unit\n7.Print an ordered list of units that a specific student is enrolled in\n0.Quit\n");
		scanf("%d",&selection);
		switch (selection) {
		case 1:
			printf("Enter the Unit code to add (Max 99 char): \n");
			scanf_s("%s", buffer, MAX_SIZE);
			insert_in_order(&units, buffer);
			break;
		case 2:
			printf("Enter the Unit code to remove (Max 99 char): \n");
			scanf_s("%s", buffer, MAX_SIZE);
			delete_from_list(&units, buffer);
			break;
		case 3:
			printf("Enter the Unit code: \n");
			scanf_s("%s", buffer, MAX_SIZE);
			printf("Enter the Student ID to enter: \n");
			scanf("%ld", &id);
			enrol_student(&units, buffer, id);
			break;
		case 4:
			printf("Enter the Unit code: \n");
			scanf_s("%s", buffer, MAX_SIZE);
			printf("Enter the Student ID to remove: \n");
			scanf("%ld", &id);
			unenrol_student(&units, buffer, id);
			break;
		case 5:
			unit_summary(&units, buffer);
			break;
		case 6:
			printf("Enter the Unit code: \n");
			scanf_s("%s", buffer, MAX_SIZE);
			print_students(&units, buffer);
			break;
		case 7:
			printf("Enter the Student ID to their enrolled classes: ");
			scanf("%ld", &id);
			find_student_classes(&units, id);
			break;
		}
	}
	printf("\nThank you\n");
	return 0;
}
