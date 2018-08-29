#include "Globo.h"
#include "Consumo.h"
#include<iostream>
#include<string.h>
using namespace std;

Globo::Globo()
{
	strcpy(codigo," ");
	strcpy(propietario," ");
	cantidadMediciones=2;
	consumos=new Consumo*[cantidadMediciones];
}

Globo::Globo(char codigo[],char propietario[],int cantidadMediciones,Consumo **consumos){
	strcpy(this->codigo,codigo);strcpy(this->propietario,propietario);
	this->cantidadMediciones=cantidadMediciones;
	this->consumos=consumos;
}

void Globo::mostrarDatos(){
	    int au;
     	cout<<"Codigo: "<<getCodigo()<<endl;
   	    cout<<"Propietario: "<<getPropietario()<<endl;
   	    cout<<"Cantidad de medidas"<<getMediciones()<<endl;
		au=getMediciones();
		 for(int j=0;j<au;j++){
   	  	    consumos[j]->mostrar();
	    }
}

Globo::~Globo()
{
	
}

char *Globo::getCodigo(){
	return codigo;
}

char *Globo::getPropietario(){
	return propietario;
}

int Globo::getMediciones(){
    return cantidadMediciones;
}

Consumo **Globo::getConsumo(){
	return consumos;
}

Consumo *Globo::getConsumo(int i){
	return consumos[i];
}
