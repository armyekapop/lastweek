#include<stdio.h>
void Fdet(int mat[3][3], float* det);
float inverse(int mat[3][3], int i, int j);
int main() {
	int mat[3][3];
	float det = 0;

	printf("Enter matrix :\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%d", &mat[i][j]);
		}
	}
	Fdet(mat, &det);
	printf("\n\ndeterminant: %f\n", det);

	printf("\nInverse of matrix is: \n");
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%.0f/%.0f\t", inverse(mat,i,j),det);
		}
		printf("\n");
	}

	return 0;
}
void Fdet(int mat[3][3], float* det)
{
	for (int i = 0; i < 3; i++)
		*det = *det + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
}
float inverse(int mat[3][3],int i,int j)
{
	return ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) ;
}