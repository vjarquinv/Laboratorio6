// Laboratorio 6 -- Interfaz Stack -- Valeria Jarquin Vargas, B83986

#ifndef STACK
#define STACK

// Estructura para un nodo de la lista enlazada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Estructura para la pila
typedef struct Stack {
    Node* top;
} Stack;

void initialize(Stack* stack); // Inicializa el stack
int isEmpty(Stack* stack); // Verifica si la pila esta vacio
void Push(Stack* stack, int value); // Agrega un elemento en la parte superior de la pila
int Pop(Stack* stack); // Elimina y devuelve el elemento en la parte superior de la pila
int Peek(Stack* stack); // Devuelve el elemento en la parte superior de la pila sin eliminarlo
void printStack(Stack* stack); // Imprime la pila
void freeStack(Stack* stack); // Libera la memoria

#endif