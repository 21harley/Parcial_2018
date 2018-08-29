#include "Helio.h"
#include<iostream>
#include<string.h>
using namespace std;

Helio::Helio():Consumo()
{
	
}

Helio::Helio(float c,char u[]):Consumo(c,u){

}

Helio::~Helio()
{
	
}

void Helio::mostrar(){
	Consumo::mostrar();
}
