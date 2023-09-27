#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Se pide:
Cargar la matriz y el nombre y apellido del alumno y luego informar: Nombre
completo del alumno y el siguiente reporte:
a. Promedio en cada una de las materias
b. Porcentaje de materias aprobadas por trimestres (nota > 6).
c. Promedio general.
*/
#define CANT_MATERIAS 5
#define LONGITUD_TEXTO 15
#define CANT_TRIMESTRE 3
#define APROBACION 6
void verMatriz(materias);

void main(){
    char nombre[20];
    char apellido[20];
    char materias[CANT_MATERIAS][LONGITUD_TEXTO] = {
        "Matematica",
        "Lengua",
        "Ingles",
        "Geografia",
        "Biologia",
    };
    int boletin[CANT_TRIMESTRE][CANT_MATERIAS];
    printf("Ingresar nombre del alumno \n>");
    gets(nombre);
    printf("Ingresar apellido del alumno \n>");
    gets(apellido);
    system("cls");
    printf("El boletin del alumno %s %s:\n",nombre, apellido);
    cargarMatriz(boletin);
    verMatriz(materias, boletin);
}

int cargarMatriz(int boletin[CANT_TRIMESTRE][CANT_MATERIAS]){
    int nota = 0;
    for(int i = 0; i < CANT_TRIMESTRE; i++){
        for(int j = 0; j < CANT_MATERIAS; j++){
            nota = rand() % 10 +1;
            boletin[i][j] = nota;
        }
    }
    return(boletin[CANT_TRIMESTRE][CANT_MATERIAS]);
}

void verMatriz(char materias[CANT_MATERIAS][LONGITUD_TEXTO], int matriz[CANT_TRIMESTRE][CANT_MATERIAS]){
    printf("       ");

    for (int x = 0; x < CANT_MATERIAS; x++){
        printf("| %s |", materias[x]);
    }

        int promediosMaterias[CANT_MATERIAS];
    for (int i = 0; i < CANT_MATERIAS; i++) {
        promediosMaterias[i] = 0;
    }
    int prom = 0;
    int porcentaje = 0;
    int suma = 0;
    printf("Promedio G.|");//Promedio General
    printf("Porcentaje A."); //Porcetaje de aprobacion
    for (int i = 0; i < CANT_TRIMESTRE; i++){
        printf("\n|Trim %d|", i+1);
        for(int j = 0; j < CANT_MATERIAS; j++){
            printf("|    %-5d |", matriz[i][j]);
            promediosMaterias[j] += matriz[i][j];
            prom += matriz[i][j];
            if(matriz[i][j] >= 6){
                porcentaje++;
            }
        }
        prom = prom / CANT_MATERIAS;
        printf("|   %d   |", prom);
        printf("|    %d   |", (100 * porcentaje)/CANT_MATERIAS);
        porcentaje = 0;
        prom = 0;

    }

    printf("\n|Prom. |");
    for (int i = 0; i < CANT_MATERIAS; i++) {
        printf("|    %d     |", promediosMaterias[i] / CANT_TRIMESTRE);
    }
}
