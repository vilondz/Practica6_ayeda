#include "nodoB.h"
#include <iostream>
#include <queue>
#include <utility>
template <class key>
class ArbolB : public NodoB<key> {
	private:
		std::unique_ptr<NodoB<key>> raiz_;
	public:
	virtual bool buscar(const key& k) const = 0;
	virtual bool insertar(const key& k)  = 0;
	void inorden() const;
	void recorre(std::unique_ptr<NodoB<key>>& nodo);
	void recorreN(std::unique_ptr<NodoB<key>>& node);
	std::ostream& operator<<(std::ostream& out){
		this->recorreN(raiz_);
	}
};

template <typename key>
void ArbolB<key>::inorden()const {
	recorre(raiz_);
}

template <typename key>
void ArbolB<key>::recorreN(std::unique_ptr<NodoB<key>>& raiz){
	std::queue<std::pair<std::unique_ptr<NodoB<key>>,int>> cola;
	int nivel_actual = 0;
	cola.push({raiz, 0});
	while(!cola.empty()){
		auto actual = cola.front();
		std::unique_ptr<NodoB<key>> nodo = actual.first;
		int nivel = actual.second;

		cola.pop();

		if (nivel > nivel_actual){
			nivel_actual = nivel;
			std::cout << std::endl;
		}

		if(nodo != nullptr){
			std::cout << nodo->dato_ << " ";
			cola.push({nodo->izdo_, nivel + 1});
			cola.push({nodo->dcho_, nivel + 1});
		}
		else{
			std::cout << "[.]";
		}
	}
}

template<typename key>
void ArbolB<key>::recorre(std::unique_ptr<NodoB<key>>& nodo){
	if(nodo == nullptr) return;
	recorre(nodo->izdo_);
	std::cout<< nodo->dato_ << "";
	recorre(nodo->dcho_);
}

