/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"
#define COTA_ERROR 1.0e-6
// Operadores de asignación


ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
	assert(this->getGrado() == m.getGrado());
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
	assert(this->getGrado() == 0);
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación


ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	//Se comprueba la precondición
	#ifndef NDEBUG
	assert(this->getGrado() == m.getGrado());
	int lastGrado = this->getGrado();
	double coef = this->getCoeficiente();
	#endif //NDEBUG

	this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	#ifndef NDEBUG
	assert(std::abs(this->getCoeficiente() - (coef + m.getCoeficiente())) < COTA_ERROR );
	assert(this->getGrado() == lastGrado);
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}



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
	assert(std::abs(this->getCoeficiente() - (coef - m.getCoeficiente())) < COTA_ERROR);
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
	assert(std::abs(this->getCoeficiente() - (lastCoef * m.getCoeficiente())) < COTA_ERROR);
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
	assert(std::abs(this->getCoeficiente() - (lastCoef / m.getCoeficiente())) < COTA_ERROR);
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
	assert(std::abs(this->getCoeficiente() - (lastCoef * x)) < COTA_ERROR);
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
	assert(std::abs(this->getCoeficiente() - (lastCoef / x)) < COTA_ERROR);
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

ed::Monomio & ed::Monomio::operator^=(int pot)
{
	#ifndef NDEBUG
		assert( pot >= 0 );
	#endif

	int valorG = this->getGrado();
	double valorC = this->getCoeficiente();

	this->setGrado(valorG*pot);
	this->setCoeficiente(std::pow(valorC,pot));

	#ifndef NDEBUG
		assert( this->getGrado() == (valorG * pot) );
		assert( std::abs(this->getCoeficiente() - std::pow(valorC,pot)) < COTA_ERROR );
	#endif

	return *this;
}

double ed::Monomio::calcularValor(double const &x)
{
	double valor , valor1;
	valor1 = std::pow(x, this->getGrado());
	valor = valor1 * this->getCoeficiente();
	//Devuelve el objeto 'valor'
	return valor;
}
