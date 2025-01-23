#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

std::vector<std::string> readInputFile(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string word;
        while (std::getline(inputFile, word)) {
            data.push_back(word);
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input file." << std::endl;
    }
    return data;
}

void writeOutputFile(const std::string& filename, const std::vector<std::string>& data) {
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

void countingSort(std::vector<std::string>& arr, int index) {
    int n = arr.size();
    std::vector<std::string> output(n);
    int count[256] = {0};

    for (int i = 0; i < n; i++) {
        int charIndex = index < arr[i].size() ? arr[i][index] : 0;
        count[charIndex]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int charIndex = index < arr[i].size() ? arr[i][index] : 0;
        output[count[charIndex] - 1] = arr[i];
        count[charIndex]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<std::string>& arr) {
    int maxLen = 0;
    for (const auto& str : arr) {
        if (str.size() > maxLen) {
            maxLen = str.size();
        }
    }

    for (int index = maxLen - 1; index >= 0; index--) {
        countingSort(arr, index);
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> data = readInputFile(inputFileName);
    radixSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}