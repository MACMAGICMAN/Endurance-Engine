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
	Transform GetTransform() { return transform; }

	void SetParent(SceneGraph& p) { parent = s; }
	void AddChild(SceneGraph* s);
	virtual void Update(float msec);
protected:
	SceneGraph* parent;
	Transform worldTransform;
	Transform transform;
	std::vector<SceneGraph*> children;
};