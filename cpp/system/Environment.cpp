#include <cstdlib>
#include <iostream>
#include <windows.h>

int main() {
    const char* varName = "MY_VAR";

    // 환경 변수 확인
    const char* value = std::getenv(varName);
    if (value) {
        std::cout << varName << " already exists: " << value << std::endl;
    } else {
        std::cout << varName << " not found. Adding it now..." << std::endl;

        // 환경 변수 추가
        std::string newVar = std::string(varName) + "=DefaultValue";
        if (_putenv(newVar.c_str()) == 0) {
            std::cout << varName << " added successfully (session-only)." << std::endl;
        } else {
            std::cerr << "Failed to add " << varName << std::endl;
        }

        // 시스템 환경 변수 설정 (영구적)
        if (SetEnvironmentVariable(varName, "DefaultValue")) {
            std::cout << varName << " added successfully (system-wide)." << std::endl;
        } else {
            std::cerr << "Failed to add " << varName << " to system variables." << std::endl;
        }
    }

    return 0;
}
