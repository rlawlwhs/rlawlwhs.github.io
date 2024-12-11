CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(THIRDPARTY_DIR)/npcap/Include
LDFLAGS = -L$(THIRDPARTY_DIR)/npcap/Lib/x64 -lwpcap -lPacket
TARGET = IterDevice

all: $(TARGET)

$(TARGET): IterDevice.o
	$(CXX) $(CXXFLAGS) -o $(TARGET).exe IterDevice.o $(LDFLAGS)

IterDevice.o: IterDevice.cpp
	$(CXX) $(CXXFLAGS) -c IterDevice.cpp

clean:
	rm -f $(TARGET).exe *.o
