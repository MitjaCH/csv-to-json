# CSV to JSON Converter

## About the Project

`csv-to-json-converter` is a command-line utility written in C that converts CSV files to JSON format. This project provides a streamlined way to transform structured data from a common spreadsheet format (CSV) into a structured data format widely used for APIs and data interchange (JSON).

### Example Conversion
#### CSV Input
```csv
Name,Age,City
Alice,30,New York
Bob,25,Los Angeles
Charlie,35,Chicago
```

#### JSON Output
```json
[
  {"Name": "Alice", "Age": "30", "City": "New York"},
  {"Name": "Bob", "Age": "25", "City": "Los Angeles"},
  {"Name": "Charlie", "Age": "35", "City": "Chicago"}
]
```

---

## Folder Structure

The project structure is organized as follows:

```
csv-to-json-converter/
│
├── .github/                 # GitHub Actions workflows
│   └── workflows/
│       └── ci.yml           # Continuous Integration workflow for testing
│
├── src/                     # Source files
│   ├── main.c               # Main entry point for the application
│   ├── csv_parser.c         # CSV parsing functionality
│   └── json_writer.c        # JSON writing functionality
│
├── include/                 # Header files
│   ├── csv_parser.h         # Header for csv_parser.c
│   └── json_writer.h        # Header for json_writer.c
│
├── tests/                   # Unit tests
│   ├── test_csv_parser.c    # Tests for CSV parsing
│   └── test_json_writer.c   # Tests for JSON writing
│
├── output/                  # Folder for generated JSON files
├── Makefile                 # Build script
└── README.md                # Project documentation
```

---

## Features

- **CSV Parsing**: Reads and parses CSV files with comma-separated values.
- **JSON Writing**: Converts parsed data into JSON format and saves to a file.
- **Automated Testing**: Unit tests for CSV parsing and JSON writing functions.
- **Continuous Integration**: GitHub Actions workflow for automated testing on each commit or pull request.

---

## Getting Started

Follow these instructions to set up and run the project on your local machine.

### Prerequisites

To compile and run this project, you need:
- **GCC** or any compatible C compiler
- **Make** (for building the project)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/MitjaCH/csv-to-json.git
   cd csv-to-json
   ```

2. Compile the project using the Makefile:

   ```bash
   make
   ```

This will generate the main executable, `csv_to_json_converter`.

---

## Usage

To convert a CSV file to JSON, run the following command:

```bash
./csv_to_json_converter <input_file.csv> <output_file.json>
```

For example:
```bash
./csv_to_json_converter sample.csv output/sample.json
```

This will read the `sample.csv` file and write the converted JSON to `output/sample.json`.

---

## Testing

This project includes unit tests for core functionalities. The tests are located in the `tests/` directory. 

To run the tests, use:

```bash
make tests
```

This will compile and run individual test binaries, `tests/test_csv_parser` and `tests/test_json_writer`.

---

## Building and Running with Makefile

The project includes a Makefile to simplify building and testing.

- **Build the Project**: Compile the main application.
  ```bash
  make
  ```

- **Run Tests**: Build and execute all tests.
  ```bash
  make tests
  ```

- **Clean Up**: Remove compiled files and test binaries.
  ```bash
  make clean
  ```

---

## Continuous Integration

The project is set up with GitHub Actions for continuous integration. The workflow is located in `.github/workflows/ci.yml`. It automatically runs the tests on each push and pull request to `main` or `develop`.

The CI pipeline includes:
- Building the project.
- Running the unit tests to ensure code quality and functionality.

To review the status of the workflow, navigate to the **Actions** tab in the GitHub repository.

---

## Contributing

Contributions are welcome! To contribute to this project:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and add tests as needed.
4. Submit a pull request with a detailed description of your changes.
