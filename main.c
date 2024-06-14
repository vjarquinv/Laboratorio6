// Laboratorio 6 -- Main Stack -- Valeria Jarquin Vargas, B83986

#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;

    // Se inicializa la pila
    initialize(&stack);

    // Se realiza 3 push
    printf("Prueba de la funcion Push\n");
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);

    // Se imprime la lista inicial
    printStack(&stack);
    printf ("\n");
    // Se realiza 2 pop
    printf("Prueba de la funcion Pop\n");
    Pop(&stack);
    Pop(&stack);
    // Se imprime la lista con un unico elemento
    printStack(&stack);
    printf ("\n");
    // Se realiza un pop
    Pop(&stack);
    // la pila queda vacia
    Pop(&stack);
    printf ("\n");

    // Se realiza 2 push para tener elementos en la pila
    printf("Se agregan elementos al stack\n");
    Push(&stack, 4);
    Push(&stack, 5);
    printf ("\n");

    printf("Prueba de la funcion Peek\n");
    printStack(&stack);
    // Se realiza peek
    Peek(&stack);
    printf ("\n");

    // Se hacen 2 pops y peek para ver que sucede si la lista esta vacia
    Pop(&stack);
    Pop(&stack);
    Peek(&stack);


    // Se libera la memoria
    freeStack(&stack);
    return 0;
}