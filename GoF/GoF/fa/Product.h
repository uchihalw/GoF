#include<iostream>
using namespace std;
// ��Ʒ����
class Product {
public:
	virtual void split() = 0;
	virtual ~Product() {}
};

//�����Ʒ��
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