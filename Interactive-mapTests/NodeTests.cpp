#include "pch.h"
#include "../Interactive-map/Node.cpp"

TEST(Node_constructor, should_have_unique_id) {
	Node node1;
	Node node2;
	EXPECT_EQ(node1.id, "#0");
	EXPECT_EQ(node2.id, "#1");
}