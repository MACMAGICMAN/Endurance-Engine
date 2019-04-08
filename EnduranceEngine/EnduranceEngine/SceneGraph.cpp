#include "SceneGraph.h"
#include <vector>

//deconstructor giving error
/*SceneGraph::~SceneGraph(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}*/
//
void SceneGraph::AddChild(SceneGraph s)
{
	children.push_back(s);
	s.parent = this;
}

void SceneGraph::SetParent(SceneGraph& p)
{
	parent = &p;
}



void SceneGraph::Update(float msec)
{
	if (parent)
	{
		t_object.worldTransform = parent->t_object.worldTransform * t_object.transform;
	}
	else
	{
		t_object.worldTransform = t_object.transform;
	}
	for (std::vector<SceneGraph>::iterator i = children.begin(); i != children.end(); i++)
	{
		(i)->Update(msec);
	}
}

