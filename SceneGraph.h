#pragma once
#include <SFML\Graphics\Transform.hpp>
#include <vector>

using namespace sf;

class SceneGraph
{
public:
	SceneGraph() { parent = NULL; }
	~SceneGraph(void);

	void setTransform(const Transform &matrix) { transform = matrix; }
	void setScale(const Transform &matrix) { scale = matrix; }
	void setRotation(const Transform &matrix) { rot = matrix; }
	Transform GetTransform() { return transform; }
	void MoveObject(SceneGraph* s, float x, float y);
	void ScaleObject(SceneGraph* s, float x, float y);
	void RotateObject(SceneGraph* s, float x);


	void SetParent(SceneGraph& p);
	void AddChild(SceneGraph* s);
	virtual void Update(float msec);
protected:
	SceneGraph* parent;
	Transform scale;
	Transform rot;
	Transform worldTransform;
	Transform transform;
	std::vector<SceneGraph*> children;
};
