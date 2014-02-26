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
#include "custom_math.h"

Vector3::Vector3(float a, float b, float c) :x(a), y(b), z(c) {}
Vector3::Vector3(float a) : Vector3(a, a, a) {}
Vector3::Vector3(const Vector3& V) {
	x = V.x; y = V.y; z = V.z;
}

void Vector3::operator= (const Vector3& V) {
	x = V.x; y = V.y; z = V.z;
}

Vector3 Vector3::operator- () const { return Vector3(-x, -y, -z); }
Vector3 Vector3::operator+ (const Vector3& V) const { return Vector3(x + V.x, y + V.y, z + V.z); }
Vector3 Vector3::operator- (const Vector3& V) const { return Vector3(x - V.x, y - V.y, z - V.z); }
Vector3 Vector3::operator* (float k) const { return Vector3(x*k, y*k, z*k); }
Vector3 Vector3::operator/ (float k) const {
	float invk = 1.0f / k;
	return *this * invk;
}

Vector3& Vector3::operator+= (const Vector3& V) { 
	x += V.x; y += V.y; z += V.z;
	return *this;
}

Vector3& Vector3::operator-= (const Vector3& V) {
	x -= V.x; y -= V.y; z -= V.z;
	return *this;
}

Vector3& Vector3::operator*= (float k) {
	x *= k; y *= k; z *= k;
	return *this;
}

Vector3& Vector3::operator/= (float k) {
	float invk = 1.0f / k;
	x *= invk; y *= invk; z *= invk;
	return *this;
}

float Vector3::length2() const { return x*x + y*y + z*z; }
float Vector3::length() const { return sqrtf(length2()); }