#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
  int opcion;

  system("clear");
  cout << "  0. Salir................................\n";
  cout << "  1. Cargar grafo desde fichero...........\n";
  cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

  cout << "Introduzca opcion...:";
  cin >> opcion;

  return opcion;
}

template <class G_Nodo, class G_Lado>
bool cargarGrafo(Grafo<G_Nodo, G_Lado> *&g)
{
  ifstream ficheroEntrada;
  string ficheroMatriz, ficheroNodos;

  string frase;
  int lado;
  string nodo;
  std::vector<string> vectorNodos;
  cout << "Fichero de nodos: ";
  cin >> ficheroNodos;

  ficheroEntrada.open(ficheroNodos.c_str());

  while (!ficheroEntrada.eof())
  {

    while (ficheroEntrada >> nodo)
    {
      vectorNodos.push_back(nodo);
    }
  }

  g = new Grafo<string, int>((int)vectorNodos.size());
  g->setNodos(vectorNodos);
  ficheroEntrada.close();

  cout << "Fichero de la matriz de conexion: ";
  cin >> ficheroMatriz;
  std::vector<int> MatrizLados;
  ficheroEntrada.open(ficheroMatriz.c_str());

  while (!ficheroEntrada.eof())
  {
    while (ficheroEntrada >> lado)
    {
      MatrizLados.push_back(lado);
    }
  }
  g->setLados(MatrizLados);

  ficheroEntrada.close();

  return true;
}

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
  // Declaraciones en el archivo .h

  // Devuelve una matriz con las distancias mínimas de cada nodo al resto de los vértices.
  // Grafo<G_Nodo, G_Lado> path(g);

  // /* No tendría porqué ser necesario si ya hay ceros en las diagonales de ady */
  // for (int i = 0; i < path.getNumeroNodos(); i++)
  //   path.setLado(i, i, 0);

  // for (int k = 0; k < path.getNumeroNodos(); k++)
  //   for (int i = 0; i < path.getNumeroNodos(); i++)
  //     for (int j = 0; j < path.getNumeroNodos(); j++)
  //     {
  //       int dt = path.getLado(i, k) + path.getLado(k, j);
  //       if (path.getLado(i, j) > dt)
  //         path.setLado(i, j, dt);

  //     }

  // path.print();
  AlgoritmosGrafos<string, int> algoritmo(g);

  algoritmo.Floyd();
  // Imprime el resultado
  algoritmo.imprimeMatrices();
  string salida;
  string llegada;

  cout << endl;
  cout << endl;
  cout << "Introduzca la ciudad de salida: ";
  cin >> salida;

  cout << "Introduzca la ciudad de llegada: ";
  cin >> llegada;

  algoritmo.imprimeCamino(salida, llegada);
}

#endif