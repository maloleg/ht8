#ifndef  GuiLabel_h
#define  GuiLabel_h

// $ver 2020-02-19

#include "gui_object.h"

#include <string>

class Label: public GuiObject
{
  std::string m_text;     // Содержит текст
  std::string m_display;  // Содержит отображаемый текст
  
  public:
    Label(size_t x, size_t y, const std::string & text);
    Label(size_t x, size_t y, size_t w, size_t h, const std::string & text);
    
    void draw() const ;
    // Методы mouse() и keypress() не используются
    void mouse(unsigned int,int,int);
    void keypress(unsigned int);
};

#endif //GuiLabel_h
