#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

class SudokuCell {
	private:
	public:
		int row;
		int col;
		int status;
		int val;
};

class SudokuBoard {
	private:
	public:
		std::vector<SudokuCell> cellList{};
		void initialize(std::vector<int> inputValues) {
			for (int i = 0; i < inputValues.size(); i++) {
				SudokuCell newCell;
				newCell.row = i / 9;
				newCell.col = i % 9;
				newCell.val = inputValues[i];
				cellList.push_back(newCell);
			}
		}
		void updateCell(int row, int col, int val) {
			cellList[row*9 + col].val = val;
		}
		void printBoard() {
			std::cout << " \t1 2 3   4 5 6   7 8 9" << std::endl;
			for (int row = 0; row < 9; row++) {
				std::cout << row;
				for (int col = 0; col < 9; col++) {
					if (col == 0) {
						std::cout << '\t';
					} else if (col%3 == 0) {
						std::cout << "  ";
					} 
					if (cellList[row*9 + col].val < 0) std::cout << ". ";
					else std::cout << cellList[row*9+col].val << " ";
				}
				std::cout << std::endl;
			}
		}
};

int main() {
    char buffer[100];
	char command[100];
	char argstr[100];
    char *args[100];

	SudokuBoard board;

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

		if (strcmp(command, "print") == 0) {
			if (board.cellList.size() == 0) std::cout << "No board loaded\n";
			else board.printBoard();
			continue;
		}

		if (strcmp(command, "load") == 0) {
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

			std::string sline;
			std::vector<int> svector;
			for (int i = 0; i < 9; i++) {
				getline(sudokuFile, sline);
				for (int j = 0; j < 9; j++) {
					if (sline[j] == 'x')  svector.push_back(-1);
					else svector.push_back(sline[j] - '0');
				}
			}
			board.initialize(svector);
			board.printBoard();
			continue;
		}

    }
    
    return 0;
}