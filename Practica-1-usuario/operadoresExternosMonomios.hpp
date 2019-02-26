/*!
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
	\author Alejandro Ariza
	\date  25-02-19
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

	/*!
	\fn					bool operator==(ed::Monomio const &m1, ed::Monomio const &m2)
	\brief     Operador que comprueba que dos monomios sean iguales
	\attention Devuelve 'true' si 'm1' es igual que 'm2'
	\pre
	\post      Los monomios tienen que ser iguales, su grado y coeficiente
*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);
	/*!
	\fn					bool operator==(double const &x, ed::Monomio const &m)
	\brief     Operador que comprueba que un monomio sea igual que un numero real
	\attention Devuelve 'true' si el coeficiente de 'm' es igual que 'x'
	\pre
	\post      El coeficiente del monomio es igual que x y su grado es 0
*/
	bool operator==(double const &x, ed::Monomio const &m);
	/*!
	\fn					bool operator==(ed::Monomio const &m, double const &x)
	\brief     Operador que comprueba que un monomio sea igual que un numero real
	\attention Devuelve 'true' si 'x' es igual que el coeficiente de 'm'
	\pre
	\post      El coeficiente del monomio es igual que x y su grado es 0
*/
	bool operator==(ed::Monomio const &m, double const x);



	//! \name Operadores de desigualdad

	/*!
	\fn					bool operator!=(ed::Monomio const &m1, ed::Monomio const &m2)
	\brief     Operador que comprueba que dos monomios sean distintos
	\attention Devuelve 'true' si 'm1' es distinto de 'm2'
	\pre
	\post      Los monomios tienen que ser distintos
*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);
	/*!
	\fn					bool operator!=(double const &x, ed::Monomio const &m)
	\brief     Operador que comprueba que un monomio sea distinto de un numero real
	\attention Devuelve 'true' si el coeficiente de 'm' es distinto de 'x'
 	\pre
	\post      El coeficiente del monomio es distinto de x y su grado es 0
*/
	bool operator!=(double const &x, ed::Monomio const &m);
	/*!
	\fn					bool operator!=(ed::Monomio const &m, double const &x)
	\brief     Operador que comprueba que un monomio sea distinto de un numero real
	\attention Devuelve 'true' si 'x' es distinto del coeficiente de 'm'
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
	//! \name Operador binario de la resta
	/*!
	\fn				 Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	\brief     Operador que crea la resta de dos monomios
	\attention Devuelve otro monomio que es la resta de dos monomios: m1 - m2
	\pre			 Los monomios m1 y m2 tienen el mismo grado.
	\post     El monomio devuelto tiene el mismo grado que los monomios m1 y m2 y su coeficiente es la resta de los coeficientes de los monomios.
*/
	 ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);
	 /////////////////////////////////////////////////////////////////////////////////////
	 	//! \name Operadores binarios de la multiplicación
		/*!
		\fn				 Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
		\brief     Operador que crea la multiplicación de dos monomios
		\attention Devuelve otro monomio que es el producto de dos monomios: m1 * m2
		\pre
		\post     El monomio devuelto tiene el grado suma de los monomios m1 y m2 y su coeficiente es el producto de los coeficientes de los monomios.
	*/
	 ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);
	 /*!
	 \fn				 Monomio & operator* (ed::Monomio const &m, double const &x)
	 \brief     Operador que crea la multiplicación de un monomio por un numero real
	 \attention Devuelve otro monomio que es el producto de un real por un monomio: m * x
	 \pre
	 \post     El monomio devuelto tiene el mismo grado que el monomio m1 y su coeficiente es el producto del coeficiente del monomio 'm' por el numero 'x'.
 */
	 ed::Monomio & operator* (ed::Monomio const &m, double const &x);
	 /*!
	 \fn				 Monomio & operator* (double const &x, ed::Monomio const &m)
	 \brief     Operador que crea la multiplicación de un monomio por un numero real
	 \attention Devuelve otro monomio que es el producto de un real por un monomio: x * m
	 \pre
	 \post     El monomio devuelto tiene el mismo grado que el monomio m1 y su coeficiente es el producto del coeficiente del monomio 'm' por el numero 'x'.
 */
 	 ed::Monomio & operator* (double const &x ,ed::Monomio const &m);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división
	/*!
	\fn				 Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	\brief     Operador que crea la division de dos monomios
	\attention Devuelve otro monomio que es la división de dos monomios: m1 / m2
	\pre
	\post     El monomio devuelto tiene el grado resta de los monomios m1 y m2 y su coeficiente es la division de los coeficientes de los monomios.
*/
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);
	/*!
	\fn				 Monomio & operator/ (ed::Monomio const &m, double cons &x)
	\brief     Operador que crea la division de un monomio por un real
	\attention Devuelve otro monomio que es la division de un monomio por un numero real: m / x
	\pre
	\post     El monomio devuelto tiene el mismo grado que el monomio m y su coeficiente es la division del coeficiente del monomio 'm' y el numero 'x'.
*/
	ed::Monomio & operator/ (ed::Monomio const &m, double const &x);
	/*!
	\fn				 Monomio & operator/ (double cons &x, ed::Monomio const &m)
	\brief     Operador que crea la division de un real por un monomio
	\attention Devuelve otro monomio que es la division de un numero real por un monomio: x / m
	\pre
	\post     El monomio devuelto tiene el mismo grado que el monomio m y su coeficiente es la division del numero 'x' y el coeficiente del monomio 'm'.
*/
	ed::Monomio & operator/ (double const &x, ed::Monomio const &m);



	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	/*!
	\fn				 istream &operator>> (istream &stream, ed::Monomio &m)
	\brief     Lee desde el flujo de entrada los atributos de un monomio separados por espacios
	\attention Devuelve
	\pre
	\post
*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
