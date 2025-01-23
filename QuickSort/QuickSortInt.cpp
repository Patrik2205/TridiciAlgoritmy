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

int partition(std::vector<long long>& arr, int low, int high) {
    long long pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<long long>& arr, int low, int high) {
    if (low < high) {
        long long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<long long> data = readInputFile(inputFileName);
    quickSort(data, 0, data.size() - 1);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}