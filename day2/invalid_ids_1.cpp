#include<bits/stdc++.h>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

std::vector<std::string> readInputFile(std::string filePath){	
	std::vector<std::string> idRanges;
	std::vector<std::string> tokens;
	std::string line;
	std::ifstream inputFile(filePath);
	if(!inputFile.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
	}

	while(std::getline(inputFile, line)){
		idRanges.push_back(line);
	}
	inputFile.close();

	std::string input = idRanges[0];
	std::stringstream ss(input);
	std::string token;

	while(std::getline(ss, token, ',')){
		tokens.push_back(token);
	}

	return tokens;
}

long getSumOfInvalidIds(std::vector<std::string> range){
	long sum = 0;
	long start = std::stol(range[0]);
	long end = std::stol(range[1]);

	std::cout << start << "-" << end << std::endl;

	for(long i=start; i <= end; i++){
		std::string number = std::to_string(i);
		size_t length = number.length();

		if(length % 2 != 0) continue;
		
		long left = 0;
		long right = length / 2;
		bool isInvalid = true;

		while(right < length){
			if(number[left] != number[right]){
				isInvalid=false;
				break;
			}
			right++;
			left++;
		}

		if(isInvalid){
			std::cout << i << std::endl;
			sum += i;
			isInvalid = true;
		}
	}

	std::cout << std::endl;
	return sum;
}

int main(){
	long sum = 0;
	std::vector<std::string> idRanges = readInputFile("./input.txt");
	for(std::string range: idRanges){
		std::vector<std::string> pair;
		std::stringstream ss(range);
		std::string token;

		while(std::getline(ss, token, '-')){
			pair.push_back(token);
		}
			
		sum += getSumOfInvalidIds(pair);
	}	

	std::cout << sum << std::endl;
	return 0;
}
