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
	// TAsk 1
	std::cout << " Задача 1. \nВведите слова -> ";
	std::string str1;
	std::getline(std::cin, str1);
	if (statistic(str1)) {
		std::cout << "Запись добавлена в файл.\n\n";
		std::cout << "Содержимое файла: \n";
		print_file("stats.txt");
	}
	else
		std::cout << "Ошибка выполнения функции. \n\n";




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
