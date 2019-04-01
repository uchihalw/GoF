#pragma once
class House {

public:
	// 稳定构建算法
	void init() 
	{

		this->BuildPart1();

		for (int i = 0; i < 4; i++) {
			this->BuildPart2();
		}

		this->BuildPart3();
	}
	// 各个部分的子对象
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;

};class StoneHouse : public House {
	virtual void BuildPart1() {};
	virtual void BuildPart2() {};
	virtual void BuildPart3() {};
};
