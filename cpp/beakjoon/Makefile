CXX = g++
TARGET = 14940

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CXX) $(CXXFLAGS) -o $(TARGET).exe $(TARGET).o $(LDFLAGS)

$(TARGET).o: $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -c $(TARGET).cpp

clean:
	rm -f $(TARGET).exe *.o