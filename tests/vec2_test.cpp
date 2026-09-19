#include "math/vec2.h"

#include <gtest/gtest.h>

namespace {

using Tactics::Math::Vec2;

// --- Constructors ---

TEST(Vec2, InitZeroVector) {
	EXPECT_EQ(Vec2(), Vec2(0, 0));
}

// --- Comparison Operators ---

TEST(Vec2, EqualityReturnTrue) {
	EXPECT_TRUE(Vec2(5, 8) == Vec2(5, 8));
}

TEST(Vec2, InequalityReturnFalse) {
	EXPECT_FALSE(Vec2(5, 8) == Vec2(3, 9));
}

TEST(Vec2, InequalityWhenXDiffers) {
	EXPECT_TRUE(Vec2(5, 8) != Vec2(1, 8));
}

TEST(Vec2, InequalityWhenYDiffers) {
	EXPECT_TRUE(Vec2(5, 8) != Vec2(5, 2));
}

// --- Member Operators ---

TEST(Vec2, AdditionOfKnownVectors) {
	EXPECT_EQ(Vec2(3, 4) + Vec2(6, 2), Vec2(9, 6));
}

TEST(Vec2, AdditionWithZeroVectorIsIdentity) {
	Vec2 a(5, 5);
	EXPECT_EQ(a + Vec2(), a);
}

TEST(Vec2, SubtractionOfKnownVectors) {
	EXPECT_EQ(Vec2(8, 3) - Vec2(4, 1), Vec2(4, 2));
}

TEST(Vec2, SelfSubtraction) {
	Vec2 a(5, 5);
	EXPECT_EQ(a - a, Vec2(0, 0));
}

TEST(Vec2, ScalarOfKnownVector) {
	EXPECT_EQ(Vec2(3, 5) * 3, Vec2(9, 15));
}

TEST(Vec2, ScalarWithZero) {
	EXPECT_EQ(Vec2(9, 7) * 0, Vec2(0, 0));
}

TEST(Vec2, ScalarWithNegation) {
	EXPECT_EQ(Vec2(7, 6) * -1, Vec2(-7, -6));
}

TEST(Vec2, NegationWithKnownVector) {
	EXPECT_EQ(-Vec2(3, 1), Vec2(-3, -1));
}

TEST(Vec2, DoubleNegationWithKnownVector) {
	Vec2 a(13, 8);
	EXPECT_EQ(-(-a), a);
}

// --- Products ---

TEST(Vec2, DotOfKnownVectors) {
	EXPECT_FLOAT_EQ(Vec2(3, 4).dot(Vec2(6, 2)), 26.0f);
}

TEST(Vec2, DotOfPerpendicularVectors) {
	EXPECT_FLOAT_EQ(Vec2(1, 0).dot(Vec2(0, 1)), 0.0f);
}

TEST(Vec2, DotOfOppositeSign) {
	EXPECT_LT(Vec2(1, 0).dot(Vec2(-1, 0)), 0.0f);
}

TEST(Vec2, DotWithSelfEqualToSqrOfLength) {
	Vec2 a(7, 3);
	EXPECT_FLOAT_EQ(a.dot(a), a.length() * a.length());
}

TEST(Vec2, CrossOfKnownValues) {
	EXPECT_FLOAT_EQ(Vec2(3, 4).cross(Vec2(6, 2)), -18.0f);
}

TEST(Vec2, CrossWithStartToEndPositiveOrientation) {
	EXPECT_GT(Vec2(1, 0).cross(Vec2(0, 1)), 0.0f);
}

TEST(Vec2, CrossWithStartToEndNegativeOrientation) {
	EXPECT_LT(Vec2(0, 1).cross(Vec2(1, 0)), 0.0f);
}

TEST(Vec2, CrossWithAntiSymmetry) {
	Vec2 a(6, 7), b(8, 4);
	EXPECT_EQ(a.cross(b), -b.cross(a));
}

// --- Utility Methods ---

TEST(Vec2, LengthOfKnownVector) {
	EXPECT_FLOAT_EQ(Vec2(3, 4).length(), 5.0f);
}

TEST(Vec2, LengthOfZeroVector) {
	EXPECT_FLOAT_EQ(Vec2(0, 0).length(), 0.0f);
}

TEST(Vec2, LengthOfUnitAxis) {
	EXPECT_FLOAT_EQ(Vec2(1, 0).length(), 1.0f);
}

TEST(Vec2, LengthOfScaledVector) {
	EXPECT_FLOAT_EQ((Vec2(3, 4) * 3.0f).length(), 15.0f);
}

TEST(Vec2, NormaliseWithKnownVector) {
	EXPECT_EQ(Vec2(3, 4).normalise(), Vec2(0.6f, 0.8f));
}

TEST(Vec2, NormaliseUnitVectorUnchanged) {
	EXPECT_EQ(Vec2(1, 0).normalise(), Vec2(1, 0));
}

TEST(Vec2, NormaliseKnownVectorLengthEqual1) {
	EXPECT_FLOAT_EQ(Vec2(3, 4).normalise().length(), 1.0f);
}

TEST(Vec2, NormaliseZeroVectorLengthEqual0NotNaN) {
	EXPECT_FLOAT_EQ(Vec2(0, 0).normalise().length(), 0.0f);
}

TEST(Vec2, NormaliseWithScalingInvarianceIsEqual) {
	EXPECT_EQ(Vec2(3, 4).normalise(), Vec2(30, 40).normalise());
}

} // namespace
