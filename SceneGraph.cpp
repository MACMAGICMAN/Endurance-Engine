#include "SceneGraph.h"
#include <vector>

SceneGraph::~SceneGraph(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void SceneGraph::AddChild(SceneGraph* s)
{
	children.push_back(s);
	s->parent = this;
}

void SceneGraph::Update(float msec)
{
	if (parent)
	{
		worldTransform = parent->worldTransform * transform;
	}
	else
	{
		worldTransform = transform;
	}
	for (std::vector<SceneGraph*>::iterator i = children.begin(); i != children.end(); i++)
	{
		(*i)->Update(msec);
	}
}

