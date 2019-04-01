#include "Prototype.h"
#include "ConcretePrototype.h"
class Main
{
	Prototype* pro;
public:
	Main(Prototype* tmp)
	{
		this->pro = tmp;
	}
	void exec()
	{
		Prototype* proto = pro->clone();
		proto->split();
	}
};
void main()
{
	Prototype_A* proto_A = new Prototype_A();
	Main* ma = new Main(proto_A);
	ma->exec();

}