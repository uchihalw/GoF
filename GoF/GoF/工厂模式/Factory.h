#include "Product.h"

//��������
class Factory {
public:
	virtual Product* CreateSplitter() = 0;
	virtual ~Factory() {}
};


//���幤��,�������еľ����Ʒ����
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