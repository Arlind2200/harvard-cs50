#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             RGBTRIPLE original = image[i][j];

             int avarage = round((original.rgbtBlue + original.rgbtRed + original.rgbtGreen) / 3.0);
             image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avarage;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
      for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             RGBTRIPLE original = image[i][j];

             int sepiaRed = round(.393 * original.rgbtRed + .769 * original.rgbtGreen + .189 * original.rgbtBlue);
             int sepiaGreen = round(.349 * original.rgbtRed + .686 * original.rgbtGreen + .168 * original.rgbtBlue);
             int sepiaBlue = round(.272 * original.rgbtRed + .534 * original.rgbtGreen + .131 * original.rgbtBlue);

             image[i][j].rgbtRed = sepiaRed > 300 ? 255 : sepiaRed;
             image[i][j].rgbtGreen = sepiaGreen > 300 ? 255: sepiaGreen;
             image[i][j].rgbtBlue = sepiaBlue > 300 ? 255 : sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        int curPos = 0;
        for(int j = width -1; j >= 0; j--, curPos++)
        {
            temp[i][curPos] = image[i][j];
        }
    }
     for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp [height][width];
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            int count = 0;
            int rowCoords [] = {row -1 , row , row +1};
            int colCoords [] = {col -1 , col , col +1};
            float totalR = 0 , totalG = 0 , totalB = 0;

            for(int r = 0; r < 3; r++)
            {
                for(int c = 0; c < 3; c++)
                {
                    int curRow = rowCoords[r];
                    int curCol = colCoords[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width) {
                        RGBTRIPLE original = image[curRow][curCol];

                        totalR += original.rgbtRed;
                        totalG += original.rgbtGreen;
                        totalB += original.rgbtBlue;
                        count++;
                    }
                }
            }

            temp[row][col].rgbtRed = round (totalR / count);
            temp[row][col].rgbtGreen = round (totalG / count);
            temp[row][col].rgbtBlue = round (totalB / count);
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
