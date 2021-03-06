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
#ifndef __VOXEL_REGION_H__
#define __VOXEL_REGION_H__

#include <vector>
#include "custom_math.h"
#include "geometry.h"
#include "voxel.h"
#include "files.h"

// Voxel region encompasses all the voxels that are within the scene
class VoxelRegion
{
public:
	VoxelRegion() = default;
	VoxelRegion(const RawFile& rf);
	~VoxelRegion() = default;
	
	// function members
	float interpolate(const Vector3& V) const;		// given a point, we interpolate the value
	void prepare();
	bool isOut(const Vector3& V) const;				// checks if a location is out of the voxel region
	unsigned int getCell(unsigned int x, unsigned int y, unsigned int z) const;

	// data
	std::vector<Voxel> voxels;
	const float* const data;					// we have an immutable pointer to the original data. We cant change anything.
	unsigned int width, height, depth;
};


#endif