#include "Product.h"
#include "Factory.h"
// Main中依赖的都是抽象基类
class Main
{
public:
	Main(Factory* fac)
	{
		this->fac = fac;
	}

	void exec() // Mian本身是稳定的，需求变化的时候不用改。只需要在未来添加Product子类和其对应的Factory子类就行 
	{
		Product* pro = fac->CreateSplitter();  // 多态new
		pro->split();
	}
private:
	Factory* fac;
};
/*
void mains()
{
	Factory_A* fac = new Factory_A();
	Main mn(fac);  // 传递哪个factory,就创建出对应的对象
	mn.exec();
}
*/
/*
每个类都有对应的具体的工厂。

定义一个用于创建对象的接口，让子类(工厂子类)决定实例化哪一个类，Factory Method使得一个类的实例化延迟到子类

用于隔离类对象的使用者和具体类型之间耦合关系 

解决"单个对象"的需求变化
*/