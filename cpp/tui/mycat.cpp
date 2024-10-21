#include <iostream>
#include <fstream>
#include <string>

// user defined functions
void help();
void concatonateFile(const std::string& filename);

// main func
int main(int argc, char* argv[]) {
	if (argv[1] == "--help" || argv[1] == "-h" || argc != 2) {
		help();
	}
	std::string filename = argv[1];
	concatonateFile(filename);
	return 0;
}

// func definition
void help() {
	std::cout << "usage: ./mycat [filename]\n";
}

void concatonateFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file.\n";
	}
	
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << "\n";
	}
	
	file.close();
}
