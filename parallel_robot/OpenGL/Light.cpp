// Light.cpp

#include "stdafx.h"
#include "Light.h"

#include <math.h>

#include "glut/glut.h"


CLight::CLight()
{
}

void CLight::InitLight()
{
	// light
	GLfloat ambientLight[] = {0.5f,0.5f,1.0f,1.0f};//moi truong
	GLfloat diffuseLight[] = {0.8f,0.8f,0.8f,1.0f};//khuyech tan
	GLfloat specularLight[] = {0.4f,0.4f,0.4f,1.0f};//phan chieu
	GLfloat positionLight[] = {20.0f,20.0f,20.0f,0.0f};

	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specularLight);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1.0);
	glLightfv(GL_LIGHT0,GL_POSITION,positionLight);

	// lighting
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	
}
