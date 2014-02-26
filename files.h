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

#ifndef __FILES_H__
#define __FILES_H__

#include <string>

typedef unsigned char byte;

// Raw files basically are implemented as byte arrays with a particular width, height and depth
// NOTE: assuming 8-bits for raw file byte. Change accordinly for different filetypes
class RawFile
{
public:
	RawFile() = default;
	RawFile(unsigned int width, unsigned int height, unsigned int depth);
	~RawFile();

	byte* data;
	float* scalars;							// we can normalize the values of the entire raw file into a [0-1] range
	unsigned int width, height, depth;
	void normalize();
};

// Implements a bunch of methods to load different types of volumetric files
class FileLoader
{
public:
	FileLoader() = default;
	~FileLoader() = default;

	void loadFromRaw(const std::string& filename, RawFile& rf);
};


#endif