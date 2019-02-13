#pragma once
#include <SFML/Graphics/Transform.hpp>

#include "Properties.h"
#include "AudioManager.h"
#include "SpriteRenderer.h"

using namespace sf;

class SceneGraph
{
public:
	SceneGraph() { parent = NULL; }
	//~SceneGraph(void);

	void SetParent(SceneGraph& p);
	void AddChild(SceneGraph s);
	virtual void Update(float msec);
	Properties t_object;
	AudioManager audio;
	SpriteRenderer sprite;

protected:	
	SceneGraph* parent;
	std::vector<SceneGraph> children;
};