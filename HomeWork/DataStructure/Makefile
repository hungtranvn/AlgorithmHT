CXXFLAGS += -g -Wall -std=c++17

NAME = run
TARGET = $(NAME)

OBJECTS = main.o SequenceInterfaceStaticArray.o SequenceInterfaceLinkedList.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
    
clean:
	-rm -f *.o $(TARGET)