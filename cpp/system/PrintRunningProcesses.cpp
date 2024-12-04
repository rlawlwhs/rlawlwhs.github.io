#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "psapi.lib")

void PrintRunningProcesses() {
	DWORD processes[1024], processCount, needed;

	// 실행 중인 프로세스 ID 목록 가져오기
	if (!EnumProcesses(processes, sizeof(processes), &needed)) {
		std::cerr << "Failed to enumerate processes.\n";
		return;
	}

	// 프로세스 개수 계산
	processCount = needed / sizeof(DWORD);

	std::wcout << L"Number of running processes: " << processCount << L"\n";

	for (unsigned int i = 0; i < processCount; i++) {
		if (processes[i] == 0) {
			continue;
		}

		// 프로세스 핸들 열기
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processes[i]);

		if (hProcess) {
			TCHAR processName[MAX_PATH] = TEXT("<unknown>");
			TCHAR processPath[MAX_PATH] = TEXT("<unknown>");
			DWORD size = MAX_PATH;

			// 프로세스 이름 가져오기
			if (GetModuleBaseName(hProcess, NULL, processName, sizeof(processName) / sizeof(TCHAR))) {
				// 프로세스 전체 경로 가져오기
				if (QueryFullProcessImageName(hProcess, 0, processPath, &size)) {
					std::wcout << L"PID: " << processes[i]
						<< L" | Name: " << processName
						<< L" | Path: " << processPath << L"\n";
				}
				else {

					std::wcout << L"PID: " << processes[i]
						<< L" | Name: " << processName
						<< L" | Path: " << GetLastError() << L"\n";
				}
			}


			// 핸들 닫기
			CloseHandle(hProcess);
		}
		else {
			std::wcout << L"PID: " << processes[i] << L" | <Access Denied>\n";
		}
	}
}

int main() {
	PrintRunningProcesses();
	return 0;
}
