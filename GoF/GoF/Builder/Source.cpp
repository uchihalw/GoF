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
	有时候面临一个"复杂对象的"的创建工作，其通常由各个部分的子对象用一定的算法构成；
	由于需求的变化，这个复杂对象的各个部分经常面临着剧烈的变化，但是将它们组合在一起的算法却是相对稳定的
	通过一种封装机制将来隔离出"复杂对象的各个部分"的变化，从而保持系统中的"稳定构建算法"不随着需求的变化而变化
*/

