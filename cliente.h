#ifndef clienteH
#define clienteH
class cliente{
	private:
		int id;
		char nombre[45];
		char direccion[70];
		char telefono[18];
	public:
		cliente();
		cliente(int id,char * nombre,char * direccion, char * telefono);
		
		void imprimir();
		void Insertar(cliente c);
		void mostrar(cliente c);
		
		int getid();
		char * getnombre();
		char * getdireccion();
		char * gettelefono();
				
};
#endif
