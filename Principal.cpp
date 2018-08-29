#include "Principal.h"
#include "Globo.h"
#include "Consumo.h"
#include "Helio.h"
#include "Freon12.h"
#include "Data.h"
#include<iostream>
#include<string.h>
#include<typeinfo>
#include<stdlib.h>
using namespace std;

Principal::Principal()
{
	cantidadG=0;
	 vGlobos=NULL;
}

void Principal::cargarDatos(){
	Data aux;
	char cadena[30],*auxC,codigo[20],propietario[20],codigo1[20],tipo[10];
	int togl=0,to=0,cad1,cad2,cot=0,medic=0,altura=0,c=0,x=0;
	unsigned long int cod;
	Consumo **consu;togl=aux.getLongitud();cantidadG=togl;
	  vGlobos=new Globo*[togl];
	 
for(int i=0;i<togl;i++){
	
	strcpy(cadena,aux.getDatosGlobo(i));
	
	auxC=strtok(cadena,"-");strcpy(codigo,auxC);
	
	auxC=strtok(NULL,"-");strcpy(propietario,auxC);strcpy(cadena," ");
	
    while(cad1!=cad2){
    	strcpy(cadena,aux.getDatosAltimetro(cot));cot++;
    	
    	auxC=strtok(cadena," / ");strcpy(codigo1,auxC);
    	
    	cad1=atoi(codigo1);cad2=atoi(codigo);
    	
    	if(cad1==cad2){
    		
    		auxC=strtok(NULL," / ");strcpy(tipo,auxC);medic=atoi(tipo);
			
			auxC=strtok(NULL," / ");cod=atoi(auxC);
			
            consu=new Consumo*[medic];
			for(int j=0;j<medic;j++){
				if(j==0){
					altura=cod&15;
				}else{
					c+=4;
					altura=(cod>>c)&15;
				}
				altura*=100;
				if(altura>1196.56&&to==0){
					consu[j]=new Freon12(0.350,"K");to++;
				}
				if(740.41>altura&&to==0){
					consu[j]=new Helio(0.500,"L");to++;
				}
				if(1196.56>altura&&altura>740.41&&to==0){
					consu[j]=new Consumo(0," n ");to++;
				}
				to=0;altura=0;
			}
	       vGlobos[i]=new Globo(codigo,propietario,medic,consu);c=0;cod=0;
		}
	}cot=0;cad1=0;cad2=1;
}	
	
}

void Principal::mostrarDatos(){
	int mando,auM,auC,a,rebaso;Consumo **aux;float tH=0,tF=0,F,rS=0;
 do{
 	system("cls");
 	cout<<"                                                Vuelos Airus    "<<endl;
 	cout<<"1. Cantidad de kilogramos de Freon12 y cantidad de litros de Helio, consumidos durante el vuelo de cada globo."<<endl;
 	cout<<"2. Por cada globo, indicar numero de veces que la altura se mantuvo en el rango de seguridad."<<endl;
 	cout<<"3. Que cantidad se debe llevar para la proxima jornada?"<<endl;
 	cout<<"4. Salida de datos final"<<endl;
 	cout<<"5. Salir"<<endl;
 	cin.sync();cin>>mando;
    switch(mando){
    	case 1:
    		system("cls");
    		for(int i=0;i<cantidadG;i++){
    			auC=vGlobos[i]->getMediciones();
    			aux=vGlobos[i]->getConsumo();
    			 for(int j=0;j<auC;j++){
    			 	if(typeid(*aux[j])==typeid(Helio)){
    			 		tH+=aux[j]->getCantidad();
					 }
					 if(typeid(*aux[j])==typeid(Freon12)){
					 	tF+=aux[j]->getCantidad();
					 }
				 }
				cout<<"Codigo:"<<vGlobos[i]->getCodigo()<<endl;
				cout<<"Propietario:"<<vGlobos[i]->getPropietario()<<endl;
				cout<<"Nro de Mediciones:"<<vGlobos[i]->getMediciones()<<endl;
				cout<<"Helio usado:"<<tH<<"Lt"<<endl;
				cout<<"Freon12 usado:"<<tF<<"Kg"<<endl;
				cout<<endl;
				tH=0;tF=0;rS=0;
			}
			system("pause");
    	break;
		case 2:
    		system("cls");
    		for(int i=0;i<cantidadG;i++){
    			auC=vGlobos[i]->getMediciones();
    			aux=vGlobos[i]->getConsumo();
    			 for(int j=0;j<auC;j++){
					 if(typeid(*aux[j])==typeid(Consumo)){
					 	rS++;
					 } 
				 }
				cout<<"Codigo:"<<vGlobos[i]->getCodigo()<<endl;
				cout<<"Propietario:"<<vGlobos[i]->getPropietario()<<endl;
				cout<<rS<<" "<<"veces que se mantuvo en el rango de seguridad"<<endl;
				tH=0;tF=0;rS=0;
				cout<<endl;
			}
			system("pause");
		break;
		case 3:
    		system("cls");
    		for(int i=0;i<cantidadG;i++){
    			auC=vGlobos[i]->getMediciones();
    			aux=vGlobos[i]->getConsumo();
    			 for(int j=0;j<auC;j++){
					 if(typeid(*aux[j])==typeid(Freon12)){
					 	tF+=aux[j]->getCantidad();rebaso++;
					 }
				 }
			}
			if(rebaso>7){
				cout<<"Para la proxima jornada traer"<<endl;	
				cout<<"Freon12 usado:"<<tF*2<<"Kg"<<endl;
				}else{
				cout<<"Para la proxima jornada traer"<<endl;	
				cout<<"Freon12 usado:"<<tF<<"Kg"<<endl;
				} 
			rebaso=0;
			system("pause");
		break;
		case 4:
    		system("cls");
    		for(int i=0;i<cantidadG;i++){
    			auC=vGlobos[i]->getMediciones();
    			aux=vGlobos[i]->getConsumo();
    			 for(int j=0;j<auC;j++){
    			 	if(typeid(*aux[j])==typeid(Helio)){
    			 		tH+=aux[j]->getCantidad();
					 }
					 if(typeid(*aux[j])==typeid(Freon12)){
					 	tF+=aux[j]->getCantidad();rebaso++;
					 	F+=aux[j]->getCantidad();
					 }
					 if(typeid(*aux[j])==typeid(Consumo)){
					 	rS++;
					 } 
				 }
				cout<<"Codigo:"<<vGlobos[i]->getCodigo()<<endl;
				cout<<"Propietario:"<<vGlobos[i]->getPropietario()<<endl;
				cout<<"Nro de Mediciones:"<<vGlobos[i]->getMediciones()<<endl;
				cout<<"Helio usado:"<<tH<<"Lt"<<endl;
				cout<<"Freon12 usado:"<<tF<<"Kg"<<endl;
				cout<<rS<<" "<<"veces que se mantuvo en el rango de seguridad"<<endl;
				cout<<endl;
				tH=0;tF=0;rS=0;
			}
			if(rebaso>7){
				cout<<"Para la proxima jornada traer"<<endl;	
				cout<<"Freon12 usado:"<<F*2<<"Kg"<<endl;
				}else{
				cout<<"Para la proxima jornada traer"<<endl;	
				cout<<"Freon12 usado:"<<F<<"Kg"<<endl;
				} 
			rebaso=0;
			system("pause");
		break;
		case 5:
			a++;
		break;	
	}
 }while(a==0);
   
}

Principal::~Principal()
{
	
}
