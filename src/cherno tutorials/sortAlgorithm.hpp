#pragma 
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

template<typename T>
void sortMyData(std::vector<T> &vec) {
	sort(vec.begin(), vec.end(), [](T a, T b)->bool {
		if (a == 1)	return true;//如果a的值为1，将1放在前面
		if (b == 1) return false;//如果b的值为1，将b放在前面
		return a < b;//将a放置在前面
	});
}

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if their bodies would
	// be empty.

	FooTest() {
		// You can do set-up work for each test here.
		std::cout << "Initializing ...!\n";
	}

	~FooTest() override {
		// You can do clean-up work that doesn't throw exceptions here.
		std::cout << "Cleanuping ...!\n";
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	void SetUp() override {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	void TearDown() override {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

};

// Tests that the Foo::Bar() method does Abc.
TEST_F(FooTest, SortMethod) {
	std::vector<int> data{ 2,1,4,5,3,6 };

	sortMyData<int>(data);
	ASSERT_EQ(data[0], 1);// 判断第一个是不是1
}