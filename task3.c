#include <stdio.h>
#include <pthread.h>

void* print_numbers(void* arg) {
    long id = (long)arg;

    for (int i = 1; i <= 5; i++) {
        printf("Thread %ld prints: %d\n", id, i);
    }

    return NULL;
}

int main() {
    pthread_t threads[3];

    for (long i = 1; i <= 3; i++) {
        pthread_create(&threads[i-1], NULL, print_numbers, (void*)i);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

