#include "Product.h"
#include "Factory.h"
class Main
{
public:
	Main(Factory* fac)
	{
		this->fac = fac;
	}

	void exec()
	{
		Product* pro = fac->CreateSplitter();
		pro->split();
	}
private:
	Factory* fac;
};

void mains()
{
	Factory_A* fac = new Factory_A();
	Main mn(fac);
	mn.exec();
}