// Подключение заголовочного файла библиотеки zGL
#include "zgl.h"

#include "gui_label.h"


Label::Label(size_t x, size_t y, const std::string & text)
  : GuiObject(x,y), m_text(text), m_display(text)
{
  m_w = m_text.length()*8;               // Шрифт фиксированного размера!
  m_h = 16;                              // Шрифт фиксированного размера!
}

Label::Label(size_t x, size_t y, size_t w, size_t h, const std::string & text)
  : GuiObject(x,y,w,h), m_text(text)
{
  if(m_h>=16)
    m_display = m_text.substr(0,m_w/8);  // Шрифт фиксированного размера!
}

void Label::draw() const
{
  zgl_DrawString(m_x,m_y,m_display.c_str());
}

// Методы mouse() и keypress() не используются
void Label::mouse(unsigned int,int,int)
{}
void Label::keypress(unsigned int)
{}
