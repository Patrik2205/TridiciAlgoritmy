#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

std::vector<long long> readInputFile(const std::string& filename) {
    std::vector<long long> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string word;
        while (std::getline(inputFile, word)) {
            data.push_back(std::stoll(word));
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open input file." << std::endl;
    }
    return data;
}

void writeOutputFile(const std::string& filename, const std::vector<long long>& data) {
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

void insertionSort(std::vector<long long>& arr) {
    std::cout << "Insertion sort started" << std::endl;

    int n = arr.size();
    for (int i = 1; i < n; i++) {
        long long key = arr[i];
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

    std::vector<long long> data = readInputFile(inputFileName);
    insertionSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}