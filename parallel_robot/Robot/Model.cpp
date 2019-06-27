// OpenObject.cpp

#include "stdafx.h"
#include "Model.h"

CModel::CModel()
{
	displaylist = 0;
	m_filename = "";

	m_bShow = true;
	m_dScale = 1.0;

	m_theta = 0.0;
	m_d = 0.0;
	m_a = 0.0;
	m_alpha = 0.0;

	m_bIsRotation = true;
}

CModel::CModel(string filename)
{
	displaylist = 0;
	m_filename = "";
	setModel(filename.c_str());

	m_bShow = true;
	m_dScale = 1.0;

	m_theta = 0.0;
	m_d = 0.0;
	m_a = 0.0;
	m_alpha = 0.0;

	m_bIsRotation = true;
}

CModel::CModel(const CModel& model)
{
	m_filename = model.m_filename;
	m_bShow = model.m_bShow;
	m_dScale = model.m_dScale;

	m_theta = model.m_theta;
	m_d = model.m_d;
	m_a = model.m_a;
	m_alpha = model.m_alpha;

	m_bIsRotation = model.m_bIsRotation;
}

void CModel::setPosition(const double& q)
{
	if (m_bIsRotation)
	{
		m_alpha = q;
	}
	else
	{
		m_d = q;
	}
}

void CModel::setDHParameter(const double& theta, const double& d, const double& a, const double& alpha)
{
	m_theta = theta;
	m_d = d;
	m_a = a;
	m_alpha = alpha;
}

void CModel::translateDH()
{
	glTranslated(0.0, 0.0, m_d*m_dScale);
	glRotated(m_theta * 180 / PI, 0, 0, 1);
	glTranslated(m_a*m_dScale, 0.0, 0.0);
	glRotated(m_alpha * 180 / PI, 1, 0, 0);
}

void CModel::drawObject()
{
	if (m_bShow)
	{
		glPushMatrix();
		m_Material.ApplyToFace(GL_FRONT);
		glScaled(m_dScale, m_dScale, m_dScale);
		glCallList(displaylist);
		glPopMatrix();
	}
}

void CModel::setModel(string filename, const Vec3D & offset/* = Vec3D()*/)
{
	displaylist = 0;
	m_filename = filename;
	if (filename.size() == 0)
		return;
	createDisplayList(filename, offset);
}

void CModel::createDisplayList(const string &filename, const Vec3D & offset/* = Vec3D()*/)
{
	displaylist = glGenLists(1);
	glNewList(displaylist, GL_COMPILE);

	m_stl.Load(filename, offset);
	m_stl.Draw(false, true);

	glDisable(GL_NORMALIZE);
	glDisable(GL_POLYGON_SMOOTH);
	glEndList();
}