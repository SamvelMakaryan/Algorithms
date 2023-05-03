#include <filesystem>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

void check(int argc, char* argv[]);
void remove(unsigned int);

int main(int argc, char* argv[]) {
	check(argc, argv);
	constexpr const unsigned int count_of_10mb = 2'621'440;
	constexpr const unsigned int count_of_files = 20;
	const std::string file_name = "sorted_file_";
	std::vector<std::fstream> files(count_of_files);
	for (int i = 0; i < count_of_files; ++i) {
		files[i].open(file_name + std::to_string(i) + ".txt", std::ios::out);
		if (!files[i].is_open()) {
			std::cerr << "Cannot open file_name_" << i << std::endl;
			exit(-1);
		}
	}
	std::fstream f(argv[1], std::ios::in);
	if (!f.is_open()) {
		std::cerr << "Cannot open " << argv[1] << " file\n";
		exit(-1);
	}
	std::vector<unsigned int> nums(count_of_10mb);
	for (int i = 0; i < count_of_files; ++i) {
		for (int j = 0; j < count_of_10mb; ++j) {
			f >> nums[j];
		}
		std::sort(nums.begin(), nums.end());
		for (int k = 0; k < count_of_10mb; ++k) {
			files[i] << nums[k] << std::endl;
		}
	}
	f.close();
	for (int i = 0; i < count_of_files; ++i) {
		files[i].close();
	}
	f.open(argv[2], std::ios::out);
	if (!f.is_open()) {
		std::cerr << "Cannot open " << argv[2] << " file\n";
		exit(-1);
	}
	for (int i = 0; i < count_of_files; ++i) {
		files[i].open(file_name + std::to_string(i) + ".txt", std::ios::in);
		if (!files[i].is_open()) {
			std::cerr << "Cannot open file_name_" << i << std::endl;
			exit(-1);
		}
	}
	std::vector<unsigned int> cur_nums(count_of_files);
	for (int i = 0; i < count_of_files; ++i) {
		files[i] >> cur_nums[i];
	}
	while (cur_nums.size() != 0) {
		int index = 0;
		while (!files[index].eof()) {
			index = std::distance(cur_nums.begin(), std::min_element(cur_nums.begin(), cur_nums.end()));
			f << cur_nums[index] << std::endl;
			files[index] >> cur_nums[index];
		}
		cur_nums.erase(cur_nums.begin() + index);
		files[index].close();
		files.erase(files.begin() + index);
	}
	remove(count_of_files);	
}

void check(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Source file wasn't specified\n";
		exit(-1);
	}
	if (!std::filesystem::exists(argv[1])) {
		std::cerr << "Source file doesn't exists\n";
		exit(-1);
	}
	if (argc < 3) {
		std::cerr << "Destination file wasn't specified\n";
		exit(-1);
	}
	if (std::filesystem::exists(argv[2])) {
		std::cout << "Destination file already exist press "
		<< " [y] if you want to modify it"
		<< " [n] if you want to exit program\n";
		std::string answer;
		std::cin >> answer;
		if (answer[0] != 'y') {
			exit(0);
		}
	}
}

void remove(unsigned int count_of_files) {
	const std::string file_name = "sorted_file_";
	for (int i = 0; i < count_of_files; ++i) {
		remove((file_name + std::to_string(i) + ".txt").data());
	}
}
