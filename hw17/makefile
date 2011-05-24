# SINGLE FILE COMPILE ONLY!
# make x to compile and run in one step
# DO NOT PUT .cpp ON THE END OF THE FILENAME ON THE NEXT LINE!!
TARGET=matrix

CXX=/opt/gcc/gcc-4.5.2/bin/g++
CPPFLAGS=-Wall -I/opt/jt/include/justthread -std=c++0x
LDFLAGS=-ljustthread -L/opt/jt/lib -Wl,-rpath,/opt/jt/lib,-rpath,/opt/gcc/gcc-4.5.2/lib64

$(TARGET) : $(TARGET).cpp

x : $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
