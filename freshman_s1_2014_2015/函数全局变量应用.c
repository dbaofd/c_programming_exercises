#include <stdio.h>
float aver;
int N;
int main()
{
	void average(int a[100]);
	int i, j, k;
	int score[100];
	printf("Enter the number of students\n");
	scanf("%d", &N);
	printf("Enter the score\n");
	for (i = 0; i < N; i++)
		scanf("%d", &score[i]);
	average(score);
	printf("Average score is %.2f\n", aver);
	return 0;
}
void average(int a[100])
{
	int i, j, k, sum = 0;
	for (i = 0; i < N; i++)
		sum += a[i];
	aver = (float)sum / 10;
}