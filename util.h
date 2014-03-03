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
#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>
#include <fstream>
#include <iostream>
#include "custom_math.h"
#include "geometry.h"

class PpmFileWriter
{
public:
	PpmFileWriter() = default;
	~PpmFileWriter() = default;

	void writePpmFile(const std::string& opfile, char* rgb, unsigned int width, unsigned int height);
};

class Camera
{
public:
	unsigned int width, height;		// film width and height
	Vector3             position;	// camera position

	virtual Ray generateRay(unsigned int x, unsigned int y) = 0;		// generate ray for coords on image plane
};

// perspective projection
class PerspectiveCamera : public Camera
{
public:
	Vector3 up, lookat;				// required for projective camera
	virtual Ray generateRay(unsigned int x, unsigned int y);
};

// parallel projection.
// simpler camera model
class OrthographicCamera : public Camera
{
public:
	OrthographicCamera() = default;
	OrthographicCamera(const Vector3& position, unsigned int width, unsigned int height);
	OrthographicCamera(const OrthographicCamera& C);

	virtual Ray generateRay(unsigned int x, unsigned int y);

};


// some util functions
inline float lerp(float val1, float val2, float t) { return val1 + t*(val2 - val1); }




#endif