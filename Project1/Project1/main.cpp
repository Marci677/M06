#include <iostream>
#include <fstream>
#include <string>
#include <array>

int levels_num = 0;
int textures_num = 0;
std::string title;
std::string* textures;

int loadTextures(std::ifstream& game_conf, int textures_num)
{
	std::string word;
	textures = new std::string[textures_num + 1];
	textures[0] = "none";
	int counter = 1;
	while(counter < textures_num + 1)
	{
		std::getline(game_conf, word, ';');
		std::getline(game_conf, word, ';');
		textures[counter] = word;
		std::cout << word << '\n';
		std::getline(game_conf, word, '\n');
		counter++;
	}
	return 0;
}

int loadLevels(std::ifstream& game_conf, int levels_num)
{

}

int main(int argc, char* argv[])
{
	std::ifstream game_conf("../Project1/game.csv");

	if (!game_conf.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	
	while (game_conf.good())
	{
		std::getline(game_conf, word, ';');
		if (word.compare("TITLE") == 0)
		{
			std::getline(game_conf, word, ';');
			title = word;
			std::cout << title << std::endl;
			std::getline(game_conf, word, '\n');
		}
		else if (word.compare("TEXTURES") == 0)
		{
			std::getline(game_conf, word, ';');
			textures_num = std::stoi(word);
			std::getline(game_conf, word, '\n');

			loadTextures(game_conf, textures_num);
		}
		else if (word.compare("LEVELS") == 0)
		{
			std::getline(game_conf, word, ';');
			levels_num = std::stoi(word);
			std::getline(game_conf, word, ';');
			loadLevels(game_conf, levels_num);
		}
	}
	game_conf.close();
	return 0;

	//OUTPUT
	/*std::ofstream archivo;
	archivo.open("datos.csv");

	archivo << "a;b;c;;\n";
	archivo << "d;e;f;;\n";
	archivo << "1;2;3.456;;\n";
	
	archivo.close();
	return 0;*/


	//INPUT
	/*std::ifstream ip("../Project1/personas.csv");

	if (!ip.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string nombre;
	std::string apellido;
	std::string edad;
	std::string peso;

	int edadi = 0;
	float pesof = 0;

	while (ip.good())
	{
	
		std::getline(ip, nombre ,';');
		std::getline(ip, apellido ,';');
		std::getline(ip, edad,';');
		std::getline(ip, peso ,'\n');

		edadi = std::stoi(edad);
		pesof = std::stof(peso);

		std::cout << "Nombre: " << nombre << " " << apellido << '\n';
		std::cout << "Edad: " << edad << '\n';
		std::cout << "Peso: " << peso << '\n';
		std::cout << "=====================" << '\n';

	}


	ip.close();
	return 0;*/
}