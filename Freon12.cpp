#include "Freon12.h"
#include<iostream>
#include<string.h>
using namespace std;
Freon12::Freon12():Consumo()
{
	
}

Freon12::Freon12(float c,char u[]):Consumo(c,u){
	
}

Freon12::~Freon12()
{
}

void Freon12::mostrar(){
	Consumo::mostrar();
}
