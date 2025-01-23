#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>

void selectionSort(std::vector<double>& arr) {
    std::cout << "Selection sort started." << std::endl;

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

std::vector<double> readInputFile(const std::string& filename) {
    std::vector<double> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        double number;
        while (inputFile >> number) {
            data.push_back(number);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open input file." << std::endl;
    }
    return data;
}

void writeOutputFile(const std::string& filename, const std::vector<double>& data) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const double item : data) {
            outputFile << item << std::endl;
        }
        outputFile.close();
    }
    else {
        std::cerr << "Error: Could not open output file." << std::endl;
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<double> data = readInputFile(inputFileName);
    selectionSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds." << std::endl;
    system("pause");

    return 0;
}
