#pragma once
#include <string>
class moves
{
public:
	moves();
	static moves& GetInstance()
	{
		static moves instance;
		return instance;
	}
	std::string moveName;
	std::string moveType;
	int moveDamage;
	void setFireSpin();
	void setFlamethrower();
	void setBubbleBeam();
	void setQuickAttack();
	void setHyperBeam();
	void setThunderPunch();
	void setScratch();
	void setThunder();
	void setRazorLeaf();
	void setVineWhip();
	void setRockThrow();
	void setStoneEdge();
	void setSolarBeam();
	void setHydropump();
};