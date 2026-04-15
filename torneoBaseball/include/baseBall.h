#ifndef BASEBALL_H
#define BASEBALL_H
#include <string>
// Constantes
#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

class baseBall
{
    public:
        baseBall();
        virtual ~baseBall();
        void llamaCiclo();
    protected:
    private:
        int busquedaAleatorios(int minimo, int maximo);
        void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
        void imprimirMatrizLinea();
        float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1],
                     char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA],
                     std::string nombreFacultad);
};
#endif // BASEBALL_H
