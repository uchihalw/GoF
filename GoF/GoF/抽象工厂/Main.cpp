#include <iostream>
using namespace std;

class IDBconnection {
public:
	virtual void show() = 0;
};
class sqlIDBconnection : public IDBconnection
{
public:
	virtual void show()
	{
		cout << "sqlIDBconnection: IDBconnection" << endl;
	}
};
class mysqlIDBconnection : public IDBconnection
{
public:
	virtual void show()
	{
		cout << "mysqlIDBconnection: IDBconnection" << endl;
	}
};


class IDBReader {
public:
	virtual void show() = 0;
};
class sqlIDBReader : public IDBReader
{
public:
	virtual void show()
	{
		cout << "sqlIDBconnection: IDBconnection" << endl;
	}
};
class mysqlIDBReader : public IDBReader
{
public:
	virtual void show()
	{
		cout << "mysqlIDBconnection: IDBconnection" << endl;
	}
};


class IDBFactory {
public:
	virtual IDBconnection* CreateIDBconnection() = 0;
	virtual IDBReader* CreateIDBReader() = 0;
};
class sqlFactory : public IDBFactory
{
public:
	virtual IDBconnection* CreateIDBconnection()
	{
		return new sqlIDBconnection();
	}
	virtual IDBReader* CreateIDBReader()
	{
		return new sqlIDBReader();
	}
};
class mysqlFactory : public IDBFactory
{
public:
	virtual IDBconnection* CreateIDBconnection()
	{
		
		return new mysqlIDBconnection();
	}

	virtual IDBReader* CreateIDBReader()
	{

		return new mysqlIDBReader();
	}
};




class Main
{
	IDBFactory *dbFactory;
public:
	Main(IDBFactory *idb)
	{
		dbFactory = idb;
	}

	void exec()
	{
		IDBconnection* conn = dbFactory->CreateIDBconnection();
		conn->show();
	}

};
void main_s()
{
	mysqlFactory * mysql = new mysqlFactory();
	Main mn(mysql);
	mn.exec();
}

/*
1.如果没有应对"多系列对象构建"的需求变化，则没有必要使用Abstract Factory模式，这时候使用简单的工厂完全可以

2."系列对象"指的是在某一特定系列下的对象之间有互相依赖、或作用的关系。不同系列的对象之间不能互相依赖

3. Abstract Factory模式主要在于应对"新系列"的需求变动，其缺点在于难以应对"新对象"的需求变动

4. 工厂模式就是抽象工厂的一个特例,IDBFactory(抽象工厂中)只创建一个对象，即只有 IDBconnection 或 IDBReader 其一
*/