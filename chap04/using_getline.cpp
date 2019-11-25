#include <iostream>
#include <string>

void read_line_by_line(std::string& line) {
  std::string content;
  std::cout << "Please introduce a text. Enter an empty line to finish." << std::endl;
  
  do {
      std::getline(std::cin, line);
      content += line + '\n';
  } while (!line.empty());
  
  std::cout << "The text you introduced was:" << std::endl << content;
}

void read_line(std::string& line) {
    while (std::getline(std::cin, line, '\n')) {
        std::cout << line << std::endl;
    }
}

void read_word(std::string& word) {
    std::cin >> word;
    std::cout << word << std::endl;
    std::cout << "This is before the while loop " << std::endl;
    while (!word.empty()) {
        std::cout << word << std::endl;
        std::cin >> word;
    }
}


int main() {
    std::string line;
    read_line(line);
    return 0;
}


