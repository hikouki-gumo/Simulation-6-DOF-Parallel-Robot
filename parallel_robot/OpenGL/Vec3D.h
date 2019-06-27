#ifndef _CVEC_H
#define _CVEC_H

//#include <float.h>
//#include <math.h>

class Vec3D {
public:
	//Constructors
	Vec3D() {x = 0; y = 0; z = 0;}
	//Vec3D(const Vec3D& s) {x = s.x; y = s.y; z = s.z;}
	Vec3D(const Vec3D& Vec) {*this = Vec;} //copy constructor
	Vec3D(double dx, double dy, double dz) {x = dx; y = dy; z = dz;}
	inline const Vec3D& operator=(const Vec3D& s) {	x = s.x; y = s.y; z = s.z; return *this; }; //overload equals
	bool IsValid() const {return !_isnan(x) && _finite(x) && !_isnan(y) && _finite(y) && !_isnan(z) && _finite(z);} //is a valid vector?

	//Attributes
	double x, y, z;

	//Operators
	inline Vec3D operator+(const Vec3D& s) const {return Vec3D(x+s.x, y+s.y, z+s.z);} //Plus
	inline Vec3D operator-(const Vec3D& s) const {return Vec3D(x-s.x, y-s.y, z-s.z);} //Minus
	inline Vec3D operator*(double f) const {return Vec3D(x*f, y*f, z*f);} //Multiply
	inline friend Vec3D operator*(double f, const Vec3D & v) {return Vec3D(v.x*f, v.y*f, v.z*f);} //if Vec3D is on right-hand side: (friend makes this global)
	inline Vec3D operator/(double f) const {return Vec3D(x/f, y/f, z/f);} //Divide
	inline Vec3D operator-() const {return Vec3D(-x, -y, -z);} //Negative
	inline bool operator==(const Vec3D& s) const {return (x==s.x && y==s.y && z==s.z);} //Is equal
	inline bool operator!=(const Vec3D& s) const {return (x!=s.x || y!=s.y || z!=s.z);} //Is not equal
	inline Vec3D& operator+=(const Vec3D& s) {x += s.x; y += s.y; z += s.z; return *this;} //add and set
	inline Vec3D& operator-=(const Vec3D& s) {x -= s.x; y -= s.y; z -= s.z; return *this;} //subract and set
	inline Vec3D& operator*=(double f) {x *= f; y *= f; z *= f; return *this;} //multiply and set
	inline Vec3D& operator/=(double f) {x /= f; y /= f; z /= f; return *this;} //subtract and set
	
	//Vector operations (change this object)
	inline double Normalize() {double l = sqrt(x*x+y*y+z*z); if (l > 0) {x /= l;y /= l;z /= l;} return l;} //normalizes this vector
	Vec3D Rot(Vec3D u, double a) {double ca = cos(a);	double sa = sin(a); return Vec3D((u.x*u.x + (1 - u.x*u.x)*ca) * x + (u.x*u.y*(1 - ca) + u.z*sa) * y + (u.z*u.x*(1 - ca) - u.y*sa) * z, (u.x*u.y*(1 - ca) - u.z*sa) * x + (u.y*u.y + (1 - u.y*u.y)*ca) * y + (u.y*u.z*(1 - ca) + u.x*sa) * z, (u.z*u.x*(1 - ca) + u.y*sa) * x + (u.y*u.z*(1 - ca) - u.x*sa) * y + (u.z*u.z + (1 - u.z*u.z)*ca) * z);} //rotates by arbitrary vector arbitrary amount
	void RotZ(double a) {double xt =  x*cos(a) - y*sin(a); double yt = x*sin(a) + y*cos(a); x = xt; y = yt;} //rotates about Z axis "a" radians
	void RotY(double a) {double xt =  x*cos(a) + z*sin(a); double zt = -x*sin(a) + z*cos(a); x = xt; z = zt;} //rotates about Y axis "a" radians
	void RotX(double a) {double yt =  y*cos(a) + z*sin(a); double zt = -y*sin(a) + z*cos(a); y = yt; z = zt;} //rotates about X axis "a" radians

	//Vector operations (don't change this object!)
	inline Vec3D Cross(const Vec3D & v) const {return Vec3D(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);} //Cross product
	inline double Dot(const Vec3D & v) const {return (x * v.x + y * v.y + z * v.z);} //Dot product
	inline Vec3D Abs() const {return Vec3D(fabs(x),fabs(y),fabs(z));} //Absolute value
	inline Vec3D Normalized() const {	double l = sqrt(x*x+y*y+z*z); return (l>0?(*this)/l:(*this));} //returns normalized vec
	inline Vec3D ProjXY() const {	return Vec3D(x,y,0);} //projection into the xy plane
	inline double Length() const {return sqrt(x*x+y*y+z*z);} //length of the vector
	inline double Length2() const {return (x*x+y*y+z*z);} //length squared of the vector
	inline Vec3D Min(const Vec3D& s) const {return Vec3D(__min(x,s.x),__min(y,s.y),__min(z,s.z));} //min vector od two
	inline Vec3D Max(const Vec3D& s) const {return Vec3D(__max(x,s.x),__max(y,s.y),__max(z,s.z));} //max vector of the two
	inline Vec3D Scale(const Vec3D & v) const {return Vec3D(x * v.x, y * v.y, z * v.z);} //scales by another vector
	double Dist(const Vec3D & v) const {return sqrt((v.x-x)*(v.x-x)+(v.y-y)*(v.y-y)+(v.z-z)*(v.z-z));} //distance from another vector
	double AlignWith(const Vec3D & target, Vec3D& rotax) 
	{
		Vec3D thisvec = Normalized(); 
		Vec3D targvec = target.Normalized(); 
		Vec3D rotaxis = thisvec.Cross(targvec); 
		if (rotaxis.Length2() == 0) 
		{
			rotaxis=target.ArbitraryNormal();
		} 
		rotax = rotaxis.Normalized(); 
		return acos(thisvec.Dot(targvec));
	} //returns vector (rotax) and amount (return val) to align this vector with target vector
	
	Vec3D ArbitraryNormal() const {Vec3D n = Normalized(); if (fabs(n.x) <= fabs(n.y) && fabs(n.x) <= fabs(n.z)){n.x = 1;} else if (fabs(n.y) <= fabs(n.x) && fabs(n.y) <= fabs(n.z)){n.y = 1;}	else {n.z = 1;}	return Cross(n).Normalized();} //generate arbitrary normal
};

#endif
