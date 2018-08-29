#include "Consumo.h"
#include<iostream>
#include<string.h>
using namespace std;
Consumo::Consumo()
{
	strcpy(unidadMedida," ");cantidad=0;
}

Consumo::Consumo(float cantidad,char unidadMedida[]){
	this->cantidad=cantidad;strcpy(this->unidadMedida,unidadMedida);
}

Consumo::~Consumo()
{
	
}

void Consumo::mostrar(){
	
	if(cantidad==0){
		cout<<"Unidad de Medida: no hay gasto"<<endl;
	}else{
		cout<<"Unidad de Medida: "<<unidadMedida<<endl;
	}
    cout<<"Cantidad: "<<cantidad<<endl;
}

float Consumo::getCantidad(){
	return cantidad;
}

char *Consumo::getUnidadMedida(){
	return unidadMedida;
}
