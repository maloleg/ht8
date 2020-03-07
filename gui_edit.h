#ifndef  GuiEdit_h
#define  GuiEdit_h

// $ver 2020-02-20

#include "gui_object.h"

// Заготовка элемента "поле ввода"
class Edit: public GuiObject
{
  size_t m_cursor;  // Положение курсора, относительно начала элемента
  
  public:
    Edit(size_t x, size_t y);
    
    void draw() const ;
    void mouse(unsigned int button, int x, int y);
    void keypress(unsigned int key);
};

#endif //GuiEdit_h
