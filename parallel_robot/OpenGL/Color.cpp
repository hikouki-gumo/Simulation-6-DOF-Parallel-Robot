// OpenObject.cpp

#include "stdafx.h"
#include "Color.h"

//////////////////////////////////////////////////////////////////////////
// CLASS CCOLOR
//////////////////////////////////////////////////////////////////////////
CColor::CColor()
{
	m_data[0] = 0.0f;
	m_data[1] = 0.0f;
	m_data[2] = 0.0f;
	m_data[3] = 1.0f;
}

CColor::CColor(float red, float green, float blue, float alpha)
{
	m_data[0] = red;
	m_data[1] = green;
	m_data[2] = blue;
	m_data[3] = alpha;
}

CColor::CColor(const CColor& color)
{
	m_data[0] = color.m_data[0];
	m_data[1] = color.m_data[1];
	m_data[2] = color.m_data[2];
	m_data[3] = color.m_data[3];
}

CColor::~CColor()
{

}

CColor& CColor::operator=(const CColor& color)
{
	m_data[0] = color.m_data[0];
	m_data[1] = color.m_data[1];
	m_data[2] = color.m_data[2];
	m_data[3] = color.m_data[3];
	return *this;
}

void CColor::setData(float red, float green, float blue, float alpha)
{
	m_data[0] = red;
	m_data[1] = green;
	m_data[2] = blue;
	m_data[3] = alpha;
}

const float* CColor::getData() const
{
	return m_data;
}

