#include<iostream>
#include<cstdlib>
#include <exception>
#include <queue>
#include <thread>

using namespace std;
/*
0. abort() ����ԭ��λ��cstdlib.h || stdlib.h
	�˺�����ֱ����ֹ���򣬶����Ƿ��ص�main().��ʾ�ĳ����쳣�ж���Ϣ�����������
double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "untenable argu\n" << endl;
		abort();
	}
}
void main()
{
	cout << "start" << endl;
	hmean(3.0,-3.0);
	cout << "end" << endl;

}

1. ���쳣�Ĵ���	
	0. �����쳣��throw���(��ʾ�����쳣)ʵ��������ת����������ֵָ�����쳣������
	1. ʹ�ô�����򲶻��쳣��catch(arg) ��ʾ�����쳣,����arg��ʾ�쳣Ҫ��Ӧ���쳣����
	2. ʹ��try�飺��ʶ�����ض����쳣���ܱ�����Ĵ���飬�������һ������catch��
	// ִ��throw���������ִ�з�����䣬��Ϊ��Ҳ����ֹ������ִ�У���throw���ǽ�����Ȩ���ظ����ó��򣬶��ǵ��³����غ����������к��ˣ�ֱ���ҵ�����try��ĺ���
	3. ��������������쳣����û��try���û��ƥ��Ĵ������ʱ����Ĭ������£��������ս�����abort()����


2. �쳣�淶������
	1. �����û�������Ҫʹ��try��
	2. �ñ��������ִ�н׶μ��Ĵ���
	// noexceptָ���������������쳣��noexcept()�ж���������Ƿ�������쳣


3. ջ���ˣ����������쳣(�����Ƿ���)����ֹ��������ͷ�ջ�е��ڴ棬���������ͷ�ջ�ĵ�һ�����ص�ַ��ֹͣ�����Ǽ����ͷ�ջ��ֱ���ҵ�һ��λ��try���еķ��ص�ַ��
   ������Ȩ��ת����β���쳣������򣬶����Ǻ������ú���ĵ�һ����䡣
	1. ��������
		in: func_1()-> func_2()-> func_3()[flag = 0]-> return(func_3) 
		ou: return(func_3)-> return(func_2)-> return(func_1)-> #2-> #3-> #5

	2. ��������
		in: func_1()-> func_2()-> func_3()[flag = 1]-> #0
		ou: #0-> #3-> #4-> #5

void func_3() {
	int flag;
	if (flag)
		throw "hello";					// #0
	return;
}
void func_2() { func_3(); return; }
void func_1() { func_2(); return; }
void main()
{
	try
	{
		cout << "before func_1" << endl; // #1
		func_1();
		cout << "after func_1" << endl;  // #2

	}									 // #3
	catch (const char* s)
	{
		cout << "after func_1 catch" << endl; // #4
	}

}											  // #5


4. ��������
	0. tips: �����һ���쳣��̳в�νṹ��catch���˳��:������λ�ڲ�νṹ��������쳣���catch��������ǰ�棬
	   ����������쳣��catch����������档
	1. catch(...){} // catch any exception


class problem {...};
void super() throw (problem)
{
	if (oh_no)
	{
		problem oops; // construct object
		throw oops;   // throw it
	}
}
try
{
	super();
}
catch (problem &p){...} // pָ��oops�ĸ���������oops������Ϊ����super()ִ����Ϻ�oops����������


5. δ�����쳣
	δ�����쳣���ᵼ�³��������쳣��ֹ���෴���������ȵ��ú���terminate()��
	��Ĭ������£�terminate()����abort()���������⣬����ָ��terminate()Ӧ���õĺ���(������abort())���޸�terminate()��������Ϊ��


*/
/*
1. queue_1 =  stack_1 + stack_2
2. stack_1: �����Ƿ�Ϊ�գ�ֻ����Ԫ��ѹ��(����β��������)
3. stack_2: (����ͷ��ɾ�����)
			1.Ϊ��ʱ����stack_1�е�Ԫ���������£�����ѹ��stack_2
			2.��Ϊ��ʱ��ֱ�Ӵ�stack_2ִ��ɾ������

*/
/*
0.�������������������һ�����̣��ý������������߳̿�ʼ�Զ�����
	//cout << "hello" << endl; ʵ���������߳���ִ�У����̴߳�main()�������أ�����������ִ�����
	// ���̴߳�main()��ʼִ�У���ô�����Լ��������̣߳�Ҳ��Ҫ��һ��������ʼ����(��ʼ����)��һ���������������ϣ��ʹ�����������߳����н���
	// ��������,�Ƿ�ִ����ϵı�־�����߳��Ƿ�ִ�����,������߳�ִ������������������ִ�����
	// ������߳�ִ�����,һ����������������̻߳�û��ִ�����,��ô��Щ���߳�Ҳ�ᱻ����ϵͳǿ����ֹ.
	// ����һ�������,����뱣�����̵߳�����״̬,��ô��Ҫ�����߳�һֱ��������,��Ҫ�����߳��������
	// �쳣:detach()

1. thread����׼���е���. // ͷ�ļ� thread
	thread myobj(myprint);// 1.�������̣߳��߳�ִ�����(���)myPrint 2.myprint�߳̿�ʼִ��
	���ֻ��thread myobj(myprint);û����������join��detach�Ȳ��������򽫱���

2. join():����/���. ���������������̵߳ȴ����߳�ִ����ϣ�Ȼ�����̺߳����̻߳��
	myobj.join();

3.detach():����. ������ʹ��
	0.��ͳ���߳����߳�Ҫ�ȴ����߳�ִ����ϣ�Ȼ���Լ��Ż��˳�
	1.���̲߳������̻߳�ϣ����߳�ִ�����̵߳ģ����߳�ִ�����̵߳ġ�
	  ���̲߳��صȴ����߳����н��������߳̿����Ƚ������˾ٲ���Ӱ�����̵߳�ִ��
	2.Ϊʲô����detach()
		��Ϊ���Ǵ����˺ܶ����̣߳������߳�����ȴ����߳̽�������������detach()
		һ��detach()֮����������̹߳�����thread����ͻ�ʧȥ��������̵߳Ĺ�������ʱ������߳̾ͻ�פ���ں�̨����
		��ʱ��������߳̾��൱�ڱ�c++����ʱ�̽ӹܣ������߳�ִ����Ϻ�������ʱ�⸺��������߳���ص���Դ(�ػ��߳�)��
		detach()ʹ�߳�myprintʧȥ�����Լ��Ŀ���
4. һ��������detach()���Ͳ�����join(),����ϵͳ�ᱨ���쳣

5.joinable()���ж��Ƿ���Գɹ�ʹ��join()����detach()
	0.�����û�е���join()����detach()֮ǰ��ʹ��joinable()����true
	1.����ڵ���join()����detach()֮��ʹ��joinable()����false

	// ִ��˳��:#1->#3->#2
	void myprint() // #3
	{
		cout << "Thread start" << endl;
	}

	int main()
	{
		thread myobj(myprint); // #1
		if (myobj.joinable()) {}
		//myobj.join();		   // #2
		//myobj.detach();
		cout << "hello" << endl;
		return 0;
	}

6.���������̵߳��ַ�
	0. �������(�ɵ��ö���)
	class TA
	{
	public:
		void operator()()
		{
			cout<<"operator() start"<<endl;
		}
	}

	void main1()
	{
		Ta ta;
		thread myobj(ta); // �ɵ��ö���
		myobj.join();

	}


	// һ��������detach()�������߳̽����ˣ������õ����ta��������
	// ���ta����ʵ�����Ǳ����Ƶ��߳���ȥ��ִ�������̺߳�ta�ᱻ���٣����Ǹ��Ƶ�ta�������ɴ���
	// ֻҪ�����TA������û�����ã�ûӴָ�룬��ô�Ͳ����������
	class TA
	{
	public:
		int m_i;
		TA(int i) :m_i(i) {}

		TA(const TA & ta):m_i(ta.m_i){}

		void operator()()
		{
			cout << "operator() start" << endl;
		}
	};
	void main2()
	{
		int my = 6;
		Ta ta(my);
		thread myobj(ta); // �ɵ��ö���
		myobj.detach();

	}
	1. ��lambda���ʽ
	auto mylambda = [] {cout<<"start"<<endl;}
	thread myobj(mylambda);
*/
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

