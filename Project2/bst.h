#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode {
    long student_id;
    struct bstNode* left;
    struct bstNode* right;
} *BSTNodePtr;

typedef struct bst {
    BSTNodePtr root;
} StudentBST;

BSTNodePtr find_bst(StudentBST* self, long n);
void insert_bst(StudentBST* self, long n);
void delete_bst(StudentBST* self, long n);
StudentBST new_bst();
void print_pre_order_bst(StudentBST* self);
void print_in_order_bst(StudentBST* self);
void print_post_order_bst(StudentBST* self);
int height_of_bst(StudentBST* self);
void destroy_bst(StudentBST* self);
int count_bst(StudentBST *self);

