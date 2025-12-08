#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float grayscale =
                (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = (int) round(grayscale);
            image[i][j].rgbtGreen = (int) round(grayscale);
            image[i][j].rgbtRed = (int) round(grayscale);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            int k = width - j - 1;
            RGBTRIPLE temp;
            temp.rgbtBlue = image[i][j].rgbtBlue;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtRed = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][k].rgbtBlue = temp.rgbtBlue;
            image[i][k].rgbtGreen = temp.rgbtGreen;
            image[i][k].rgbtRed = temp.rgbtRed;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int blue_sum = 0;
            int green_sum = 0;
            int red_sum = 0;

            if (i == 0)
            {

                if (j == 0)
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i][j].rgbtBlue + new_image[i][j + 1].rgbtBlue +
                               new_image[i + 1][j].rgbtBlue + new_image[i + 1][j + 1].rgbtBlue) /
                              4.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i][j].rgbtGreen + new_image[i][j + 1].rgbtGreen +
                               new_image[i + 1][j].rgbtGreen + new_image[i + 1][j + 1].rgbtGreen) /
                              4.0);
                    image[i][j].rgbtRed =
                        round((new_image[i][j].rgbtRed + new_image[i][j + 1].rgbtRed +
                               new_image[i + 1][j].rgbtRed + new_image[i + 1][j + 1].rgbtRed) /
                              4.0);
                }

                else if (j == width - 1)
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i][j].rgbtBlue + new_image[i][j - 1].rgbtBlue +
                               new_image[i + 1][j].rgbtBlue + new_image[i + 1][j - 1].rgbtBlue) /
                              4.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i][j].rgbtGreen + new_image[i][j - 1].rgbtGreen +
                               new_image[i + 1][j].rgbtGreen + new_image[i + 1][j - 1].rgbtGreen) /
                              4.0);
                    image[i][j].rgbtRed =
                        round((new_image[i][j].rgbtRed + new_image[i][j - 1].rgbtRed +
                               new_image[i + 1][j].rgbtRed + new_image[i + 1][j - 1].rgbtRed) /
                              4.0);
                }

                else
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i][j].rgbtBlue + new_image[i][j - 1].rgbtBlue +
                               new_image[i + 1][j].rgbtBlue + new_image[i + 1][j - 1].rgbtBlue +
                               new_image[i + 1][j + 1].rgbtBlue + new_image[i][j + 1].rgbtBlue) /
                              6.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i][j].rgbtGreen + new_image[i][j - 1].rgbtGreen +
                               new_image[i + 1][j].rgbtGreen + new_image[i + 1][j - 1].rgbtGreen +
                               new_image[i + 1][j + 1].rgbtGreen + new_image[i][j + 1].rgbtGreen) /
                              6.0);
                    image[i][j].rgbtRed =
                        round((new_image[i][j].rgbtRed + new_image[i][j - 1].rgbtRed +
                               new_image[i + 1][j].rgbtRed + new_image[i + 1][j - 1].rgbtRed +
                               new_image[i + 1][j + 1].rgbtRed + new_image[i][j + 1].rgbtRed) /
                              6.0);
                }
            }

            else if (i == height - 1)
            {

                if (j == 0)
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i][j].rgbtBlue + new_image[i][j + 1].rgbtBlue +
                               new_image[i - 1][j].rgbtBlue + new_image[i - 1][j + 1].rgbtBlue) /
                              4.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i][j].rgbtGreen + new_image[i][j + 1].rgbtGreen +
                               new_image[i - 1][j].rgbtGreen + new_image[i - 1][j + 1].rgbtGreen) /
                              4.0);
                    image[i][j].rgbtRed =
                        round((new_image[i][j].rgbtRed + new_image[i][j + 1].rgbtRed +
                               new_image[i - 1][j].rgbtRed + new_image[i - 1][j + 1].rgbtRed) /
                              4.0);
                }

                else if (j == width - 1)
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i][j].rgbtBlue + new_image[i][j - 1].rgbtBlue +
                               new_image[i - 1][j].rgbtBlue + new_image[i - 1][j - 1].rgbtBlue) /
                              4.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i][j].rgbtGreen + new_image[i][j - 1].rgbtGreen +
                               new_image[i - 1][j].rgbtGreen + new_image[i - 1][j - 1].rgbtGreen) /
                              4.0);
                    image[i][j].rgbtRed =
                        round((new_image[i][j].rgbtRed + new_image[i][j - 1].rgbtRed +
                               new_image[i - 1][j].rgbtRed + new_image[i - 1][j - 1].rgbtRed) /
                              4.0);
                }

                else
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i][j].rgbtBlue + new_image[i][j - 1].rgbtBlue +
                               new_image[i - 1][j].rgbtBlue + new_image[i - 1][j - 1].rgbtBlue +
                               new_image[i - 1][j + 1].rgbtBlue + new_image[i][j + 1].rgbtBlue) /
                              6.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i][j].rgbtGreen + new_image[i][j - 1].rgbtGreen +
                               new_image[i - 1][j].rgbtGreen + new_image[i - 1][j - 1].rgbtGreen +
                               new_image[i - 1][j + 1].rgbtGreen + new_image[i][j + 1].rgbtGreen) /
                              6.0);
                    image[i][j].rgbtRed =
                        round((new_image[i][j].rgbtRed + new_image[i][j - 1].rgbtRed +
                               new_image[i - 1][j].rgbtRed + new_image[i - 1][j - 1].rgbtRed +
                               new_image[i - 1][j + 1].rgbtRed + new_image[i][j + 1].rgbtRed) /
                              6.0);
                }
            }

            else
            {
                if (j == 0)
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i - 1][j].rgbtBlue + new_image[i - 1][j + 1].rgbtBlue +
                               new_image[i][j].rgbtBlue + new_image[i][j + 1].rgbtBlue +
                               new_image[i + 1][j].rgbtBlue + new_image[i + 1][j + 1].rgbtBlue) /
                              6.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i - 1][j].rgbtGreen + new_image[i - 1][j + 1].rgbtGreen +
                               new_image[i][j].rgbtGreen + new_image[i][j + 1].rgbtGreen +
                               new_image[i + 1][j].rgbtGreen + new_image[i + 1][j + 1].rgbtGreen) /
                              6.0);
                    image[i][j].rgbtRed =
                        round((new_image[i - 1][j].rgbtRed + new_image[i - 1][j + 1].rgbtRed +
                               new_image[i][j].rgbtRed + new_image[i][j + 1].rgbtRed +
                               new_image[i + 1][j].rgbtRed + new_image[i + 1][j + 1].rgbtRed) /
                              6.0);
                }

                else if (j == width - 1)
                {
                    image[i][j].rgbtBlue =
                        round((new_image[i - 1][j].rgbtBlue + new_image[i - 1][j - 1].rgbtBlue +
                               new_image[i][j].rgbtBlue + new_image[i][j - 1].rgbtBlue +
                               new_image[i + 1][j].rgbtBlue + new_image[i + 1][j - 1].rgbtBlue) /
                              6.0);
                    image[i][j].rgbtGreen =
                        round((new_image[i - 1][j].rgbtGreen + new_image[i - 1][j - 1].rgbtGreen +
                               new_image[i][j].rgbtGreen + new_image[i][j - 1].rgbtGreen +
                               new_image[i + 1][j].rgbtGreen + new_image[i + 1][j - 1].rgbtGreen) /
                              6.0);
                    image[i][j].rgbtRed =
                        round((new_image[i - 1][j].rgbtRed + new_image[i - 1][j - 1].rgbtRed +
                               new_image[i][j].rgbtRed + new_image[i][j - 1].rgbtRed +
                               new_image[i + 1][j].rgbtRed + new_image[i + 1][j - 1].rgbtRed) /
                              6.0);
                }

                else
                {
                    for (int a = i - 1; a <= i + 1; a++)
                    {
                        for (int b = j - 1; b <= j + 1; b++)
                        {
                            blue_sum += new_image[a][b].rgbtBlue;
                            green_sum += new_image[a][b].rgbtGreen;
                            red_sum += new_image[a][b].rgbtRed;
                        }
                    }
                    image[i][j].rgbtBlue = round(blue_sum / 9.0);
                    image[i][j].rgbtGreen = round(green_sum / 9.0);
                    image[i][j].rgbtRed = round(red_sum / 9.0);
                }
            }
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue_Gx = 0;
            int green_Gx = 0;
            int red_Gx = 0;

            int blue_Gy = 0;
            int green_Gy = 0;
            int red_Gy = 0;

            if (i == 0)
            {

                if (j == 0)
                {
                    blue_Gx = (new_image[i][j + 1].rgbtBlue * 2 + new_image[i + 1][j + 1].rgbtBlue);
                    blue_Gy = (new_image[i + 1][j].rgbtBlue * 2 + new_image[i + 1][j + 1].rgbtBlue);
                    green_Gx =
                        (new_image[i][j + 1].rgbtGreen * 2 + new_image[i + 1][j + 1].rgbtGreen);
                    green_Gy =
                        (new_image[i + 1][j].rgbtGreen * 2 + new_image[i + 1][j + 1].rgbtGreen);
                    red_Gx = (new_image[i][j + 1].rgbtRed * 2 + new_image[i + 1][j + 1].rgbtRed);
                    red_Gy = (new_image[i + 1][j].rgbtRed * 2 + new_image[i + 1][j + 1].rgbtRed);
                }

                else if (j == width - 1)
                {
                    blue_Gx =
                        (new_image[i][j - 1].rgbtBlue * (-2) - new_image[i + 1][j - 1].rgbtBlue);
                    blue_Gy = (new_image[i + 1][j].rgbtBlue * 2 + new_image[i + 1][j - 1].rgbtBlue);
                    green_Gx =
                        (new_image[i][j - 1].rgbtGreen * (-2) - new_image[i + 1][j - 1].rgbtGreen);
                    green_Gy =
                        (new_image[i + 1][j].rgbtGreen * 2 + new_image[i + 1][j - 1].rgbtGreen);
                    red_Gx = (new_image[i][j - 1].rgbtRed * (-2) - new_image[i + 1][j - 1].rgbtRed);
                    red_Gy = (new_image[i + 1][j].rgbtRed * 2 + new_image[i + 1][j - 1].rgbtRed);
                }

                else
                {
                    blue_Gx =
                        (new_image[i][j - 1].rgbtBlue * (-2) - new_image[i + 1][j - 1].rgbtBlue +
                         new_image[i][j + 1].rgbtBlue * 2 + new_image[i + 1][j + 1].rgbtBlue);
                    blue_Gy = (new_image[i + 1][j].rgbtBlue * 2 + new_image[i + 1][j - 1].rgbtBlue +
                               new_image[i + 1][j + 1].rgbtBlue);
                    green_Gx =
                        (new_image[i][j - 1].rgbtGreen * (-2) - new_image[i + 1][j - 1].rgbtGreen +
                         new_image[i][j + 1].rgbtGreen * 2 + new_image[i + 1][j + 1].rgbtGreen);
                    green_Gy =
                        (new_image[i + 1][j].rgbtGreen * 2 + new_image[i + 1][j - 1].rgbtGreen +
                         new_image[i + 1][j + 1].rgbtGreen);
                    red_Gx = (new_image[i][j - 1].rgbtRed * (-2) - new_image[i + 1][j - 1].rgbtRed +
                              new_image[i][j + 1].rgbtRed * 2 + new_image[i + 1][j + 1].rgbtRed);
                    red_Gy = (new_image[i + 1][j].rgbtRed * 2 + new_image[i + 1][j - 1].rgbtRed +
                              new_image[i + 1][j + 1].rgbtRed);
                }
            }

            else if (i == height - 1)
            {

                if (j == 0)
                {
                    blue_Gx = (new_image[i][j + 1].rgbtBlue * 2 + new_image[i - 1][j + 1].rgbtBlue);
                    blue_Gy =
                        (new_image[i - 1][j].rgbtBlue * (-2) - new_image[i - 1][j + 1].rgbtBlue);
                    green_Gx =
                        (new_image[i][j + 1].rgbtGreen * 2 + new_image[i - 1][j + 1].rgbtGreen);
                    green_Gy =
                        (new_image[i - 1][j].rgbtGreen * (-2) - new_image[i - 1][j + 1].rgbtGreen);
                    red_Gx = (new_image[i][j + 1].rgbtRed * 2 + new_image[i - 1][j + 1].rgbtRed);
                    red_Gy = (new_image[i - 1][j].rgbtRed * (-2) - new_image[i - 1][j + 1].rgbtRed);
                }

                else if (j == width - 1)
                {
                    blue_Gx =
                        (new_image[i][j - 1].rgbtBlue * (-2) - new_image[i - 1][j - 1].rgbtBlue);
                    blue_Gy =
                        (new_image[i - 1][j].rgbtBlue * (-2) - new_image[i - 1][j - 1].rgbtBlue);
                    green_Gx =
                        (new_image[i][j - 1].rgbtGreen * (-2) - new_image[i - 1][j - 1].rgbtGreen);
                    green_Gy =
                        (new_image[i - 1][j].rgbtGreen * (-2) - new_image[i - 1][j - 1].rgbtGreen);
                    red_Gx = (new_image[i][j - 1].rgbtRed * (-2) - new_image[i - 1][j - 1].rgbtRed);
                    red_Gy = (new_image[i - 1][j].rgbtRed * (-2) - new_image[i - 1][j - 1].rgbtRed);
                }

                else
                {
                    blue_Gx =
                        (new_image[i][j - 1].rgbtBlue * (-2) - new_image[i - 1][j - 1].rgbtBlue +
                         new_image[i][j + 1].rgbtBlue * 2 + new_image[i - 1][j + 1].rgbtBlue);
                    blue_Gy = (new_image[i - 1][j].rgbtBlue * (-2) -
                               new_image[i - 1][j - 1].rgbtBlue - new_image[i - 1][j + 1].rgbtBlue);
                    green_Gx =
                        (new_image[i][j - 1].rgbtGreen * (-2) - new_image[i - 1][j - 1].rgbtGreen +
                         new_image[i][j + 1].rgbtGreen * 2 + new_image[i - 1][j + 1].rgbtGreen);
                    green_Gy =
                        (new_image[i - 1][j].rgbtGreen * (-2) - new_image[i - 1][j - 1].rgbtGreen -
                         new_image[i - 1][j + 1].rgbtGreen);
                    red_Gx = (new_image[i][j - 1].rgbtRed * (-2) - new_image[i - 1][j - 1].rgbtRed +
                              new_image[i][j + 1].rgbtRed * 2 + new_image[i - 1][j + 1].rgbtRed);
                    red_Gy = (new_image[i - 1][j].rgbtRed * (-2) - new_image[i - 1][j - 1].rgbtRed -
                              new_image[i - 1][j + 1].rgbtRed);
                }
            }

            else
            {
                if (j == 0)
                {
                    blue_Gy =
                        (new_image[i - 1][j].rgbtBlue * (-2) - new_image[i - 1][j + 1].rgbtBlue +
                         new_image[i + 1][j].rgbtBlue * 2 + new_image[i + 1][j + 1].rgbtBlue);
                    blue_Gx = (new_image[i - 1][j + 1].rgbtBlue + new_image[i][j + 1].rgbtBlue * 2 +
                               new_image[i + 1][j + 1].rgbtBlue);
                    green_Gy =
                        (new_image[i - 1][j].rgbtGreen * (-2) - new_image[i - 1][j + 1].rgbtGreen +
                         new_image[i + 1][j].rgbtGreen * 2 + new_image[i + 1][j + 1].rgbtGreen);
                    green_Gx =
                        (new_image[i - 1][j + 1].rgbtGreen + new_image[i][j + 1].rgbtGreen * 2 +
                         new_image[i + 1][j + 1].rgbtGreen);
                    red_Gy = (new_image[i - 1][j].rgbtRed * (-2) - new_image[i - 1][j + 1].rgbtRed +
                              new_image[i + 1][j].rgbtRed * 2 + new_image[i + 1][j + 1].rgbtRed);
                    red_Gx = (new_image[i - 1][j + 1].rgbtRed + new_image[i][j + 1].rgbtRed * 2 +
                              new_image[i + 1][j + 1].rgbtRed);
                }

                else if (j == width - 1)
                {
                    blue_Gy =
                        (new_image[i - 1][j].rgbtBlue * (-2) - new_image[i - 1][j - 1].rgbtBlue +
                         new_image[i + 1][j].rgbtBlue * 2 + new_image[i + 1][j - 1].rgbtBlue);
                    blue_Gx =
                        (-new_image[i - 1][j - 1].rgbtBlue + new_image[i][j - 1].rgbtBlue * (-2) -
                         new_image[i + 1][j - 1].rgbtBlue);
                    green_Gy =
                        (new_image[i - 1][j].rgbtGreen * (-2) - new_image[i - 1][j - 1].rgbtGreen +
                         new_image[i + 1][j].rgbtGreen * 2 + new_image[i + 1][j - 1].rgbtGreen);
                    green_Gx =
                        (-new_image[i - 1][j - 1].rgbtGreen + new_image[i][j - 1].rgbtGreen * (-2) -
                         new_image[i + 1][j - 1].rgbtGreen);
                    red_Gy = (new_image[i - 1][j].rgbtRed * (-2) - new_image[i - 1][j - 1].rgbtRed +
                              new_image[i + 1][j].rgbtRed * 2 + new_image[i + 1][j - 1].rgbtRed);
                    red_Gx = (-new_image[i - 1][j - 1].rgbtRed +
                              new_image[i][j - 1].rgbtRed * (-2) - new_image[i + 1][j - 1].rgbtRed);
                }

                else
                {
                    blue_Gy =
                        (new_image[i - 1][j].rgbtBlue * (-2) - new_image[i - 1][j + 1].rgbtBlue -
                         new_image[i - 1][j - 1].rgbtBlue + new_image[i + 1][j].rgbtBlue * 2 +
                         new_image[i + 1][j + 1].rgbtBlue + new_image[i + 1][j - 1].rgbtBlue);
                    blue_Gx =
                        (new_image[i - 1][j + 1].rgbtBlue + new_image[i][j + 1].rgbtBlue * 2 +
                         new_image[i + 1][j + 1].rgbtBlue - new_image[i - 1][j - 1].rgbtBlue +
                         new_image[i][j - 1].rgbtBlue * (-2) - new_image[i + 1][j - 1].rgbtBlue);
                    green_Gy =
                        (new_image[i - 1][j].rgbtGreen * (-2) - new_image[i - 1][j + 1].rgbtGreen -
                         new_image[i - 1][j - 1].rgbtGreen + new_image[i + 1][j].rgbtGreen * 2 +
                         new_image[i + 1][j + 1].rgbtGreen + new_image[i + 1][j - 1].rgbtGreen);
                    green_Gx =
                        (new_image[i - 1][j + 1].rgbtGreen + new_image[i][j + 1].rgbtGreen * 2 +
                         new_image[i + 1][j + 1].rgbtGreen - new_image[i - 1][j - 1].rgbtGreen +
                         new_image[i][j - 1].rgbtGreen * (-2) - new_image[i + 1][j - 1].rgbtGreen);
                    red_Gy = (new_image[i - 1][j].rgbtRed * (-2) - new_image[i - 1][j + 1].rgbtRed -
                              new_image[i - 1][j - 1].rgbtRed + new_image[i + 1][j].rgbtRed * 2 +
                              new_image[i + 1][j + 1].rgbtRed + new_image[i + 1][j - 1].rgbtRed);
                    red_Gx = (new_image[i - 1][j + 1].rgbtRed + new_image[i][j + 1].rgbtRed * 2 +
                              new_image[i + 1][j + 1].rgbtRed - new_image[i - 1][j - 1].rgbtRed +
                              new_image[i][j - 1].rgbtRed * (-2) - new_image[i + 1][j - 1].rgbtRed);
                }
            }

            int blue_sobel_value = (int) round(sqrt(pow(blue_Gx, 2) + pow(blue_Gy, 2)));
            int green_sobel_value = (int) round(sqrt(pow(green_Gx, 2) + pow(green_Gy, 2)));
            int red_sobel_value = (int) round(sqrt(pow(red_Gx, 2) + pow(red_Gy, 2)));

            if (blue_sobel_value > 255)
            {
                blue_sobel_value = 255;
            }

            if (green_sobel_value > 255)
            {
                green_sobel_value = 255;
            }

            if (red_sobel_value > 255)
            {
                red_sobel_value = 255;
            }

            image[i][j].rgbtBlue = blue_sobel_value;
            image[i][j].rgbtGreen = green_sobel_value;
            image[i][j].rgbtRed = red_sobel_value;
        }
    }

    return;
}
