#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_parser.h"

// Parse a line from the CSV file into an array of strings (columns)
char **parse_csv_line(const char *line, int *num_columns) {
    char **columns = NULL;
    char *token = NULL;
    char *line_copy = strdup(line);
    *num_columns = 0;

    token = strtok(line_copy, ",");
    while (token != NULL) {
        columns = realloc(columns, sizeof(char *) * (*num_columns + 1));
        columns[*num_columns] = strdup(token);
        (*num_columns)++;
        token = strtok(NULL, ",");
    }

    free(line_copy);
    return columns;
}

// Convert a CSV file to JSON format
int convert_csv_to_json(const char *csv_file, const char *json_file) {
    FILE *csv = fopen(csv_file, "r");
    if (!csv) {
        return -1; // File open failed
    }

    FILE *json = fopen(json_file, "w");
    if (!json) {
        fclose(csv);
        return -1;
    }

    char line[1024];
    int line_count = 0;
    int num_columns = 0;
    char **columns = NULL;

    fprintf(json, "[\n");

    while (fgets(line, sizeof(line), csv)) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character

        columns = parse_csv_line(line, &num_columns);

        if (line_count > 0) {
            fprintf(json, ",\n");
        }

        fprintf(json, "  {\n");

        for (int i = 0; i < num_columns; i++) {
            fprintf(json, "    \"column_%d\": \"%s\"", i + 1, columns[i]);
            if (i < num_columns - 1) {
                fprintf(json, ",");
            }
            fprintf(json, "\n");
            free(columns[i]);
        }

        fprintf(json, "  }");
        line_count++;

        free(columns);
    }

    fprintf(json, "\n]\n");

    fclose(csv);
    fclose(json);

    return 0; // Success
}
