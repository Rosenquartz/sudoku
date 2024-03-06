#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

int main() {
    char buffer[100];
	char command[100];
	char argstr[100];
    char *args[100];
    
    while(true) {
        memset(buffer, 0, sizeof(buffer));
		memset(command, 0, 100);
		memset(argstr, 0, 100);
		memset(args, 0, 100);

        printf("$ ");
        fgets(buffer, 100, stdin);
		sscanf(buffer, "%s %[^\n]s", command, argstr);

		args[0] = command;
		int idx = 1;
		args[idx++] = strtok(argstr, " ");
		while ((args[idx++] = strtok(NULL, ""))) {}

		if (strcmp(command, "exit") == 0) {
			std::cout << "Thanks for playing!" << std::endl;
			exit(0);
		}

		if (strcmp(command, "fill") == 0) {
			std::cout << "The fill commanad is not yet supported." << std::endl;
			continue;
		}

		if (strcmp(command, "unfill") == 0) {
			std::cout << "The unfill command is not yet supported." << std::endl;
			continue;
		}

		if (strcmp(command, "generate") == 0) {
			std::cout << "The generate command is not yet supported." << std::endl;
			continue;
		}

		if (strcmp(command, "load") == 0) {
			
			std::cout << "Loading" << std::endl;
			if (args[1] == NULL) {
				std::cout << "Error: file not specified" << std::endl;
				continue;
			}

			std::ifstream sudokuFile;
			sudokuFile.open(args[1]);

			if (!sudokuFile.good()) {
				std::cout << "Error: file not working" << std::endl;
				sudokuFile.close();
				continue;
			}

			std::cout << args[1] << " loaded." << std::endl;

			std::string sline;
			getline(sudokuFile, sline);
			std::cout << sline << std::endl;
			getline(sudokuFile, sline);
			std::cout << sline << std::endl;
			getline(sudokuFile, sline);
			std::cout << sline << std::endl;
			getline(sudokuFile, sline);
			std::cout << sline << std::endl;
			sudokuFile.close();

			std::cout << args[1] << " closed." << std::endl;
			continue;
		}

    }
    
    return 0;
}