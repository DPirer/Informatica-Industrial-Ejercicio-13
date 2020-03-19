#include <stdio.h>

// Pedro Antonio Estévez Pérez

// Ejercicio 13

/* En los bits 10,9,8,7 de una variable de tipo short int hay codificado un número.
 * Almacena su valor en una variable de tipo unsigned char y muéstralo por pantalla
 * en formato decimal usando printf().*/

int main(void)
{
    short int codificado;
    printf("Introduce un numero: ");
    scanf("%d", &codificado);
    unsigned char descodificado;
    int i;

    /* Antes de nada, imprimimos el vector para ver mejor que el ejercicio está
     * correcto una vez se ejecute.*/

    printf("En binario es: ");
    for(i = 32768; i > 0; i >>= 1)
    {
        if(i & codificado)
            printf("1");
        else
            printf("0");
    }
    printf("b\n");

    /* Ponemos todos los bits a 0 excepto los que necesitamos, los deslazamos
     * a la derecha y los metemos en la nueva variable.*/

    codificado = codificado & 0x0780;
    codificado = codificado >> 7;
    descodificado = codificado;

    /* Ya tenemos la variable con los bits que debe. Imprimimos sólo la mitad derecha,
     * ya que la izquierda siempre seran 0 y transformamos el binario para ver el
     * mensaje oculto.*/

    printf("El codigo oculto es: ");
    for(i = 8; i > 0; i >>= 1)
    {
        if(i & descodificado)
            printf("1");
        else
            printf("0");
    }
    printf("b\n");
    printf("Que equivale al numero: %u\n\n", descodificado);
}
