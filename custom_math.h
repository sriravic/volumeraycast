/**
The MIT License (MIT)

Copyright (c) [2014] [Srinath Ravichandran]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef __CUSTOM_MATH_H__
#define __CUSTOM_MATH_H__

#include <cmath>

class Vector3
{
public:
	Vector3() = default;
	Vector3(float a);
	Vector3(float x, float y, float z);
	Vector3(const Vector3& V);
	~Vector3() = default;

	Vector3 operator- (void) const;
	void operator= (const Vector3& V);

	Vector3 operator+ (const Vector3& V) const;
	Vector3 operator- (const Vector3& V) const;
	Vector3 operator* (float k) const;
	Vector3 operator/ (float k) const;

	Vector3& operator+= (const Vector3& V);
	Vector3& operator-= (const Vector3& V);
	Vector3& operator/= (float k);
	Vector3& operator*= (float k);

	friend Vector3 operator* (float k, const Vector3 &V) {
		return V * k;
	}
	friend Vector3 operator/ (float k, const Vector3& V) {
		return Vector3(k / V.x, k / V.y, k / V.z);
	}

	float length() const;
	float length2() const;
	
	float x, y, z;
};

inline float dot(const Vector3& A, const Vector3& B) {
	return A.x*B.x + A.y*B.y + A.z*B.z;
}

inline Vector3 cross(const Vector3& A, const Vector3& B) {
	return Vector3(A.y*B.z - A.z*B.y,
		A.z*B.x - A.x*B.z,
		A.x*B.y - A.y*B.x
		);
}


#endif