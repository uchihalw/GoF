#include "Builder.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <string>
using namespace  std;
void main()
{
	House* pHouse = new StoneHouse();
	pHouse->init();
}



/*
	��ʱ������һ��"���Ӷ����"�Ĵ�����������ͨ���ɸ������ֵ��Ӷ�����һ�����㷨���ɣ�
	��������ı仯��������Ӷ���ĸ������־��������ž��ҵı仯�����ǽ����������һ����㷨ȴ������ȶ���
	ͨ��һ�ַ�װ���ƽ��������"���Ӷ���ĸ�������"�ı仯���Ӷ�����ϵͳ�е�"�ȶ������㷨"����������ı仯���仯
*/

