#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>

void bubbleSort(std::vector<std::string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

std::vector<std::string> readInputFile(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string word;
        while (std::getline(inputFile, word)) {
            data.push_back(word);
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open input file." << std::endl;
    }
    return data;
}

void writeOutputFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const std::string& item : data) {
            outputFile << item << " ";
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

    std::vector<std::string> data = readInputFile(inputFileName);
    bubbleSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}
