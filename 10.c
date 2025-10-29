#include <stdio.h>
#include <pthread.h>

// ESTA FUNCIÓN imprime el final del mensaje motivacional
void * f1(void * arg){
    printf("porque soy el mejor!!");
    return NULL;
}

// ESTA FUNCIÓN imprime la parte media del mensaje
void * f2(void * arg){
    printf("de forma rapida y divertida ");
    return NULL;
}

// ESTA FUNCIÓN imprime el inicio del mensaje de aprendizaje
void * f3(void * arg){
    printf("Estoy aprendiendo ");
    return NULL;
}

// ESTA FUNCIÓN principal organiza los hilos para formar un mensaje coherente
int main() {
    pthread_t thread01, thread02, thread03;
    
    // Crear hilos en el orden correcto para el mensaje
    pthread_create(&thread01, NULL, f3, NULL);  // "Estoy aprendiendo "
    pthread_create(&thread02, NULL, f2, NULL);  // "de forma rapida y divertida "
    pthread_create(&thread03, NULL, f1, NULL);  // "porque soy el mejor!!"
    
    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);
    pthread_join(thread03, NULL);
    printf("\n");
    return 0;
}