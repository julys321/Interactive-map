#include "pch.h"
#include "../Interactive-map/EmptyClass.cpp"

TEST(emptyClass_isDoingNothing, should_return_false_when_using_isDoingNothing) {
	EmptyClass emptyClass;
	EXPECT_FALSE(emptyClass.isDoingNothing());
}