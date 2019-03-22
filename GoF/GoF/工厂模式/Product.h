#include<iostream>
using namespace std;
// 产品基类
class Product {
public:
	virtual void split() = 0;
	virtual ~Product() {}
};

//具体产品类
class Product_A: public Product {
	void split()
	{
		cout << "Product_A" << endl;
	}
};

class Product_B : public Product {
	void split()
	{
		cout << "Product_B" << endl;
	}
};

class Product_C : public Product {
	void split()
	{
		cout << "Product_C" << endl;
	}
};