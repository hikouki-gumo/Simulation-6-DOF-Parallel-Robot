#pragma once

//#include <float.h>
//#include <math.h>

#define PI 3.1415926535897932384626433832795

class CVector4D;
class CMatrix4D;

class CVector4D
{
	double m_dData[4];
public:
	CVector4D()
	{
		for (int i=0; i<3; i++) 
			m_dData[i] = 0; 
		m_dData[3] = 1;
	}
	CVector4D(double* vector)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = vector[i];
	}
	CVector4D(double x, double y, double z, double a=1)
	{
		m_dData[0]= x; 
		m_dData[1]=y; 
		m_dData[2]=z; 
		m_dData[3]=a;
	}
	CVector4D(const CVector4D& vector)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = vector.m_dData[i];
	}
	virtual~CVector4D(){}
public:
	const double* getData() const
	{
		return m_dData;
	}
	float* getData_f() const
	{
		float* temp = new float[4];
		for (int i=0; i<4; i++) 
			temp[i] = (float)m_dData[i]; 
		return temp;
	}
	void setData(const double* &vector)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = vector[i];
	}
	void setData(double x, double y, double z, double a=1)
	{
		m_dData[0]= x; 
		m_dData[1]=y; 
		m_dData[2]=z; 
		m_dData[3]=a;
	}
	void move(double  x, double y, double z, double a=0)
	{
		m_dData[0]+=x; 
		m_dData[1]+=y;
		m_dData[2]+=z;
		m_dData[3]+=a;
	}
	void scale(double _scale)
	{
		for (int i=0;i<4;i++)
			m_dData[i]*=_scale;
	}
	CVector4D& normal()
	{
		double temp = sqrt(m_dData[0]*m_dData[0]+m_dData[1]*m_dData[1]+m_dData[2]*m_dData[2]); 
		if (temp !=0)
		{
			for (int i=0; i<3; i++) 
				m_dData[i]/=temp;
			m_dData[3] = 1;
		}
		return *this;
	}
	double module()const
	{
		return sqrt(m_dData[0]*m_dData[0]+m_dData[1]*m_dData[1]+m_dData[2]*m_dData[2]); 
	}
public:
	bool operator==(const CVector4D& othervector) const
	{
		for (int i=0; i<4; i++)
			if (m_dData[i] != othervector.m_dData[i]) 
				return false;
		return true;
	}
	bool operator!=(const CVector4D& othervector) const
	{
		return !(*this==othervector);
	}
public:
	CVector4D& operator=(const CVector4D& vector)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = vector.m_dData[i]; 
		return *this;
	}
	double& operator[](int index)
	{
		return m_dData[index];
	}
	double operator[](int index) const
	{
		return m_dData[index];
	}
	CVector4D operator+(const CVector4D& vector) const
	{
		CVector4D temp;
		for (int i=0; i<4; i++) 
			temp.m_dData[i] = m_dData[i]+vector.m_dData[i]; 
		return temp;
	}
	CVector4D operator-(const CVector4D& vector) const
	{
		CVector4D temp;
		for (int i=0; i<4; i++) 
			temp.m_dData[i] = m_dData[i]-vector.m_dData[i]; 
		return temp;
	}
	double operator*(const CVector4D& vector) const
	{
		double temp=0;
		for (int i=0; i<4; i++) 
			temp+=m_dData[i]*vector.m_dData[i]; 
		return temp;
	}
	CVector4D operator*(double _scale) const
	{
		return CVector4D(m_dData[0]*_scale, m_dData[1]*_scale, m_dData[2]*_scale, m_dData[3]*_scale);
	}
	friend CVector4D operator*(double _scale, const CVector4D& vector)
	{
		return CVector4D(_scale*vector.m_dData[0], _scale*vector.m_dData[1], _scale*vector.m_dData[2], _scale*vector.m_dData[3]);
	}
	CVector4D operator/(double _scale) const
	{
		if (_scale==0) return CVector4D();
		return CVector4D(m_dData[0]/_scale, m_dData[1]/_scale, m_dData[2]/_scale, m_dData[3]/_scale);
	}
	CVector4D& operator+=(const CVector4D& vector)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] += vector.m_dData[i]; 
		return *this;
	}
	CVector4D& operator-=(const CVector4D& vector)
	{ 
		for (int i=0; i<4; i++) 
			m_dData[i] -= vector.m_dData[i]; 
		return *this;
	}
	CVector4D& operator*=(double _scale)
	{
		for (int i=0; i<4; i++) 
			m_dData[i]*=_scale; 
		return *this;
	}
	CVector4D& operator/=(double _scale)
	{
		if (_scale !=0)
			for (int i=0; i<4; i++) 
				m_dData[i]/=_scale;
		return *this;
	}
/*	bool operator==(const CVector4D& vector) const{
		return ((m_dData[0]==vector.m_dData[0])&&
			(m_dData[1]==vector.m_dData[1])&&
			(m_dData[2]==vector.m_dData[2])&&
			(m_dData[3]==vector.m_dData[3]));}
*/	CVector4D operator-() const
	{
		return CVector4D(-m_dData[0], -m_dData[1], -m_dData[2], -m_dData[3]);
	}
	CVector4D& operator!()
	{
		for(int i=0;i<4;i++) 
			m_dData[i]=-m_dData[i]; return *this;
	}
	CVector4D directMultiplies(const CVector4D& vector) const
	{
		CVector4D temp;
		temp.m_dData[0] = m_dData[1]*vector.m_dData[2] - m_dData[2]*vector.m_dData[1];
		temp.m_dData[1] = m_dData[2]*vector.m_dData[0] - m_dData[0]*vector.m_dData[2];
		temp.m_dData[2] = m_dData[0]*vector.m_dData[1] - m_dData[1]*vector.m_dData[0];
		return temp;
	}
	friend CMatrix4D;
public:
	friend ostream &operator<<(ostream &out, const CVector4D &Vector)
	{
		out<<Vector[0]<<"	"<<Vector[1]<<"	"<<Vector[2]<<"	"<<Vector[3]<<endl;
		return out;
	}
	friend istream &operator>>(istream &is, CVector4D &Vector)
	{
		is>>Vector[0]>>Vector[1]>>Vector[2]>>Vector[3];
		string temp;
		getline(is, temp);
		return is;
	}
};

class CMatrix4D{
protected:
	CVector4D m_dData[4];
	
public:
	CMatrix4D()
	{
		m_dData[0].setData(1, 0, 0, 0); 
		m_dData[1].setData(0, 1, 0, 0); 
		m_dData[2].setData(0, 0, 1, 0); 
		m_dData[3].setData(0, 0, 0, 1);
	}
	CMatrix4D(const double* &_matrix)
	{
		int index=0;
		for (int i=0;i<4; i++)
			for (int j=0; j<4; j++, index++)
				m_dData[i][j] = _matrix[index];
	}
	CMatrix4D(const CVector4D& _v0, const CVector4D& _v1, const CVector4D& _v2, const CVector4D& _v3 = CVector4D(0, 0, 0, 1))
	{
		m_dData[0] = _v0;
		m_dData[1] = _v1;
		m_dData[2] = _v2;
		m_dData[3] = _v3;
	}
	CMatrix4D(const CMatrix4D& _matrix)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = _matrix.m_dData[i];
	}
	virtual~CMatrix4D(){}
public:
	void setData(const double* &_matrix)
	{
		int index=0;
		for (int i=0;i<4; i++)
			for (int j=0; j<4; j++, index++)
				m_dData[i][j] = _matrix[index];
	}
	void setData(const CMatrix4D& _matrix)
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = _matrix.m_dData[i];
	}
	void setData(const CVector4D& _v0, const CVector4D& _v1, const CVector4D& _v2, const CVector4D& _v3 = CVector4D(0, 0, 0, 1))
	{
		m_dData[0] = _v0;
		m_dData[1] = _v1;
		m_dData[2] = _v2;
		m_dData[3] = _v3;
	} 
	double** getData() const
	{
		int i, j;
		double** temp;
		temp = new double*[4];
		for (i=0; i<4; i++)
			temp[i] = new double[4];
		for (i=0; i<4; ++i)
			for (j=0; j<4; ++j)
				temp[i][j] = m_dData[i][j];
			return temp;
	}
	double* getData_d() const{
		double* temp = new double [16];
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				temp[i*4+j]=m_dData[i][j];
		return temp;}
	float* getData_f() const
	{
		float* temp = new float[16];
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				temp[i*4+j]=float(m_dData[i][j]);
		return temp;
	}
	void reset()
	{
		for(int i=0; i<4;++i){
			for(int j=0;j<4;++j)
				m_dData[i][j]=0;
			m_dData[i][i]=1;
		}
	}
public:
	double det() const
	{
		double	m_dData00 = m_dData[0][0], m_dData01 = m_dData[0][1], m_dData02 = m_dData[0][2], m_dData03 = m_dData[0][3],
				m_dData10 = m_dData[1][0], m_dData11 = m_dData[1][1], m_dData12 = m_dData[1][2], m_dData13 = m_dData[2][3],
				m_dData20 = m_dData[2][0], m_dData21 = m_dData[2][1], m_dData22 = m_dData[2][2], m_dData23 = m_dData[2][3],
				m_dData30 = m_dData[3][0], m_dData31 = m_dData[3][1], m_dData32 = m_dData[3][2], m_dData33 = m_dData[3][3];
		return (m_dData00*m_dData11*m_dData22*m_dData33-m_dData00*m_dData11*m_dData23*m_dData32-m_dData00*m_dData21*m_dData12*m_dData33+m_dData00*m_dData21*m_dData13*m_dData32+m_dData00*m_dData31*m_dData12*m_dData23-m_dData00*m_dData31*m_dData13*m_dData22-m_dData10*m_dData01*m_dData22*m_dData33+m_dData10*m_dData01*m_dData23*m_dData32+m_dData10*m_dData21*m_dData02*m_dData33-m_dData10*m_dData21*m_dData03*m_dData32-m_dData10*m_dData31*m_dData02*m_dData23+m_dData10*m_dData31*m_dData03*m_dData22+m_dData20*m_dData01*m_dData12*m_dData33-m_dData20*m_dData01*m_dData13*m_dData32-m_dData20*m_dData11*m_dData02*m_dData33+m_dData20*m_dData11*m_dData03*m_dData32+m_dData20*m_dData31*m_dData02*m_dData13-m_dData20*m_dData31*m_dData03*m_dData12-m_dData30*m_dData01*m_dData12*m_dData23+m_dData30*m_dData01*m_dData13*m_dData22+m_dData30*m_dData11*m_dData02*m_dData23-m_dData30*m_dData11*m_dData03*m_dData22-m_dData30*m_dData21*m_dData02*m_dData13+m_dData30*m_dData21*m_dData03*m_dData12);
	}

	double det_hemogenous() const
	{
		return 1;
	}

	CMatrix4D inverse() const
	{
		CMatrix4D temp_matrix;
		double	m_dData00 = m_dData[0][0], m_dData01 = m_dData[0][1], m_dData02 = m_dData[0][2], m_dData03 = m_dData[0][3],
				m_dData10 = m_dData[1][0], m_dData11 = m_dData[1][1], m_dData12 = m_dData[1][2], m_dData13 = m_dData[2][3],
				m_dData20 = m_dData[2][0], m_dData21 = m_dData[2][1], m_dData22 = m_dData[2][2], m_dData23 = m_dData[2][3],
				m_dData30 = m_dData[3][0], m_dData31 = m_dData[3][1], m_dData32 = m_dData[3][2], m_dData33 = m_dData[3][3];
		double determinant = det();

		temp_matrix[0][0] =(m_dData11*m_dData22*m_dData33-m_dData11*m_dData23*m_dData32-m_dData21*m_dData12*m_dData33+m_dData21*m_dData13*m_dData32+m_dData31*m_dData12*m_dData23-m_dData31*m_dData13*m_dData22)/determinant;
		temp_matrix[0][1] =(-m_dData01*m_dData22*m_dData33+m_dData01*m_dData23*m_dData32+m_dData21*m_dData02*m_dData33-m_dData21*m_dData03*m_dData32-m_dData31*m_dData02*m_dData23+m_dData31*m_dData03*m_dData22)/determinant;
		temp_matrix[0][2] =(m_dData01*m_dData12*m_dData33-m_dData01*m_dData13*m_dData32-m_dData11*m_dData02*m_dData33+m_dData11*m_dData03*m_dData32+m_dData31*m_dData02*m_dData13-m_dData31*m_dData03*m_dData12)/determinant;
		temp_matrix[0][3] =(-m_dData01*m_dData12*m_dData23+m_dData01*m_dData13*m_dData22+m_dData11*m_dData02*m_dData23-m_dData11*m_dData03*m_dData22-m_dData21*m_dData02*m_dData13+m_dData21*m_dData03*m_dData12)/determinant;
		temp_matrix[1][0] =(-m_dData10*m_dData22*m_dData33+m_dData10*m_dData23*m_dData32+m_dData20*m_dData12*m_dData33-m_dData20*m_dData13*m_dData32-m_dData30*m_dData12*m_dData23+m_dData30*m_dData13*m_dData22)/determinant;
		temp_matrix[1][1] =(m_dData00*m_dData22*m_dData33-m_dData00*m_dData23*m_dData32-m_dData20*m_dData02*m_dData33+m_dData20*m_dData03*m_dData32+m_dData30*m_dData02*m_dData23-m_dData30*m_dData03*m_dData22)/determinant;
		temp_matrix[1][2] =(-m_dData00*m_dData12*m_dData33+m_dData00*m_dData13*m_dData32+m_dData10*m_dData02*m_dData33-m_dData10*m_dData03*m_dData32-m_dData30*m_dData02*m_dData13+m_dData30*m_dData03*m_dData12)/determinant;
		temp_matrix[1][3] =(m_dData00*m_dData12*m_dData23-m_dData00*m_dData13*m_dData22-m_dData10*m_dData02*m_dData23+m_dData10*m_dData03*m_dData22+m_dData20*m_dData02*m_dData13-m_dData20*m_dData03*m_dData12)/determinant;
		temp_matrix[2][0] =(m_dData10*m_dData21*m_dData33-m_dData10*m_dData23*m_dData31-m_dData20*m_dData11*m_dData33+m_dData20*m_dData13*m_dData31+m_dData30*m_dData11*m_dData23-m_dData30*m_dData13*m_dData21)/determinant;
		temp_matrix[2][1] =(-m_dData00*m_dData21*m_dData33+m_dData00*m_dData23*m_dData31+m_dData20*m_dData01*m_dData33-m_dData20*m_dData03*m_dData31-m_dData30*m_dData01*m_dData23+m_dData30*m_dData03*m_dData21)/determinant;
		temp_matrix[2][2] =(m_dData00*m_dData11*m_dData33-m_dData00*m_dData13*m_dData31-m_dData10*m_dData01*m_dData33+m_dData10*m_dData03*m_dData31+m_dData30*m_dData01*m_dData13-m_dData30*m_dData03*m_dData11)/determinant;
		temp_matrix[2][3] =(-m_dData00*m_dData11*m_dData23+m_dData00*m_dData13*m_dData21+m_dData10*m_dData01*m_dData23-m_dData10*m_dData03*m_dData21-m_dData20*m_dData01*m_dData13+m_dData20*m_dData03*m_dData11)/determinant;
		temp_matrix[3][0] =(-m_dData10*m_dData21*m_dData32+m_dData10*m_dData22*m_dData31+m_dData20*m_dData11*m_dData32-m_dData20*m_dData12*m_dData31-m_dData30*m_dData11*m_dData22+m_dData30*m_dData12*m_dData21)/determinant;
		temp_matrix[3][1] =(m_dData00*m_dData21*m_dData32-m_dData00*m_dData22*m_dData31-m_dData20*m_dData01*m_dData32+m_dData20*m_dData02*m_dData31+m_dData30*m_dData01*m_dData22-m_dData30*m_dData02*m_dData21)/determinant;
		temp_matrix[3][2] =(-m_dData00*m_dData11*m_dData32+m_dData00*m_dData12*m_dData31+m_dData10*m_dData01*m_dData32-m_dData10*m_dData02*m_dData31-m_dData30*m_dData01*m_dData12+m_dData30*m_dData02*m_dData11)/determinant;
		temp_matrix[3][3] =(m_dData00*m_dData11*m_dData22-m_dData00*m_dData12*m_dData21-m_dData10*m_dData01*m_dData22+m_dData10*m_dData02*m_dData21+m_dData20*m_dData01*m_dData12-m_dData20*m_dData02*m_dData11)/determinant;
		return temp_matrix;
	}
	CMatrix4D inverse_hemogenous() const
	{
		CMatrix4D temp_matrix;
		double temp;
		for (int i=0; i<3; i++)
		{
			temp=0;
			for (int j=0; j<3; j++)
			{
				temp_matrix[i][j]=m_dData[j][i];
				temp-=m_dData[j][i]*m_dData[j][3];
			}
			temp_matrix.m_dData[i][3]=temp;
		}
		return temp_matrix;
	}
	CMatrix4D operator/(const CMatrix4D& other_matrix) const{
		if ((*this)==other_matrix){ 
			return CMatrix4D();}
		return (*this)*(other_matrix.inverse());}
	CMatrix4D transpose() const{
		CMatrix4D temp_matrix;
		for (int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				temp_matrix[i][j]=m_dData[j][i];
		return temp_matrix;}
public:
	bool operator==(const CMatrix4D& other_matrix) const
	{
		for (int i=0; i<4; ++i)
			if (m_dData[i] != other_matrix.m_dData[i])
				return false;
			return true;
	}
	bool operator !=(const CMatrix4D& other_matrix) const
	{
		return !(*this==other_matrix);
	}
public:
	CMatrix4D& operator=(const CMatrix4D& _matrix)
	{
		for (int i=0; i<4; i++)
			m_dData[i]=_matrix.m_dData[i]; 
		return *this;
	}
	CVector4D& operator[](int index)
	{
		return m_dData[index];
	}
	CVector4D operator[](int index) const
	{
		return m_dData[index];
	}
	CMatrix4D operator+(const CMatrix4D& _matrix) const
	{
		CMatrix4D temp;
		for (int i=0; i<4; i++)
			temp.m_dData[i]=m_dData[i]+_matrix.m_dData[i]; 
		return temp;
	}
	CMatrix4D& operator+=(const CMatrix4D& _matrix)
	{
		for (int i=0; i<4; i++)
			m_dData[i]+=_matrix.m_dData[i];
		return *this;
	}
	CMatrix4D operator-(const CMatrix4D& _matrix) const
	{
		CMatrix4D temp;
		for (int i=0; i<4; i++)
			temp.m_dData[i]=m_dData[i]+_matrix.m_dData[i]; 
		return temp;
	}
	CMatrix4D& operator-=(const CMatrix4D& _matrix)
	{
		for (int i=0; i<4; i++)
			m_dData[i]-=_matrix.m_dData[i];
		return *this;
	}
	CMatrix4D operator*(const CMatrix4D& _matrix) const
	{
		CMatrix4D temp;
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
			{	
				temp[i][j] = 0;
				for (int k=0; k<4; k++)
					temp[i][j]+=m_dData[i].m_dData[k]*_matrix.m_dData[k].m_dData[j];
			}
		return temp;
	}
	CVector4D operator*(const CVector4D& vector) const
	{
		CVector4D vect;
		for (int i=0; i<4; i++) 
			vect[i]=m_dData[i]*vector;
		return vect;
	}
	CMatrix4D operator*(double _scale) const
	{
		CMatrix4D _matrix;
		for (int i=0; i<4; i++) 
			_matrix.m_dData[i]=m_dData[i]*_scale;
		return _matrix;
	}
	CMatrix4D& operator*=(double _scale)
	{
		for (int i=0; i<4; i++) 
			m_dData[i]*=_scale;
		return *this;
	}
	friend CMatrix4D operator*(double _scale, const CMatrix4D& _matrix)
	{
		CMatrix4D _mat;
		for (int i=0; i<4; i++) 
			_mat.m_dData[i]=_matrix.m_dData[i]*_scale;
		return _mat;
	}
	CMatrix4D operator/(double _scale) const
	{
		if (_scale==0) return CMatrix4D();
		CMatrix4D _matrix;
		for (int i=0; i<4; i++) 
			_matrix.m_dData[i]=m_dData[i]/_scale;
		return _matrix;
	}
	CMatrix4D& operator/=(double _scale)
	{
		for (int i=0; i<4; i++) 
			m_dData[i]/=_scale;
		return *this;
	}
	CMatrix4D operator-() const
	{
		CMatrix4D _matrix;
		for (int i=0; i<4; i++)
			_matrix.m_dData[i] = -m_dData[i];
		return _matrix;
	}
	CMatrix4D& operator!()
	{
		for (int i=0; i<4; i++) 
			m_dData[i] = -m_dData[i]; return *this;
	}
public:
	CMatrix4D(double theta, double alpha, double a, double d)
	{
		m_dData[0].setData(cos(theta), -sin(theta)*cos(alpha), sin(theta)*sin(alpha), a*cos(theta));
		m_dData[1].setData(sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta));
		m_dData[2].setData(0, sin(alpha), cos(alpha), d);
		m_dData[3].setData(0, 0, 0, 1);
	}
	CMatrix4D(int ID, double value)
	{
		switch(ID)
		{
		case 0:{//rotate around axis x
			m_dData[0].setData(1, 0, 0, 0);
			m_dData[1].setData(0, cos(value), -sin(value), 0);
			m_dData[2].setData(0, sin(value), cos(value), 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 1:{//rotate around axis y
			m_dData[0].setData(cos(value), 0, sin(value), 0);
			m_dData[1].setData(0, 1, 0, 0);
			m_dData[2].setData(-sin(value), 0, cos(value), 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 2:{//rotate around axis z
			m_dData[0].setData(cos(value), -sin(value), 0, 0);
			m_dData[1].setData(sin(value), cos(value), 0, 0);
			m_dData[2].setData(0, 0, 1, 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 3:{//translate belong axis x
			m_dData[0].setData(1, 0, 0, value);
			m_dData[1].setData(0, 1, 0, 0);
			m_dData[2].setData(0, 0, 1, 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 4:{//translate belong axis y
			m_dData[0].setData(1, 0, 0, 0);
			m_dData[1].setData(0, 1, 0, value);
			m_dData[2].setData(0, 0, 1, 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 5:{//translate belong axis z
			m_dData[0].setData(1, 0, 0, 0);
			m_dData[1].setData(0, 1, 0, 0);
			m_dData[2].setData(0, 0, 1, value);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		}
	}
	void setData(double theta, double alpha, double a, double d)
	{
		m_dData[0].setData(cos(theta), -sin(theta)*cos(alpha), sin(theta)*sin(alpha), a*cos(theta));
		m_dData[1].setData(sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta));
		m_dData[2].setData(0, sin(alpha), cos(alpha), d);
		m_dData[3].setData(0, 0, 0, 1);
	}
	void setData(int ID, double value)
	{
		switch(ID)
		{
		case 0:{//rotate around axis x
			m_dData[0].setData(1, 0,          0,           0);
			m_dData[1].setData(0, cos(value), -sin(value), 0);
			m_dData[2].setData(0, sin(value), cos(value),  0);
			m_dData[3].setData(0, 0,          0,           1);
			break;
			   }
		case 1:{//rotate around axis y
			m_dData[0].setData(cos(value),  0, sin(value), 0);
			m_dData[1].setData(0,           1, 0,          0);
			m_dData[2].setData(-sin(value), 0, cos(value), 0);
			m_dData[3].setData(0,           0, 0,          1);
			break;
			   }
		case 2:{//rotate around axis z
			m_dData[0].setData(cos(value), -sin(value), 0, 0);
			m_dData[1].setData(sin(value), cos(value),  0, 0);
			m_dData[2].setData(0,			 0,			  1, 0);
			m_dData[3].setData(0,			 0,			  0, 1);
			break;
			   }
		case 3:{//translate belong axis x
			m_dData[0].setData(1, 0, 0, value);
			m_dData[1].setData(0, 1, 0, 0);
			m_dData[2].setData(0, 0, 1, 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 4:{//translate belong axis y
			m_dData[0].setData(1, 0, 0, 0);
			m_dData[1].setData(0, 1, 0, value);
			m_dData[2].setData(0, 0, 1, 0);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		case 5:{//translate belong axis z
			m_dData[0].setData(1, 0, 0, 0);
			m_dData[1].setData(0, 1, 0, 0);
			m_dData[2].setData(0, 0, 1, value);
			m_dData[3].setData(0, 0, 0, 1);
			break;
			   }
		}
	}
	void setData_euler_rotation(const double phi, const double theta, const double psi)
	{
		m_dData[0][0] = cos(phi)*cos(theta)*cos(psi) - sin(phi)*sin(psi);
		m_dData[0][1] = -cos(phi)*cos(theta)*sin(psi)-sin(phi)*cos(psi);
		m_dData[0][2] = cos(phi)*sin(theta);
		m_dData[0][3] = 0;
		m_dData[1][0] = sin(phi)*cos(theta)*cos(psi)+cos(phi)*sin(psi);
		m_dData[1][1] = -sin(phi)*cos(theta)*sin(psi)+cos(phi)*cos(psi);
		m_dData[1][2] = sin(phi)*sin(theta);
		m_dData[1][3] = 0;
		m_dData[2][0] = -sin(theta)*cos(psi);
		m_dData[2][1] = sin(theta)*sin(psi);
		m_dData[2][2] = cos(theta);
		m_dData[2][3] = 0;
		m_dData[3][0]=m_dData[3][1]=m_dData[3][2] = 0;m_dData[3][3] = 1;}
	void setData_rotatevector(const double angle, const CVector4D& vector){
		if ((vector[0]==0)&&(vector[1]==0)&&(vector[2]==0)) return;
	}

public:
	CVector4D get_euler_rotation() const
	{
		double phi, theta, psi;
		double cphi, sphi;
		if ((m_dData[0][2]==0)&&(m_dData[1][2]==0)) phi=0;
		else phi=atan2(m_dData[0][2], m_dData[1][2]);
		sphi=sin(phi); cphi=cos(phi);
		theta=atan2(cphi*m_dData[0][2]+sphi*m_dData[1][2], m_dData[2][2]);
		psi = atan2(-sphi*m_dData[0][0]+cphi*m_dData[1][0], -sphi*m_dData[0][1]+cphi*m_dData[1][1]);
		return CVector4D(phi, theta, psi);
	}

	void get_rotatevector(double& phi, CVector4D&vector) const
	{
		phi=0;
		vector.setData(1, 0, 0);
		double sphi, cphi;
		cphi=(m_dData[0][0]+m_dData[1][1]+m_dData[2][2]-1)/2;
		sphi=sqrt(	(m_dData[2][1]-m_dData[1][2])*(m_dData[2][1]-m_dData[1][2])+
					(m_dData[0][2]-m_dData[2][0])*(m_dData[0][2]-m_dData[2][0])+
					(m_dData[1][0]-m_dData[0][1])*(m_dData[1][0]-m_dData[0][1]))/2;
		if ((sphi==0)&&(cphi==0)) return;
		phi=atan2(sphi, cphi);
		
		if (cphi==1)return;
		int sgn;
		if ((m_dData[2][1]-m_dData[1][2])==0) sgn=0;
		else if ((m_dData[2][1]-m_dData[1][2])>0) sgn=1; 
		else sgn=-1;
		vector[0] = sgn*sqrt((m_dData[0][0]-cphi)/(1-cphi));
		
		if ((m_dData[0][2]-m_dData[2][0])==0) sgn=0;
		else if ((m_dData[0][2]-m_dData[2][0])>0) sgn=1; 
		else sgn=-1;
		vector[1] = sgn*sqrt((m_dData[1][1]-cphi)/(1-cphi));
		
		if ((m_dData[1][0]-m_dData[0][1])==0) sgn=0;
		else if ((m_dData[1][0]-m_dData[0][1])>0) sgn=1; 
		else sgn=-1;
		vector[2] = sgn*sqrt((m_dData[2][2]-cphi)/(1-cphi));
		vector.normal();
	}
public:
	void apply_rotatevector(const CVector4D _scale = CVector4D(1, 1, 1)) const
	{
		if ((_scale[0]==0) || (_scale[1]==0) || (_scale[2]==0)) 
			return;
		glScaled(_scale[0], _scale[1], _scale[2]);
		glTranslated(m_dData[0][3], m_dData[1][3], m_dData[2][3]);
		CVector4D vector;
		double angle;
		get_rotatevector(angle, vector);
		glRotated(180*angle/PI, vector[0], vector[1], vector[2]);
		glScaled(1/_scale[0], 1/_scale[1], 1/_scale[2]);
	}

	void apply_rotate_euler(const CVector4D _scale = CVector4D(1, 1, 1)) const
	{
		if ((_scale[0]==0) || (_scale[1]==0) || (_scale[2]==0)) 
			return;
		glScaled(_scale[0], _scale[1], _scale[2]);
		CVector4D vector = get_euler_rotation();
		glTranslated(m_dData[0][3], m_dData[1][3], m_dData[2][3]);
		glRotated(180*vector[0]/PI, 0, 0, 1);
		glRotated(180*vector[1]/PI, 0, 1, 0);
		glRotated(180*vector[2]/PI, 0, 0, 1);
		glScaled(1/_scale[0], 1/_scale[1], 1/_scale[2]);
	}
public:
	friend ostream &operator<<(ostream &out, const CMatrix4D &matrix)
	{
		out<<matrix[0]<<matrix[1]<<matrix[2]<<matrix[3];
		return out;
	}
	friend istream &operator>>(istream &is, CMatrix4D &matrix)
	{
		is>>matrix[0]>>matrix[1]>>matrix[2]>>matrix[3];
		return is;
	}
};

typedef CVector4D CPoint4D;
