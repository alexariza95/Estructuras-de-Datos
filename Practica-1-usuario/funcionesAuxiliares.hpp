/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author Alejandro Ariza
  \date  25-02-19
*/


#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Monomio.hpp"

namespace ed
{
	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*!
			\brief Se comprueban todos metodos relacionados directamente con un monomio.
			\param Ninguno
			\pre Ninguna
			\post Ninguna
		*/
	void testMonomio();


	/*!
		\brief Se comprueban los metodos y/o operadores EXTERNOS a la clase Monomio
		\param Ninguno
		\pre Ninguna
		\post Ninguna
	*/
	void operadoresExternosMonomios();

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
