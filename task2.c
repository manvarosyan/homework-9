#include <stdio.h>
#include <pthread.h>

#define SIZE 8

int arr[SIZE] = {2, 3, 4, 5, 6, 7, 8, 9};

typedef struct{
	int start;
	int end;
}Range;

void* sum_part(void* arg){
	Range* range = (Range*)arg;
	int sum = 0;

	for (int i = range->start; i <= range->end; i++){
		sum += arr[i];
	}

	printf("Sum of array[%d..%d] = %d\n", range->start, range->end, sum);

	return NULL;
}

int main(){
	pthread_t thread1;
	pthread_t thread2;

	Range r1 = {0, SIZE/2 - 1};
	Range r2 = {SIZE/2, SIZE - 1};

	pthread_create(&thread1, NULL, sum_part, &r1);
	pthread_create(&thread2, NULL, sum_part, &r2);

	pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

	return 0;
}
