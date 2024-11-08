#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "csv_parser.h"

void test_parse_csv_line() {
    char line[] = "John,30,New York";
    int num_columns = 0;
    char **columns = parse_csv_line(line, &num_columns);

    assert(num_columns == 3);
    assert(strcmp(columns[0], "John") == 0);
    assert(strcmp(columns[1], "30") == 0);
    assert(strcmp(columns[2], "New York") == 0);

    // Clean up
    for (int i = 0; i < num_columns; i++) {
        free(columns[i]);
    }
    free(columns);
}

int main() {
    test_parse_csv_line();
    printf("CSV Parser Test Passed!\n");
    return 0;
}
