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

void SceneGraph::SetParent(SceneGraph& p)
{
	parent = &p;
}

void SceneGraph::MoveObject(SceneGraph *s, float x, float y)
{
	Transform q = s->GetTransform;
	q.translate(x, y);
	s->setTransform(q);
}

void SceneGraph::ScaleObject(SceneGraph* s, float x, float y)
{
	Transform q = s->GetTransform;
	q.scale(x, y);
	s->setScale(q);
}

void SceneGraph::RotateObject(SceneGraph* s, float x)
{
	Transform q = s->GetTransform;
	q.rotate(x);
	s->setRotation(q);
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

