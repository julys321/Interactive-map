#include "pch.h"
#include "../Interactive-map/Room.cpp"


TEST(Room_constructor, should_have_unique_id) {
	Room room1(0);
	Room room2(0);
	EXPECT_EQ(room1.id, "000");
	EXPECT_EQ(room2.id, "001");
}

TEST(Room_id, should_jump_when_99_rooms_already_exist) {
	for (int i = 0; i <= 99; i++) {
		Room room(0);
	}
	Room room(0);
	EXPECT_EQ(room.id, "002");//static func so dependent on other unit tests
}