#include <iostream>
#include "proveedor.h"
using namespace std;

//AUTOR:  JUAN VIZCAYA 29976865  ESTRUCTURA DE DATOS
proveedor::proveedor(int id ,char * n, char * t){
	this->id = id;
	strcpy(nombre,n);
	strcpy(telefono,t);
}

proveedor::proveedor(){
	
}

void proveedor::imprimir(){
	cout<<id<<"\t"<<nombre<<"\t"<<telefono<<endl;
}


int proveedor::getid(){
	return id;
}

char * proveedor::getnombre(){
	return nombre;
}

char * proveedor::gettelefono(){
	return telefono;
}

void proveedor::setid(int id){
	this->id = id;
}

void proveedor::setnombre(char  * n){
	strcpy(nombre,n);
}

void proveedor::settelefono(char * t){
	strcpy(telefono,t);
}
