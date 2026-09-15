#include "vec2.h"
#include <iostream>

using namespace Tactics::Math;

int main() {
	Vec2 a(3, 4);
	Vec2 b(6, 2);
	std::cout << a << std::endl;
	std::cout << a.length() << std::endl;
	Vec2 norm = a.normalise();
	std::cout << norm << std::endl;

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * 3 << std::endl;
	std::cout << -a << std::endl;
	std::cout << a.dot(b) << std::endl;
	std::cout << a.cross(b) << std::endl;
	return 0;
}
