#include <iostream>

#include "cliente.h"

#include <fstream>

using namespace std;

fstream cle;

cliente::cliente(){
	
}


cliente::cliente(int id,char * n,char * d,char * t){
	this->id = id;
	strcpy(nombre,n);
	strcpy(direccion,d);
	strcpy(telefono,t);
	
}





void cliente::imprimir(){
	
	cout<<id<<"\t"<<nombre<<"\t\t"<<direccion<<"\t\t"<<telefono<<endl;
	
}

int cliente::getid(){
	return id;
}

char * cliente::getnombre(){
	return nombre;
}

char * cliente::getdireccion(){
	return direccion;
}

char * cliente::gettelefono(){
	return telefono;
}


