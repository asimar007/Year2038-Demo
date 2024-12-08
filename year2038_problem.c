#include <stdio.h>
#include <time.h>

int main() {
    // Maximum value for 32-bit signed integer
    time_t max_time = 2147483647; // 2^31 - 1
    printf("Maximum 32-bit time: %s", ctime(&max_time));

    // Adding 1 second to cause overflow
    time_t overflow_time = max_time + 1;
    printf("After overflow: %s", ctime(&overflow_time)); // Undefined behavior
    return 0;
}
