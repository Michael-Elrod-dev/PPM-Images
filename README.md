# PPM Image Reader and Writer  
This program reads a PPM (Portable Pixmap) image file, ignoring any comments, and writes the image to a new PPM file. The program is written in C.

## Usage  
Compile the program using the following command:
```
gcc -o ppmReadWrite driver.c ppmUtil.c
```
Run the program with the input PPM file and the desired output PPM file as command-line arguments:
```
./ppmReadWrite <input ppm file> <output ppm file>
```

## Program Structure  
The program is divided into two files:

- driver.c: Contains the main function which reads the input file, processes the image, and writes it to the output file.
- ppmUtil.c: Contains utility functions for reading and writing PPM image files, as well as handling memory allocation and comments.

## Utility Functions
- void ckComment(FILE* fp): Checks for comments in the PPM file and ignores them.
- void readHeader(FILE* fp, header_t* header): Reads the header information from the PPM file.
- pixel_t* readPixels(FILE* fp, header_t header): Reads the pixel data from the PPM file.
- void writeHeader(FILE* fp, header_t header): Writes the header information to the output PPM file.
- void writePixels(FILE* fp, pixel_t* pixels, header_t header): Writes the pixel data to the output PPM file.
- pixel_t* read(FILE* fp, header_t* header): Reads the entire PPM image, including header and pixel data.
- void write(FILE* fp, header_t header, pixel_t* pixels): Writes the entire PPM image, including header and pixel data.
- pixel_t* allocatePixMemory(header_t header): Allocates memory for the pixel data based on the image dimensions.
- void freeMemory(pixel_t* pixels): Frees the allocated memory for pixel data.
