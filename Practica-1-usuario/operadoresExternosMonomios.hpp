/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_
#define COTA_ERROR 1.0e-6

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad

	//! \name operador igual con dos monomios
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);
	//! \name operador igual comparando monomio con real m==r
	bool operator==(ed::Monomio const &m, double const x);
	//! \name operador igual comparando monomio con real r==m
	bool operator==(double const &x, ed::Monomio const &m);


	//! \name Operadores de desigualdad

	/*!
	\fn					bool operator!=(ed::Monomio const &m1, ed::Monomio const &m2)
	\brief     Operador que comprueba que dos monomios sean distintos
	\attention se comparan dos monomios
	\pre
	\post      Que los monomios sean distintos
*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);
	/*!
	\fn					bool operator!=(double const &x, ed::Monomio const &m)
	\brief     Operador que comprueba que un monomio sea distinto de un numero real
	\attention se compara un monomio con un numero real
	\pre
	\post      El coeficiente del monomio es distinto de x y su grado es 0
*/
	bool operator!=(double const &x, ed::Monomio const &m);
	/*!
	\fn					bool operator!=(ed::Monomio const &m, double const &x)
	\brief     Operador que comprueba que un monomio sea distinto de un numero real
	\attention se compara un monomio con un numero real
	\pre
	\post      El coeficiente del monomio es distinto de x y su grado es 0
*/
	bool operator!=(ed::Monomio const & m, double const &x);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/*!
	\fn				  Monomio & operator+(ed::Monomio const & m)
	\brief     Operador que crea una copia del monomio enviado por parámetros
	\attention Devuelve una copia del Monomio “m”: +m
	\pre
	\post      El monomio devuelto es igual al monomio “m”, es decir, tiene el mismo grado y el mismo coeficiente.
*/
	ed::Monomio & operator+(ed::Monomio const & m);
	/*!
	\fn				  Monomio & operator-(ed::Monomio const & m)
	\brief     Operador que crea una copia del monomio enviado por parámetros pero con coeficiente negativo
	\attention Devuelve una copia del Monomio “m”: -m
	\pre
	\post      El monomio devuelto es igual al monomio “m”, es decir, tiene el mismo grado y coeficiente negativo
*/
	ed::Monomio & operator-(ed::Monomio const &m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	/*!
	\fn				 Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	\brief     Operador que crea la suma de dos monomios
	\attention Devuelve otro monomio que es la suma de dos monomios: m1 + m2
	\pre			 Los monomios m1 y m2 tienen el mismo grado.
	\post     El monomio devuelto tiene el mismo grado que los monomios m1 y m2 y su coeficiente es la suma de los coeficientes de los monomios.
*/
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);

	 ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);
	 
	 ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación

	// COMPLETAR

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	// COMPLETAR


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
