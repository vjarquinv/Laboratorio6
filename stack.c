// Laboratorio 6 -- Stack -- Valeria Jarquin Vargas, B83986
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Funcion para inicializar la pila
void initialize(Stack* stack) {
    stack->top = NULL;
}

// Funcion para verificar si la pila esta vacia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Funcion para hacer push en la pila (Agrega un elemento a la parte superior de la pila)
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
    printf("Se hizo push del elemento %d en el stack\n", value);
}

// Funcion para eliminar y devolver el elemento en la parte superior de la pila
int Pop(Stack* stack) {
    // Se verifica si la pila esta vacia
    if (isEmpty(stack)) {
        printf("El stack esta vacio. No se puede hacer pop.\n");
        return 1; // Se devuelve un 1 para indicar que la pila esta vacia
    }
    Node* temp = stack->top;
    // Se asigna el elemento que se va a eliminar
    int poppedValue = temp->data;
    // El elemento en la parte superior de la cima pasa a hacer el siguiente
    stack->top = stack->top->next;
    free(temp);
    printf("Se hizo pop del elemento %d del stack\n", poppedValue);
    return poppedValue;
}

// Funcion que devuelve el elemento en la parte superior de la pila sin eliminarlo
int Peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("El stack esta vacio. No se puede hacer peek.\n");
        return 1; // Se devuelve un 1 para indicar que la pila esta vacia
    }
    // Se asigna el elemento en la parte superior de la pila
    int topValue = stack->top->data;
    printf("El elemento en la parte superior del stack es %d\n", topValue);
    return topValue;
}

// Funcion para imprimir la pila completa
void printStack(Stack* stack) {
    Node* temp = stack->top;
    // Si la pila esta vacia
    if (temp == NULL) {
        printf("El stack esta vacio\n");
        return;
    }
    printf("Los elementos en el stack:\n");
    // Mientras la variable temp sea distinta a NULL se va a imprimir el siguiente elemento
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