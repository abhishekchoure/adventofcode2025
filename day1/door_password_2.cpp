#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<fstream>

std::vector<std::string> readDocument(std::string filePath){
	std::vector<std::string> rotations;
	std::string line;
	std::ifstream inputFile(filePath);
	if(!inputFile.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
	}

	while(std::getline(inputFile, line)){
		rotations.push_back(line);
	}

	inputFile.close();
	return rotations;
}

int main(){
	std::vector<std::string> rotations = readDocument("./input.txt");	
	int pointer = 50;
	int counter = 0;

	for(std::string rotation: rotations){
		std::string degreeStr = rotation.substr(1);
		int degree = std::stoi(degreeStr);

		if(degreeStr.length() == 3){
			counter += degree / 100;
			degree = degree % 100;
		}
		
		if(rotation[0] == 'L'){
			if(pointer - degree < 0){
				if(pointer != 0) counter++;
				pointer = pointer - degree + 100;
			}else if(pointer - degree == 0){
				counter++;
				pointer = 0;
			}else{
				pointer = pointer - degree;
			}
		}

		if(rotation[0] == 'R'){
			if(pointer + degree > 99){
				pointer = pointer + degree - 100;
				counter++;
			}else if(pointer + degree == 100){
				counter++;
				pointer = 0;
			}else{
				pointer = pointer + degree;
			}
		}
	}

	std::cout << counter << std::endl;
	return 0;
}
