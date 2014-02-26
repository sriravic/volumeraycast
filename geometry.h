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

#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

class Ray
{
public:
	Ray() = default;
	Ray(const Vector3& origin, const Vector3& direction, float tmin = 0.0f, float tmax = FLT_MAX) {
		this->origin = origin;
		this->direction = direction;
		this->tmax = tmax;
		this->tmin = tmin;
	};
	Ray(const Ray& R);

	Vector3 operator() (float t) const {
		return origin + direction * t;
	}

	Vector3 origin, direction;
	float tmin, tmax;

};

class Bbox
{
public:
	Bbox() :bmin(FLT_MAX), bmax(-FLT_MAX) {}
	Bbox(const Vector3& min, const Vector3& max) :bmin(min), bmax(max){}
	Bbox(const Bbox& B) { bmin = B.bmin; bmax = B.bmax; }

	// ray-box intersection
	bool intersect(const Ray& R) {
		Vector3 inv_dir = 1.0f / R.direction;
		
	}
	
	Vector3 bmin, bmax;
};




#endif