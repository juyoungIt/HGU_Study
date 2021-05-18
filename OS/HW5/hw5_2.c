// hw5_2.c
// Writer : Juyoung Ha

#include <stdio.h>
#include <malloc.h>

typedef struct {
	int dim;
	float *data;
} DynamicVector;

// define a new type 'Vector' by aliasing DynamicVector
typedef DynamicVector Vector;


DynamicVector* AllocVector(int dim);
void DeleteVector(DynamicVector *vec);

void FillVector(Vector *vec, int dim, int dir);

float GetVectorData(Vector *vec, int idx);
void SetVectorData(Vector *vec, int idx, float v);

void DisplayVector(Vector *vec);

float DotProduct(Vector *vec1, Vector *vec2);


int main()
{
	Vector *vec1 = AllocVector(10);
	Vector *vec2 = AllocVector(10);

	FillVector(vec1, 10, 0);
	printf("vec1 = ");
	DisplayVector(vec1);

	FillVector(vec2, 10, 1);
	printf("vec2 = ");
	DisplayVector(vec2);

	printf("DotProduct(vec1, vec2) = %f\n", DotProduct(vec1, vec2));

	DeleteVector(vec1);
	DeleteVector(vec2);

	return 0;
}

DynamicVector* AllocVector(int dim)
{
	DynamicVector *vec = NULL;

	vec = (DynamicVector*)malloc(sizeof(DynamicVector));
	if(vec == NULL) {
		printf("Error! - memory allocation failed.\n");
		return NULL;
	}
	vec->data = (float*)malloc(sizeof(float) * dim);
	if(vec->data == NULL) {
		printf("Error! - memory allocation failed.\n");
		free(vec);
		return NULL;
	}
	vec->dim = dim;
	return vec;
}

void DeleteVector(DynamicVector *vec)
{
	if(vec == NULL)
		return;

	free(vec->data);
	free(vec);
}

void FillVector(Vector *vec, int dim, int dir)
{
	vec->dim = dim;
	
	if(dir == 0) {
		for(int i=0 ; i<dim ; i++)
			SetVectorData(vec, i, i+1);
	}
	else {
		for(int i=0 ; i<dim ; i++)
			SetVectorData(vec, i, dim-i);
	}
}

float GetVectorData(Vector *vec, int idx)
{
	return vec->data[idx];
}

void SetVectorData(Vector *vec, int idx, float v)
{
	vec->data[idx] = v;
}

float DotProduct(Vector *vec1, Vector *vec2)
{
	if(vec1->dim != vec2->dim){
		printf("Error! vec1->dim = %d, vec2->dim = %d\n", vec1->dim, vec2->dim);
		return 0.F;
	}

	float dot = 0.F;
	for(int i=0 ; i<vec1->dim ; i++)
		dot += GetVectorData(vec1, i) * GetVectorData(vec2, i);	
	return dot;
}

void DisplayVector(Vector *vec)
{
	for(int i = 0; i < vec->dim; i++)
		printf("%.3f ", vec->data[i]);

	printf("(dim = %d)\n", vec->dim);
}

