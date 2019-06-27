#ifndef _STL_
#define _STL_

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#include <string>
#include <vector>
#include "Vec3D.h"
#include "glut/glut.h"

//structure to hold each facet
struct CFacet {
	CFacet() {}
//	CFacet(const CVec& an, const CVec& av1, const CVec& av2, const CVec& av3) : n(an), v1(av1), v2(av2), v3(av3) {}
	CFacet(const Vec3D& an, const Vec3D& av1, const Vec3D& av2, const Vec3D& av3) { n = an; v[0] = av1; v[1] = av2; v[2] = av3;}
	CFacet(const CFacet& p) { v[0]=p.v[0]; v[1]=p.v[1]; v[2]=p.v[2]; n=p.n;}
	Vec3D n; //normal
	Vec3D v[3]; //vertices
};

class CSTL_File
{
public:
	CSTL_File(void);
	~CSTL_File(void);

	CSTL_File(CSTL_File& s);
	CSTL_File& operator=(const CSTL_File& s);

	std::string ObjectName;
	bool Load(std::string filename, const Vec3D & offset = Vec3D());
	bool Save(std::string filename, bool Binary = true) const;

	void ComputeBoundingBox(Vec3D& pmin, Vec3D& pmax);

	std::vector<CFacet> Facets;

	void Clear() { Facets.clear(); ObjectName = "Default";} // clear/reset the list of trianges
	int Size() const { return (int)Facets.size(); }

	void AddFacet(const Vec3D& n, const Vec3D& v1, const Vec3D& v2, const Vec3D& v3) {Facets.push_back(CFacet(n,v1,v2,v3));	}
	void AddFacet(float nx, float ny, float nz, float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z){ AddFacet(Vec3D(nx, ny, nz), Vec3D(v1x,v1y,v1z), Vec3D(v2x,v2y,v2z), Vec3D(v3x,v3y,v3z)); }

public:

	// file i/o
	bool LoadBinary(std::string filename, const Vec3D & offset = Vec3D());
	bool LoadAscii(std::string filename, const Vec3D & offset = Vec3D());



	void Draw(bool bModelhNormals, bool bShaded);

	//add a facet

	

	//manipulation...
	void Rotate(Vec3D ax, double a);
	void RotX(double a);
	void RotY(double a);
	void RotZ(double a);
	void Scale(Vec3D d);
	void Translate(const Vec3D & d);
};

#endif