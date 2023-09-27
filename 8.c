//1-escribir un codigo que a travez de un menu me llene dos vectores de 10 posiciones cada uno con numeros al azar entre 20 y 35 la primera opcion del menu debe mostrar estos vectores y cuantos datos se repiten en cada uno.
//2-debe mostrar estos numeros al azar pero sin que los datos se repitan.
//3-debe mostrar la union entre ambos vectores
//4-debe mostrar la interseccion entre ambos vectores
//5-debe mostrar la resta de los elementos del Primer Vector Menos el Segundo Vector(V1-V2)
//6-debe mostrar la resta del segundo vector menos el primer vector (V2-V1)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define POSICIONES 10

int unionVectores(int[], int);
void imprimir(int[], int);
void diferenciaArrays(int[], int[], int);
void unionArrays(int[], int[]);
void interArray(int[], int[]);
int cargar(int[]);
void numAzarSinRepetir(int[]);
void restaVector1(int[], int[]);
void restaVector2(int[], int[]);
void repeticionesArrays(int[]);

void main(){
    int opcion;
    int firstArray[POSICIONES]; int secondArray[POSICIONES];
    cargar(firstArray);
    cargar(secondArray);
    printf("Primer Vector\n");
    imprimir(firstArray, POSICIONES);
    printf("\nSegundo Vector\n");
    imprimir(secondArray, POSICIONES);
    printf("\n\n||MENU PRINCIPAL||\n1-Ver vector y cuantos datos se repiten en cada vector\n2-Ver vector con numeros al azar distintos\n3-Ver Union entre vectores\n4-Interseccion entre vectores\n5-Resta entre el primer vector y el segundo\n6-Resta entre el segundo vector y el primero\n");
    do{
        printf("\nIngrese una opcion\n>");
        scanf("%d", &opcion);
            switch(opcion){
            case 1:
                printf("La cantidad de repeticiones del primer vector es de: ");
                repeticionesArrays(firstArray);
                printf("\nLa cantidad de repeticiones del segundo vector es de: ");
                repeticionesArrays(secondArray);
                break;
            case 2:
                numAzarSinRepetir(firstArray);
                printf("\n");
                numAzarSinRepetir(secondArray);
                break;
            case 3:
                unionArrays(firstArray, secondArray);
                break;
            case 4:
                interArray(firstArray, secondArray);
                break;
            case 5:
                restaVector1(firstArray, secondArray);
                break;
            case 6:
                restaVector2(firstArray, secondArray);
                break;
            default:
                printf("Opcion Invalida\n");
                break;
        }
    }while(opcion <=6 && opcion >= 1);
}
void numAzarSinRepetir(int array[]){
    int numero;
    bool band;
    for(int i = 0; i < POSICIONES; i++){
        do{
            numero = rand() % 16 + 20;
            band = false;
            for(int j = 0; j < i; j++){
                if(array[j]== numero){
                    band=true;
                    break;
                }
            }
        }while(band);
        array[i] = numero;
    }

    imprimir(array, POSICIONES);
}
void repeticionesArrays(int first[]){
    int aux;
    bool bandera = false;
    while(!bandera){
        bandera = true;
        for(int i = 0; i < POSICIONES; i++){
            if(first[i]> first[i+1]){
                aux = first[i];
                first[i] = first[i+1];
                first[i + 1] = aux;
                bandera = false;
            }
        }
    }
    int cantRepeticiones = 0;
    for (int i = 0; i < POSICIONES; i++){
        if(first[i]== first[i+1]){
            cantRepeticiones++;
        }
    }
    printf("%d", cantRepeticiones);
}
void interArray(int first[],int second[]){
    int intersec = 0;
    int cont = 0;
    int third[POSICIONES];
    for(int i = 0; i < POSICIONES; i++){
        for(int j = 0; j < POSICIONES; j++){
            if(first[i] == second[j]){
                intersec = 1;
                break;
            }
        }
        if(intersec == 1){
            third[cont] = first[i];
            cont++;
        }
        intersec = 0;
    }
    imprimir(third, cont);
}
void diferenciaArrays(int unionArray[],int diferenciaArray[],int tamanio){
    int repetido = 0;
    int contador = 0;
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            if(unionArray[i] == unionArray[j] && i != j){
                repetido = 1;
                break;
            }
        }
        if(repetido != 1){
            diferenciaArray[contador] = unionArray[i];
            contador++;
        }
        repetido = 0;
    }
}
void unionArrays(int first[],int second[]){
    int repetidos = 0;
    int third[20];
    for(int i = 0; i < POSICIONES; i++){
        third[i] = first[i];
    }
    for(int j = 0; j < POSICIONES; j++){
        third[j+POSICIONES] = second[j];
    }
    imprimir(third, 20);
}
int cargar(int array[]){
    int numero = 0;
    for(int i = 0; i <  POSICIONES;i++){
        numero = rand() % 16 + 20;
        array[i] = numero;
    }
    return array[POSICIONES];
}
void imprimir(int vector[], int largo){
    for(int i = 0; i < largo; i++){
        printf("%d |", vector[i]);
    }
}
void restaVector1(int array1[], int array2[]){
    int restaVectores[POSICIONES];
    for(int i = 0; i < POSICIONES; i++){
        restaVectores[i] = array1[i] - array2[i];
    }
    imprimir(restaVectores, POSICIONES);
}
void restaVector2(int array1[], int array2[]){
    int restaVectores[POSICIONES];
    for(int i = 0; i < POSICIONES; i++){
        restaVectores[i] = array2[i] - array1[i];
    }
    imprimir(restaVectores, POSICIONES);
}
