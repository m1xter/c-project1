#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include "busquedab.h"

using namespace std;


int bb(vector<producto> array,char * dato ,int inicio,int fin){
	int mid;
	
	while(inicio <=  fin ){
		mid = (inicio + fin ) /2	;
		if(strcmp(array[mid].getdescripcion(),dato) == 0 ){
			return mid;
		}else if(strcmp(dato,array[mid].getdescripcion()) < 0){
			fin  = mid - 1;
		}else{
			inicio = mid + 1;
		}
		
	}
	
	return -1;
}




void busqueda_binaria(vector<producto> array,char *  dato){
	system("cls");
	int tam = array.size();
	
	int pos = bb(array,dato,0,tam-1);
	
	if(pos != -1){
		cout<<endl;
		cout<<"Se encontro del producto buscado !"<<endl;
		cout<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<< array[pos].getid() <<  " " << array[pos].getid_proveedor()  << " " << array[pos].getdescripcion() << " " << array[pos].getstock() << " "  << array[pos].getprecio() << " " << array[pos].getstock_min()<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<endl;
		
		
	}
	
	
}


