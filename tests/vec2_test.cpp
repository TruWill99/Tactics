#include "math/vec2.h"

#include <gtest/gtest.h>

namespace {

using Tactics::Math::Vec2;

TEST(Vec2, Addition) {
	EXPECT_EQ(Vec2(3, 4) + Vec2(6, 2), Vec2(9, 6));
}

} // namespace
