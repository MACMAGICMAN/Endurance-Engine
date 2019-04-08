#pragma once
#include <SFML/Graphics/Transform.hpp>

using namespace sf;

class Properties {
public:
	Properties();
	~Properties();

	Transform worldTransform;
	Transform transform;

	void SetTransform(const Transform &matrix) { transform = matrix; }
	Transform GetTransform() { return transform; }

	void Translate(float x, float y);
	void Scale(float x, float y);
	void Rotate(float degrees);
};