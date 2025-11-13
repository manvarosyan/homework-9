#include <stdio.h>
#include <pthread.h>

int numbers[] = {1, 2, 3, 4, 5};
#define SIZE (sizeof(numbers) / sizeof(numbers[0]))

void* square_function(void* arg) {
    int num = *((int*)arg);
    printf("Square of %d is %d\n", num, num * num);
    return NULL;
}

int main() {
    pthread_t threads[SIZE];

    for (int i = 0; i < SIZE; i++) {
        pthread_create(&threads[i], NULL, square_function, &numbers[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

