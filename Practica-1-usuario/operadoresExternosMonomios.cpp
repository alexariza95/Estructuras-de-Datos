/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad


	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool aserto = false;
		if(m1.getCoeficiente() == m2.getCoeficiente() && m1.getGrado() == m2.getGrado())
		{
			aserto = true;
		}
		else{
			aserto = false;
		}
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aserto;
	}

	bool operator==(ed::Monomio const &m, double const &x)
	{
		bool aserto = false;
		if(m.getCoeficiente() == x && m.getGrado() == 0)
		{
			aserto = true;
		}
		else
		{
			aserto = false;
		}
		return aserto;
	}

	bool operator==(double const &x, ed::Monomio const &m)
	{
		bool aserto = false;
		if(x == m.getCoeficiente() && m.getGrado() == 0)
		{
			aserto = true;
		}
		else
		{
			aserto = false;
		}
		return aserto;
	}

	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool aserto = false;
		if(m1.getCoeficiente() != m2.getCoeficiente() && m1.getGrado() != m2.getGrado())
		{
			aserto = true;
		}
		else
		{
			aserto = false;
		}
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aserto;
	}

	bool operator!=(double const &x, ed::Monomio const &m)
	{
		bool aserto = false;
		if(m.getCoeficiente() != x && m.getGrado() != 0)
		{
			aserto = true;
		}
		else{
			aserto = false;
		}
		return aserto;
	}

	bool operator!=(ed::Monomio const &m, double const &x)
	{
		bool aserto = false;
		if(x != m.getCoeficiente() && m.getGrado() != 0)
		{
			aserto = true;
		}
		else
		{
			aserto = false;
		}
		return aserto;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
		assert(m.getCoeficiente() == nuevo->getCoeficiente() && m.getGrado() == nuevo->getGrado());
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const &m)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-m.getCoeficiente());
		#ifndef NDEBUG
		assert(m.getCoeficiente() == -(nuevo->getCoeficiente()) && m.getGrado() == nuevo->getGrado());
		#endif //NDEBUG

		return *nuevo;
	}

	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		int grade;
		#ifndef NDEBUG
		assert(m1.getGrado() == m2.getGrado());
		#endif //NDEBUG
		grade = m1.getGrado();

		double coef;
		coef = m1.getCoeficiente() + m2.getCoeficiente();

		nuevo->setGrado(grade);
		nuevo->setCoeficiente(coef);

		#ifndef NDEBUG
		assert(nuevo->getGrado() == m1.getGrado() && nuevo->getGrado() == m2.getGrado() && nuevo->getCoeficiente() == coef);
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

//Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		int grade;
		#ifndef NDEBUG
		assert(m1.getGrado() == m2.getGrado());
		#endif //NDEBUG
		grade = m1.getGrado();

		double coef;
		coef = m1.getCoeficiente() - m2.getCoeficiente();

		nuevo->setGrado(grade);
		nuevo->setCoeficiente(coef);

		#ifndef NDEBUG
		assert(nuevo->getGrado() == m1.getGrado() && nuevo->getGrado() == m2.getGrado() && nuevo->getCoeficiente() == coef);
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		int grade;
		grade = m1.getGrado() + m2.getGrado();

		double coef;
		coef = m1.getCoeficiente() * m2.getCoeficiente();

		nuevo->setGrado(grade);
		nuevo->setCoeficiente(coef);

		#ifndef NDEBUG
		assert(nuevo->getGrado() == m1.getGrado()+m2.getGrado() && nuevo->getCoeficiente() == coef);
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double const &x)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		int grade;
		grade = m.getGrado():

		double coef;
		coef = m.getCoeficiente() * x;

		nuevo->setGrado(grade);
		nuevo->setCoeficiente(coef);

		#ifndef NDEBUG
		assert(nuevo->getGrado() == m.getGrado() && nuevo->getCoeficiente() == coef);
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División

	// COMPLETAR


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m)
	{
		// COMPLETAR

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		// COMPLETAR

		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
