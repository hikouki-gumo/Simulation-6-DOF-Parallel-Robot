// OpenGLInit.cpp

#include "stdafx.h"
#include "OpenGLInit.h"

COpenGLInit::COpenGLInit()
{
	m_hWnd = NULL;
	m_hDC = NULL;
	m_hRC = NULL;
	m_nTimerID = 4; // Thay đổi nếu cần để tránh trùng với timer sẵn có
	m_nTimerElapse =50;

}

// Set up pixel format for graphics initialization
void COpenGLInit::SetupPixelFormat()
{
 	PIXELFORMATDESCRIPTOR pfd, *ppfd;
 	int pixelformat;
 
 	ppfd = &pfd;
 
 	ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
 	ppfd->nVersion = 1;
 	ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
 	ppfd->dwLayerMask = PFD_MAIN_PLANE;
 	ppfd->iPixelType = PFD_TYPE_COLORINDEX;
 	ppfd->cColorBits = 32;
 	ppfd->cDepthBits = 32;
 	ppfd->cAccumBits = 0;
 	ppfd->cStencilBits = 0;
 
 	pixelformat = ChoosePixelFormat(m_hDC, ppfd);
 	SetPixelFormat(m_hDC, pixelformat, ppfd);
}

// Initialize OpenGL graphics
void COpenGLInit::OnCreate(HWND hWnd, HDC _hDC)
{
    m_hDC = _hDC;

    SetupPixelFormat();

    m_hRC = wglCreateContext(m_hDC);
    wglMakeCurrent(m_hDC, m_hRC);

	 //mode
	glPolygonMode(GL_FRONT,GL_FILL);
	glPolygonMode(GL_BACK,GL_FILL);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	//glShadeModel(GL_FLAT);
	glEnable(GL_NORMALIZE);

    m_Light.InitLight();

   // Perspective
   CRect rect;
   ::GetClientRect(m_hWnd, &rect);
   double aspect = (rect.Height() == 0) ? rect.Width() : (double)rect.Width()/(double)rect.Height();
   gluPerspective(45,aspect,0.1,1000.0);

   // material
   m_Material.InitMaterial();

   glEnable(GL_DEPTH_TEST);//Kiem tra chieu sau
   
   glClearDepth(1.0f);


   glShadeModel(GL_SMOOTH);


}

// Resize graphics to fit window
void COpenGLInit::OnSize(UINT nType, int width, int height)
{
	glViewport(0,0,width,height);

	GLfloat fAspect;
	GLfloat fNearPlane,fFarPlane;
	fNearPlane=10.0f;
	fFarPlane=100000.0f;
	if (height==0) 
		fAspect=(GLfloat)width;
	else
		fAspect=(GLfloat)width/(GLfloat)height;
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,fAspect,fNearPlane,fFarPlane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-120.0, 20.0, 80.0,20.0,-80.0,0.0,0.0, 0.0,1.0);
}

// Draw frame
void COpenGLInit::OnDraw()
{
    glClearColor(0.1f,0.5f,0.5f,0.5f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	//Rời hệ tọa độ ra giữa khung màn hình để có vị trí quan sát thuận lợi
	glTranslated(-300,-300,-1000.0);

	m_MayaCamera.UpdateView();
	
	
	m_Robot.Draw();
	//m_Robot.drawbanmay();

    // Show the new scene
    SwapBuffers(m_hDC);
}

void COpenGLInit::OnDestroy()
{
	::wglMakeCurrent(NULL,  NULL);

	if (m_hRC)
		::wglDeleteContext(m_hRC);
}