#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

// Function to check if a word is a stop word
bool isStopWord(const std::string& word) {
    static const std::vector<std::string> stopWords = {"the", "and", "is", "of", "to", "in", "a", "for", "on", "with"};
    return std::find(stopWords.begin(), stopWords.end(), word) != stopWords.end();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::map<std::string, int> wordFrequency;

    std::string word;
    while (inputFile >> word) {
        // Convert word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Remove punctuation
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());

        // Check if word is a stop word
        if (!isStopWord(word)) {
            wordFrequency[word]++;
        }
    }

    // Write word-frequency pairs to output file
    for (const auto& pair : wordFrequency) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Word frequency successfully written to output.txt\n";

    return 0;
}
