// ep1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <gtest\gtest.h>

using namespace std;

struct Foo {
	virtual int Plus(int left, int right)
	{
		return 2;
	}
};

struct Bar : public Foo {
	virtual int Plus(int left, short right)
	{
		return 4;
	}
};

TEST(Episode1, OverrideTest_CallParent)
{
	unique_ptr<Foo> op(new Foo());
	EXPECT_EQ(2, op->Plus(1, 1));
}

TEST(Episode1, OverrideTest_CallDerived)
{
	unique_ptr<Foo> op(new Bar());
	EXPECT_EQ(4, op->Plus(1, 1));
}


int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

