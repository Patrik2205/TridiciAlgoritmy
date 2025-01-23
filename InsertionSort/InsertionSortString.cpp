#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

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
        for (const auto& str : data) {
            outputFile << str << std::endl;
        }
        outputFile.close();
    }
    else {
        std::cerr << "Unable to open output file." << std::endl;
    }
}

void insertionSort(std::vector<std::string>& arr) {
    std::cout << "Insertion sort started" << std::endl;

    int n = arr.size();
    for (int i = 1; i < n; i++) {
        std::string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> data = readInputFile(inputFileName);
    insertionSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}