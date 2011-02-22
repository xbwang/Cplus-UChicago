TARGET=problem2

$(TARGET) : $(TARGET).cpp
	g++ -Wall -l justthread -I/usr/include/justthread -std=c++0x -g -O0 -o $(TARGET) $(TARGET).cpp
	g++ -Wall -l justthread -I/usr/include/justthread -std=c++0x    -O2 -o $(TARGET)rel $(TARGET).cpp

x : $(TARGET)
	./$(TARGET)


clean:
	rm $(TARGET)
	rm $(TARGET)rel
