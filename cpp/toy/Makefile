# 컴파일러 정의
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(THIRDPARTY_DIR)/rapidjson-master/include

# 타겟 및 소스
TARGET = Japanese.exe
SRC = Japanese.cpp

# 빌드 규칙
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	del /f $(TARGET)

.PHONY: all clean