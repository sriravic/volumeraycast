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
	// return the value

}

unsigned int VoxelRegion::getCell(unsigned int x, unsigned int y, unsigned int z) const { 
	if (x < )
	return x + y * width + z * width * height; 
}

bool VoxelRegion::isOut(const Vector3& V) const {
	
}