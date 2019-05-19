#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

namespace ed
{

template <class G_Nodo, class G_Lado>
class Grafo
{
private:
	std::vector<G_Nodo> _nodos;
	std::vector< std::vector<G_Lado> > _lados;

public:
	// constructores
	Grafo()
	{
		this->_lados = NULL;
		this->_nodos = NULL;
	}

	Grafo(int n)
	{
		this->_nodos = new int[n];
	}

	Grafo(const ed::Grafo<G_Nodo, G_Lado> &g)
	{
		this->_lados = g._lados;
		this->_nodos = g._nodos;
	}

	// destructor
	~Grafo() {}

	//Getters & Setters
	G_Nodo getNodos()
	{
		return this->_nodos;
	}

	G_Lado getLados()
	{
		return this->_lados;
	}

	void setNodo(G_Nodo n)
	{
		this->_nodos = n;
	}

	void setLado(G_Lado l)
	{
		this->_lados = l;
	}

	// funciones
	void borrarGrafo()
	{
		this->_nodos.clear();
		this->_lados.clear();
	}

	const Grafo &operator=(const ed::Grafo<G_Nodo, G_Lado> &g)
	{
		if (this == g)
			return *new Grafo();

		this->_nodos = g._nodos;
		this->_lados = g._lados;

		return *this;
	}
};
} // namespace ed

#endif
