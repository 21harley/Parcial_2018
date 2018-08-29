#ifndef HELIO_H
#define HELIO_H

#include "Consumo.h"

class Helio : public Consumo
{
	public:
		Helio();
		Helio(float c,char u[]);
		~Helio();
		void mostrar();
	protected:
};

#endif
