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

// Funcion para verificar si la pila esta vacia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Funcion para hacer push en la pila
void Push(Stack* stack, int value) {
    // Reservar memoria
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Fallo reservando  memoria\n");
        return;
    }
    newNode->data = value;
    // El valor siguiente va a ser el top de el stack
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Se hizo push del valor %d en la pila\n", value);
}

// Funcion para hacer pop en la pila y 
int Pop(Stack* stack) {
    // Se verifica si la pila esta vacia
    if (isEmpty(stack)) {
        printf("La pila esta vacia. No se puede hacer pop.\n");
        return 1; // Se devuelve un 1 para indicar que la pila esta vacia
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Se hizo pop del valor %d de la pila\n", poppedValue);
    return poppedValue;
}

// Funcion para imprimir la pila completa
void printStack(Stack* stack) {
    Node* temp = stack->top;
    // Si la pila esta vacia
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

// Funcion para liberar memoria
void freeStack(Stack* stack) {
    Node* temp = stack->top;
    Node* nextNode;
    
    // Mientras temp sea distinto a null, va recorriendo el siguiente nodo y usando la funcion free
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

    Pop(&stack);
    Pop(&stack);
    printStack(&stack);
    
    Pop(&stack);
    

    printStack(&stack);

    freeStack(&stack);
    return 0;
}