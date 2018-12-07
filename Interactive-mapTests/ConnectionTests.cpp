#include "pch.h"
#include "../Interactive-map/Connection.cpp"

TEST(Connection_constructor, should_have_connectedWithId_be_Outside_when_leadsOutside_is_true) {
	Connection connection(true,"wrongId");
	EXPECT_EQ(connection.connectedWithId, "Outside");
}