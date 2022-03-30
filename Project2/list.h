#pragma once
#include "bst.h"

typedef char* String;

typedef struct listNode {
    String unit_code;
    StudentBST students;
    struct listNode* next;
} *ListNodePtr;

typedef struct list {
    ListNodePtr head;
} UnitList;

UnitList new_list();
void print_list(UnitList* self);
void insert_in_order(UnitList* self, String data);
void delete_from_list(UnitList* self, String data);
void destroy_list(UnitList* self);
void
enrol_student(UnitList* self, String unit, long id);