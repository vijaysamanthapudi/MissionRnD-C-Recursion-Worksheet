/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiral_traverse(int **input_array, int *result, int rows, int columns, int startingx, int endingx, int startingy, int endingy, int index);
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL)
		return NULL;
	if (rows <= 0 || columns <= 0)
		return NULL;
	int *res = (int *)malloc(sizeof(int)*(rows*columns));
	int start = 0, stx = 0, endx = rows - 1, sty = 0, endy = columns - 1;
	res = spiral_traverse(input_array, res, rows, columns, stx, endx, sty, endy, start);
	return res;
	
}

int *spiral_traverse(int **input_array, int *res, int rows, int columns, int stx, int endx, int sty, int endy, int start)
{
	int temp;
	if (start > rows*columns - 1)
	{
		return res;
	}
	else
	{
		for (temp = sty; temp <= endy; temp = temp + 1)
		{
			res[start] = input_array[stx][temp];
			start++;
		}
		stx++;
		for (temp = stx; temp <= endx; temp = temp + 1)
		{
			res[start] = input_array[temp][endy];
			start++;
		}
		endy--;
		if (stx < endx)
		{
			for (temp = endy; temp >= sty; temp -= 1)
			{
				res[start] = input_array[endx][temp];
				start++;
			}
			endx--;
		}
		if (sty < endy)
		{
			for (temp = endx; temp >= stx; temp -= 1)
			{
				res[start] = input_array[temp][sty];
				start++;
			}
			sty++;
		}
		if (start== rows*columns - 1)
		{
			if (stx == sty && endx == endy)
				res[start] = input_array[stx][endy];
			return res;
		}
	}
	return spiral_traverse(input_array, res, rows, columns, stx, endx, sty, endy, start);
}
