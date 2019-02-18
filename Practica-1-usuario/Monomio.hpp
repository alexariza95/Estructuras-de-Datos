/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	private:

		double coeficiente; //!< coeficiente del monomio
		int grado; //!< grado del monomio

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

	//! \name Constructores de la clase Monomio

	inline Monomio(double coeficiente = 0.0, int grado = 0)
	{
		// Se comprueba la precondición
		#ifndef NDEBUG
			assert(grado>=0);
		#endif // NDEBUG

		this->setCoeficiente(coeficiente);
		this->setGrado(grado);

		// Se compruebam las postcondiciones

		#ifndef NDEBUG
			assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
			assert(this->getGrado() == grado);
		#endif // NDEBUG
	}


	inline Monomio(const Monomio &m)
	{
		this->setCoeficiente(m.getCoeficiente());
		this->setGrado(m.getGrado());

		#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
		assert(m.getGrado() == this->getGrado());
		#endif // NDEBUG
	}


	//! \name Observadores: funciones de consulta de la clase Monomio

	inline double getCoeficiente() const
	{
		return this->coeficiente;
	}

	inline int getGrado() const
	{
		return this->grado;
	}



	//! \name Funciones de modificación de la clase Monomio

	inline void setCoeficiente(double x)
	{
		this->coeficiente = x;

		#ifndef NDEBUG
		assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR);
		#endif // NDEBUG
	}

	inline void setGrado(int n)
	{
		this->grado = n;

		#ifndef NDEBUG
		assert(this->getGrado() == n);
		#endif //NDEBUG
	}


	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		//! \name Operador = con otro Monomio
		Monomio & operator=(Monomio const &m);

		//! Operador = con numero real
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

		//! \name Operador += Monomio
		Monomio & operator+=(Monomio const &m);


		//! \name Operador -= Monomio
		Monomio & operator-=(Monomio const &m);
		//! \name Operador *= Monomio
		Monomio & operator*=(Monomio const &m);
		//! \name Operador /= Monomio
		Monomio & operator/=(Monomio const &m);
		//! \name Operador *= Real
		Monomio & operator*=(double const &x);
		//! \name Operador /= Real
		Monomio & operator/=(double const &x);



	/////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Monomio

		inline void leerMonomio()
		{
			int grado;
			double coeficiente;

			std::cout<<"Introduzca el grado del monomio"<<"\n";
			std::cin>>grado;

			std::cout<<"Introduzca el coeficiente del monomio"<<"\n";
			std::cin>>coeficiente;

			this->setGrado(grado);
			this->setCoeficiente(coeficiente);

			#ifndef NDEBUG
			assert(this->getGrado() >= 0);
			#endif //NDEBUG
		}

		void escribirMonomio()
		{
			if(this->getCoeficiente() == 1)
			{
				std::cout<<"coeficiente "<<this->getCoeficiente()<<"^"<<this->getGrado()<<"\n";
			}
			if(this->getCoeficiente() == -1)
			{
				std::cout<<"coeficiente -"<<this->getCoeficiente()<<"^"<<this->getGrado()<<"\n";
			}
		}


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Monomio

	// COMPLETAR



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
