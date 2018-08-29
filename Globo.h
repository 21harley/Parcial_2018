#ifndef GLOBO_H
#define GLOBO_H
#include "Consumo.h"

class Globo
{
	char codigo[10];
	char propietario[25];
	int cantidadMediciones;
	Consumo **consumos;
	public:
		Globo();
		Globo(char codigo[],char propietario[],int cantidadMediciones,Consumo **consumos);
		~Globo();
		void mostrarDatos();
		char *getCodigo();
		char *getPropietario();
		int getMediciones();
		Consumo **getConsumo();
		Consumo *getConsumo(int i);
	protected:
};

#endif
