#include <stdio.h>
#include "ppmUtil.h"

int main(int argc, char *argv[]) {

    // Check if the correct number of arguments are provided.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_ppm_file> <output_ppm_file>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading.
    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 2;
    }

    // Open the output file for reading.
    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 3;
    }

    // Read the PPM image from the input file.
    header_t header;
    pixel_t *pixels = read(inputFile, &header);

    // Write the PPM image to the output file.
    write(outputFile, header, pixels);

    // Close the input and output files and free allocated memory.
    fclose(inputFile);
    fclose(outputFile);
    freeMemory(pixels);

    return 0;
}
