#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "json_writer.h"

void test_write_json() {
    // Test writing a JSON string to a file
    FILE *json_file = fopen("test_output.json", "w");
    assert(json_file != NULL);

    const char *data = "{\"name\": \"John\", \"age\": 30}";
    write_json(json_file, data);
    fclose(json_file);

    // Verify the output manually or by reading back the file (simplified)
    json_file = fopen("test_output.json", "r");
    char buffer[1024];
    fgets(buffer, sizeof(buffer), json_file);
    assert(strcmp(buffer, data) == 0);
    fclose(json_file);
}

int main() {
    test_write_json();
    printf("JSON Writer Test Passed!\n");
    return 0;
}
