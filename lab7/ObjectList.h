#pragma once
#include <iostream>
#include <vector>
#include "Track.h"

template <typename T>
class ObjectList
{
private:
	std::vector<T> objects;
public:
	void addObject(const T& newObject) {
		objects.push_back(newObject);
	}

	void displayObjects() const {
		for (const auto& obj : objects) {
			std::cout << obj << std::endl;
		}
	}
};