#include <stdio.h>
#include <pthread.h>

// ESTA FUNCIÓN imprime un mensaje motivacional
void * f1(void * arg){
    printf("porque soy el mejor!!");
    return NULL;
}

// ESTA FUNCIÓN imprime un mensaje sobre el aprendizaje
void * f2(void * arg){
    printf("de forma rapida y divertida ");
    return NULL;
}

// ESTA FUNCIÓN imprime el inicio del mensaje de aprendizaje
void * f3(void * arg){
    printf("Estoy aprendiendo ");
    return NULL;
}

// ESTA FUNCIÓN principal coordina la ejecución de tres hilos en orden específico
int main() {
    pthread_t thread01, thread02, thread03;
    pthread_create(&thread01, NULL, f3, NULL);  // Primero
    pthread_create(&thread02, NULL, f2, NULL);  // Segundo  
    pthread_create(&thread03, NULL, f1, NULL);  // Tercero
    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);
    printf("\n");
    return 0;
}