/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

/////////////////////////////////////////////////////////////


ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{


	 std::copy ( p.vector.begin(), p.vector.end(), std::back_inserter(this->vector) );


	 #ifndef NDEBUG
	 for( int i = 0; i<this->getNumeroMonomios(); i++ )
	 {
 	 	assert(this->vector[i] == p.vector[i]);
	 }
	 #endif
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	this->vector.clear();
	this->vector.push_back(m);
	#ifndef NDEBUG
	assert(this->vector.size() == 1 && this->vector[0] == m);
	#endif
	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	this->vector.clear();
	ed::Monomio m = x;
	this->vector.clear();
	this->vector.push_back(m);

	#ifndef NDEBUG
	assert(this->vector.size() == 1 && this->vector[0] == m);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////


ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	for( int i = 0; i < p.getNumeroMonomios(); i++)
	{
		this->vector.push_back(p.vector[i]);
	}
	this->ordenaPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES
ed::Polinomio & ed::Polinomio::operator+=(Monomio const &m)
{
	this->vector.push_back(m);
	this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{
	Monomio m;
	m = x;
	this->vector.push_back(m);
	//this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{
	for( int i = 0; i < p.getNumeroMonomios(); i++)
	{
		this->vector.push_back(-p.vector[i]);
	}
	this->ordenaPolinomio();
	// Se devuelve el objeto actual
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(Monomio const &m)
{
	this->vector.push_back(-m);
	this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{
	Monomio m;
	m = x;
	this->vector.push_back(-m);
	this->ordenaPolinomio();
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p)
{
	ed::Polinomio *nuevo = new ed::Polinomio();
	Monomio m;

	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		for(int j = 0; j < p.getNumeroMonomios(); j++)
		{
			m = this->vector[i] * p.vector[j];
			nuevo->vector.push_back(m);
		}
	}
	nuevo->ordenaPolinomio();
	*this = *nuevo;
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(Monomio const &m)
{
	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		this->vector[i] *= m;
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		this->vector[i] *= x;
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p)
{
	#ifndef NDEBUG
		assert( this->getGrado() >= p.getGrado() );
		assert( p.esNulo() == false );
	#endif

	ed::Polinomio *nuevo = new ed::Polinomio();
	Monomio m;

	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		for(int j = 0; j < p.getNumeroMonomios(); j++)
		{
			if(this->vector[i].getGrado() >= p.vector[j].getGrado())
			{
				m = this->vector[i] / p.vector[j];
				nuevo->vector.push_back(m);
			}
		}
	}
	nuevo->ordenaPolinomio();
	*this = *nuevo;
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(Monomio const &m)
{
	#ifndef NDEBUG
		assert( m.getGrado() <= this->getGrado() );
		assert( this->esNulo() == false );
	#endif

	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		if(this->vector[i].getGrado() >= m.getGrado())
		{
			this->vector[i] /= m;
		}
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &x)
{
	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		this->vector[i] /= x;
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio
void ed::Polinomio::leerPolinomio()
{

	int tam,valorG;
	double valorC;
	std::cout<<"Numero de Monomios del Polinomio:";
	std::cin>>tam;
	Monomio m;
	this->vector.clear();

	for(int i = 0; i < tam; i++)
	{
		std::cout<<"Monomio "<<i+1<<"\n";
		std::cout<<"Coeficiente: ";
		std::cin>>valorC;
		std::cout<<"Grado: ";
		std::cin>>valorG;
		for(int j = 0; j < tam; j++)
		{
			if( (this->vector[j].getGrado() == valorG) || (valorG < 0) )
			{
				std::cout<<"No puedes introducir dos monomios con el mismo grado en un mismo Polinomio ni un grado negativo, se ha asignado un valor de 0 al ultimo grado introducido\n";
				valorG = 0;
			}
		}
		m.setCoeficiente(valorC);
		m.setGrado(valorG);
		this->vector.push_back(m);
	}
	if(this->isOrdered() == false)
	{
		this->ordenaPolinomio();
	}
	std::cout<<"Se ha creado el Polinomio!\n";
}

void ed::Polinomio::escribirPolinomio()
{
	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		if(i != 0)
		{
			std::cout<<" + ";
		}
		this->vector[i].escribirMonomio();
	}
}

double ed::Polinomio::calcularValor(double const &x)
{
	double res = 0;
	for(int i = 0; i < this->getNumeroMonomios(); i++)
	{
		res += this->vector[i].calcularValor(x);
	}
	return res;
}
