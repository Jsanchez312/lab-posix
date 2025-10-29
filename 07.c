#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 900000000
long long sum = 0;

// ESTA FUNCIÓN modifica la suma global en un hilo usando el valor pasado como parámetro
void* function(void *arg ) {
    int valor = *(int *)arg;
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += valor;
    }
    return NULL;
}

// ESTA FUNCIÓN principal crea hilos para operaciones concurrentes en la suma global
int main(void) {
    pthread_t id01, id02;
    int valor1 = 1;
    int valor2 = -1;

    pthread_create(&id01, NULL, function, &valor1);
    pthread_create(&id02, NULL, function, &valor2);

    pthread_join(id01, NULL);
    pthread_join(id02, NULL);

    printf("Sum = %lld\n", sum);
    return 0;
}