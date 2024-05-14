#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>

#include "mezclad.h"
using namespace std;
fstream fl; // -> archivo de clientes
fstream fl1; // -> archivo aux 1
fstream fl2; // -> archivo aux 2

void particiona(int part ){
	int k,l; cliente R;
	
	fl.open("cli.dat",ios::in | ios::binary); //-> lectura
	fl1.open("f1.dat",ios::out | ios::binary); // -> escritura
	fl2.open("f2.dat",ios::out | ios::binary); // -> escritura
	
	do{
		k = 0;
		do{
			fl.read((char *)&R,sizeof(R));
			
			fl1.write((char * )&R,sizeof(R)); // -> crea grupo 1
			
			k = k + 1;
		}while(k < part && fl.eof());
		
		do{
			fl.read((char *)&R,sizeof(R));
			
			fl2.write((char * )&R,sizeof(R)); // -> crea grupo 2 
			
			l = l+1;
		}while( l < part && fl.eof() );
	}while(fl.eof());
	
	
	fl.close(); // cierre de cli.dat
	fl1.close(); // cierre de f1.dat
	fl2.close(); // cierre de f2.dat
	
}


void fusiona(int part ){
	
	int k,l; cliente R1,R2; bool B1,B2; // -> variables
	
	fl.open("cli.dat",ios::out| ios::binary); //-> escritura
	fl1.open("f1.dat",ios::in | ios::binary); // -> lectura
	fl2.open("f2.dat",ios::in | ios::binary); // -> lectura
	
	
	
	
	B1 = true; B2 = true;
	
	if(fl1.eof()){
		fl1.read((char *)&R1,sizeof(R1));
		R1.imprimir();
		B1 = false;
	}
	
	if(fl2.eof()){
		fl2.read((char *)&R2,sizeof(R2));
		R2.imprimir();
		B2 = false;
	}
	
	do{ // 8
		 k =0; l=0;
		 do{ // 8.1
		 	if(strcmp(R1.getnombre(),R2.getnombre()) <= 0){ // 8.1.1
		 		fl.write((char * )&R1,sizeof(R1)); 
		 		B1 = true; k = k + 1;		 		
		 		if(fl1.eof()){ // 8.1.1.1
					fl1.read((char *)&R1,sizeof(R1)); 			
					B1 = false;
				 }else{
					fl.write((char * )&R2,sizeof(R2)); 		 
				 	B2 = true; l = l + 1;
				 }//  fin de 8.1.1.1
				 
				 if(fl2.eof()){ // 8.1.1.3
				 	fl2.read((char *)&R2,sizeof(R2)); 			
				 	B2 = false;
				 }				 
			 }// fin de 8.1.1
			 
		 }while((k < part) && (B1 == false) && (l < part ) && (B2 == false)); // fin de 8.1
		 
		 
		 do{ // 8.3
		 	fl.write((char * )&R1,sizeof(R1)); 
		 	B1 = true; k = k+1;
		 	if(fl1.eof()){ //8.3.1
		 		fl1.read((char *)&R1,sizeof(R1)); 	
				 B1 = false;		
			 }// fin de 8.3.1
		 }while((k < part ) && (B1 == false));// fin de 8.3
		 
		 do{ // 8.5
		 	fl.write((char * )&R2,sizeof(R2)); 
		 	B2  = true; l = l + 1;
		 	if(fl.eof()){ // 8.5.1
		 		fl2.read((char *)&R2,sizeof(R2)); 	
		 		B2 = false;
			 }// fin de 8.5.1
			 
		 }while((l < part ) && (B2 == false)); // fin de 8.5
		 
	}while( ( fl1.eof() || B1 == false) && ( fl2.eof()  || B2 == false ) );//fin de 8
	
	if(B1 == false){ // 10
		fl.write((char * )&R1,sizeof(R1)); 
	} // fin de 10
	
	if(B2 == false){// 12
		fl.write((char * )&R2,sizeof(R2)); 
	}// fin de 12
	
	do{ // 14
		fl1.read((char *)&R1,sizeof(R1)); 	
		fl.write((char * )&R1,sizeof(R1)); 
	}while(fl1.eof());// finde 14
	
	do{ // 16		
		fl2.read((char *)&R2,sizeof(R2)); 	
		fl.write((char * )&R2,sizeof(R2)); 
	}while(fl2.eof()); // fin de 16
	
	fl.close(); // cierre de cli.dat
	fl1.close(); // cierre de f1.dat
	fl2.close(); // cierre de f2.dat
	
}


void mezcla_directa(int n){
		
	int part = 1; // -> empiza siendo grupos de 1
	do{
		particiona( part ); // -> crea los grupos y los separa entre f1 y f2																
		fusiona( part); 	 // -> hace el sort como tal 
		part = part * 2;
	}while(part < ((n+1)/2));
	
}
