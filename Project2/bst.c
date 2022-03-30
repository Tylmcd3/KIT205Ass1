#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


BSTNodePtr find_bst_node(BSTNodePtr self, long n) {
    if (self == NULL || (n == self->student_id)) {
        return self;
    }
    else if (n < self->student_id) {
        return find_bst_node(self->left, n);
    }
    else {
        return find_bst_node(self->right, n);
    }
}

BSTNodePtr find_bst(StudentBST* self, long n) {
    return find_bst_node(self->root, n);
}

BSTNodePtr insert_bst_node(BSTNodePtr self, long n) {
    if (self == NULL) { // found where to insert the node
        self = malloc(sizeof *self);
        self->student_id = n;
        self->left = self->right = NULL;
    }
    else if (n < self->student_id) {
        self->left = insert_bst_node(self->left, n);
    }
    else if (n > self->student_id) {
        self->right = insert_bst_node(self->right, n);
    }
    return self;
}

void insert_bst(StudentBST* self, long n) {
    self->root = insert_bst_node(self->root, n);
}

BSTNodePtr min_node(BSTNodePtr self) {
    BSTNodePtr current = self;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

BSTNodePtr delete_bst_node(BSTNodePtr self, long n) {
    if (self != NULL) {
        if (n == self->student_id) {//found item
            if (self->left != NULL && self->right != NULL) {//two child case
                BSTNodePtr successor = min_node(self->right);
                self->student_id = successor->student_id;
                self->right = delete_bst_node(self->right, self->student_id);
            }
            else {
                BSTNodePtr to_free = self;
                if (self->left) {
                    self = self->left;
                }
                else {
                    self = self->right;
                }
                free(to_free);
            }
        }
        else if (n < self->student_id) {
            self->left = delete_bst_node(self->left, n);
        }
        else if (n > self->student_id) {
            self->right = delete_bst_node(self->right, n);
        }
    }
    return self;
}

void delete_bst(StudentBST* self, long n) {
    self->root = delete_bst_node(self->root, n);
}

StudentBST new_bst() {
    StudentBST newBST;
    newBST.root = NULL;
    return newBST;
}

void print_pre_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        printf(" %d ", self->student_id);
        print_pre_order_bst_node(self->left);
        print_pre_order_bst_node(self->right);
        printf(")");
    }
    else {
        printf("_");
    }
}
void print_pre_order_bst(StudentBST* self) {
    print_pre_order_bst_node(self->root);
}

void print_in_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_in_order_bst_node(self->left);
        printf(" %d ", self->student_id);
        print_in_order_bst_node(self->right);
        printf(")");
    }
    else {
        printf("_");
    }
}
void print_in_order_bst(StudentBST* self) {
    print_in_order_bst_node(self->root);
}

void print_post_order_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        printf("(");
        print_post_order_bst_node(self->left);
        print_post_order_bst_node(self->right);
        printf(" %d ", self->student_id);
        printf(")");
    }
    else {
        printf("_");
    }
}
void print_post_order_bst(StudentBST* self) {
    print_post_order_bst_node(self->root);
}

int height_of_bst_node(BSTNodePtr self) {
    int left = 0, right = 0;
    int level = 1;
    if (self->left != NULL) {
        left = height_of_bst_node(self->left);

    }
    if (self->right != NULL) {
        right = height_of_bst_node(self->right);
    }
    if (left > right) {
        level += left;
    }
    else {
        level += right;
    }

    return level;

}

int height_of_bst(StudentBST* self) {
    return height_of_bst_node(self->root);
}

void destroy_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        if (self->left != NULL) {
            destroy_bst_node(self->left);
        }
        else if (self->right != NULL) {
            destroy_bst_node(self->right);
        }
        else {
            free(self);
        }
    }
}

void destroy_bst(StudentBST* self) {
    destroy_bst_node(self->root);
}

