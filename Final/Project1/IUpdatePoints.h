#pragma once

class IUpdatePoints
{
public:
	virtual void updatePoints(double credit, event name=WINGAME)=0;
};