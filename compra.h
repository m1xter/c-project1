#ifndef compraH
#define compraH
class compra{
	private:
		int id;
		int id_producto;
		int id_factura;
		int cantidad;
	public:
		compra();
		compra(int id,int id_producto,int id_factura,int cantidad);
		
		void imprimir();
		
		
		int getid();
		int getid_producto();
		int getid_factura();
		int getcantidad();
};
#endif
