#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef int64_t time64_t; // Use a 64-bit integer for time representation

void print_time(time64_t t) {
    char buffer[26];
    struct tm *tm_info;

    // Convert to time_t for compatibility with standard library functions
    time_t time_value = (time_t)t;

    tm_info = localtime(&time_value);
    if (tm_info == NULL) {
        printf("Error: Unable to convert time\n");
        return;
    }

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Time: %s\n", buffer);
}

int main() {
    // Maximum value for 32-bit signed integer
    time64_t max_time = 2147483647; // 2^31 - 1 sign integer
    printf("Maximum 32-bit time:\n");
    print_time(max_time);

    // Adding 1 second (to show extended range in 64-bit mode)
    time64_t safe_time = max_time + 1;
    printf("After adding 1 second:\n");
    print_time(safe_time);

    // Large future date
    time64_t large_future_time = 9223372036854775807LL; // 2^63 - 1
    printf("Large future time:\n");
    print_time(large_future_time);

    return 0;
}
