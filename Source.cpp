#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<fstream>

struct Message
{
	char author[10];
	char message[255];
};
bool checkFile(std::fstream& file)
{
	if (!file)
	{
		std::cout << "Error file open.\n";
		return 0;
	}
	else return 1;
}
void read(std::fstream& file, int& countRead)
{
	Message m;
	file.seekg(countRead * sizeof(Message), std::ios::beg);// go to needed position in file
	file.read(reinterpret_cast <char*>(&m), sizeof(m));
	std::cout << m.author << ": " << m.message << std::endl;
}
void write(std::fstream& file, int& countWrite)
{
	Message m;
	std::cout << "Enter your name and message: ";
	std::cin >> m.author;
	std::cin >> m.message;
	file.seekp(countWrite * sizeof(Message), std::ios::beg);
	file.write(reinterpret_cast <char*>(&m), sizeof(m));
}

int main(int argc, char *argv[]) //argc - argument counter, argv - argument variable
{
	//first option
	/*char *filename = argv[1];
	char* word = argv[2];*/

	/*second option*/
	//char filename[30];
	//char word[30];
	//strcpy(filename, argv[1]);
	//strcpy(word, argv[2]);
	//if (argc < 3) //if not enough arguments in command line
	//{
	//	std::cout << "Use command line and write file name and word.\n";
	//	system("pause");
	//	return 1;
	//}

	//std::ifstream fin(filename);
	//char str[20];
	//while (!fin.eof())
	//{
	//	fin >> str;//read till backspace
	//	if (strcmp(str, word) == 0)
	//		std::cout << "Yes\n";
	//}

	// 1. Return size of the file that is a command line argument
	//char filename[30];
	//char word[30];
	//strcpy(filename, argv[1]);
	//strcpy(word, argv[2]);

	//if (argc < 3) // if not enough arguments in the command line
	//{
	//	std::cout << "Use command line and write filename and word\n";
	//	system("pause");
	//	return 1;
	//}

	//std::ifstream fin(filename);
	//fin.seekg(0, std::ios::end); // go to the end of the file
	//int size = fin.tellg();
	//std::cout << size << "\n";

	// 2. Copy one file into another. File names are passed as a command line arguments
	char firstFile[30], secondFile[30];
	char str1[30];
	strcpy(firstFile, argv[1]);
	strcpy(secondFile, argv[2]);

	std::ifstream fin1(firstFile);
	while (!fin1.eof())
	{
		fin1 >> str1;
	}
	std::ofstream file2(secondFile);
	file2 << str1;

	// 3. Write app to send messages through a binary file. Binary file name and number of messages pass as the command line arguments
	//Message m;
	//std::fstream file;
	//char filename[20];
	//strcpy(filename, argv[1]);

	//std::ofstream file1(filename);
	//file1.close();

	//int amount = atoi(argv[2]);// char to int
	//bool flag = 1;
	//bool isWrite = 0, isRead = 0;
	//int countRead = 0, countWrite = 0, countReadAll = 0, countWriteAll = 0;
	//char command[10];

	//while (flag)
	//{
	//	std::cout << "Enter read\\write: ";
	//	std::cin >> command;
	//	if (strcmp(command, "write") == 0)
	//	{
	//		if (countWriteAll - countReadAll >= amount)
	//		{
	//			std::cout << "No place to write.\n";
	//			continue;
	//		}
	//		file.open(filename, std::ios::binary | std::ios::out | std::ios::ate);

	//		if (!checkFile(file)) return 0;
	//		write(file, countWrite);

	//		if (countWrite < amount) countWrite++;
	//		else countWrite = 0;

	//		file.close();
	//		isWrite = 1;
	//		countWriteAll++;
	//	}
	//	else if (strcmp(command, "read") == 0)
	//	{
	//		if (isWrite == 0 || countWriteAll <= countReadAll) continue;
	//		file.open(filename, std::ios::binary | std::ios::in | std::ios::ate);
	//		if (!checkFile) return 0;
	//		read(file, countRead);
	//		if (countRead < amount) countRead++;
	//		else countRead = 0;

	//		countReadAll++;
	//		isRead = 1;

	//		file.close();
	//	}
	//	else if (strcmp(command, "exit") == 0)
	//		flag = 0;
	//}
	//file.close();
	//file.open(filename, std::ios::binary | std::ios::in);
	//while (!file.eof())
	//{
	//	file.read(reinterpret_cast <char*>(&m), sizeof(m));
	//	std::cout << m.author << ": " << m.message << std::endl;
	//}

	return 0;
}
