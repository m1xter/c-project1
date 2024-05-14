#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>


#include "usuario.h"
#include "usuario.cpp"

#include "programa.h"
#include "programa.cpp"


//AUTOR:  JUAN VIZCAYA 29976865  ESTRUCTURA DE DATOS

using namespace std;



fstream arc;

char roles[][10]={"admin","personal","vendedor"};

void login(){
				
	int id;
	char nombre[45];
	char contra[45];
	char tipo[45];
	int op;
	int flag;
	usuario u;
	usuario buf;
	
	while(op!=4){
		system("cls");
		cout<<"-------LOGIN--------"<<endl;		
		cout<<"1. Iniciar sesion"<<endl;
		cout<<"2. Crear usuario"<<endl;
		cout<<"3. listar usuario"<<endl;
		cout<<"4. salir"<<endl;
		cout<<"Opcion:    ";
		cin >> op;
		
		switch(op){
			case 1:
				system("cls");
				cout<<"-------LOGIN--------"<<endl;
				cout<<" USUARIO: "; 
				cin>>nombre;		
				cout<<endl;
				cout<<" CONTRASENA: "; 
				cin>>contra;
				
				
				arc.open("usu.dat",ios::in | ios::binary);
				    if(arc){
				    	while(arc.read((char *)&buf,sizeof(buf))){
				    		if(strcmp(buf.getnombre(),nombre) == 0 &&  strcmp(buf.getcontra(),contra) == 0 ){
				    			
				    			programa(buf);
				    			break;
							}else{
								cout<<"usuario no registrado "<<endl;
							}
						}
				    arc.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
				
				
				
				system("pause");
			break;				
			case 2:
				system("cls");
				cout<<"------Nuevo Usuario-------"<<endl;
				cout<<"nombre: "; cin>> nombre;
				cout<<endl;
				cout<<"contrasena: "; cin>> contra;
				cout<<endl;
				cout<<" PERMISOS  [admin / personal / vendedor]: " ;				
				cin>>tipo;
				
				
				for(int i =0;i>=3;i++){
					if(strcmp(tipo,roles[i]) == 1){
						cout<<"error vuelve a escribir"<<endl;
						cout<<" PERMISOS  [admin / personal / vendedor]: " ;				
						cin>>tipo;	
					}
				}
				
				
				
				
				
					id = 1+rand()%(401-1);
					u = usuario(id,nombre,contra,tipo);
				
					arc.open("usu.dat",ios::app|ios::binary);
					if(arc){
						arc.write((char * )&u,sizeof(u));
						arc.close();	
					}else{
						cout<<"ERROR EN ESCRIBIR EN EL ARCHIVO"<<endl;
					}
					
				
				
				
				system("pause");
			break;			
			case 3:
				system("cls");
				arc.open("usu.dat",ios::in | ios::binary);
				    if(arc){
				    	while (1)
						    {
						        arc.read((char *)&buf,sizeof(buf));
						        if (arc.eof()) break;						        
						        buf.imprimir();
						    }
				    arc.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
					system("pause");
			break;
			
		}
	}
	
	
	
}




//MAIN
int main(int argc, char** argv) {
	
	login();
	
	
	
	
	
	
	return 0;
}
