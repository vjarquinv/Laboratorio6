# Laboratorio 6 -- Makefile Stack -- Valeria Jarquin Vargas, B83986

CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lm

SRCS = main.c stack.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# Nombre del ejecutable
EXEC = main

# Regla para ejecutar
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos
clean:
	rm -f $(OBJS) $(EXEC)