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
#include "voxelregion.h"

VoxelRegion::VoxelRegion(const RawFile& rf):data(rf.scalardata) {
	width = rf.width; height = rf.height; depth = rf.depth;
	voxels.resize(width * height * depth);
}

void VoxelRegion::prepare() {
	// we create a cube of dimension of from [0 , dim_max] on all three dimensions
	// we create grid dimensions from the raw file 
	// and we assign the grid points as centers to the voxels
	// also we then assign data to the voxels here from the normalized 
	unsigned int idx = 0;
	for (unsigned int z = 0; z < depth; z++) {
		for (unsigned int y = 0; y < height; y++) {
			for (unsigned int x = 0; x < width; x++) {
				voxels[idx].location = Vector3(x, y, z);
				voxels[idx].scalardata = data[idx];
				idx++;
			}
		}
	}
}

float VoxelRegion::interpolate(const Vector3& V) const {
	// we find first which cell the point is in.
	//first get a floor of all the x,y,z coords to get the nearest cell
	unsigned int x = (unsigned int)floor(V.x);
	unsigned int y = (unsigned int)floor(V.y);
	unsigned int z = (unsigned int)floor(V.z);
	
	// get the 8 corners of the cell
	// check for corner cases
	unsigned int v00 = getCell(x, y, z);
	unsigned int v01 = getCell(x + 1, y, z);
	unsigned int v02 = getCell(x + 1, y + 1, z);
	unsigned int v03 = getCell(x, y + 1, z);
	unsigned int v04 = getCell(x, y, z + 1);
	unsigned int v05 = getCell(x + 1, y, z + 1);
	unsigned int v06 = getCell(x + 1, y + 1, z + 1);
	unsigned int v07 = getCell(x, y + 1, z + 1);

	// linearly interpolate with all the 8 corners
	float w00 = (V - voxels[v00].location).length();
	float w01 = (V - voxels[v01].location).length();
	float w02 = (V - voxels[v02].location).length();
	float w03 = (V - voxels[v03].location).length();
	float w04 = (V - voxels[v04].location).length();
	float w05 = (V - voxels[v05].location).length();
	float w06 = (V - voxels[v06].location).length();
	float w07 = (V - voxels[v07].location).length();
	float totalWeight = w00 + w01 + w02 + w03 + w04 + w05 + w06 + w07;
	// normalize
	w00 /= totalWeight;
	w01 /= totalWeight;
	w02 /= totalWeight;
	w03 /= totalWeight;
	w04 /= totalWeight;
	w05 /= totalWeight;
	w06 /= totalWeight;
	w07 /= totalWeight;

	// return the value
	return voxels[v00].scalardata * w00 + voxels[v01].scalardata * w01 + voxels[v02].scalardata * w02 +
		voxels[v03].scalardata * w03 + voxels[v04].scalardata * w04 + voxels[v05].scalardata * w05 +
		voxels[v06].scalardata * w06 + voxels[v07].scalardata * w07;
}

// Its upto getCell to check the boundaries and give the correct value
// callers don't need to validate boundary conditions
unsigned int VoxelRegion::getCell(unsigned int x, unsigned int y, unsigned int z) const { 
	if (x < 0) x = 0; if (y < 0) y = 0; if (z < 0) z = 0;
	if (x > width) x = width; if (y > height) y = height; if (z > depth) z = depth;
	return x + y * width + z * width * height; 
}

// NOTE: not complete function
// to be completed. Have to check the conditions correctly before updating this function
bool VoxelRegion::isOut(const Vector3& V) const {
	return true;
}