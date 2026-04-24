#include "nodoB.h"
template <class key>
class ArbolB : public NodoB<key> {
	private:
		std::unique_ptr<NodoB<key>> raiz_;
	public:
	bool buscar(const key& k) = 0;
	bool insertar(const key& k) const = 0;
	void inorden() const;
	std::ostream& operator<<(std::ostream& out, const ArbolB arbol);

};