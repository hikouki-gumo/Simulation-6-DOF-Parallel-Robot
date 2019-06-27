// OpenGLInit.h

#pragma once

// Khuôn mẫu các hàm thư viện OpenGL
#include <gl/gl.h>
#include <gl/glu.h>

// Các thư viện cần liên kết của OpenGL
#pragma comment(lib, "opengl32.lib") 
#pragma comment(lib, "glu32.lib") 

#pragma warning ( disable : 4566 )

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Light.h"
#include "Material.h"
#include "MayaCamera.h"

#include "..\Robot\Model.h"
#include"..\Robot\Robot.h"



class COpenGLInit
{
public:
	CMaterial m_Material;
	CLight m_Light;
	CMayaCamera m_MayaCamera;
public:
	// Hàm khởi tạo
	COpenGLInit();
	void OnCreate(HWND hWnd, HDC _hDC);
	void OnSize(UINT nType, int cx, int cy);
	void OnDestroy();
	void OnDraw();
protected:
	void SetupPixelFormat();
	
public:
	HWND    m_hWnd;
	HDC     m_hDC;
	HGLRC   m_hRC;
	int m_nTimerID;		// ID của bộ đếm thời gian (timer)
	int m_nTimerElapse;	// Khoảng thời gian giữa các lần vẽ lại
	CRobot m_Robot;
};
