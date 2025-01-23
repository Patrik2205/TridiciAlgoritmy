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

void heapify(std::vector<std::string>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<std::string>& arr) {
    std::cout << "Heap sort started" << std::endl;

    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    std::string inputFileName = "vstup.txt";
    std::string outputFileName = "vystup.txt";

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::string> data = readInputFile(inputFileName);
    heapSort(data);
    writeOutputFile(outputFileName, data);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    system("pause");

    return 0;
}