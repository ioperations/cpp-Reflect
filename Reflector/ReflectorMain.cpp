// Reflector.cpp : 定义控制台应用程序的入口点。
//
#include "Person.h"
#include "Reflector.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(testReflect,testcase0){
	Person *allen = getNewInstance<Person>("Allen");
	Person *luffy = getNewInstance<Person>("Luffy");

	testing::internal::CaptureStdout();
	allen->show();
	std::string output = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	EXPECT_EQ(output, "Hello, I'm Allen\n");
	luffy->show();
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Hello, I'm Luffy\n");

	testing::internal::CaptureStdout();
	std::cout << "My test";
	output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "My test");

	delete allen;
	delete luffy;
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
