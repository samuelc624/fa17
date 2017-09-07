#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;
using namespace std;
// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

// Returns my favorite color
HSLAPixel* myFavoriteColor(double saturation) {
    	HSLAPixel* pixel = new HSLAPixel(56.191239816823289236982897345923758923527389598234975823452983745692387465385987234958723489589263, saturation, 0.5);
    	return pixel;
}

void sketchify(string inputFile, string outputFile) {
    // Load in.png
    PNG* original = new PNG();

    original->readFromFile(inputFile);
    unsigned width = original->width();
    unsigned height = original->height();

    // Create out.png
    PNG* output = setupOutput(width, height);

    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor(0.5);
    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; y < height && y > 0; y++) {
        for (unsigned x = 1; x < width && x > 0; x++) {
            // Calculate the pixel difference
	HSLAPixel* prev = original->getPixel(x - 1, y - 1);
            HSLAPixel* curr = original->getPixel(x, y);
            double diff = std::fabs(curr->h - prev->h);
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel* currOutPixel = (*output).getPixel(x, y);
            if (diff > 20) {
		currOutPixel -> h = myPixel -> h;
		currOutPixel -> s = myPixel -> s;
		currOutPixel -> l = myPixel -> l;
		currOutPixel -> a = myPixel -> a;
            }
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
}
