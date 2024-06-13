#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo de la lista enlazada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estructura para la pila
typedef struct Stack {
    Node* top;
} Stack;

// Funcion para inicializar la pila
void initialize(Stack* stack) {
    stack->top = NULL;
}

// Funcion para hacer push en la pila
void Push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Fallo reservando  memoria\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Se hizo push del valor %d en la pila\n", value);
}

// Funcion para imprimir la pila completa
void printStack(Stack* stack) {
    Node* temp = stack->top;
    if (temp == NULL) {
        printf("La pila esta vacia\n");
        return;
    }
    printf("Los valores en la pila:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeStack(Stack* stack) {
    Node* temp = stack->top;
    Node* nextNode;
    
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    
    stack->top = NULL;
}

int main() {
    Stack stack;
    initialize(&stack);

    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);

    printStack(&stack);

    freeStack(&stack);
    return 0;
}