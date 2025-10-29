/*************************
 * Autor: Juan Pablo Sanchez
 * Fecha:28/10/2025
 * Profesor: Jhon Corredor
 * Clase: Sistemas Operativos
 * **************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// ESTA FUNCIÓN simula una operación que entra en condición de carrera
void* operation(void* arg)
{
    printf("\nEntered race...\n");
    //critical section
    sleep(4);
    printf("\nJust Exiting race...\n");
    return NULL;
}

// ESTA FUNCIÓN principal demuestra ejecución concurrente de hilos
int main()
{
    pthread_t thread01,thread02;
    pthread_create(&thread01,NULL,operation,NULL);
    sleep(2);
    pthread_create(&thread02,NULL,operation,NULL);

    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    
    return 0;

}
