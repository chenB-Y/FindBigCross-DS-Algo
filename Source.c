//Name: Chen Haziza
//ID: 319027892 
//Name: Shahar Naim
//ID: 318685807


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
	int x;
	int y;
}point;
int BigCross1(int M[15][15], int m, int* rowC1, int* colC1);
int BigCross2(int M1[50][50], int m, int* rowC2, int* colC2);

int main()
{
	int rowC1 = 0;
	int colC1 = 0;
	int rowC2 = 0;
	int colC2 = 0;
	int matrix_size;
	time_t t;
	rand(time(NULL));
	int M1[50][50] = { 0 };
	int M[15][15] = { 0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
					   0,1,0,1,1,0,0,1,0,0,0,0,1,0,0,
					   0,0,0,0,1,0,1,1,1,0,0,1,0,0,0,
					   0,0,1,0,1,0,0,1,0,0,1,1,1,1,0,
					   0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,
					   1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,
					   0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,
					   0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,
					   0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,
					   0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,
					   0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,
					   0,1,0,0,1,1,1,1,1,1,1,0,1,0,0,
					   0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,
					   0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,
					   0,0,0,0,0,0,0,1,0,0,1,0,1,0,0 };
	printf("***************************section1***************************\n\n");
	printf("***************************matrix1***************************\n");
	// print matrix M (matrix of function : bigcroos1)
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printf(" %d", M[i][j]);
		}
		printf("\n");
	}
	printf("the data of the big cross in the matrix:\n\n");
	matrix_size = BigCross1(M, 15, &rowC1, &colC1);
	if (matrix_size != 0)
	{
		printf("the length of the branch is:%d\n", BigCross1(M, 15, &rowC1, &colC1));
		printf("the center is : (%d, %d)\n", rowC1, colC1);
	}
	else
	{
		printf("there is no cross in this matrix\n");
	}
	printf("***************************section2***************************\n\n");
	// insert natrix M1 with random number(0/1)(matrix of function : bigcroos2)
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			M1[i][j] = rand() % 2;
		}
	}
	//// print matrix M1 (matrix of function : bigcroos2)
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			printf(" %d", M1[i][j]);
		}
		printf("\n");
	}
	printf("the data of the big cross in the matrix:\n\n");
	matrix_size = BigCross2(M1, 50, &rowC2, &colC2);
	if (matrix_size != 0)
	{
		printf("the length of the branch is:%d\n", BigCross2(M1, 50, &rowC2, &colC2));
		printf("the center is : (%d, %d)\n", rowC2, colC2);
	}
	else
	{
		printf("there is no cross in this matrix\n");
	}
}


int BigCross1(int M[15][15], int m, int* x, int* y)
{
	int i = 0, j = 0, up = 0, down = 0, right = 0, left = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, min = 0, size = 0;
	char middle[4];
	for (i = 0; i < m - 1; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			if (M[i][j] == 1)
			{
				min = 0, counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
				for (up = i - 1; up >= 0 && (M[up][j] == 1); up--)
					counter1++;
				if (counter1 != 0)
				{
					for (down = i + 1; down < m && (M[down][j] == 1); down++)
						counter2++;
					if (counter2 != 0)
					{
						for (right = j + 1; right < m && (M[i][right] == 1); right++)
							counter3++;
						if (counter3 != 0)
						{
							for (left = j - 1; left >= 0 && (M[i][left] == 1); left--)
								counter4++;
							if (counter4 != 0)
								min = fmin(fmin(counter1, counter2), fmin(counter3, counter4));
						}
					}
				}
			}
			if (size < min)
			{
				size = min;
				*x = i;
				*y = j;
			}
		}
	}


	return size;

}

BigCross2(int M1[50][50], int m, int* rowC, int* colC)
{
	int i = 0, j = 0, k = 0, z = 0, r = 0, w = 0, counter = 0, size = 0;
	point arr[1250];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (M1[i][j] == 1)
			{
				if (M1[i][j + 1] == 1 && M1[i + 1][j] == 1 && M1[i][j - 1] == 1 && M1[i - 1][j] == 1)
				{
					arr[k].x = i;
					arr[k].y = j;
					k++;
				}

			}
		}
	}

	for (z = 0; z < k; z++)
	{
		r = arr[z].x;
		w = arr[z].y;
		counter = 1;
		for (int f = 2; f + r < 50 && f + w < 50; f++)
		{
			if (M1[r + f][w] == 1 && M1[r - f][w] == 1 && M1[r][w + f] == 1 && M1[r][w - f] == 1)
				counter++;
			else
				break;
		}
		if (counter > size)
		{
			size = counter;
			*rowC = r;
			*colC = w;
		}

	}
	return size;
}