#include <cstdlib>   // for getenv, _putenv
#include <iostream>
#include <windows.h> // for SetEnvironmentVariable

int main() {
    const char* varName = "MY_VAR";

    // ȯ�� ���� Ȯ��
    const char* value = std::getenv(varName);
    if (value) {
        std::cout << varName << " already exists: " << value << std::endl;
    } else {
        std::cout << varName << " not found. Adding it now..." << std::endl;

        // ȯ�� ���� �߰�
        std::string newVar = std::string(varName) + "=DefaultValue";
        if (_putenv(newVar.c_str()) == 0) {
            std::cout << varName << " added successfully (session-only)." << std::endl;
        } else {
            std::cerr << "Failed to add " << varName << std::endl;
        }

        // �ý��� ȯ�� ���� ���� (������)
        if (SetEnvironmentVariable(varName, "DefaultValue")) {
            std::cout << varName << " added successfully (system-wide)." << std::endl;
        } else {
            std::cerr << "Failed to add " << varName << " to system variables." << std::endl;
        }
    }

    return 0;
}