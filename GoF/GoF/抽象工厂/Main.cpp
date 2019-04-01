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
1.���û��Ӧ��"��ϵ�ж��󹹽�"������仯����û�б�Ҫʹ��Abstract Factoryģʽ����ʱ��ʹ�ü򵥵Ĺ�����ȫ����

2."ϵ�ж���"ָ������ĳһ�ض�ϵ���µĶ���֮���л��������������õĹ�ϵ����ͬϵ�еĶ���֮�䲻�ܻ�������

3. Abstract Factoryģʽ��Ҫ����Ӧ��"��ϵ��"������䶯����ȱ����������Ӧ��"�¶���"������䶯

4. ����ģʽ���ǳ��󹤳���һ������,IDBFactory(���󹤳���)ֻ����һ�����󣬼�ֻ�� IDBconnection �� IDBReader ��һ
*/