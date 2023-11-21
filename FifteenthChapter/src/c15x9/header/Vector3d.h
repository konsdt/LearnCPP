#ifndef VECTOR3D
#define VECTOR3D

#include "Point3d.h"

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z);


	void print() const;
    // make Point3d class a friend of Vector3d
    friend class Point3d;
};


#endif