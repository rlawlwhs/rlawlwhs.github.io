#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>  

int main() {
	const char* path = std::getenv("PATH");  
	if (path) {
		std::cout << "PATH 환경변수: " << path << std::endl;
	}
	else {
		std::cout << "환경변수를 찾을 수 없습니다." << std::endl;
	}

	return 0;
}
