#include<iostream>
#include<cstdlib>
#include <exception>
#include <queue>
#include <thread>

using namespace std;
/*
0. abort() 函数原型位于cstdlib.h || stdlib.h
	此函数将直接终止程序，而不是返回到main().显示的程序异常中断消息随编译器而异
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

1. 对异常的处理	
	0. 引发异常：throw语句(表示引发异常)实际上是跳转。紧随其后的值指出了异常的特征
	1. 使用处理程序捕获异常：catch(arg) 表示捕获异常,其中arg表示异常要响应的异常类型
	2. 使用try块：标识其中特定的异常可能被激活的代码块，它后面跟一个或多个catch块
	// 执行throw语句类似于执行返回语句，因为它也将终止函数的执行；但throw不是将控制权返回给调用程序，而是导致程序沿函数调用序列后退，直到找到包含try块的函数
	3. 如果函数引发了异常，而没有try块或没有匹配的处理程序时。在默认情况下，程序最终将调用abort()函数


2. 异常规范的作用
	1. 告诉用户可能需要使用try块
	2. 让编译器添加执行阶段检查的代码
	// noexcept指出函数不会引发异常，noexcept()判断其操作数是否会引发异常


3. 栈解退：函数由于异常(而不是返回)而终止，则程序将释放栈中的内存，但不会在释放栈的第一个返回地址后停止，而是继续释放栈，直到找到一个位于try块中的返回地址。
   随后控制权将转到块尾的异常处理程序，而不是函数调用后面的第一条语句。
	1. 函数返回
		in: func_1()-> func_2()-> func_3()[flag = 0]-> return(func_3) 
		ou: return(func_3)-> return(func_2)-> return(func_1)-> #2-> #3-> #5

	2. 函数解退
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


4. 其他特性
	0. tips: 如果有一个异常类继承层次结构，catch块的顺序:将捕获位于层次结构最下面的异常类的catch语句放在最前面，
	   将捕获基类异常的catch语句放在最后面。
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
catch (problem &p){...} // p指向oops的副本而不是oops本身。因为函数super()执行完毕后，oops将不复存在


5. 未捕获异常
	未捕获异常不会导致程序立刻异常终止。相反，程序将首先调用函数terminate()。
	在默认情况下，terminate()调用abort()函数。此外，可以指定terminate()应调用的函数(而不是abort())来修改terminate()的这种行为。


*/
/*
1. queue_1 =  stack_1 + stack_2
2. stack_1: 无论是否为空，只负责元素压入(队列尾部插入结点)
3. stack_2: (队列头部删除结点)
			1.为空时，将stack_1中的元素由上至下，依次压入stack_2
			2.不为空时，直接从stack_2执行删除操作

*/
/*
0.程序的运行起来，生成一个进程，该进程所属的主线程开始自动运行
	//cout << "hello" << endl; 实际上是主线程在执行，主线程从main()函数返回，则整个进程执行完毕
	// 主线程从main()开始执行，那么我们自己创建的线程，也需要从一个函数开始运行(初始函数)，一旦这个函数运行完毕，就代表我们这个线程运行结束
	// 整个进程,是否执行完毕的标志是主线程是否执行完毕,如果主线程执行完毕则代表整个进程执行完毕
	// 如果主线程执行完毕,一般情况下如其他子线程还没有执行完毕,那么这些子线程也会被操作系统强行终止.
	// 所以一般情况下,如果想保持子线程的运行状态,那么需要让主线程一直保持运行,不要让主线程运行完毕
	// 异常:detach()

1. thread：标准库中的类. // 头文件 thread
	thread myobj(myprint);// 1.创建了线程，线程执行起点(入口)myPrint 2.myprint线程开始执行
	如果只有thread myobj(myprint);没有其他诸如join或detach等操作，程序将报错

2. join():加入/汇合. 就是阻塞，让主线程等待子线程执行完毕，然后子线程和主线程汇合
	myobj.join();

3.detach():分离. 不建议使用
	0.传统多线程主线程要等待子线程执行完毕，然后自己才会退出
	1.主线程不和子线程汇合，主线程执行主线程的，子线程执行子线程的。
	  主线程不必等待子线程运行结束，主线程可以先结束，此举并不影响子线程的执行
	2.为什么引入detach()
		因为我们创建了很多子线程，让主线程逐个等待子线程结束，所以引入detach()
		一旦detach()之后，与这个主线程关联的thread对象就会失去与这个主线程的关联，此时这个子线程就会驻留在后台运行
		此时，这个子线程就相当于被c++运行时刻接管，当子线程执行完毕后，由运行时库负责清理该线程相关的资源(守护线程)。
		detach()使线程myprint失去我们自己的控制
4. 一旦调用了detach()，就不能用join(),否则系统会报告异常

5.joinable()：判断是否可以成功使用join()或者detach()
	0.如果在没有调用join()或者detach()之前，使用joinable()返回true
	1.如果在调用join()或者detach()之后，使用joinable()返回false

	// 执行顺序:#1->#3->#2
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

6.其他创建线程的手法
	0. 用类对象(可调用对象)
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
		thread myobj(ta); // 可调用对象
		myobj.join();

	}


	// 一旦调用了detach()，那主线程结束了，这里用的这个ta对象还在吗？
	// 这个ta对象实际上是被复制到线程中去。执行完主线程后，ta会被销毁，但是复制的ta对象依旧存在
	// 只要你这个TA对象里没有引用，没哟指针，那么就不会产生问题
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
		thread myobj(ta); // 可调用对象
		myobj.detach();

	}
	1. 用lambda表达式
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

