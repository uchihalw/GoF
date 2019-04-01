#include "Product.h"
#include "Factory.h"
// Main�������Ķ��ǳ������
class Main
{
public:
	Main(Factory* fac)
	{
		this->fac = fac;
	}

	void exec() // Mian�������ȶ��ģ�����仯��ʱ���øġ�ֻ��Ҫ��δ�����Product��������Ӧ��Factory������� 
	{
		Product* pro = fac->CreateSplitter();  // ��̬new
		pro->split();
	}
private:
	Factory* fac;
};
/*
void mains()
{
	Factory_A* fac = new Factory_A();
	Main mn(fac);  // �����ĸ�factory,�ʹ�������Ӧ�Ķ���
	mn.exec();
}
*/
/*
ÿ���඼�ж�Ӧ�ľ���Ĺ�����

����һ�����ڴ�������Ľӿڣ�������(��������)����ʵ������һ���࣬Factory Methodʹ��һ�����ʵ�����ӳٵ�����

���ڸ���������ʹ���ߺ;�������֮����Ϲ�ϵ 

���"��������"������仯

�ŵ㣺�˷��˼򵥹���Υ������-���ԭ���ȱ�㣬�ֱ����˷�װ���󴴽����̵��ŵ�,���Ϳͻ��˺͹���������ԣ�����˵������ģʽ���ǡ��򵥹���ģʽ���Ľ�һ��������ƹ㡣

ȱ�㣺ÿ����һ����Ʒ����Ӧ��ҲҪ����һ���ӹ������Ӵ��˶���Ŀ�������
*/