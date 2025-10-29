/*********************************************************************************************
 * Pontificia Universidad Javeriana
 * Autor: Juan Sánchez
 * Materia Sistemas Operativos
 * Docente: J. Corredor, PhD
 * Fecha: 27/10/2025
 * Tema: Posix para la creación de hilos concurrentes:
 *
 * Descripción:
 * "Este código evidencia condiciones de carrera en operaciones de incremento/decremento
 *  sin mecanismos de sincronización"
 *
 *********************************************************************************************/
#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 900000000
long long sum = 0;

// ESTA FUNCIÓN incrementa o decrementa la suma global según el valor
void function(int valor) {
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += valor;
    }
}

// ESTA FUNCIÓN principal ejecuta secuencialmente incremento y decremento
int main(void) {
    function(1);
    function(-1);
    printf("Sum = %lld\n", sum);
    return 0;

}

