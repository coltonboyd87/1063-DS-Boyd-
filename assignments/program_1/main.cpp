//Program Name: Program 1 - Image Manipulation 
//Author: Colton Boyd 
//Description: 
//  This program reads in images stored as rgb values in a space delimited file format.
//Course: 1063 Data Structures
//Semester: Spring 2017
//Date: 2/9/18 

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

//Structure to hold RGB values 
struct rgb {
	int r;
	int g;
	int b;
	rgb() {
		r = 0; 
		g = 0; 
		b = 0; 
	}
};

//Function Name: flipVert 
//Description: This function flips RGB values from an image stored in 
//  2D array vetically. 
//Params:
//  rgb** image - 2D array holding rgb values
//  int width - width of image
//  int height - height of image
//Returns: void 

void flipVert(rgb** image, int width, int height)
{
	rgb temp; 
	for (int i = 0; i <= (height / 2); i++)
	{
		for (int j = 0; j < width; j++)
		{
			temp = image[i][j];
			image[i][j] = image[height - 1 -i][j];
			image[height - 1 - i][j] = temp; 
		}
	}
}

//Function Name: flipHorz 
//Description: This function flips RGB values from an image stored in 
// 2D array horizontally. 
//Params: 
//  rgb** image - 2D array holding rgb values
//  int width - width of image 
//  int height - height of image
//Returns: void 

void flipHorz(rgb** image, int width, int height) {
	rgb temp; 
	for (int j = 0; j <= (width / 2); j++)
	{
		for (int i = 0; i < height; i++)
		{
			temp = image[i][j]; 
			image[i][j] = image[i][width - 1 - j];
			image[i][width - 1 - j] = temp;
		}
	}
}

//Function Name: grayScale 
//Description: This function gets all the RGB values pulled from file 
//  and converts into a image composed of gray color values.
//Parmas: 
//  rgb** image - 2D array holding rgb values
//  int width - width of image 
//  int height - height of image
//Returns: void 

void grayScale(rgb** image, int width, int height) {
	int r, g, b, gray;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			r = image[i][j].r;
			g = image[i][j].g;
			b = image[i][j].b;

			gray = (r + g + b) / 3;

			image[i][j].r = gray;
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
}


int main() {
	ifstream ifile;          //Input / output files
	ofstream ofile;
	ifile.open("smiley.txt");
	ofile.open("smiley2.txt");
	int r, g, b, gray;

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.

	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++) {
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	flipVert(imgArray, width, height);
	flipHorz(imgArray, width, height); 
	grayScale(imgArray, width, height); 

//Write out our color data to a new file
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}


	return 0;
}
