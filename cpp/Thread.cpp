#include <iostream>
#include <thread>
#include <chrono>  // 시간 지연을 위해 필요
#include <mutex>   // 뮤텍스 사용을 위해 필요

// 뮤텍스 객체 생성
std::mutex mtx;

// 쓰레드로 실행할 함수 (단일 인자)
void printMessage(const std::string& message) {
	// 뮤텍스를 이용해 안전하게 출력
	mtx.lock();
	std::cout << message << std::endl;
	mtx.unlock();
}

// 쓰레드로 실행할 함수 (여러 인자)
void addNumbers(int a, int b) {
	mtx.lock();
	std::cout << "a + b = " << a + b << std::endl;
	mtx.unlock();
}

// 오래 걸리는 작업 (detach 예시)
void longRunningTask() {
	std::this_thread::sleep_for(std::chrono::seconds(3));  // 3초 대기
	mtx.lock();
	std::cout << "오래 걸리는 작업이 완료되었습니다." << std::endl;
	mtx.unlock();
}

int main() {
	// 1. 기본 쓰레드 예시
	std::thread t1(printMessage, "쓰레드 1: 기본 함수 실행");

	// 2. 람다 함수로 쓰레드 생성
	std::thread t2([]() {
		std::lock_guard<std::mutex> lock(mtx);  // 뮤텍스 자동 관리
		std::cout << "쓰레드 2: 람다 함수 실행" << std::endl;
		});

	// 3. 여러 인자를 전달하는 쓰레드
	std::thread t3(addNumbers, 5, 10);

	// 4. detach 쓰레드 예시 (백그라운드에서 실행)
	std::thread t4(longRunningTask);
	t4.detach();  // 이 쓰레드는 메인 쓰레드와 독립적으로 동작

	// 쓰레드들이 완료될 때까지 대기 (detach한 t4는 제외)
	t1.join();
	t2.join();
	t3.join();

	std::cout << "메인 쓰레드: 모든 작업 완료" << std::endl;

	return 0;
}
