#include <iostream>

class Vector3d;


class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{ }

	void print() const
	{
		std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v);
	
};

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z)
		: m_x{x}, m_y{y}, m_z{z}
	{
	}

	void print() const
	{
		std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}
    // make Point3d class a friend of Vector3d
    friend class Point3d;
};

void Point3d::moveByVector(const Vector3d& v)
{
    m_x = m_x + v.m_x;
    m_y = m_y + v.m_y;
    m_z = m_z + v.m_z;
    // implement this function as a friend of class Vector3d
    
}

int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}