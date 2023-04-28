#include <iostream>
#include <string>
#include <fstream> // библиотека позволяющая взаимодействовать с файловой системой компа

bool print_file(std::string file_path) {
	std::ifstream in;
	in.open(file_path);
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
		std::cout << std::endl;
		return true;
	}
	return false;
}
bool clear_file(std::string file_path) {
	std::ofstream clear;
	clear.open(file_path);
	if (clear.is_open()) {
		clear.close();
		return true;
	}
	return false;
}
bool statistic(std::string word);



int main() {
	setlocale(LC_ALL, "Ru");
	int n;
	std::string path = "file.txt";
	// Task1 Class ofstrem
	/*std::ofstream out; // Объект класса для записи данных в файл
	// Or std::ofstream out(path);
	out.open(path, std::ios::app); // Открытие файла, с его последующим дополнением 
	if (out.is_open()) { // Проверка файла, на правильность его нахождения
		std::cout << "Файл открыт для записи.\n";
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		out << str << '\n'; // Добавление информации в файл
		std::cout << "Запись добавлена в файл! ";
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	// Возможные причины при открытии файла:
	// 1. Неправильный синтаксис указания пути к файлу;
	// 2. Нет доступа к файлу;
	// 3. Файл открыт другим объектом или приложением.
	out.close(); // Закрытие файла */
	// Class ifstream
	/*std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открыт для чтения! \n";
		std::cout << "Содержимое файла: \n";
		std::string file_text;

		// посимвольное считывание 
		//char sym;
		//while (in.get(sym))
			//std::cout << sym; //Только вывод 
		//	file_text += sym;
		//std::cout << file_text << std::endl;

		//Пословное считывание 
		//while (!in.eof()) {
			//std::string tmp;
			//in >> tmp;
			//file_text += tmp + '\n';
		//}
		//std::cout << file_text << std::endl;

		// Построчное Считывание 
		std::string line;
		while (std::getline(in, line))
			file_text += line + '\n';
		std::cout << file_text << std::endl;


	}
	else
		std::cout << "Ошибка открытия файла! \n";
	// Возможные причины ошибок при открытия файла:
	// 1. Неправильный синтаксис указания пути к файлу;
	// 2. Нет доступа к файлу;
	// 3. Файл не существует. 
	in.close();*/
	//Delete File
	/*if (remove(path.c_str()) == 0)
		std::cout << "Файл \"" << path << "\" удален. \n";
	else
		std::cout << " Ошибка удаления файла. \n";

	// Возможные причины ошибок при удалении файла:
	// 1. Неправильный синтаксис указания пути к файлу;
	// 2. Нет доступа к файлу;
	// 3. Файл не существует;
	// 4. Файл открыт.
	*/
	// TAsk 1, 2
	std::cout << " Задача 1. \n";
	int action;
	do {
		std::cout << "Выберете действие:\n";
		std::cout << "1. Добавление статистики в файл;\n";
		std::cout << "2. Вывод файла;\n";
		std::cout << "3. Очистка файла;\n";
		std::cout << "4. Завершение работы. \n";
		std::cout << "Введите номер команды -> ";
		std::cin >> action;
		std::string str1;
		switch (action) {
		case 1:
			std::cout << "Введите строку -> ";
			std::cin.ignore();
			std::getline(std::cin, str1);
			if (statistic(str1)) 
				std::cout << "Запись добавлена в файл.\n\n";
			else
				std::cout << "Ошибка выполнения функции. \n\n";
			break;
		case 2:
			std::cout << "Содержимое файла: \n";
			print_file("stats.txt");
			break;
		case 3:
			clear_file("stats.txt");
			std::cout << "Файл очищен.\n\n";
			break;
		case 4:
			std::cout << "Программа Завершена!\n\n";
			break;
		default:
			std::cout << "Ошибка ввода!\n\n";
		}

		
	} while (action != 4);
	



	return 0;
}



bool statistic(std::string word) {
	std::ofstream out;
	out.open("Stats.txt", std::ios::app);
	if (out.is_open()) {
		out << word << ' ' << word.length() << '\n';
		out.close();
		return true;
	}
	return false;
}
