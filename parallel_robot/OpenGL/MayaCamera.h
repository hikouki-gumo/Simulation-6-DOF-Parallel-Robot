class CMayaCamera
{
public:
	float	 m_fLastX;
	float	 m_fLastY;
	float	 m_fPosX;
	float	 m_fPosY;
	float	 m_fZoom;
	float	 m_fRotX;
	float	 m_fRotY;

	CMayaCamera()
	{
		m_fPosX = 0.0f;    // X position of model in camera view
		m_fPosY = 0.0f;    // Y position of model in camera view
		m_fZoom = 1.0f;    // Zoom on model in camera view
		m_fRotX = 0.0f;    // Rotation on model in camera view
		m_fRotY = 0.0f;    // Rotation on model in camera view
	}
	void DefaultView(void)
	{
		m_fPosX = 0.0f;    // X position of model in camera view
		m_fPosY = 0.0f;    // Y position of model in camera view
		m_fZoom = 1.0f;    // Zoom on model in camera view
		m_fRotX = 0.0f;    // Rotation on model in camera view
		m_fRotY = 0.0f;    // Rotation on model in camera view
	}
	void UpdateView()
	{
		glScalef(m_fZoom,m_fZoom,m_fZoom);
		glTranslatef(m_fPosX, m_fPosY, 0.0f);
		glRotatef(m_fRotX, 1.0f, 0.0f, 0.0f);
		glRotatef(m_fRotY, 0.0f, 1.0f, 0.0f);
	}
	void OnMouseMove(UINT nFlags, CPoint point)
	{
		int xPos = point.x; 
		int yPos = point.y; 

		int diffX = (int)(xPos - m_fLastX);
		int diffY = (int)(yPos - m_fLastY);
		m_fLastX  = (float)xPos;
		m_fLastY  = (float)yPos;

		// Left mouse button
		//if (nFlags & MK_LBUTTON)
		if (nFlags==MK_LBUTTON)
		{
			m_fRotX += (float)0.5f * diffY;

			if ((m_fRotX > 360.0f) || (m_fRotX < -360.0f))
			{
				m_fRotX = 0.0f;
			}
			m_fRotY += (float)0.5f * diffX;

			if ((m_fRotY > 360.0f) || (m_fRotY < -360.0f))
			{
				m_fRotY = 0.0f;
			}
		}

		// Right mouse button DOWN, pan Z direction
		else if (nFlags & MK_RBUTTON)
		{
			//m_fZoom -= (float)0.1f * diffY;
			m_fPosX += (float)1.0f * diffX;
			m_fPosY -= (float)1.0f * diffY;
		}

		// Middle mouse button DOWN, pan X,Y direction
		else if (nFlags & MK_MBUTTON)
		{
			//m_fPosX += (float)0.05f * diffX;
			//m_fPosY -= (float)0.05f * diffY;
		}
	}
	void OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
	{
		float fZoom = m_fZoom + 0.003f*zDelta;
		if(fZoom > 0)
			m_fZoom = fZoom;
	}
};