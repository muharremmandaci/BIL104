/* Libraries */
#include <stdio.h>
#include <math.h>

/* Function Prototypes */
void calculate_pq(int num_questions, int num_students, float p[num_questions], float q[num_questions],int students[num_questions][num_students]);
float calculate_total_pq(int num_questions, float p[num_questions], float q[num_questions]);
float calculate_question_sums(int num_questions, float p[num_questions], float question_sums[num_questions]);
int calculate_grand_sum(int num_questions, float question_sums[num_questions]);
float calculate_kr20(int num_questions, float total_pq, float var);
float calculate_sum_squares(float average, int num_questions, float question_sums[num_questions]);
float calculate_standart_deviation(float sum_squares, int num_questions);

/* Main Function */
int main(){

    /* Right and wrong answers for every questions for students */
	int students[10][10]= {
						{1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
						{1, 0, 1, 1, 0, 1, 1, 1, 1, 0},
						{1, 0, 1, 0, 0, 1, 0, 1, 1, 0},
						{1, 0, 1, 0, 0, 1, 0, 1, 1, 0},
						{0, 0, 1, 0, 0, 1, 1, 1, 1, 0},
						{0, 0, 1, 0, 0, 1, 1, 1, 1, 0},
						{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
						{1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
						{1, 0, 0, 0, 0, 0, 1, 1, 1, 0},
						{1, 0, 0, 0, 0, 0, 1, 1, 1, 0}
				};

	/* Variables */
	int temp = 0;
	int num_questions = 10;
	int num_students = 10;
	float total_pq = 0;
	float grand_sum = 0;
	float average = 0;
	float var = 0;
	float kr20 = 0;
	float sum_squares = 0;
	float standart_deviation = 0 ;

	/* Array Variables */
	float p[10] = {0};
	float q[10] = {0};
	float question_sums[10] = {0};
	float rix[10] = {0};
	int averages_students_respondents[10] = {0};

	/* Calculates */
	calculate_pq(num_questions, num_students, p, q, students);
	total_pq = calculate_total_pq(num_questions, p, q);
	calculate_question_sums(num_questions, p, question_sums);
	grand_sum = calculate_grand_sum(num_questions, question_sums);
	average = grand_sum / num_questions;
	sum_squares = calculate_sum_squares(average, num_questions, question_sums);
	var = sum_squares / num_questions;
	standart_deviation = calculate_standart_deviation(sum_squares, num_questions);
	kr20 = calculate_kr20(num_questions, total_pq, var);

	/* Prints */
	printf("toplam_pq : %.2f\n", total_pq);
	printf("var : %.2f\n", var);
	printf("grand_sum : %.2f\n", grand_sum);
	printf("average : %.2f\n", average);
	printf("kr20 : %.2f\n", kr20);
	
	return 0;	
}

/* Function Definitions */
void calculate_pq(int num_questions, int num_students, float p[num_questions], float q[num_questions],int students[num_questions][num_students]){

	int i, j;	
	for(i = 0 ; i < num_questions ; i++)
	{	
		for(j = 0 ; j < num_students ; j++)
		{
			if(students[j][i] == 1)
			{
				p[i]++;
			}
			else
			{
				q[i]++;
			}
		}
		p[i] /= num_questions;
		q[i] /= num_questions;
	}	
}

float calculate_total_pq(int num_questions, float p[num_questions], float q[num_questions]){

	float total_pq = 0;

	int i;
	for( i = 0 ; i < num_questions ; i++)
	{
		total_pq += (p[i] * q[i]);
	}

	return total_pq;
}

float calculate_question_sums(int num_questions, float p[num_questions], float question_sums[num_questions]){

	int i;
	for (i = 0 ; i < num_questions ; i++)
	{
		question_sums[i] = (p[i] * 10.0);
	}
}

int calculate_grand_sum(int num_questions, float question_sums[num_questions]){

	int grand_sum = 0;

	int i;
	for (i = 0 ; i < num_questions ; i++)
	{
		grand_sum += question_sums[i];
	}

	return grand_sum;
}

float calculate_sum_squares(float average, int num_questions, float question_sums[num_questions]){
	
	float sum_squares = 0;

	int i;
	for (i = 0 ; i < num_questions ; i++)
	{
		sum_squares += pow((average - question_sums[i]), 2);
	}
	
	return sum_squares;
}

float calculate_standart_deviation(float sum_squares, int num_questions){

	float standart_deviation = 0;

	standart_deviation = sqrt(sum_squares / (num_questions - 1));

	return standart_deviation;
}

float calculate_kr20(int num_questions, float total_pq, float var){

	float kr20 = 0;

	kr20 = (num_questions / (num_questions - 1.0)) * (1.0 - (total_pq / var));

	return kr20;
}
