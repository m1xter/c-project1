
#include <iostream>

#include "usuario.h"

using namespace std;



usuario::usuario(){
	
}

usuario::usuario(int id,char * n ,char * c,char * t){
	this->id = id;
	strcpy(nombre,n);
	strcpy(contra,c);
	strcpy(tipo,t);
}


void usuario::imprimir(){
	cout<<id<<"\t"<<nombre<<"\t"<<contra<<"\t"<<tipo<<endl;
}

int usuario::getid(){
	return id;
}

char * usuario::getcontra(){
	return contra;
}

char * usuario::getnombre(){
	return nombre;
}

char * usuario::gettipo(){
	return tipo;
}



