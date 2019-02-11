#pragma once

#include <SFML\Graphics\Transform.hpp>
#include <vector>

using namespace sf;

class Parameters {
public:
	Parameters() {  }
	~Parameters() { };
	void setTransform(const Transform &matrix) {transform = matrix; }
	Transform GetTransform() { return transform; }
	void MoveObject(float x, float y);
	void ScaleObject(float x, float y);
	void RotateObject(float x);
	Transform worldTransform;
	Transform transform;
	//Transform scale;
	//Transform rot;

protected:


	
};