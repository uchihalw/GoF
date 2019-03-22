#include "Product.h"

//工厂基类
class Factory {
public:
	virtual Product* CreateSplitter() = 0;
	virtual ~Factory() {}
};


//具体工厂,即工厂中的具体产品线类
class Factory_A : public Factory {
public:
	virtual Product* CreateSplitter() {
		return new Product_A();
	}
};

class Factory_B : public Factory {
public:
	virtual Product* CreateSplitter() {
		return new Product_B();
	}
};

class Factory_C : public Factory {
public:
	virtual Product* CreateSplitter() {
		return new Product_C();
	}
};