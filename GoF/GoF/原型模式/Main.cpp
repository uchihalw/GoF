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
void mains()
{
	Prototype_A* proto_A = new Prototype_A();
	Main* ma = new Main(proto_A);
	ma->exec();

}
/*
	原型模式就是用原型实例指定创建对象的种类，并且通过复制这些原型创建新的对象。
	Prototype：抽象原型类。声明克隆自身的接口。
	ConcretePrototype：具体原型类。实现克隆的具体操作。
	Client：客户类。让一个原型克隆自身，从而获得一个新的对象。
*/