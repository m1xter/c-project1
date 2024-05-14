#ifndef facturaH
#define facturaH
class factura{
	private:
		int id_factura;
		int id_cliente;
		char fecha[20];
	public:
		factura();
		factura(int id_factura,int id_cliente,char * fecha);
		
		void imprimir();
		int getid_factura();
		int getid_cliente();
		char * getfecha();
};
#endif
