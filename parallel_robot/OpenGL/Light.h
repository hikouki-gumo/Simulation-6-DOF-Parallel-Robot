// Light.h

#pragma once

// Khuôn mẫu các hàm thư viện OpenGL
#include <gl/gl.h>
#include <gl/glu.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CLight
{
public:
	// Hàm khởi tạo
	CLight();

	void InitLight();

};
