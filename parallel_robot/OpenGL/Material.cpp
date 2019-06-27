// OpenObject.cpp

#include "stdafx.h"
#include "Material.h"

void CMaterial::glMaterialC(int face, int pname, const CColor& color) const
{
	glMaterialfv(face, pname, color.getData());
}

CMaterial::CMaterial()
{
	m_AmbientColor.setData(0.2f, 0.2f, 0.2f, 1);
	m_DiffuseColor.setData(0.2f, 0.2f, 0.2f, 1);
	m_SpecularColor.setData(0, 0, 0, 1);
	m_EmissionColor.setData(0, 0, 0, 1);
	m_dShininessColor = 0.0f;
}

CMaterial::CMaterial(const CColor& ambient, const CColor& diffuse, const CColor& specular, const CColor& emission, float shininess)
{
	m_AmbientColor = ambient;
	m_DiffuseColor = diffuse;
	m_SpecularColor = specular;
	m_EmissionColor = emission;
	m_dShininessColor = shininess;
}

CMaterial::CMaterial(const CMaterial& material)
{
	m_AmbientColor = material.m_AmbientColor;
	m_DiffuseColor = material.m_DiffuseColor;
	m_SpecularColor = material.m_SpecularColor;
	m_EmissionColor = material.m_EmissionColor;
	m_dShininessColor = material.m_dShininessColor;
}

CMaterial& CMaterial::operator=(const CMaterial& material)
{
	m_AmbientColor = material.m_AmbientColor;
	m_DiffuseColor = material.m_DiffuseColor;
	m_SpecularColor = material.m_SpecularColor;
	m_EmissionColor = material.m_EmissionColor;
	m_dShininessColor = material.m_dShininessColor;
	return *this;
}

void CMaterial::SetData(const CColor& ambient, const CColor& diffuse, const CColor& specular, const CColor& emission, float shininess)
{
	m_AmbientColor = ambient;
	m_DiffuseColor = diffuse;
	m_SpecularColor = specular;
	m_EmissionColor = emission;
	m_dShininessColor = shininess;
}

void CMaterial::ApplyToFace(int face) const
{
	glMaterialC(face, GL_AMBIENT, m_AmbientColor);
	glMaterialC(face, GL_DIFFUSE, m_DiffuseColor);
	glMaterialC(face, GL_SPECULAR, m_SpecularColor);
	glMaterialC(face, GL_EMISSION, m_EmissionColor);
	glMaterialf(face, GL_SHININESS, m_dShininessColor);
}

void CMaterial::Reset()
{
	m_AmbientColor.setData(0.2f, 0.2f, 0.2f, 1);
	m_DiffuseColor.setData(0.8f, 0.8f, 0.8f, 1);
	m_SpecularColor.setData(0, 0, 0, 1);
	m_EmissionColor.setData(0, 0, 0, 1);
	m_dShininessColor = 0.0;
}

void CMaterial::InitMaterial()
{
	float	MatAmbient[]  = {0.2f, 0.5f, 0.2f, 1.0f};
	float	MatDiffuse[]  = {0.5f, 0.5f, 1.0f, 1.0f};
	float	MatSpecular[]  = {0.75f, 0.75f, 0.75f, 1.0f};
	float	MatShininess[]  = { 64 };
	float	MatEmission[]  = {0.0f, 0.0f, 0.0f, 1.0f};
	float MatAmbientBack[]  = {0.0f, 0.5f, 0.0f, 1.0f}; // green material behind

	glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmbient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,MatShininess);
	glMaterialfv(GL_FRONT,GL_EMISSION,MatEmission);
	glMaterialfv(GL_BACK,GL_AMBIENT,MatAmbientBack);

	glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}