#pragma once

#include <string>
#include <map>
#include <iostream>

/********************所有需要实现反射的类需要继承它************************/
class ReflectObject {
	public:
		virtual ~ReflectObject(){}
};
/************************************************************************/


/******************对象工厂抽象类，用来生成对象实例************************/
class ObjectFactory {
	public:
		ObjectFactory(){}
		virtual ~ObjectFactory(){}
		virtual ReflectObject* newInstance() = 0;
};
/************************************************************************/


/***********反射器，用来管理（对象名，对象工厂）的映射关系******************/
class Reflector
{
	public:
		Reflector();
		~Reflector();
		void registerFactory(const std::string& className, ObjectFactory *of);
		ReflectObject* getNewInstance(const std::string& className);
	private:
		std::map<std::string, ObjectFactory*> objectFactories;
};
/************************************************************************/


/**********************获取反射器实例，全局唯一****************************/
Reflector& reflector();
/************************************************************************/


/***********需要被反射的类，需要在其对应的 cpp 文件中进行反射声明***********/
#define REFLECT(name)\
	class ObjectFactory_##name : public ObjectFactory{\
		public:\
			   ObjectFactory_##name(){}\
		virtual ~ObjectFactory_##name(){}\
		ReflectObject* newInstance() {\
			return new name(); \
		}\
	}; \
class Register_##name{\
	public:\
		   Register_##name(){\
			   reflector().registerFactory(#name, new ObjectFactory_##name()); \
		   }\
};\
Register_##name register_##name;
/************************************************************************/



/***********************根据类名获取对象实例******************************/
template<typename T>
T* getNewInstance(const std::string& className) {
	return dynamic_cast<T*>(reflector().getNewInstance(className));
}
/************************************************************************/
