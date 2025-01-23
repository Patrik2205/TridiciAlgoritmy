#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

std::vector<long long> readInputFile(const std::string& filename) {
    std::vector<long long> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string word;
        while (std::getline(inputFile, word)) {
            data.push_back(std::stoll(word));
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input file." << std::endl;
    }
    return data;
}

void writeOutputFile(const std::string& filename, const std::vector<long long>& data) {
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

void countingSort(std::vector<long long>& arr, long long exp) {
    int n = arr.size();
    std::vector<long long> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<long long>& arr) {
    long long maxVal = *max_element(arr.begin(), arr.end());
    for (long long exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<long long> data = readInputFile(inputFileName);
    radixSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}