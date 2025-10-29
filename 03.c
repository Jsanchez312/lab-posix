/*************************
 * Autor: Juan Pablo Sanchez
 * Fecha:28/10/2025
 * Profesor: Jhon Corredor
 * Clase: Sistemas Operativos
 * **************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int count = 0;
#define COUNT_DONE  15
#define COUNT_HALT1  4
#define COUNT_HALT2 11

// ESTA FUNCIÓN incrementa el contador pero se detiene en un rango específico usando condition variables
void *count01(void *arg) {
    for(;;) {
        pthread_mutex_lock( &condition_mutex );
        while( count >= COUNT_HALT1 && count <= COUNT_HALT2 )
        {
            pthread_cond_wait( &condition_cond, &condition_mutex );
        }
        pthread_mutex_unlock( &condition_mutex );

        pthread_mutex_lock( &count_mutex );
        count++;
        printf("Counter value functionCount ==> 01 <=>: %d\n",count);
        pthread_mutex_unlock( &count_mutex );

        if(count >= COUNT_DONE) return(NULL);
    }
}

// ESTA FUNCIÓN incrementa el contador y señala a los hilos en espera cuando está fuera del rango crítico
void *count02(void *arg) {
    for(;;) {
        pthread_mutex_lock( &condition_mutex );
        if( count < COUNT_HALT1 || count > COUNT_HALT2 )
        {
            pthread_cond_signal( &condition_cond );
        }
        pthread_mutex_unlock( &condition_mutex );

        pthread_mutex_lock( &count_mutex );
        count++;
        printf("Counter value functionCount ==> 02 <=>: %d\n",count);
        pthread_mutex_unlock( &count_mutex );

        if(count >= COUNT_DONE) return(NULL);
    }
}

// ESTA FUNCIÓN principal crea dos hilos que coordinan el incremento del contador
int main() {
    pthread_t thread1, thread2;
    pthread_create( &thread1, NULL, &count01, NULL);
    pthread_create( &thread2, NULL, &count02, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    return 0;

}
