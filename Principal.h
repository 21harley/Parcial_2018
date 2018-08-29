#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Globo.h"

class Principal
{
	int cantidadG;
	Globo **vGlobos;
	public:
		Principal();
		~Principal();
		void cargarDatos();
		void mostrarDatos();
	protected:
};

#endif
