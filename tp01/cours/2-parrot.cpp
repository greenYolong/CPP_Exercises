#include <string>
#include <sstream>
#include <iostream> 
#include <vector>

int main () {
    std::string line;
    std::stringstream lines;
    while (true){
        std::getline(std::cin, line);
        if(line.empty()){
            break;
        }
        lines << line;
    }
    std::cout << lines.str() << std::endl;
    return 0;
}