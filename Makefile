CXX=g++

SRC_PATH=./src
INC_PATH=$(SRC_PATH)/include
BIN_PATH=./bin

CPP_SRC=$(wildcard $(SRC_PATH)/*.cpp)

VERSION=v0_1_alpha_1
TARGET=$(BIN_PATH)/main_$(VERSION)

$(TARGET) : $(CPP_SRC)
	$(CXX) -I $(INC_PATH) $^ -o $@

.PHONY : clean
clean:
	rm $(TARGET)