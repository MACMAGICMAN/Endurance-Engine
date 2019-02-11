#include "stdafx.h"
#include "Parameters.h"

void Parameters::MoveObject(float x, float y)
{
	Transform q = GetTransform();
	q.translate(x, y);
	setTransform(q);
}

void Parameters::ScaleObject(float x, float y)
{
	Transform q = GetTransform();
	q.scale(x, y);
	setTransform(q);
}

void Parameters::RotateObject(float x)
{
	Transform q = GetTransform();
	q.rotate(x);
	setTransform(q);
}