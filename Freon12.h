#ifndef FREON12_H
#define FREON12_H

#include "Consumo.h"

class Freon12 : public Consumo
{
	public:
		Freon12();
		Freon12(float c,char u[]);
		void mostrar();
		~Freon12();
	protected:
};

#endif
