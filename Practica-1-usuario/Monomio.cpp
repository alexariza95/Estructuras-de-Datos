/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
	assert(std::abs(this->getGrado() - m.getGrado()) < COTA_ERROR);
	#endif //NDEBUG
	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	this->setGrado(0);
	this->setCoeficiente(x);

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR);
	assert(std::abs(this->getGrado() - 0) < COTA_ERROR);
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	//Se comprueba la precondicións
	#ifndef NDEBUG
	assert(this->getGrado() == m.getGrado());
	int lastGrado = this->getGrado();
	double coef = this->getCoeficiente();
	#endif //NDEBUG

	this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	#ifndef NDEBUG
	assert(this->getCoeficiente() == coef + m.getCoeficiente());
	assert(this->getGrado() == lastGrado);
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}



// COMPLETAR EL RESTO DE OPERADORES
ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	//Se comprueba la precondición
	#ifndef NDEBUG
	assert(this->getGrado() == m.getGrado());
	int lastGrado = this->getGrado();
	double coef = this->getCoeficiente();
	#endif //NDEBUG

	this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

	#ifndef NDEBUG
	assert(this->getCoeficiente() == coef - m.getCoeficiente());
	assert(this->getGrado() == lastGrado);
	#endif //NDEBUG

	//Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	double lastCoef = this->getCoeficiente();
	int lastGrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	this->setGrado(this->getGrado() + m.getGrado());

	#ifndef NDEBUG
	assert(this->getCoeficiente() == lastCoef * m.getCoeficiente());
	assert(this->getGrado() == lastGrado + m.getGrado());
	#endif //NDEBUG

	//Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	double lastCoef = this->getCoeficiente();
	int lastGrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
	this->setGrado(this->getGrado() - m.getGrado());

	#ifndef NDEBUG
	assert(this->getCoeficiente() == lastCoef / m.getCoeficiente());
	assert(this->getGrado() == lastGrado - m.getGrado());
	#endif //NDEBUG

	//Se devuelve el objeto actual
	return *this;
}



ed::Monomio & ed::Monomio::operator*=(double const &x)
{
	double lastCoef = this->getCoeficiente();
	int lastGrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() * x);

	#ifndef NDEBUG
	assert(this->getCoeficiente() == (lastCoef * x));
	assert(this->getGrado() == lastGrado);
	#endif //NDEBUG

	//Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator/=(double const &x)
{
	double lastCoef = this->getCoeficiente();
	int lastGrado = this->getGrado();

	#ifndef NDEBUG
	assert(x != 0.0);
	#endif //NDEBUG

	this->setCoeficiente(this->getCoeficiente() / x);
	#ifndef NDEBUG
	assert(this->getCoeficiente() == (lastCoef / x));
	assert(this->getGrado() == lastGrado);
	#endif //NDEBUG

	//Se devuelve el objeto actual
	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// HECHO EN .HPP


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double const &x)
{
	double valor , valor1;
	valor1 = std::pow(x, this->getGrado());
	valor = valor1 * this->getCoeficiente();
	//Devuelve el objeto 'valor'
	return valor;
}
