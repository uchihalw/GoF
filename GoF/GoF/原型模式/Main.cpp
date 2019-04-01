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
	ԭ��ģʽ������ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
	Prototype������ԭ���ࡣ������¡����Ľӿڡ�
	ConcretePrototype������ԭ���ࡣʵ�ֿ�¡�ľ��������
	Client���ͻ��ࡣ��һ��ԭ�Ϳ�¡�����Ӷ����һ���µĶ���
*/