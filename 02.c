/*************************
 * Autor: Juan Pablo Sanchez
 * Fecha:28/10/2025
 * Profesor: Jhon Corredor
 * Clase: Sistemas Operativos
 * **************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 10
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

// ESTA FUNCIÓN incrementa un contador compartido de forma segura usando mutex
void *thread_function(void *arg) {
    int i = *(int *) (arg);
    printf("Thread number: %d | Thread ID %ld\n", i, pthread_self());
    pthread_mutex_lock( &mutex1 );
    counter++;
    pthread_mutex_unlock( &mutex1 );
    return NULL;
}

// ESTA FUNCIÓN principal crea múltiples hilos y espera a que terminen
int main() {
    pthread_t thread_id[NTHREADS];
    int i, j;
    int thread_args[NTHREADS];

    for(i=0; i < NTHREADS; i++)
    {
        thread_args[i] = i;
        pthread_create( &thread_id[i], NULL, thread_function, &thread_args[i] );
    }

    // Esperar a que todos los hilos terminen
    for(i=0; i < NTHREADS; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    printf("Final counter value: %d\n", counter);
    return 0;

}
