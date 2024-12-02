#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <vector>
#include <winsock2.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

void PrintTcpTable() {
	// 버퍼 크기 계산
	ULONG bufferSize = 0;
	GetExtendedTcpTable(nullptr, &bufferSize, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);

	std::vector<char> buffer(bufferSize);
	PMIB_TCPTABLE_OWNER_PID tcpTable = reinterpret_cast<PMIB_TCPTABLE_OWNER_PID>(buffer.data());

	// TCP 테이블 가져오기
	if (GetExtendedTcpTable(tcpTable, &bufferSize, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
		std::cout << "Number of TCP connections: " << tcpTable->dwNumEntries << "\n";

		for (DWORD i = 0; i < tcpTable->dwNumEntries; i++) {
			MIB_TCPROW_OWNER_PID& row = tcpTable->table[i];

			// IP 주소 변환
			IN_ADDR localAddr, remoteAddr;
			localAddr.S_un.S_addr = row.dwLocalAddr;
			remoteAddr.S_un.S_addr = row.dwRemoteAddr;

			// 포트 번호 추출
			USHORT localPort = ntohs(static_cast<USHORT>(row.dwLocalPort));
			USHORT remotePort = ntohs(static_cast<USHORT>(row.dwRemotePort));

			// 출력
			std::cout << "Local Address: " << inet_ntoa(localAddr) << ":" << localPort
				<< " -> Remote Address: " << inet_ntoa(remoteAddr) << ":" << remotePort
				<< " | State: " << row.dwState
				<< " | PID: " << row.dwOwningPid << "\n";
		}
	}
	else {
		std::cerr << "Failed to retrieve TCP table.\n";
	}
}

int main() {
	PrintTcpTable();
	return 0;
}
