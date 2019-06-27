// OpenObject.h

#pragma once

#include <gl/gl.h>
#include <gl/glu.h>

class CColor
{
public:
	float m_data[4];
public:
	CColor();
	CColor(float red, float green, float bluee, float alpha = 1.0);
	CColor(const CColor& color);
	virtual ~CColor();
public:
	CColor& operator=(const CColor& color);
	void setData(float red, float green, float blue, float alpha = 1.0);
public:
	const float*  getData() const;
};
