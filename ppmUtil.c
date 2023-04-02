#include "ppmUtil.h"

// Helper function to check for comments and ignore them.
void ckComment(FILE* fp) {
    int c;
    // Consume any whitespace
    while (isspace(c = fgetc(fp)));

    // Skip any comment lines.
    while (c == '#') {
        while (fgetc(fp) != '\n');
        while (isspace(c = fgetc(fp)));
    }

    // Put the non-comment character back into the file stream.
    ungetc(c, fp);
}

// Reads the header information from the PPM file.
void readHeader(FILE* fp, header_t* header) {
    fscanf(fp, "%2s", header->type);
    ckComment(fp);
    fscanf(fp, "%u", &header->width);
    ckComment(fp);
    fscanf(fp, "%u", &header->height);
    ckComment(fp);
    fscanf(fp, "%u", &header->maxVal);
    fgetc(fp);
}

// Reads the pixel data from the PPM file.
pixel_t* readPixels(FILE* fp, header_t header) {
    size_t pixelCount = header.width * header.height;
    pixel_t* pixels = allocatePixMemory(header);
    fread(pixels, sizeof(pixel_t), pixelCount, fp);
    return pixels;
}

// Writes the header information to the output PPM file.
void writeHeader(FILE* fp, header_t header) {
    fprintf(fp, "%s\n", header.type);
    fprintf(fp, "%u %u\n", header.width, header.height);
    fprintf(fp, "%u\n", header.maxVal);
}

// Writes the pixel data to the output PPM file.
void writePixels(FILE* fp, pixel_t* pixels, header_t header) {
    size_t pixelCount = header.width * header.height;
    fwrite(pixels, sizeof(pixel_t), pixelCount, fp);
}

// Reads the entire PPM image, including header and pixel data.
pixel_t* read(FILE* fp, header_t* header) {
    readHeader(fp, header);
    return readPixels(fp, *header);
}

// Writes the entire PPM image, including header and pixel data.
void write(FILE* fp, header_t header, pixel_t* pixels) {
    writeHeader(fp, header);
    writePixels(fp, pixels, header);
}

// Allocates memory for the pixel data.
pixel_t* allocatePixMemory(header_t header) {
    return (pixel_t*) malloc(header.width * header.height * sizeof(pixel_t));
}

// Frees the memory used for pixel data.
void freeMemory(pixel_t* pixels) {
    free(pixels);
}
