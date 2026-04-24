#include <memory>
template<class key>
class NodoB {
	public:
		key dato_;
		std::unique_ptr<NodoB<key>> izdo_;
		std::unique_ptr<NodoB<key>> dcho_;
		NodoB(const key dato, std::unique_ptr<NodoB<key> izdo = nullptr, std::unique_ptr<NodoB<key>> dcho = nullptr) :
		dato_(dato), izdo_(izdo), dcho_(dcho){}
};

