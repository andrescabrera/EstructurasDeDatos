/*
 * Andrés Cabrera, EJ 1 Cap2, Estr. de Datos y Algoritmos, Turno Noche.
 *
 * matrizInt.h
 */

#ifndef MATRIZINT_H_
#define MATRIZINT_H_
#define FILAS	3
#define COLS	3
#define VALMIN	0
#define VALMAX	9
/*
 * muestra una matriz de enteros
 */
void mostrarMatrizInt(int A[][COLS], int filas, int cols);
/*
 * genera una matriz de enteros entre VALMIN y VALMAX
 */
void generarMatrizInt(int A[][COLS], int filas, int cols);
/*Suma de Matrices Cuadradas de Igual Dimensión*/
void sumarMatrizInt(int A[][COLS], int B[][COLS], int C[][COLS], int filas, int cols);
/*buscar menor, y fila que lo contiene*/
int buscarMenor(int A[][COLS], int filas, int cols, int nmenor);
// producto de matrices
void productoMatrices(int A[][COLS], int B[][COLS], int C[][COLS], int n);
//trasponer matrices cuadradas
void trasponerMatriz(int A[][COLS], int B[][COLS], int n);
//suma de la diagonal principal
void sumaDiagonalMatriz(int A[][COLS], int n);

#endif /* MATRIZINT_H_ */
