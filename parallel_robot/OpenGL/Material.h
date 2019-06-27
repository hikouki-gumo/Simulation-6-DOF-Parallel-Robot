// OpenObject.h

#pragma once

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include <gl/gl.h>
#include <gl/glu.h>

#include "Color.h"


class CMaterial
{
public:
	CColor m_AmbientColor;
	CColor m_DiffuseColor;
	CColor m_SpecularColor;
	CColor m_EmissionColor;
	float  m_dShininessColor;
protected:	
	void glMaterialC(int face, int pname, const CColor& color) const;
public:
	CMaterial();
	CMaterial(const CColor& ambient, const CColor& diffuse, const CColor& specular, const CColor& emission = CColor(0, 0, 0, 1), float shininess=0.0f);
	CMaterial(const CMaterial& material);
public:
	CMaterial& operator=(const CMaterial& material);

	void SetData(const CColor& ambient, const CColor& diffuse, const CColor& specular, const CColor& emission=CColor(0, 0, 0, 1), float shininess = 0.0f);
	void ApplyToFace(int face = GL_FRONT_AND_BACK) const;
	void Reset();
public:
	void InitMaterial();
};

static CMaterial storageMaterial[28] = {
	CMaterial (CColor(0.02150f, 0.17450f, 0.02150f, 1), CColor(0.07568f, 0.61514f, 0.07568f, 1), CColor(0.63300f, 0.72781f, 0.63300f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.13500f, 0.22250f, 0.15750f, 1), CColor(0.54890f, 0.63000f, 0.31623f, 1), CColor(0.31623f, 0.31623f, 1.00000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.05375f, 0.05000f, 0.06625f, 1), CColor(0.18275f, 0.17000f, 0.22525f, 1), CColor(0.33274f, 0.32683f, 0.34643f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.17450f, 0.01175f, 0.01175f, 1), CColor(0.61514f, 0.04136f, 0.04136f, 1), CColor(0.72781f, 0.62696f, 0.62696f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.10000f, 0.18725f, 0.17450f, 1), CColor(0.39674f, 0.74151f, 0.69102f, 1), CColor(0.29725f, 0.30829f, 0.30668f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.32941f, 0.22353f, 0.02745f, 1), CColor(0.78039f, 0.75863f, 0.11372f, 1), CColor(0.99216f, 0.94118f, 0.80784f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.21250f, 0.12750f, 0.05400f, 1), CColor(0.74100f, 0.51840f, 0.18144f, 1), CColor(0.39355f, 0.27190f, 0.16672f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.25000f, 0.25000f, 0.25000f, 1), CColor(0.40000f, 0.40000f, 0.40000f, 1), CColor(0.77460f, 0.77460f, 0.77460f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.19125f, 0.07350f, 0.02250f, 1), CColor(0.70380f, 0.27048f, 0.08280f, 1), CColor(0.25678f, 0.13762f, 0.08601f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.24725f, 0.19950f, 0.07450f, 1), CColor(0.75164f, 0.60648f, 0.22648f, 1), CColor(0.62828f, 0.55580f, 0.36606f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.19225f, 0.19225f, 0.19225f, 1), CColor(0.50754f, 0.50754f, 0.50754f, 1), CColor(0.50827f, 0.50827f, 0.50827f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.00000f, 0.00000f, 0.00000f, 1), CColor(0.01000f, 0.01000f, 0.01000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.00000f, 0.10000f, 0.06000f, 1), CColor(0.00000f, 0.50980f, 0.50980f, 1), CColor(0.50196f, 0.50196f, 0.50196f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.00000f, 0.00000f, 0.00000f, 1), CColor(0.10000f, 0.35000f, 0.10000f, 1), CColor(0.45000f, 0.55000f, 0.45000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.00000f, 0.00000f, 0.00000f, 1), CColor(0.50000f, 0.00000f, 0.00000f, 1), CColor(0.70000f, 0.60000f, 0.60000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.02000f, 0.02000f, 0.02000f, 1), CColor(0.01000f, 0.01000f, 0.01000f, 1), CColor(0.40000f, 0.40000f, 0.40000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.00000f, 0.05000f, 0.05000f, 1), CColor(0.40000f, 0.50000f, 0.50000f, 1), CColor(0.40000f, 0.70000f, 0.40000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.00000f, 0.05000f, 0.00000f, 1), CColor(0.40000f, 0.50000f, 0.40000f, 1), CColor(0.04000f, 0.70000f, 0.04000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.05000f, 0.00000f, 0.00000f, 1), CColor(0.50000f, 0.40000f, 0.40000f, 1), CColor(0.70000f, 0.04000f, 0.04000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.05000f, 0.05000f, 0.05000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0.70000f, 0.70000f, 0.70000f, 1), CColor(0, 0, 0, 1), 50),
	CMaterial (CColor(0.05000f, 0.05000f, 0.00000f, 1), CColor(0.50000f, 0.50000f, 0.40000f, 1), CColor(0.70000f, 0.70000f, 0.04000f, 1), CColor(0, 0, 0, 1), 50),//20
	CMaterial (CColor(0.95000f, 0.95000f, 0.95000f, 1), CColor(0.85000f, 0.85000f, 0.85000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0, 0, 0, 1), 50),//21:Trang' sua~ by Nambk
	CMaterial (CColor(0.85000f, 0.85000f, 0.85000f, 1), CColor(0.85000f, 0.85000f, 0.85000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0, 0, 0, 1), 50),//22
	CMaterial (CColor(0.75000f, 0.75000f, 0.75000f, 1), CColor(0.90000f, 0.09800f, 0.70000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0, 0, 0, 1), 50),//23
	CMaterial (CColor(0.65000f, 0.55000f, 0.45000f, 1), CColor(0.43000f, 0.51000f, 0.57000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0, 0, 0, 1), 50),//24:
	CMaterial (CColor(0.55000f, 0.45000f, 0.35000f, 1), CColor(0.99000f, 0.99000f, 0.01000f, 1), CColor(0.50000f, 0.50000f, 0.50000f, 1), CColor(0, 0, 0, 1), 50),//25: Blue
	CMaterial (CColor(0.45000f, 0.35000f, 0.25000f, 1), CColor(0.99000f, 0.01000f, 0.99000f, 1), CColor(0.25000f, 0.25000f, 0.25000f, 1), CColor(0, 0, 0, 1), 50),//26: Mau hong 255,0,255
	CMaterial (CColor(0.35000f, 0.25000f, 0.15000f, 1), CColor(0.08000f, 0.85000f, 0.55000f, 1), CColor(0.25000f, 0.25000f, 0.25000f, 1), CColor(0, 0, 0, 1), 50)//27: Mau xanh son cua so^?
};
