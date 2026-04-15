#include "baseBall.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <string.h>

using namespace std;

baseBall::baseBall()
{
    //ctor
}

void baseBall::llamaCiclo() {
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];

    char opcion;
    bool repetir = true;

    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;

    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Yankees","Red Sox","Chicago","Dodgers","Giants"};

    do {
        system("cls");
        promedio_facultad_1 = promedio_facultad_2 = promedio_facultad_3 = 0;

        cout << "*** Comparativo de Temporadas ***" << endl << endl;

        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Temporada 2023");

        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Temporada 2024");

        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Temporada 2025");

        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3) {
            cout << " La Temporada con el mejor promedio es : Temporada 2023 Promedio: " << promedio_facultad_1 << endl;
        } else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3) {
            cout << " La Temporada con el mejor promedio es : Temporada 2024 Promedio: " << promedio_facultad_2 << endl;
        } else if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1) {
            cout << " La Temporada con el mejor promedio es : Temporada 2025 Promedio: " << promedio_facultad_3 << endl;
        } else {
            cout << " Algunas Temporadas tienen el mismo promedio " << endl << endl;
        }

        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n') repetir = false;

    } while (repetir);
}

int baseBall::busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void baseBall::llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) {
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        float suma = 0;
        for (int x = 0; x < NUMERO_NOTAS; x++) {
            int calificacion = 0;
            if (x == 0 || x == 3) calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            else if (x == 1) calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            else if (x == 2) calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);

            suma += calificacion;
            matriz[y][x] = calificacion;
        }
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void baseBall::imprimirMatrizLinea() {
    cout << "+--------";
    for (int x = 0; x < NUMERO_NOTAS + 1; x++) cout << "+---------";
    cout << "+\n";
}

float baseBall::imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                     char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA],
                     string nombreFacultad) {
    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);

    cout << nombreFacultad << endl;
    cout << "Puntos de los Ultimos 5 juegos" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Equipo";
    for (int x = 0; x < NUMERO_NOTAS; x++) cout << setw(9) << "Pts";
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();

    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        cout << "!" << setw(8) << alumnos[y] << "!";
        for (int x = 0; x < NUMERO_NOTAS; x++) cout << setw(9) << matriz[y][x] << "!";
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += promedio;
        if (promedio > promedioMayor) {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }

    float promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Mejor punteo: " << setw(10) << alumnoPromedioMayor << setw(10) << promedioMayor << endl;
    cout << "Peor punteo: " << setw(10) << alumnoPromedioMenor << setw(10) << promedioMenor << endl;
    cout << "Punteo prom: " << setw(10) << promedioGeneral << endl << endl;

    return promedioGeneral;
}

baseBall::~baseBall()
{
    //dtor
}
