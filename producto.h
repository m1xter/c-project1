#ifndef PRODUCTOH
#define PRODUCTOH
class producto{
	private:
		int id;
		int id_proveedor;
		int stock;
		float precio;
		char descripcion[45];
		int stock_min;		 
	public:
		producto(int id ,int id_proveedor,int stock,float precio,char * descripcion,int stock_min);
		producto();
		void imprimir();
		void mostrar();
		void mostrar_factura(int cant);
		float precio_final(int cant);
		
		int getid();
		int getid_proveedor();
		int getstock();
		float getprecio();
		char * getdescripcion();
		int getstock_min();
		
		void setid(int id);
		void setid_proveedor(int id_proveedor);
		void setstock(int stock);
		void setdescripcion(char * descripcion);
		void setstock_min(int stock_min);
		void setprecio(float precio);
		
};
#endif
