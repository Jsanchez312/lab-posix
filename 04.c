#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

pthread_t ttd[3];
int counter;
pthread_mutex_t lock;

// ESTA FUNCIÓN simula un trabajo computacional intensivo
void* compute(void *arg) {
    unsigned long t = 0;
    
    pthread_mutex_lock(&lock);
    counter += 1;
    printf("\n Job %d has started\n", counter);
    pthread_mutex_unlock(&lock);

    for(t=0; t<0xFFFFFFFF;t++);
    
    pthread_mutex_lock(&lock);
    printf("\n Job %d has finished\n", counter);
    pthread_mutex_unlock(&lock);

    return NULL;
}

// ESTA FUNCIÓN principal crea y gestiona múltiples hilos de trabajo
int main(void) {
    int t = 0;
    int error;

    // Inicializar mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(t < 3) {
        error = pthread_create(&(ttd[t]), NULL, &compute, NULL);
        if (error != 0)
            printf("\nThread can't be created : [%s]", strerror(error));
        t++;
    }

    pthread_join(ttd[0], NULL);
    pthread_join(ttd[1], NULL);
    pthread_join(ttd[2], NULL); 

    pthread_mutex_destroy(&lock);
    return 0;
}