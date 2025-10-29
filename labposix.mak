CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGETS = challenge01 challenge02 challenge03 challenge04 challenge05 challenge06 challenge07 challenge08 challenge09 challenge10

# Regla por defecto: compilar todos los challenges
all: $(TARGETS)

# Reglas individuales para cada challenge
challenge01: challenge01.c
	$(CC) $(CFLAGS) -o $@ $<

challenge02: challenge02.c
	$(CC) $(CFLAGS) -o $@ $<

challenge03: challenge03.c
	$(CC) $(CFLAGS) -o $@ $<

challenge04: challenge04.c
	$(CC) $(CFLAGS) -o $@ $<

challenge05: challenge05.c
	$(CC) $(CFLAGS) -o $@ $<

challenge06: challenge06.c
	$(CC) $(CFLAGS) -o $@ $<

challenge07: challenge07.c
	$(CC) $(CFLAGS) -o $@ $<

challenge08: challenge08.c
	$(CC) $(CFLAGS) -o $@ $<

challenge09: challenge09.c
	$(CC) $(CFLAGS) -o $@ $<

challenge10: challenge10.c
	$(CC) $(CFLAGS) -o $@ $<

# Compilar y ejecutar un challenge específico
run_%: %
	./$<

# Limpiar archivos compilados
clean:
	rm -f $(TARGETS)