#include <stdio.h>
#include <stdlib.h>
#include "json_writer.h"

// Function to write the JSON structure
void write_json(FILE *json, const char *data) {
    fprintf(json, "%s", data);
}
