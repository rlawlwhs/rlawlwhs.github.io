#include <iostream>
#include <fstream>  // 파일 입출력
#include <string>

int main() {
	std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);  // 읽기, 쓰기, 추가 모드

	if (file.is_open()) {
		file << "새로운 내용을 파일에 추가합니다." << std::endl;  // 파일에 쓰기

		// 파일 읽기 (파일 처음으로 이동 후 읽기)
		file.seekg(0);  // 파일 포인터를 파일의 시작으로 이동
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;  // 읽은 줄 출력
		}

		file.close();  // 파일 닫기
	}
	else {
		std::cout << "파일을 열 수 없습니다." << std::endl;
	}

	return 0;
}
