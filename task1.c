#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg){
	int thread_number = *((int*)arg);
	printf("Thread %d is running (ID: %lu)\n", thread_number, pthread_self());
	return NULL;
}

int main(){
	pthread_t threads[3];
	int thread_ids[3];

	for(int i = 0; i < 3; i++){
		thread_ids[i] = i + 1;
		if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0){
			perror("Failed to create thread");
			return 1;
		}
	}

	for(int i = 0 ; i < 3; i++){
		pthread_join(threads[i], NULL);
	}

	printf("All threads have completed. Exiting the program. \n");
	return 0;
}

