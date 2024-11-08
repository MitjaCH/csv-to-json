#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv_parser.h"
#include "json_writer.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.csv> <output.json>\n", argv[0]);
        return 1;
    }

    const char *csv_file = argv[1];
    const char *json_file = argv[2];

    // Convert CSV to JSON
    if (convert_csv_to_json(csv_file, json_file) == 0) {
        printf("Conversion successful: %s\n", json_file);
    } else {
        printf("Conversion failed.\n");
    }

    return 0;
}
