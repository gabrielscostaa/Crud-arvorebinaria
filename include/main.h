#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#ifdef _WIN32
    #define CLEAR "cls"
#elif __linux__
    #define CLEAR "clear"
#endif

struct ListNode {
    int poltrona;
    int disponivel;
    struct ListNode *prev;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

struct TreeNode {
    int poltrona;
    int disponivel;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

#include <avl.h>
#include <create.h>
#include <delete.h>
#include <list.h>
#include <order.h>
#include <search.h>

// Utils
bool isNumber (char *str);

#endif // MAIN_H