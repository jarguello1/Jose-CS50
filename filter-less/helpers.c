#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //take the original color values from the pixel
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            //average color values
            int grey_value = round((red + green + blue) / 3.0);

            //change all color values to the same averaged value
            image[i][j].rgbtRed = grey_value;
            image[i][j].rgbtGreen = grey_value;
            image[i][j].rgbtBlue = grey_value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //take the original color values from the pixel
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            //use sepia formula on each value, cap values at 255
            int sepia_red = round((.393 * red) + (.769 * green) + (.189 * blue));
            if (sepia_red > 255)
            {
                sepia_red = 255;
            }
            int sepia_green = round((.349 * red) + (.686 * green) + (.168 * blue));
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }
            int sepia_blue = round((.272 * red) + (.534 * green) + (.131 * blue));
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }

            //replace RGB values in the image with new RGB values
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //arrays to store pixel horizontal location
    RGBTRIPLE temp_array[height][width];

    //loop through the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //take the original j location of each pixel
            temp_array[i][j] = image[i][j];
        }

        //place the j locations in reverse
        for (int k = 0; k < width; k++)
        {
            image[i][k] = temp_array[i][width - 1 - k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create 2d array to store modified pixels
    RGBTRIPLE image_buffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_buffer[i][j] = image[i][j];
        }
    }

    //integer to store and add rgb values of surrounding pixels

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float redsum = 0;
            float greensum = 0;
            float bluesum = 0;
            int counter = 0;

            for (int k = -1; k < 2; k++)
            {
                if (k + i < 0 || k + i > height - 1)
                {
                    continue;
                }
                for (int l = -1; l < 2; l++)
                {
                    if (l + j < 0 || l + j > width - 1)
                    {
                        continue;
                    }
                    redsum += image_buffer[i + k][j + l].rgbtRed;
                    bluesum += image_buffer[i + k][j + l].rgbtBlue;
                    greensum += image_buffer[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(redsum / counter);
            image[i][j].rgbtBlue = round(bluesum / counter);
            image[i][j].rgbtGreen = round(greensum / counter);
        }
    }
    return;
}


