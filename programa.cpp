#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sys/time.h> 
#include <math.h>
#include <ctime>
#include <time.h>


#include "programa.h"
#include "cliente.h"
#include "cliente.cpp"

#include "producto.h"
#include "producto.cpp"

#include "proveedor.h"
#include "proveedor.cpp"

#include "compra.h"
#include "compra.cpp"

#include "factura.h"
#include "factura.cpp"

#include "quicksort.h"
#include "quicksort.cpp"

#include "mezclad.h"
#include "mezclad.cpp"

#include "busquedab.h"
#include "busquedab.cpp"

#include "utilidades.h"
#include "utiladades.cpp"

//AUTHO:  JUAN VIZCAYA 29976865  

fstream f;
fstream f2;
//AUTOR:  JUAN VIZCAYA 29976865  ESTRUCTURA DE DATOS


void Elicliente(){
	ifstream ifs;
	ofstream ofs;
	cliente cbuf;
	int idproveedor;
	
					cout<<"Ingrese el id del cliente que desea Eliminar"<<endl;
					cout<<": ";
					cin>>idproveedor;
					
					ifs.open("cli.dat",ios::in | ios::binary);
					ofs.open("temp.dat",ios::out | ios::binary);
					
				    while(!ifs.eof()){
				    	ifs.read((char*)&cbuf,sizeof(cbuf));
				    	
				    	if(ifs){
				    		if(cbuf.getid() == idproveedor){
				    			
				    			cout<<"----------se va eliminar ------------"<<endl;
				    			cbuf.imprimir();
				    			
				    			
							}else{
								ofs.write((char*)&cbuf,sizeof(cbuf));
							}
						}
					}
					
					ofs.close();
					ifs.close();
					remove("cli.dat");
					rename("temp.dat","cli.dat");
					
}




void mostrarproveedores(){
	proveedor probuf;
	string id;
	string nombre;
	string tlf;			
					cout<<"	LISTA DE PROVEEDORES                  \n";
					cout<<"----------------------------------------------------------\n";
					cout<<"ID          NOMBRE             		TELEFONO          			  \n";
					cout<<"----------------------------------------------------------\n";
					f.open("proveedor.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&probuf,sizeof(probuf));
						        if (f.eof()) break;						        
						        id = to_string(probuf.getid());
						        nombre = probuf.getnombre();
						        tlf = probuf.gettelefono();
						        
						        cout<< id << espaciar(id.size(),10) << nombre << espaciar(nombre.size(),25) << tlf << espaciar(tlf.size(),10)<<endl;
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
					cout<<"----------------------------------------------------------\n";
					
}


int n_clientes(){
	int tamano;
	cliente cbuf;
	vector<cliente> c;
					f.open("cli.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&cbuf,sizeof(cbuf));
						        if (f.eof()) break;						        
						        c.push_back(cbuf);								
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}		
			tamano = c.size();			
	return tamano;
}

void mostrarclientes(){
	 cliente cbuf;
	 string nombre;
	 string direccion;
	 string telefono;
	 string ids;
	 int id;
	 
	system("cls");
	cout<<"------------------------Lista de Clientes-----------------------------------\n";
	cout<<"ID               NOMBRE          DIRECCION       TELEFONO           \n";
	cout<<"----------------------------------------------------------------------------\n";
	//ID = 10 espacios  nombre = 15 espacios  direccoin = 15 espacios tlf = 20 espacios
					f.open("cli.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&cbuf,sizeof(cbuf));
						        if (f.eof()) break;						        
						        ids = to_string(cbuf.getid());
						        nombre = cbuf.getnombre();
						        direccion = cbuf.getdireccion();
						        telefono = cbuf.gettelefono();
						        
						        
						        	cout<<ids<<espaciar(ids.size(),15)<< nombre << espaciar(nombre.size(),15) << direccion << espaciar(direccion.size(),15) << telefono << espaciar(telefono.size(),20) << endl;
								
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}					
	cout<<endl;
	cout<<"----------------------------------------------------------------------------\n";
	cout<<endl;	
}





void mostrarproductos(){
	string id;
	string id_proveedor;
	string stock;
	string precio;
	string descripcion;
	string stock_min;
					cout<<"                              LISTA DE PRODUCTOS                                              \n";
					cout<<endl;									
					cout<<"----------------------------------------------------------------------------------------------\n";
					cout<<"ID        ID_PROVEEDOR        STOCK     PRECIO         DESCRIPCION        STOCK_MIN           \n";
					cout<<"----------------------------------------------------------------------------------------------\n";
					producto pbuf;
				    f.open("pro.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&pbuf,sizeof(pbuf));
						        if (f.eof()) break;	
								
								
								id = to_string(pbuf.getid());
								id_proveedor = to_string(pbuf.getid_proveedor());
								stock = to_string(pbuf.getstock());
								precio = to_string(pbuf.getprecio());
								descripcion = pbuf.getdescripcion();
								stock_min = to_string(pbuf.getstock_min());
									        						        
						        cout<< id << espaciar(id.size(),10) << id_proveedor << espaciar(id_proveedor.size(),20) << stock << espaciar(stock.size(),10) << precio << espaciar(precio.size(), 15) << descripcion << espaciar(descripcion.size(),20) << stock_min << espaciar(stock_min.size(), 10) << endl;
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
					cout<<"----------------------------------------------------------------------------------------------\n";
}





void mostrarfactura(int id_factura){	
	factura fbuf;
	compra compbuf;	
	producto pbuf;
	float final;
	vector<int> total;
	string cantidad ;
	string descripcion;
	string precio;	
					cout<<endl;
					cout<<endl;
					cout<<endl;
					cout<<"-------------------FACTURA-------------------------\n";
					cout<<"id de la factura: "<<id_factura<<endl;
					cout<<"Compras realizadas  "<<endl;							
					cout<<"---------------------------------------------------\n";
					cout<<"CANTIDAD    DESCRIPCION        PRECIO          \n";
					cout<<"---------------------------------------------------\n";
					
					f.open("compra.dat",ios::in | ios::binary);
				    if(f){
				    	while(f.read((char *)&compbuf,sizeof(compbuf))){
				    		if(compbuf.getid_factura() == id_factura){				    			
				    			f2.open("pro.dat",ios::in | ios::binary);
							    if(f2){
							    	while(f2.read((char *)&pbuf,sizeof(pbuf))){
							    		if(compbuf.getid_producto() == pbuf.getid()){
							    			
							    			cantidad = to_string(compbuf.getcantidad());
											descripcion = pbuf.getdescripcion();
											precio = to_string(pbuf.precio_final(compbuf.getcantidad()));											
							    			final = final + pbuf.precio_final(compbuf.getcantidad());
							    			
							    			cout<< cantidad << espaciar(cantidad.size(),10) << descripcion << espaciar(descripcion.size(),20) << precio << espaciar(precio.size(),10) << endl;
										}
									}
							    f2.close();
								}else{
									cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
								}								
							}
						}
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
			cout<<endl;					
			cout<<"TOTAL: "<<final<<endl;
			cout<<"---------------------------------------------------\n";
			cout<<endl;			
}


void actu_stock(int idproducto,int cantidad){	
	producto pbuf;
	int r;	
		f2.open("pro.dat",ios::in | ios::binary |ios::out);
					f2.seekg(0);
				    if(f2){
				    	while(f2.read((char *)&pbuf,sizeof(pbuf))){
				    		if(pbuf.getid() == idproducto){
				    			
				    			if(pbuf.getstock() == pbuf.getstock_min()){
				    				cout<<"Stock minimo alcanzado no se pueden hacer mas compras"<<endl;
								}
								if(pbuf.getstock_min()< pbuf.getstock() ){
									r = pbuf.getstock() - cantidad;
				    			
				    				pbuf.setstock(r);
									f2.seekp(-sizeof(pbuf),ios::cur);
					    			f2.write((char * )&pbuf,sizeof(pbuf));										
								}
				    			
				    			
							}
						}
				    f2.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
	
}



void registrar(){
	int id;
	char nombre[45];
	char direccion[40];
	char telefono[18];
	vector<int> ids;
	int idcompra;
	int idproducto;
	int idfactura;
	int cantidad; 
	bool bandera;
	char repetir[] = "y";
	compra com;
	compra combuf;	
	cliente c;
	cliente cbuf;
	
	
	system("cls");
	cout<<"----------REGISTRAR COMPRA---------------"<<endl;
	cout<<endl;
	cout<<"Ingrese id del cliente:  ";
	cin>>id;
					
					f.open("cli.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&cbuf,sizeof(cbuf));
						        if (f.eof()) break;						        
						    	ids.push_back(cbuf.getid());
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
	
	
					for(int i =0;i < ids.size();i++){
						if(id == ids[i]){
						bandera = true;
						
						f.open("cli.dat",ios::in | ios::binary);
				    if(f){
				    	while(f.read((char *)&cbuf,sizeof(cbuf))){
				    		if(cbuf.getid() == id ){
								f.close();
								
								
								idcompra = 1+rand()%(401-1);
								
								cout<<endl;
								cout<<endl;
																
								mostrarproductos();
								
								cout<<endl;
								cout<<endl;
								
								cout<<"Ingrese id de la Factura: ";
								cin>>idfactura;
								cout<<"ID DE LA FACTURA: "<< idfactura<<endl;																
									while(strcmp(repetir,"y") == 0){
										
										cout<<"Ingrese Id del producto que desea agregar: ";
										cin>>idproducto;
										cout<<"cuantas unidades desea comprar ?: ";
										cin>>cantidad;									
																				
										com = compra(idcompra,idproducto,idfactura,cantidad);
										actu_stock(idproducto,cantidad);
										
										
										f.open("compra.dat",ios::app|ios::binary);
										if(f){
											f.write((char * )&com,sizeof(com));
											f.close();	
										}else{
											cout<<"ERROR EN ESCRIBIR EN EL ARCHIVO COMPRA.DAT"<<endl;
										}
										
										cout<<"agregar otro producto ? [y/n]: ";
										cin>>repetir;	
									}
								
							}
						}
				    
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO CLI.DAT" <<endl;
				}
					
					
					mostrarfactura(idfactura);
							
						}
					}//fin del for
					
				
				if(bandera == false){
					
								cout<<"cliente no registrado por favor registrelo"<<endl;
								f.close();								
								cout<<"nombre: ";
								cin>>nombre;
								cout<<"direccion: ";
								cin>>direccion;
								cout<<"telefono: ";
								cin>>telefono;
								
								c = cliente(id,nombre,direccion,telefono);
								
								
								f.open("cli.dat",ios::app|ios::binary);
								if(f){
									f.write((char * )&c,sizeof(c));
									f.close();	
								}else{
									cout<<"ERROR EN ESCRIBIR EN EL ARCHIVO CLI.DAT"<<endl;
								}
								
							cout<<"cliente registrado con exito!"<<endl;
					
				}
	
	system("pause");
}


void regicliente(){
	int id;
	char nombre[45];
	char direccion[70];
	char telefono[18];
	cliente c;
	system("cls");
	
								cout<<"nombre: ";
								cin>>nombre;
								cout<<"direccion: ";
								cin>>direccion;
								cout<<"telefono: ";
								cin>>telefono;
								
								c = cliente(id,nombre,direccion,telefono);
																
								f.open("cli.dat",ios::app|ios::binary);
								if(f){
									f.write((char * )&c,sizeof(c));
									f.close();	
								}else{
									cout<<"ERROR EN ESCRIBIR EN EL ARCHIVO CLI.DAT"<<endl;
								}
								
							cout<<"cliente registrado con exito!"<<endl;
}



void registrarP(){
	system("cls");
		int id;
		int id_proveedor;
		int stock;
		float precio;
		char descripcion[45];
		int stock_min;
		string ids;
		string ids_proveedor;
		string stocks;
		string precios;
		string descripcions;
		string stock_mins;
		producto p;
		producto pbuf;
		
		
		mostrarproveedores();
		
		cout<<endl;
		
		cout<<"---------------------REGISTRAR  PRODUCTO------------------\n";
		cout<<"----------------------------------------------------------\n";
		cout<<endl;
		cout<<"Id: ";
		cin>>id;	
		cout<<"Id del proveedor: ";
		cin>>id_proveedor;
		cout<<"Stock del producto: ";
		cin>>stock;
		cout<<"Precio del producto: ";
		cin>>precio;
		cout<<"Descripcion del producto: ";
		cin>>descripcion;
		cout<<"Stock minimo del producto: ";
		cin>>stock_min;
		cout<<endl;
		
		
					p = producto(id,id_proveedor,stock,precio,descripcion,stock_min);
		
					f.open("pro.dat",ios::app|ios::binary);
					if(f){
						f.write((char * )&p,sizeof(p));
						f.close();	
					}else{
						cout<<"ERROR EN ESCRIBIR EN EL ARCHIVO"<<endl;
					}
		
			cout<<"----------------------------------------------------------\n";
			cout<<endl;
			cout<<"LISTA DE PRODUCTOS"<<endl;			
			cout<<endl;									
			cout<<"----------------------------------------------------------------------------------------------\n";
			cout<<"ID        ID_PROVEEDOR        STOCK     PRECIO         DESCRIPCION        STOCK_MIN           \n";
			cout<<"----------------------------------------------------------------------------------------------\n";
		
				    f.open("pro.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&pbuf,sizeof(pbuf));
						        if (f.eof()) break;						        
						        
						        ids = to_string(pbuf.getid());
						        ids_proveedor = to_string(pbuf.getid_proveedor());
						        stocks = to_string(pbuf.getstock());
						        stock_mins = to_string(pbuf.getstock_min());
						        descripcions = pbuf.getdescripcion();
						        precios = to_string(pbuf.getprecio());
						        
						        cout<< ids << espaciar(ids.size(),10) << ids_proveedor << espaciar(ids_proveedor.size(),20) << stocks << espaciar(stocks.size(),10) << precios << espaciar(precios.size(), 15) << descripcions << espaciar(descripcions.size(),20) << stock_mins << espaciar(stock_mins.size(), 10) << endl;
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
		
		
		
}

void Regiproveedores(){
	system("cls");
	
		int id;
		char nombre[45];
		char telefono[30];
		proveedor pro;
		proveedor probuf;
		cout<<"---------Registro de proveedores-----------------";
		cout<<endl;
		cout<<"id del proveedor: ";
		cin>>id;
		cout<<"Nombre del proveedor: ";
		cin>>nombre;
		cout<<"telefono del proveedor: ";
		cin>>telefono;
		
		pro = proveedor(id,nombre,telefono);
		
		
		
					f.open("proveedor.dat",ios::app|ios::binary);
					if(f){
						f.write((char * )&pro,sizeof(pro));
						f.close();	
					}else{
						cout<<"ERROR EN ESCRIBIR EN EL ARCHIVO"<<endl;
					}
	
		cout<<"----------------------------------------"<<endl;	
	system("pause");
}


void Eliproducto(){
	ifstream ifs;
	ofstream ofs;
	producto pbuf;
	int idproveedor;
	
					cout<<"Ingrese el id del producto que desea Eliminar"<<endl;
					cout<<": ";
					cin>>idproveedor;
					
					ifs.open("pro.dat",ios::in | ios::binary);
					ofs.open("temp.dat",ios::out | ios::binary);
					
				    while(!ifs.eof()){
				    	ifs.read((char*)&pbuf,sizeof(pbuf));
				    	
				    	if(ifs){
				    		if(pbuf.getid() == idproveedor){
				    			
				    			cout<<"----------se va eliminar ------------"<<endl;
				    			pbuf.imprimir();
				    			
				    			
							}else{
								ofs.write((char*)&pbuf,sizeof(pbuf));
							}
						}
					}
					
					ofs.close();
					ifs.close();
					remove("pro.dat");
					rename("temp.dat","pro.dat");					
}



void Eliproveedor(){
	ifstream ifs;
	ofstream ofs;
	proveedor probuf;	
	int idproveedor;
	
					cout<<"Ingrese el id del proveedor que desea Eliminar"<<endl;
					cout<<": ";
					cin>>idproveedor;
					
					ifs.open("proveedor.dat",ios::in | ios::binary);
					ofs.open("temp.dat",ios::out | ios::binary);
					
				    while(!ifs.eof()){
				    	ifs.read((char*)&probuf,sizeof(probuf));
				    	
				    	if(ifs){
				    		if(probuf.getid() == idproveedor){
				    			
				    			cout<<"----------se va eliminar ------------"<<endl;
				    			probuf.imprimir();
				    			
				    			
							}else{
								ofs.write((char*)&probuf,sizeof(probuf));
							}
						}
					}
					
					ofs.close();
					ifs.close();
					remove("proveedor.dat");
					rename("temp.dat","proveedor.dat");
					
}


void Modiproveedores(){
	int idproveedor;
	char nombre[45];
	char telefono[30];
	proveedor probuf;
	system("cls");
	
					mostrarproveedores();
	
					cout<<"-------------------------------------------------"<<endl;
	
					cout<<"Ingrese el id del proveedor que desea modificar"<<endl;
					cout<<": ";
					cin>>idproveedor;
					
					cout<<endl;
					cout<<endl;
					cout<<endl;
					f.open("proveedor.dat",ios::in | ios::binary |ios::out);
					f.seekg(0);
				    if(f){
				    	while(f.read((char *)&probuf,sizeof(probuf))){
				    		if(probuf.getid() == idproveedor){
				    			
				    			
				    			probuf.imprimir();
				    			cout<<"------------------------------------"<<endl;
				    			cout<<endl;
				    			cout<<"Nombre del proveedor: ";
								cin>>nombre;
								probuf.setnombre(nombre);
								cout<<"telefono del proveedor: ";
								cin>>telefono;								
								probuf.settelefono(telefono);
								cout<<endl;
								f.seekp(-sizeof(probuf),ios::cur);
				    			f.write((char * )&probuf,sizeof(probuf));
				    			
							}
						}
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
	
}	


void menuproveedores(){
	int op;
		
		while(op !=4){
			system("cls");
			
			cout<<"-------MENU--------"<<endl;			
			cout<<"1. Registrar proveedor"<<endl;
			cout<<"2. Modificar proveedor"<<endl;						
			cout<<"3. Eliminar proveedor"<<endl;		
			cout<<"4. Salir"<<endl;
			cout<<"Opcion:    ";	
			cin>>op;
			switch(op){
				case 1:
					Regiproveedores();
				break;
				case 2:
					Modiproveedores();
				break;
				case 3:
					Eliproveedor();
				break;				
				
			}
			system("pause");
		}
	
}


long obtenerTiempo(){
    struct timeval inicio;
    // gettimeofdat devuelve el tiempo del reloj de la computadora
    gettimeofday(&inicio, NULL);
    // Retornamos el tiempo en segundo multiplicado por un millon que será 00:00:00 + el tiempo en microsegundos
    return inicio.tv_sec*1000000+inicio.tv_usec;
}


void mostrar_qs(vector<producto>array){
			string id;
			string id_proveedor;
			string stock;
			string precio;
			string descripcion;
			string stock_min;
			
			cout<<endl;									
			cout<<"----------------------------------------------------------------------------------------------\n";
			cout<<"ID        ID_PROVEEDOR        STOCK     PRECIO         DESCRIPCION        STOCK_MIN           \n";
			cout<<"----------------------------------------------------------------------------------------------\n";
			for(int i =0;i<array.size();i++){
				id = to_string(array[i].getid());
				id_proveedor = to_string(array[i].getid_proveedor());
				stock = to_string(array[i].getstock());
				precio = to_string(array[i].getprecio());
				descripcion = array[i].getdescripcion();
				stock_min = to_string(array[i].getstock_min());
				
				cout<< id << espaciar(id.size(),10) << id_proveedor << espaciar(id_proveedor.size(),20) << stock << espaciar(stock.size(),10) << precio << espaciar(precio.size(), 15) << descripcion << espaciar(descripcion.size(),20) << stock_min << espaciar(stock_min.size(), 10) << endl;
			}			
			cout<<"----------------------------------------------------------------------------------------------\n";
}



vector<producto> ordenqs(){
	
	system("cls");
	string id;
	string id_proveedor;
	string stock;
	string precio;
	string descripcion;
	string stock_min;
	vector<producto> array;
	
					producto pbuf;
				    f.open("pro.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&pbuf,sizeof(pbuf));
						        if (f.eof()) break;						        						        
								array.push_back(pbuf);
						        
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
			
			
			
    		//clock_t cl = clock();
    		
			qs(array,0,array.size()-1);					
			
			//double time = (clock()-cl)*1000000/CLOCKS_PER_SEC;
			
			
		return array;
	}
	
void ordenqs_mostrar(){
	
	system("cls");
	string id;
	string id_proveedor;
	string stock;
	string precio;
	string descripcion;
	string stock_min;
	vector<producto> array;
	
					producto pbuf;
				    f.open("pro.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&pbuf,sizeof(pbuf));
						        if (f.eof()) break;						        						        
								array.push_back(pbuf);
						        
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
					
			cout<<endl;
			cout<<"------------------------------LISTA DE PRODUCTOS SIN ORDENAR----------------------------------\n";			
			mostrar_qs(array);
			
    		//clock_t cl = clock();
    		
			qs(array,0,array.size()-1);				
			
			//double time = (clock()-cl)*1000000/CLOCKS_PER_SEC;	
			
			cout<<endl;			
			cout<<"------------------------------LISTA DE PRODUCTOS ORDENADA-------------------------------------\n";									
			mostrar_qs(array);
		
	}


void menuproductos(){
	int op;
	char descripcion[45];
	vector <producto> v;
		while(op !=5){
			system("cls");
			
			cout<<"-------MENU--------"<<endl;			
			cout<<"1. Registrar producto"<<endl;
			cout<<"2. Ordenar productos"<<endl;	
			cout<<"3. Buscar  productos"<<endl;	
			cout<<"4. Eliminar productos"<<endl;
			cout<<"5. Salir"<<endl;
			cout<<"Opcion:    ";	
			cin>>op;
			switch(op){
				case 1:
					registrarP();
				break;
				case 2:
					
					ordenqs_mostrar();
					
				break;
				case 3:
					cout<<"ingrese el nombre del producto que desea buscar: "<<endl;
					cin>>descripcion;
					busqueda_binaria(ordenqs(),descripcion);
				break;				
				case 4:
					Eliproducto();
				break;		
				
			}
			system("pause");
		}
	
}



void tipo_orden(){
	int n;
	int op;		
	
		while(op !=3){
			system("cls");
			
			cout<<"-------MENU--------"<<endl;			
			cout<<"1. Mezcla Directa"<<endl;
			cout<<"2. Mezcla Natural"<<endl;									
			cout<<"3. Salir"<<endl;
			cout<<"Opcion:    ";	
			cin>>op;
			switch(op){
				case 1:
					n = n_clientes();			
					
					
					mezcla_directa(n);
					
					mostrarclientes();
				break;
				case 2:
					 	 //mostrarclientes();
				break;
				case 3:
					
				break;				
				
			}
			system("pause");
		}
	
}


void menuclientes(){
	int op;
		
		while(op !=4){
			system("cls");
			
			cout<<"-------MENU--------"<<endl;			
			cout<<"1. Registrar Clientes"<<endl;
			cout<<"2. Ordenar Clientes"<<endl;									
			cout<<"3.Eliminar Clientes"<<endl;
			cout<<"4. Salir"<<endl;
			cout<<"Opcion:    ";	
			cin>>op;
			switch(op){
				case 1:
					regicliente();
				break;
				case 2:
					  tipo_orden();	//mostrarclientes();  
				break;
				case 3:
					  Elicliente();
				break;				
				
			}
			system("pause");
		}
	
}








void cerar_caja(){
	fstream f3;
	proveedor probuf;
	producto pbuf;
	char id[23];
	char nombre[23];
	char telefono[23];
	f3.open("cierre.txt",ios::out);
		if(f3.is_open()){
			f3<<"---------CIERRE DE CAJA-------------\n";
			f3<<"|PROVEEDORES|\n";
	
					f.open("proveedor.dat",ios::in | ios::binary);
				    if(f){
				    	while (1)
						    {
						        f.read((char *)&probuf,sizeof(probuf));
						        if (f.eof()) break;	
													        
						        f3<<probuf.getid();
						        f3<<"  ";
						        f3<<probuf.getnombre();
						        f3<<"  ";
						        f3<<probuf.gettelefono();
						        f3<<"\n";
						    }
				    f.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}
								
				f3<<"|PRODUCTOS A RESTABLECER|\n";
			
				
				    f2.open("pro.dat",ios::in | ios::binary);
				    if(f2){
				    	while (1)
						    {
						        f2.read((char *)&pbuf,sizeof(pbuf));
						        if (f2.eof()) break;						        						        
						        
						        	f3<<pbuf.getid();
						        	f3<<"  ";
						        	f3<<pbuf.getdescripcion();
						        	f3<<"  ";						        	
						        	f3<<pbuf.getid_proveedor();
						        	f3<<"  ";
						        	f3<<pbuf.getstock();
						        	f3<<"  ";
						        	f3<<pbuf.getstock_min();
									f3<<"\n";						        
						    }
				    f2.close();
					}else{
						cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
					}			
			f3.close();
			
		}
	

}












void programa(usuario u ){
	int op;
		
		while(op !=6){
			system("cls");
			cout<<"----------------------------------------------"<<endl;			
			cout<<"Sesion iniciada como: ";
			cout<<u.getnombre();
			cout<<"     permisos: ";
			cout<<u.gettipo();
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
			
			cout<<"-------MENU--------"<<endl;			
			cout<<"1. Registrar compra"<<endl;
			cout<<"2. Administrar productos"<<endl;		
			cout<<"3. Administrar Proveedores"<<endl;	
			cout<<"4. Administrar Clientes"<<endl;					
			cout<<"5. Cerrar caja"<<endl;
			cout<<"6. Salir"<<endl;
			cout<<"Opcion:    ";	
			cin>>op;
			switch(op){
				case 1:
					//admin,vendedor
					if(strcmp(u.gettipo(),"admin") == 0 || strcmp(u.gettipo(),"vendedor") == 0){
						registrar();
					}else{
						cout<<"no tienes los permisos para realizar esta accion !"<<endl;
						
					}
					
				break;
				case 2:
					//admin,personal
					if(strcmp(u.gettipo(),"admin") == 0 || strcmp(u.gettipo(),"personal") == 0){
						menuproductos();
					}else{
						cout<<"no tienes los permisos para realizar esta accion !"<<endl;
					}
					
				break;
				case 3:
					//admin
					if(strcmp(u.gettipo(),"admin") == 0 ){
						menuproveedores();
					}else{
						cout<<"no tienes los permisos para realizar esta accion !"<<endl;
				}
					
				break;
				case 4:
					menuclientes();
				break;
				case 5:
					cerar_caja();
				break;
				
			}
			
		}
		
		
	
}





























