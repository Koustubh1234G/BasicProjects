#include <iostream>
#include <fstream>
#include <string>

void help();
void searchInFile(const std::string& filename, const std::string& pattern);

int main(int argc, char* argv[]) {
	if (argv[1] == "-h" || argv[1] == "--help" || argc < 3) {
		help();
		return 1;
	}
	
	std::string pattern = argv[1];
	std::string filename = argv[2];
	
	searchInFile(filename, pattern);

	return 0;
}


void help() {
	std::cout<<"usage: ";
	std::cout<<"mygrep <pattern> <filename>"<< std::endl;
}

void searchInFile(const std::string& filename, const std::string& pattern) {
	std::ifstream file(filename);
	if(!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}

	std::string line;
	bool patternFound = false;
	while (std::getline(file, line)) {
		size_t pos = 0;
		while ((pos = line.find(pattern,pos)) != std::string::npos) {
			patternFound = true;
			// change pattern color green
			std::cout << line.substr(0, pos); // printing text before pattern
			
			if (pos + pattern.length() <= line.length()) {
				std::cout << "\033[1;32m" << line.substr(pos, pattern.length()) << "\033[0m"; // Print pattern in green
				pos += pattern.length(); // Move past the pattern
		    	}
		        std::cout << line.substr(pos) << std::endl; // Print the rest of the line
		        break;
		}
	}	
	file.close();
	
	if (!patternFound) {
		std::cout << "\033[1;31mPattern not found: " << pattern << "\033[0m" << std::endl;
	}
}
