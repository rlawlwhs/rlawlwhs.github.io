CFLAGS = -I"$(NPCAP_INCLUDE)"
LDFLAGS = -L"$(NPCAP_LIB_x64)" -lwpcap -lPacket

TARGET = .\out\IterDevice.exe
SRC = .\network\IterDevice.c
OUT_DIR = .\out

all: $(TARGET)

$(TARGET): $(SRC) | $(OUT_DIR)
	gcc $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	
	
# 출력 디렉터리 생성
$(OUT_DIR):
	mkdir $(OUT_DIR)

# 청소 규칙
clean:
	if exist $(TARGET) del /f $(TARGET)
	if exist out rmdir /s /q $(OUT_DIR)

.PHONY: all clean

