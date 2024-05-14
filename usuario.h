#ifndef USUARIO_H
#define USUARIO_H

class usuario{
	private:
		int id;
		char nombre[45];
		char contra[45];
		char tipo[45];
	public:
		usuario();
		usuario(int id,char * nombre, char * contra,char * tipo);
		
		
		int getid();
		char * getnombre();
		char * getcontra();
		char * gettipo();
		
		void setnombre(char * nombre);
		void setcontra(char * contra);
		
		void imprimir();
		
		
		
				
};
#endif
