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
            image[i][k] = temp_array[i][width-1-k];
        }
    }
    return;
}