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

#include "files.h"

RawFile::RawFile(unsigned int w, unsigned int h, unsigned int d) :width(w), height(h), depth(d) {
	// allocate enough memory for data here
	totalSize = width * height * depth;
	data = new byte[totalSize];
	scalardata = new float[totalSize];
}

RawFile::~RawFile() {
	if (data != nullptr) delete[] data;
	if (scalardata != nullptr) delete[] scalardata;
}

void RawFile::normalize() {
	// find the max value
	byte max_val = *(std::max_element(data, data + totalSize));
	std::transform(data, data + totalSize, scalardata, [max_val](byte val) { return ((float)val / (float)max_val); });		//use lambda function
}

// file loader class
void FileLoader::loadFromRaw(const std::string& filename, RawFile& rf) const {
	std::ifstream ifile(filename);
	if (!ifile.bad()) {
		// read the file for file size
		// NOTE: its assumed input file has no specific fields indicating its size. Its just raw data
		//       So we read so many bytes and close stream
		ifile.read(rf.data, rf.totalSize);
		ifile.close();
		rf.normalize();			// call normalize to finish our required work
	}
	else {
		std::cerr << "Invalid RAW file\n Please check\n";
	}
	
}