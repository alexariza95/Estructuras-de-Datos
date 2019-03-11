/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_
#define COTA_ERROR 1.0e-6 // Cota de error para los numeros reales
// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "operadoresExternosMonomios.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:
     std::vector<ed::Monomio> vector;

     //funcion que comprueba que el polinomio esta ordenado
     inline bool isOrdered()
     {
     	bool aserto = true;
     	for(int i = 0; i < this->getNumeroMonomios() - 1; i++)
     	{
     		if(this->vector[i].getGrado() < this->vector[i + 1].getGrado())
        {
          aserto = false;
        }
     	}
      return aserto;
     }
   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

  inline Polinomio()
  {
    ed::Monomio *nuevo = new ed::Monomio();

    this->vector.push_back(*nuevo);
    #ifndef NDEBUG
    assert(this->esNulo() == true);
    #endif
  }


  inline Polinomio(const Polinomio &p)
    {
      this->vector = p.vector;
      #ifndef NDEBUG
        for(int i = 0; i<this->getNumeroMonomios(); i++)
        {
          assert(this->vector[i] == p.vector[i]);
        }
      #endif
    }
  //! \name Observadores: funciones de consulta de la clase Polinomio

	inline bool esNulo()
  {
    bool aserto = false;

    if(this->vector.size() == 1 && this->vector[0].getGrado() == 0 && std::abs(this->vector[0].getCoeficiente() - 0.0) < COTA_ERROR )
    {
      aserto = true;
    }
    return aserto;
  }

  inline int getGrado()
  {
    #ifndef NDEBUG
    assert(this->isOrdered() == true);
    #endif
    return this->vector[0].getGrado();
  }

  inline int getNumeroMonomios()
  {
    return this->vector.size();
  }

  inline bool existeMonomio(int n)
  {
    #ifndef NDEBUG
    assert(this->esNulo() == true);
    #endif

    bool aserto = false;
    for(int i=0; i<this->getNumeroMonomios(); i++)
    {
      if(this->getMonomio(n) == vector[i])
      {
        aserto = true;
      }
    }
    return aserto;
  }

  inline ed::Monomio getMonomio(int n)
  {
    #ifndef NDEBUG
    assert(this->esNulo() == true);
    #endif

    for(int i=0; i<this->getNumeroMonomios(); i++)
    {
      if(this->vector[i].getGrado() == n)
      {
        return vector[i];
      }
    }
    return 0;
  }

	//! \name Funciones de modificación de la clase Polinomio

	// COMPLETAR


 	////////////////////////////////////////////////////////////////

   //! \name Operadores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);

  // Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);


	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio



}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
