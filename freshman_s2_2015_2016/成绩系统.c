#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)
#define NULL 0
struct score
{
	int a;
	int b;
	int c;
};
struct student
{
	long num;
	char name[10];
	struct score fen;
};
int N;
struct student *E;
int *A, *B, *C, *Y;
int formax(int a[], int N)
{
	int i, j, temp;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (*(a + j) > *(a + j + 1))
			{
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
	return *(a + N - 1);
}
int forIFa(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (X == E[i].fen.a)
			printf("%ld %s %d\n", E[i].num, E[i].name, E[i].fen.a);
	return 0;
}
int forIFb(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (X == E[i].fen.b)
			printf("%ld %s %d\n", E[i].num, E[i].name, E[i].fen.b);
	return 0;
}
int forIFc(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (X == E[i].fen.c)
			printf("%ld %s %d\n", E[i].num, E[i].name, E[i].fen.c);
	return 0;
}
int forIFabc(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (X == (E[i].fen.a + E[i].fen.b + E[i].fen.c))
			printf("%ld %s %d %d %d %d\n", E[i].num, E[i].name, E[i].fen.a,
				   E[i].fen.b, E[i].fen.c, E[i].fen.a + E[i].fen.b + E[i].fen.c);
	}
	return 0;
}
int main()
{
	int i;
	float suma = 0, sumb = 0, sumc = 0, sumy = 0;
	printf("请输入学生人数:");
	scanf("%d", &N);
	A = (int *)calloc(N, sizeof(int));
	B = (int *)calloc(N, sizeof(int));
	C = (int *)calloc(N, sizeof(int));
	Y = (int *)calloc(N, sizeof(int));
	E = (struct student *)calloc(N, sizeof(struct student));
	for (i = 0; i < N; i++)
	{
		scanf("%ld%s%d%d%d", &E[i].num, &E[i].name, &E[i].fen.a, &E[i].fen.b, &E[i].fen.c);
		A[i] = E[i].fen.a;
		B[i] = E[i].fen.b;
		C[i] = E[i].fen.c;
		Y[i] = A[i] + B[i] + C[i];
		suma += A[i];
		sumb += B[i];
		sumc += C[i];
		sumy += Y[i];
	}
	printf("A课程:average %.2f分数最高的同学信息\n", suma / N);
	forIFa(formax(A, N), N);
	printf("B课程:average %.2f分数最高的同学信息\n", sumb / N);
	forIFb(formax(B, N), N);
	printf("C课程:average %.2f分数最高的同学信息\n", sumc / N);
	forIFc(formax(C, N), N);
	printf("总分:average %.2f最高的同学信息\n", sumy / N);
	forIFabc(formax(Y, N), N);
	return 0;
}