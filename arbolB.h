#include "nodoB.h"
template <class key>
class ArbolB : public NodoB<key> {
	private:
		std::unique_ptr<NodoB<key>> raiz_;
	public:
	bool buscar(const key& k) = 0;
	bool insertar(const key& k) const = 0;
	void inorden() const;
	void recorre(std::unique_ptr<NodoB<key>>& nodo);
	std::ostream& operator<<(std::ostream& out, const ArbolB arbol);
};

template <typename key>
void ArbolB<key>::inorden()const {
	recorre(raiz_);
}
template<typename key>
void ArbolB<key>::recorre(std::unique_ptr<NodoB<key>>& nodo){
	if(nodo == nullptr) return;
	recorre(nodo->izdo_);
	std::cout<< nodo->dato_ << "";
	recorre(nodo->dcho_);
}
