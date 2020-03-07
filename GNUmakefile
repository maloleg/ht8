PRG=gui
SRC=main.cpp \
    gui_object.cpp \
    gui_manager.cpp \
    gui_label.cpp \
    gui_button.cpp \
    gui_edit.cpp \
    gui_textedit.cpp \
    input.cpp
OBJ=$(SRC:.cpp=.o)

CPPFLAGS+=-I.
CXXFLAGS+=-std=c++17
LDFLAGS+=-L.
LDLIBS+=-lzgl -lGL -lX11

.PHONY: all clean run

all: $(PRG)

$(PRG): $(OBJ)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

.cpp.o:
	$(COMPILE.cpp) $< -o $@

clean:
	$(RM) $(PRG) $(OBJ)

run: $(PRG)
	LD_LIBRARY_PATH=. ./$(PRG)

main.o: main.cpp
gui_object.o: gui_object.h gui_object.cpp
gui_manager.o: gui_manager.h gui_manager.cpp
gui_label.o: gui_label.h gui_label.cpp
gui_button.o: gui_button.h gui_button.cpp
gui_edit.o: gui_edit.h gui_edit.cpp
input.o: input.h input.cpp
