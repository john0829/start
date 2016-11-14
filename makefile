CXXFLAGS = -O3 -o main.exe -L./libCppUnitLite
LIBS = ./cppunitlite/libCppUnitLite.a

main.exe: main.cpp
	g++ main.cpp  $(LIBS) $(CXXFLAGS)
clean:
	rm main.exe
