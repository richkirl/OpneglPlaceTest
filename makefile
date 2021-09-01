CXX       	:= g++
CXX_FLAGS 	:= -Wall -Wextra -std=c++17 -ggdb

BIN     	:=  /home/settler/WorDirCXX/013-LearnOpengl/013-LearnOpengl
SRC     	:=  /home/settler/WorDirCXX/013-LearnOpengl/013-LearnOpengl 
INCLUDE 	:= /usr/local/include -I/home/settler/WorDirCXX/013-LearnOpengl/013-LearnOpengl
LIB     	:= /usr/local/lib
LIBRARIES   	:= -lGL -lglfw -lGLEW -lfreetype
EXECUTABLE  	:= main


all:    $(BIN)/$(EXECUTABLE)

run:    	
		$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): *.cpp *.hpp
		$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $> -o $@ $(LIBRARIES)
clean:		clean all
		rm $(EXECUTABLE).o $(EXECUTABLE)
