#ifndef CSV_PARSER_H
#define CSV_PARSER_H

// Function to parse a single line of the CSV file into columns
char **parse_csv_line(const char *line, int *num_columns);

// Main function to convert CSV to JSON
int convert_csv_to_json(const char *csv_file, const char *json_file);

#endif
