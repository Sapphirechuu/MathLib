#include "transform2d.h"

transform2d::transform2d()
{
	localPos = { 0, 0 };
	localRot = 0;
	localScale = { 1, 1 };
	parent = NULL;
}

void transform2d::translate(const vec2 & offset)
{
	localPos.x += offset.x;
	localPos.y += offset.y;
}

void transform2d::rotate(const float angle)
{
	localRot += angle;
}

void transform2d::lookAt(const transform2d & target)
{

}

vec2 transform2d::forward() const
{
	return vec2();
}

void transform2d::setForward(const vec2 & newFwd)
{
}

mat3 transform2d::getTRSMatrix() const
{
	return mat3::translation(localPos) * mat3::rotation(localRot) * mat3::scale(localScale);
}

vec2 transform2d::worldPosition() const
{
	mat3 resultm;
	if (parent != NULL)
	{
		resultm = parent->getTRSMatrix() * getTRSMatrix();
	}
	else
	{
		resultm = getTRSMatrix();
	}
	vec2 finalR{resultm.m7, resultm.m8};
	return finalR;

}

float transform2d::worldRotation() const
{
	mat3 resultm;
	if (parent != NULL)
	{
		resultm = parent->getTRSMatrix() * getTRSMatrix();
	}
	else
	{
		resultm = getTRSMatrix();
	}
	float finalR = resultm.m1;
	return finalR;
}

vec2 transform2d::worldScale() const
{
	mat3 resultm;
	if (parent != NULL)
	{
		resultm = parent->getTRSMatrix() * getTRSMatrix();
	}
	else
	{
		resultm = getTRSMatrix();
	}
	vec2 finalR{ resultm.m1, resultm.m5 };
	return finalR;
}

void transform2d::setParent(transform2d * newparent)
{
	parent = newparent;
	parent->children.push_back(this);
}

transform2d * transform2d::getParent()
{
	return parent;
}

transform2d const * transform2d::getParent() const
{
	return parent;
}

transform2d * transform2d::getChildren()
{
	if (children[0] != NULL)
	{
		return children[0];
	}
	return NULL;
}

transform2d * const * transform2d::getChildren() const
{
	if (children[0] != NULL)
	{
		return &children[0];
	}
	return NULL;
}

size_t transform2d::getChildrenCount() const
{
	return children.size();
}
