#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Helper function to check if the string contains at least one special character
bool containsSpecialChar(const std::string& str, const std::vector<std::string>& specialChars) {
    for (const auto& ch : str) {
        if (std::find(specialChars.begin(), specialChars.end(), std::string(1, ch)) != specialChars.end()) {
            return true;
        }
    }
    return false;
}

// Helper function to generate all combinations of the given strings
void generateCombinations(const std::vector<std::string>& elements, std::ofstream& file, 
                          const std::vector<std::string>& specialChars, std::string current = "", int start = 0) {
    if (current.length() > 8 && containsSpecialChar(current, specialChars)) {
        file << current << std::endl;  // Write the valid combination to the file
    }
    for (size_t i = start; i < elements.size(); ++i) {
        generateCombinations(elements, file, specialChars, current + elements[i], i + 1); // Include the current element and recurse
    }
}

// Main function to generate the wordlist
void generateWordlist(const std::vector<std::string>& names,
                      const std::vector<std::string>& nicknames,
                      const std::vector<std::string>& days,
                      const std::vector<std::string>& months,
                      const std::vector<std::string>& years, 
                      const std::vector<std::string>& petNames, 
                      const std::vector<std::string>& partnerNames,
                      const std::vector<std::string>& specialChars,
                      const std::string& outputFile) {
    std::ofstream file(outputFile);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Combine all elements into a single vector
    std::vector<std::string> allElements;
    allElements.insert(allElements.end(), nicknames.begin(), nicknames.end());
    allElements.insert(allElements.end(), days.begin(), days.end());
    allElements.insert(allElements.end(), months.begin(), months.end());
    allElements.insert(allElements.end(), years.begin(), years.end());
    allElements.insert(allElements.end(), petNames.begin(), petNames.end());
    allElements.insert(allElements.end(), partnerNames.begin(), partnerNames.end());
    allElements.insert(allElements.end(), specialChars.begin(), specialChars.end());

    // Generate combinations with each name as the prefix
    for (const auto& name : names) {
        generateCombinations(allElements, file, specialChars, name +""); // Start with the name and generate combinations
        generateCombinations(allElements, file, specialChars, name + ".");
        generateCombinations(allElements, file, specialChars, name + "_");
        generateCombinations(allElements, file, specialChars, name + "@");

    }
    
    

    file.close();
}

void getInput(std::vector<std::string>& vec, const std::string& prompt) {
    std::string input;
    std::cout << "Enter " << prompt << " (type 'done' when finished): " << std::endl;
    while (true) {
        std::getline(std::cin, input);
        if (input == "done") break;
        vec.push_back(input);
    }
}

int main() {
    std::vector<std::string> names;
    std::vector<std::string> nicknames;
    std::vector<std::string> days;
    std::vector<std::string> months;
    std::vector<std::string> years;
    std::vector<std::string> petNames;
    std::vector<std::string> partnerNames;
    std::vector<std::string> specialChars;

    getInput(names, "names");
    getInput(nicknames, "nicknames");
    getInput(days, "days of birth");
    getInput(months, "months of birth");
    getInput(years, "years of birth");
    getInput(petNames, "pet names");
    getInput(partnerNames, "partner names");
    getInput(specialChars, "special characters");

    std::string outputFile;
    std::cout << "Enter the output file name: ";
    std::getline(std::cin, outputFile);

    generateWordlist(names, nicknames, days, months, years, petNames, partnerNames, specialChars, outputFile);

    std::cout << "Wordlist generated successfully in " << outputFile << "." << std::endl;
    return 0;
}
