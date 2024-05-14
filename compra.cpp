#include <iostream>
#include "compra.h"
using namespace std;

compra::compra(int id,int id_producto,int id_factura,int cantidad){
	this->id = id;
	this->id_producto = id_producto;
	this->id_factura = id_factura;
	this->cantidad = cantidad;
}

compra::compra(){
	
}

void compra::imprimir(){
	cout<<id<<"\t"<<id_producto<<"\t"<<id_factura<<"\t"<<cantidad<<endl;
}

int compra::getcantidad(){
	return cantidad;
}

int compra::getid(){
	return id;
}

int compra::getid_producto(){
	return id_producto;
}

int compra::getid_factura(){
	return id_factura;
}
