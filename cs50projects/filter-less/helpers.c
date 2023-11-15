#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int average = 0;
            average += round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0));
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;

            int sepiaRed = fmin(255, round((0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue)));
            int sepiaGreen = fmin(255, round((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue)));
            int sepiaBlue = fmin(255, round((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue)));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE tempo = image[i][j];
            image[i][j] = image[i][width-1 - j];
            image[i][width-1 - j] = tempo;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp_image[i][j] = image[i][j];
        }
    }

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            int red = 0;
            int blue = 0;
            int green = 0;
            float colors = 0.00;

            for (int f = -1; f < 2; f++) {
                for (int u = -1; u < 2; u++) {
                    int middle = x + f;
                    int middle_two = y + u;

                    if (middle > (height-1) || middle_two > (width-1) || middle < 0 || middle_two < 0) {
                        continue;
                    }

            red += image[middle][middle_two].rgbtRed;
            blue += image[middle][middle_two].rgbtBlue;
            green += image[middle][middle_two].rgbtGreen;
            colors += 1;
                }
            }
        temp_image[x][y].rgbtRed = round(red/colors);
        temp_image[x][y].rgbtBlue = round(blue/colors);
        temp_image[x][y].rgbtGreen = round(green/colors);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = temp_image[i][j];
        }
    }

    return;
}
