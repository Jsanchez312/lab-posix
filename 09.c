/*************************
 * Autor: Juan Pablo Sanchez
 * Fecha:28/10/2025
 * Profesor: Jhon Corredor
 * Clase: Sistemas Operativos
 * **************************/
#include <stdio.h>
#include <pthread.h>

long balance = 0;

// ESTA FUNCIÓN incrementa el balance global en un hilo
void * increment(void * arg){
    for(long i=0;i<10000000;i++) {
        balance++;
    }
    pthread_exit(NULL);
}

// ESTA FUNCIÓN decrementa el balance global en un hilo
void * decrement(void * arg){
    for(long j=0;j<10000000;j++) {
        balance--;
    }
    pthread_exit(NULL);
}

// ESTA FUNCIÓN principal demuestra race condition en acceso a variable compartida
int main(){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Value of balance is :%ld\n", balance);
    return 0;

}
