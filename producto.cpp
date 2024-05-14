#include <iostream>
#include "producto.h"
#include <fstream>
using namespace std;

//AUTOR:  JUAN VIZCAYA 29976865  ESTRUCTURA DE DATOS
producto::producto(){
	
}

producto::producto(int id ,int id_proveedor,int stock,float precio,char * d,int stock_min){
	this->id = id;
	this->id_proveedor = id_proveedor;
	this->stock = stock;
	this->precio = precio;
	strcpy(descripcion,d);
	this->stock_min = stock_min;
}

void producto::imprimir(){
	cout<<id<<"\t"<<id_proveedor<<"\t"<<stock<<"\t"<<precio<<"\t"<<descripcion<<"\t"<<stock_min<<endl;
}

void producto::mostrar(){
	cout<<"\t"<<descripcion<<"\t"<<precio<<endl;
}


float producto::precio_final(int cant){
	return precio * cant;
}

int producto::getid(){
	return id;
}

int producto::getid_proveedor(){
	return id_proveedor;
}

int producto::getstock(){
	return stock;
}

float producto::getprecio(){
	return precio;
}

char * producto::getdescripcion(){
	return descripcion;
}

int producto::getstock_min(){
	return stock_min;
}


void producto::setid(int id ){
	this->id = id;
}

void producto::setid_proveedor(int id_proveedor){
	this->id_proveedor = id_proveedor;
}

void producto::setstock(int stock){
	this->stock = stock;
}

void producto::setprecio(float precio){
	this->precio = precio;
}

void producto::setdescripcion(char * descripcion){
	strcpy(descripcion,descripcion);
}

void producto::setstock_min(int stock_min){
	this->stock_min = stock_min;
}

