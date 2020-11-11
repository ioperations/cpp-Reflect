#pragma once
#include "Reflector.h"


class Person : public ReflectObject
{
public:
	Person();
	virtual ~Person();
	virtual void show();
};
