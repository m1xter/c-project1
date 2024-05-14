#ifndef proveedorH
#define proveedorH
class proveedor{
	private:
		int id;
		char nombre[45];
		char telefono[30];
		
	public:
		proveedor(int id,char * nombre, char * telefono);
		proveedor();
		void imprimir();
		
		int getid();
		char * getnombre();
		char * gettelefono();
		
		void setid(int id);
		void setnombre ( char * nombre);
		void settelefono(char * telefono);
};
#endif
