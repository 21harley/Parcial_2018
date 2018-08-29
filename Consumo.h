#ifndef CONSUMO_H
#define CONSUMO_H

class Consumo
{
	char unidadMedida[10];
	float cantidad;
	public:
		Consumo();
		Consumo(float cantidad,char unidadMedida[]);
		char *getUnidadMedida();
		float getCantidad();
		virtual void mostrar();
		~Consumo();
	protected:
};

#endif
