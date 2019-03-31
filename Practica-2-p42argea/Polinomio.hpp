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

   //! \name Funciones o métodos públicos de la clase Polinomio
   public:

	//! \name Constructores de la clase Polinomio

  inline Polinomio()
   {
     this->vector.clear();
     Monomio m;
     this->vector.push_back(m);
     #ifndef NDEBUG
       assert( this->esNulo() == true );
     #endif
}

inline Polinomio(const Polinomio &p)
{
  this->vector = p.vector;
  #ifndef NDEBUG
    for(int i = 0; i < this->getNumeroMonomios(); i++)
    {
      assert( (this->vector[i] == p.vector[i]) );
    }
  #endif
}
  //! \name Observadores: funciones de consulta de la clase Polinomio

	inline bool esNulo()const
  {
    bool aserto = false;

    if(this->vector.size() == 1 && this->vector[0].getGrado() == 0 && std::abs(this->vector[0].getCoeficiente() - 0.0) < COTA_ERROR )
    {
      aserto = true;
    }
    return aserto;
  }

  inline int getGrado()const
  {
    #ifndef NDEBUG
    assert(this->isOrdered() == true);
    #endif
    return this->vector[0].getGrado();
  }

  inline int getNumeroMonomios()const
  {
    return this->vector.size();
  }

  inline bool existeMonomio(int n) const
  {
    #ifndef NDEBUG
    assert(this->esNulo() == false);
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

  inline ed::Monomio & getMonomio(int n)const
  {
    ed::Monomio *m = new ed::Monomio();
    #ifndef NDEBUG
    assert(this->esNulo() == false);
    #endif

    for(int i=0; i<this->getNumeroMonomios(); i++)
    {
      if(this->vector[i].getGrado() == n)
      {
        (*m) = vector[i];
      }
    }
    return (*m);
  }

	//! \name Funciones de modificación de la clase Polinomio

  inline Monomio obtieneMonomio(int n) const
  {
    #ifndef NDEBUG
      assert( this->esNulo() == false );
    #endif

    return this->vector[n];
}



  inline void addMonomio(Monomio const &m)
  {
    this->vector.push_back(m);
    #ifndef NDEBUG
      assert( this->vector.back() == m );
    #endif
  }

  inline void remove(int n)
  {
    #ifndef NDEBUG
      assert( this->getNumeroMonomios() >= n );
    #endif
    int old = this->getNumeroMonomios();
    this->vector.erase(this->vector.begin()+n);
    #ifndef NDEBUG
      assert( this->getNumeroMonomios() == (old-1) );
    #endif
}

//Funcion que comprueba si el polinomio esta ordenado
inline bool isOrdered()const
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


//Funcion ordena y agrupa polinomio
inline void ordenaPolinomio()
{
  int pasos;
  Monomio temp;

  //Ordenar el polinomio
  for(int cont = this->getNumeroMonomios()/2; cont != 0; cont /= 2) {
    for(pasos = 1; pasos != 0;) {
      pasos = 0;
      for(int i = cont; i < this->getNumeroMonomios(); i ++) {
        if(this->vector[i - cont].getGrado() < this->vector[i].getGrado()) {
          temp = this->vector[i];
          this->vector[i] = this->vector[i - cont];
          this->vector[i - cont] = temp;
          pasos ++;
        }
      }
    }
  }

  //bucle que suma aquellos monomios con mismo grado
  for( int i = 0; i < this->getNumeroMonomios() -1; i++)
  {
    if(this->vector[i].getGrado() == this->vector[i+1].getGrado())
    {
      this->vector[i] += this->vector[i+1];
      this->vector.erase(this->vector.begin()+i+1);
    }
  }

  #ifndef NDEBUG
    assert(this->isOrdered() == true);
  #endif
} //ordenarPolinomio
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
    Polinomio & operator+=(Monomio const &m);
    Polinomio & operator+=(double const &x);

    Polinomio & operator-=(Polinomio const &p);
    Polinomio & operator-=(Monomio const &m);
    Polinomio & operator-=(double const &x);

    Polinomio & operator*=(Polinomio const &p);
    Polinomio & operator*=(Monomio const &m);
    Polinomio & operator*=(double const &x);

    Polinomio & operator/=(Polinomio const &p);
    Polinomio & operator/=(Monomio const &m);
  Polinomio & operator/=(double const &x);

	// COMPLETAR EL RESTO DE OPERADORES


  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio

  void leerPolinomio();
  void escribirPolinomio();

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio
  double calcularValor(double const &x);


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
