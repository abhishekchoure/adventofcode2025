#include<bits/stdc++.h>
#include<fstream>
#include<vector>
#include<string>

std::vector<std::string> readInputJoltages(std::string filePath){
	std::vector<std::string> joltages;
	std::string line;
	std::ifstream inputFile(filePath);
	if(!inputFile.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
	}

	while(std::getline(inputFile, line)){
		joltages.push_back(line);
	}

	inputFile.close();
	return joltages;
}

int getLargestPossibleJoltage(std::string joltage){
	int firstLargestBattery = INT_MIN;
	int postIndex = 0;
	for(size_t i=0; i < joltage.length() - 1; i++){
		int battery = joltage[i] - '0';
		if(battery > firstLargestBattery){
			firstLargestBattery = battery;
			postIndex = i;
		}
	}
	
	int secondLargestBattery = INT_MIN;
	std::string leftToSearch = joltage.substr(postIndex + 1);
	
	for(size_t i=0; i < leftToSearch.length(); i++){
		secondLargestBattery = std::max(secondLargestBattery, leftToSearch[i] - '0');
	}

	int largestJoltage = firstLargestBattery * 10 + secondLargestBattery;
	return largestJoltage;
}  

int main(){
	std::vector<std::string> joltages = readInputJoltages("./input.txt");
	int sum = 0;
	for(std::string joltage: joltages){
		int largestJoltage = getLargestPossibleJoltage(joltage);
		std::cout << joltage << " - " << largestJoltage << std::endl;
		sum += largestJoltage;
	}

	std::cout << sum << std::endl;
	return 0;
}
