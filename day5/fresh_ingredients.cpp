#include<bits/stdc++.h>
#include<fstream>
#include<vector>
#include<string>

std::vector<long> getAllIdsFromInput(std::string filePath){
	std::vector<long> ids;
	std::string line;
	std::ifstream inputFile(filePath);
	if(!inputFile.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
	}

	
	while(std::getline(inputFile, line)){
		if(!(line.find('-') != std::string::npos) && !line.empty()){
			ids.push_back(std::stol(line));
		}
	}

	inputFile.close();
	return ids;
}

std::vector<std::vector<long>> getAllRangesFromInput(std::string filePath){
	std::vector<std::vector<long>> pairs;
	std::string line;
	std::ifstream inputFile(filePath);

	if(!inputFile.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
	}
	
	while(std::getline(inputFile, line)){
		std::stringstream ss(line);
		std::string min_str, max_str;
		if(std::getline(ss, min_str, '-') && std::getline(ss, max_str)){
			long min = std::stol(min_str);
			long max = std::stol(max_str);
			std::vector<long> pair;
			pair.push_back(min);
			pair.push_back(max);
			pairs.push_back(pair);
		}
	}


	inputFile.close();
	return pairs;
}

int main(){
	std::vector<std::vector<long>> pairs = getAllRangesFromInput("./input.txt");
	std::vector<long> ids = getAllIdsFromInput("./input.txt");
	int freshIds = 0;

	for(long id: ids){
		for(std::vector<long> pair: pairs){
			if(id >= pair[0] and id <= pair[1]){
				freshIds++;
				break;
			}
		}
	}
	std::cout << freshIds << std::endl;
}
