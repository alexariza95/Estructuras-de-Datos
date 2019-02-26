/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>
#include <cassert>
#include "operadoresExternosMonomios.hpp"

//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad


	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool aserto = false;
		if((m1.getGrado() == m2.getGrado()) && (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR))
		{
			aserto = true;
		}
		#ifndef NDEBUG
			assert( aserto == ((m1.getGrado() == m2.getGrado()) && (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR) && (aserto == true)));
		#endif
		return aserto;
	}

	bool operator==(ed::Monomio const &m, double const &x)
	{
		bool aserto = false;
		if(m.getGrado() == 0 && std::abs(m.getCoeficiente() - x) < COTA_ERROR)
		{
			aserto = true;
		}
		#ifndef NDEBUG
			assert( aserto == ((m.getGrado() == 0) && (std::abs(m.getCoeficiente() - x) < COTA_ERROR) && (aserto == true)) );
		#endif

		return aserto;
	}

	bool operator==(double const &x, ed::Monomio const &m)
	{
		bool aserto = false;
		if(m.getGrado() == 0 && (std::abs(m.getCoeficiente() - x) < COTA_ERROR))
		{
			aserto = true;
		}
		#ifndef NDEBUG
					assert( aserto == ((m.getGrado() == 0) && (std::abs(m.getCoeficiente() - x) < COTA_ERROR) && (aserto == true)) );
		#endif
		return aserto;
	}

	// Operadores de desigualdad

	// COMPLETAR
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		bool aserto = false;
		if((m1.getGrado() != m2.getGrado()) || (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR))
		{
			aserto = true;
		}
		#ifndef NDEBUG
					assert( aserto == ((m1.getGrado() != m2.getGrado()) || (std::abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR) || (aserto == true)) );
		#endif
		// MODIFICAR: SE DEVUELVE UN VALOR ARBITRARIO PARA NO GENERAR AVISOS AL COMPILAR
		return aserto;
	}

	bool operator!=(double const &x, ed::Monomio const &m)
	{
		bool aserto = false;
		if((m.getGrado() != 0) || (std::abs(m.getCoeficiente() - x) > COTA_ERROR))
		{
			aserto = true;
		}
		#ifndef NDEBUG
					assert( aserto == ((m.getGrado() != 0) || (std::abs(m.getCoeficiente() - x) > COTA_ERROR) || (aserto == true)) );
		#endif
		return aserto;
	}

	bool operator!=(ed::Monomio const &m, double const &x)
	{
		bool aserto = false;
		if((m.getGrado() != 0) || (std::abs(m.getCoeficiente() - x) > COTA_ERROR))
		{
			aserto = true;
		}
		#ifndef NDEBUG
					assert( aserto == ((m.getGrado() != 0) || (std::abs(m.getCoeficiente() - x) > COTA_ERROR) || (aserto == true)) );
		#endif
		return aserto;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		#ifndef NDEBUG
		assert(std::abs(nuevo->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR && m.getGrado() == nuevo->getGrado());
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const &m)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(-m.getCoeficiente());
		#ifndef NDEBUG
		assert(std::abs(m.getCoeficiente() + nuevo->getCoeficiente()) < COTA_ERROR  && m.getGrado() == nuevo->getGrado());
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
		assert(nuevo->getGrado() == m1.getGrado() && nuevo->getGrado() == m2.getGrado());
		assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() + m2.getCoeficiente())) < COTA_ERROR);
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
		assert(nuevo->getGrado() == m1.getGrado() && nuevo->getGrado() == m2.getGrado());
		assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() - m2.getCoeficiente())) < COTA_ERROR);
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
		assert(nuevo->getGrado() == m1.getGrado()+m2.getGrado());
		assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * m2.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double const &x)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();
		int grade;
		grade = m.getGrado();

		double coef;
		coef = m.getCoeficiente() * x;

		nuevo->setGrado(grade);
		nuevo->setCoeficiente(coef);

		#ifndef NDEBUG
		assert(nuevo->getGrado() == m.getGrado());
		assert(std::abs(nuevo->getCoeficiente() - (m.getCoeficiente() * x)) < COTA_ERROR );
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (double const &x ,ed::Monomio const &m)
	{
		ed::Monomio *nuevo = new ed::Monomio();
		int grade;
		grade = m.getGrado();

		double coef;
		coef = m.getCoeficiente() * x;

		nuevo->setGrado(grade);
		nuevo->setCoeficiente(coef);

		#ifndef NDEBUG
		assert(nuevo->getGrado() == m.getGrado());
		assert(std::abs(nuevo->getCoeficiente() - (x * m.getCoeficiente())) < COTA_ERROR );
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División
		ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
		{
			ed::Monomio *nuevo = new ed::Monomio();
			#ifndef NDEBUG
			assert(m1.getGrado() >= m2.getGrado() && m2.getCoeficiente() != 0.0);
			#endif //NDEBUG
			int grade;
			grade = m1.getGrado() - m2.getGrado();

			double coef;
			coef = m1.getCoeficiente() / m2.getCoeficiente();

			nuevo->setGrado(grade);
			nuevo->setCoeficiente(coef);

			#ifndef NDEBUG
			assert(nuevo->getGrado() == m1.getGrado()-m2.getGrado());
			assert(std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / m2.getCoeficiente())) < COTA_ERROR);
			#endif //NDEBUG

			// Se devuelve el resultado
			return *nuevo;
		}

		ed::Monomio & operator/ (ed::Monomio const &m, double const &x)
		{
			// Se crea un nuevo objeto monomio
			ed::Monomio *nuevo = new ed::Monomio();
			#ifndef NDEBUG
			assert(x != 0.0);
			#endif //NDEBUG
			int grade;
			grade = m.getGrado();

			double coef;
			coef = m.getCoeficiente() / x;

			nuevo->setGrado(grade);
			nuevo->setCoeficiente(coef);

			#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado());
			assert(std::abs(nuevo->getCoeficiente() - (m.getCoeficiente()/x)) < COTA_ERROR);
			#endif //NDEBUG

			// Se devuelve el resultado
			return *nuevo;
		}

		ed::Monomio & operator/ (double const &x, ed::Monomio const &m)
		{
			ed::Monomio *nuevo = new ed::Monomio();
			#ifndef NDEBUG
			assert(m.getGrado() == 0 && m.getCoeficiente() != 0.0);
			#endif //NDEBUG
			int grade;
			grade = m.getGrado();

			double coef;
			coef = x / m.getCoeficiente();

			nuevo->setGrado(grade);
			nuevo->setCoeficiente(coef);

			#ifndef NDEBUG
			assert(nuevo->getGrado() == 0 && std::abs(nuevo->getCoeficiente() - (x / m.getCoeficiente())) < COTA_ERROR);
			#endif //NDEBUG

			// Se devuelve el resultado
			return *nuevo;
		}
	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
  istream &operator>>(istream &stream, ed::Monomio &m)
	{
		double x;
		int grado;
		stream >> x;
		stream >> grado;
		if( grado < 0 )
		{
			std::cout<<"Se debe introducir un grado mayor o igual a 0\n";
			exit (-1);
		}
		m.setCoeficiente(x);
		m.setGrado(grado);
   	// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m)
	{
		stream << m.getCoeficiente() << " " << m.getGrado();
		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
