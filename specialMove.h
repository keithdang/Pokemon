#pragma once
#include "moves.h"
class specialMove :public moves
{
public:
	specialMove();
	std::string specialAbility;
	void stun();
	void setConfuseRay();
	~specialMove();
};

