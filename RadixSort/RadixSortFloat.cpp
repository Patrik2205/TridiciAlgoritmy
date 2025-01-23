#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>

std::vector<double> readInputFile(const std::string& filename) {
    std::vector<double> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string word;
        while (std::getline(inputFile, word)) {
            data.push_back(std::stod(word));
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input file." << std::endl;
    }
    return data;
}

void writeOutputFile(const std::string& filename, const std::vector<double>& data) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& value : data) {
            outputFile << value << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open output file." << std::endl;
    }
}

int getMaxExponent(const std::vector<double>& arr) {
    double maxVal = *max_element(arr.begin(), arr.end());
    return static_cast<int>(std::log10(maxVal)) + 1;
}

void countingSort(std::vector<double>& arr, int exp) {
    int n = arr.size();
    std::vector<double> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = static_cast<int>(arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = static_cast<int>(arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<double>& arr) {
    int maxExp = getMaxExponent(arr);
    for (int exp = 1; maxExp / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<double> data = readInputFile(inputFileName);
    radixSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}