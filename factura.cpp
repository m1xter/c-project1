#include <iostream>
#include "factura.h"

using namespace std;


factura::factura(){
	
}

factura::factura(int id_factura,int id_cliente,char  * f){
	this->id_factura = id_factura;
	this->id_cliente = id_cliente;
	strcmp(fecha,f);
}

void factura::imprimir(){
	cout<<id_factura<<'\t'<<id_cliente<<"\t"<<fecha<<"\t"<<endl;
}

int factura::getid_factura(){
	return id_factura;
}

int factura::getid_cliente(){
	return id_cliente;
}

char * factura::getfecha(){
	return fecha;
}
