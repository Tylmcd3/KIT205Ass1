#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bst.h"

int main() {
	UnitList units = new_list();
	printf("Make a selection\n1.Add unit\n2.Remove unit\n3.Enrol student in a unit\n4.Un-enrol student from a unit\n5.Print units with the total students in each unit\n6.Print all students enrolled in a unit\n7.Print an ordered list of units that a specific student is enrolled in\n");
	int selection = 1;
	String buffer = NULL;
	long id;
	while (selection) {
		scanf("%d",&selection);
		switch (selection) {
		case 1:
			printf("Enter the Unit code to add (Max 99 char): \n");
			scanf("%s", buffer);
			insert_in_order(&units, buffer);
			break;
		case 2:
			printf("Enter the Unit code to remove (Max 99 char): \n");
			scanf("%s", buffer);
			delete_from_list(&units, buffer);
			break;
		case 3:
			printf("Enter the Unit code: \n");
			scanf("%s", buffer);
			printf("Enter the Student ID to enter: \ns");
			scanf("%ld", &id);
			enrol_student(&units, buffer, id);

		}
	}
}
