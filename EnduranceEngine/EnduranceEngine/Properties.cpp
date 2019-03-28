#include "stdafx.h"
#include "Properties.h"
#include <windows.h>

Properties::Properties()
{
}

Properties::~Properties()
{
}

void Properties::Translate(float x, float y)
{
	Transform t = GetTransform();
	t.translate(x, y);
	SetTransform(t);
}

void Properties::Scale(float x, float y)
{
	Transform t = GetTransform();
	t.scale(x, y);
	SetTransform(t);
}

void Properties::Rotate(float degrees)
{
	Transform t = GetTransform();
	t.rotate(degrees);
	SetTransform(t);
}