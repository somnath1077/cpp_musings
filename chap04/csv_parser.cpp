#include <string>
#include <vector>
#include <sstream> //istringstream
#include <iostream> // cout
#include <fstream> // ifstream

/**
 * Reads csv file into table, exported as a vector of vector of doubles.
 * @param inputFileName input file name (full path).
 * @return data as vector of vector of doubles.
 */
std::vector<std::vector<double>> parse_csv_file(std::string input_file_name) {

    std::vector<std::vector<double>> data;
    std::ifstream inputFile(input_file_name);
    int l = 0;

    while (inputFile) {
        l++;
        std::string s;

        if (!getline(inputFile, s)) break;

        if (s[0] != '#') {
            std::istringstream ss(s);
            std::vector<double> record;

            while (ss) {
                std::string line;
                if (!std::getline(ss, line, ','))
                    break;
                try {
                    record.push_back(stof(line));
                }                catch (const std::invalid_argument e) {
                    std::cout << "NaN found in file " << inputFileName << " line " << l
                            << endl;
                    e.what();
                }
            }

            data.push_back(record);
        }
    }

    if (!inputFile.eof()) {
        std::cerr << "Could not read file " << inputFileName << "\n";
        __throw_invalid_argument("File not found.");
    }

    return data;
}

int main() {
    std::vector<vector<double>> data = parse_csv_file("test.csv");

    for (auto l : data) {
        for (auto x : l)
            std::cout << x << " ";
        std::cout << std::endl;
    }

    return 0;
}
