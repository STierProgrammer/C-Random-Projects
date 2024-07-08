#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void helloWorld();
void variablesAndTypes();
void arrays();
void multidimensionalArrays();
void conditions();
void strings();
void forLoops();
void whileLoops();
void functions();
int add(int a, int b);
void staticAndAdvanced();
void pointers();
void structures();
void functionArgumentsByReference(int *x);
void dynamicAllocation();
void arraysAndPointers();
void recursion(int n);
void linkedList();
void binaryTree();
void unions();
void pointerArithmetics();
void functionPointers();
void bitmasks();

// Struct Definitions
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Union Definition
typedef union {
    int i;
    float f;
    char c;
} MyUnion;

// Enum Definition
typedef enum {
    BIT0 = 1 << 0,
    BIT1 = 1 << 1,
    BIT2 = 1 << 2,
    BIT3 = 1 << 3
} Bitmask;

void helloWorld() {
    printf("Hello, World!\n");
}

void variablesAndTypes() {
    int a = 10;
    float b = 20.5;
    char c = 'A';
    printf("Integer: %d, Float: %.2f, Char: %c\n", a, b, c);
}

void arrays() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("Array[%d] = %d\n", i, arr[i]);
    }
}

void multidimensionalArrays() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
}

void conditions() {
    int x = 10;
    if (x > 0) {
        printf("x is positive.\n");
    } else {
        printf("x is non-positive.\n");
    }
}

void strings() {
    char str1[11] = "Hello";
    char str2[] = "World";
    strcat(str1, str2);
    printf("Concatenated String: %s\n", str1);
}

void forLoops() {
    for (int i = 0; i < 5; i++) {
        printf("For loop iteration %d\n", i);
    }
}

void whileLoops() {
    int i = 0;
    while (i < 5) {
        printf("While loop iteration %d\n", i);
        i++;
    }
}

void functions() {
    int sum = add(5, 10);
    printf("Sum of 5 and 10 is: %d\n", sum);
}

int add(int a, int b) {
    return a + b;
}

void staticAndAdvanced() {
    static int counter = 0;
    counter++;
    printf("Static variable counter: %d\n", counter);
}

void pointers() {
    int x = 5;
    int *ptr = &x;
    printf("Pointer value: %d\n", *ptr);
}

void structures() {
    typedef struct {
        int id;
        char name[20];
    } Person;
    
    Person p1;
    p1.id = 1;
    strcpy(p1.name, "Alice");
    printf("Person ID: %d, Name: %s\n", p1.id, p1.name);
}

void functionArgumentsByReference(int *x) {
    *x = 20;  
}

void dynamicAllocation() {
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2;
        printf("Dynamic Array[%d] = %d\n", i, arr[i]);
    }
    free(arr);
}

void arraysAndPointers() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr;
    for (int i = 0; i < 3; i++) {
        printf("Array Element %d = %d\n", i, *(ptr + i));
    }
}

void recursion(int n) {
    if (n > 0) {
        printf("Recursion step %d\n", n);
        recursion(n - 1);
    }
}

void linkedList() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = NULL;

    Node *temp = head;
    while (temp != NULL) {
        printf("Linked List Node Data: %d\n", temp->data);
        temp = temp->next;
    }

    free(head->next);
    free(head);
}

void binaryTree() {
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = 10;
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->data = 5;
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->data = 15;

    printf("Binary Tree Root Node Data: %d\n", root->data);
    printf("Binary Tree Left Child Data: %d\n", root->left->data);
    printf("Binary Tree Right Child Data: %d\n", root->right->data);

    free(root->left);
    free(root->right);
    free(root);
}

void unions() {
    MyUnion u;
    u.i = 10;
    printf("Union Integer Value: %d\n", u.i);
    u.f = 5.5;
    printf("Union Float Value: %.2f\n", u.f);
    u.c = 'A';
    printf("Union Char Value: %c\n", u.c);
}

void pointerArithmetics() {
    int arr[3] = {1, 2, 3};
    int *ptr = arr;
    printf("Pointer Arithmetic: %d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2));
}

void functionPointers() {
    int (*funcPtr)(int, int) = add;
    printf("Function Pointer Result: %d\n", funcPtr(3, 4));
}

void bitmasks() {
    Bitmask mask = (Bitmask)(BIT1 | BIT3);
    printf("Bitmask with BIT1 and BIT3 set: %d\n", mask);
}

int main() {
    helloWorld();

    variablesAndTypes();

    arrays();

    multidimensionalArrays();

    conditions();

    strings();

    forLoops();

    whileLoops();

    functions();

    staticAndAdvanced();

    pointers();

    structures();

    int value = 10;

    functionArgumentsByReference(&value);

    printf("Value after functionArgumentsByReference: %d\n", value);

    dynamicAllocation();

    arraysAndPointers();

    recursion(5);

    linkedList();

    binaryTree();

    unions();

    pointerArithmetics();

    functionPointers();

    bitmasks();

    return 0;
}
