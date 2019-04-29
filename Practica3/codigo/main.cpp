/*!
  \file   macros.hpp
  \brief  Macros para la pantalla
  \author Alejandro Ariza Gener
  \date   26-02-2019
  \note  http://isthe.com/chongo/tech/comp/ansi_escapes.html
*/

#include <cstdlib> //para usar srand()
#include <iostream>

#include "arbolbinarioordenadoenlazado.hpp"
#include "generarpersona.hpp"
#include "macros.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"

using namespace ed;
int menu();
int generaRandom();

int main() {
  srand(time(0));
  ArbolBinarioOrdenadoEnlazado<Persona> a;

  // TODO
  int option, nPersonas, cont;
  Persona p;
  EscribirNodo<Persona> escribe;
  AlmacenarNodo<Persona> almacena;

  do {
    option = menu();

    std::cout << CLEAR_SCREEN;
    PLACE(3, 1);

    switch (option) {
    case 0:
      PLACE(3, 1);
      std::cout << BIYELLOW;
      std::cout << "[0] Fin del programa" << std::endl << std::endl;
      std::cout << RESET;
      break;

    case 1:
      std::cout << "Inserte el numero de personas\n";
      std::cin >> nPersonas;
      cont = 0;
      for (int i = 0; i < nPersonas; i++) {
        p = generarDatosPersonales();
        if (a.insertar(p)) {
          cont++;
        }
      }
      std::cout << "Se han insertado " << cont << " personas\n";
      break;

    case 2:
      if (!a.estaVacio()) {
        std::cout << "Introduce los datos del usuario a comprobar\n";
        std::cin >> p;
        if (a.buscar(p)) {
          std::cout << "La persona está en el arbol:\n" << p;
        } else {
          std::cout << "La persona que busca no se encuentra en el arbol\n";
        }
      } else {
        std::cout << "El arbol está vacio\n";
      }
      break;

    case 3:
      if (a.estaVacio()) {
        std::cout << "No se pueden mostrar ya que el arbol está vacio\n";
      } else {
        a.recorridoPreOrden(almacena); // se almacenan los datos
        std::cout << "Los datos pre orden son:\n";
        a.recorridoPreOrden(escribe);
      }
      break;

    case 4:
      if (a.estaVacio()) {
        std::cout << "No se pueden mostrar ya que el arbol está vacio\n";
      } else {
        a.recorridoPostOrden(almacena); // se almacenan los datos
        std::cout << "Los datos post orden son:\n";
        a.recorridoPostOrden(escribe);
      }
      break;

    case 5:
      if (a.estaVacio()) {
        std::cout << "No se pueden mostrar ya que el arbol está vacio\n";
      } else {
        a.recorridoInOrden(almacena); // se almacenan los datos
        std::cout << "Los datos in orden son:\n";
        a.recorridoInOrden(escribe);
      }
      break;

    case 6:
      if (!a.estaVacio()) {
        std::cout << "Introduce los datos del usuario a borrar\n";
        std::cin >> p;
        if (a.buscar(p)) {
          a.borrar();
          std::cout << "Se ha eliminado a la persona indicada\n";
        } else {
          std::cout << "No existe la persona que desea borrar\n";
        }
      } else {
        std::cout << "El arbol está vacio\n";
      }
      break;

    case 7:
      if (a.estaVacio() == false) {
        a.borrarArbol();
        std::cout << "Se ha eliminado el arbol completo\n";
      } else {
        std::cout << "El arbol ya está vacio\n";
      }
      break;

    default:
      std::cout << BIRED;
      std::cout << "Opción incorrecta ";
      std::cout << RESET;
      std::cout << "--> ";
      std::cout << ONIRED;
      std::cout << option << std::endl;
      std::cout << RESET;
    }

    if (option != 0) {
      std::cout << "Para mostrar el ";
      std::cout << BIGREEN;
      std::cout << "menú, ";
      std::cout << RESET;
      std::cout << "pulse ";
      std::cout << INVERSE;
      std::cout << "ENTER";
      std::cout << RESET;
      // Pausa
      std::cin.ignore();
      std::cout << CLEAR_SCREEN;
    }
  } while (option != 0);

  return 0;
}

int menu() {

  int opcion, posicion;
  // Se muestran las opciones del menú
  posicion = 2;

  // Se borra la pantalla
  std::cout << CLEAR_SCREEN;

  PLACE(posicion++, 10);
  std::cout << BIBLUE;
  std::cout << "Programa principal | Opciones del menú";
  std::cout << RESET;

  posicion++;

  PLACE(posicion++, 10);
  std::cout << "[1] Insertar Personas" << std::endl;

  PLACE(posicion++, 10);
  std::cout << "[2] Comprobar Persona" << std::endl;

  PLACE(posicion++, 10);
  std::cout << "[3] Mostrar Arbol Pre-Orden" << std::endl;

  PLACE(posicion++, 10);
  std::cout << "[4] Mostrar Arbol Post-Orden" << std::endl;

  PLACE(posicion++, 10);
  std::cout << "[5] Mostrar Arbol In-Orden" << std::endl;

  PLACE(posicion++, 10);
  std::cout << "[6] Borrar una Persona" << std::endl;

  PLACE(posicion++, 10);
  std::cout << "[7] Borrar todas las Personas" << std::endl;

  posicion++;
  PLACE(posicion++, 10);
  std::cout << BIRED;
  std::cout << "[0] Fin del programa " << std::endl;
  std::cout << RESET;

  posicion++;
  PLACE(posicion++, 10);
  std::cout << BIYELLOW;
  std::cout << "Opción: ";
  std::cout << RESET;
  std::cin >> opcion;

  // Se elimina el salto de línea del flujo de entrada
  std::cin.ignore();

  return opcion;
}

int generaRandom() {
  int valor = rand() % 100;
  return valor;
}