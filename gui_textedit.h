#ifndef  GuiTextEdit_h
#define  GuiTextEdit_h

// $ver 2020-02-27

#include "gui_object.h"

#include <vector>
#include <string>

// Заготовка элемента "редактор текста"
class TextEdit: public GuiObject
{
  size_t m_cursor;  // см. Edit
  size_t m_line;    //

  size_t selectedfrom;
  size_t selectedto;

  size_t linefrom;
  size_t lineto;
  bool is_selected;

  std::vector<std::string> m_textlines;

  std::string Big;

  
  public:
    TextEdit(size_t x, size_t y);
    
    void draw();
    void mouse(unsigned int button, int x, int y);
    void keypress(unsigned int key);

    void set_text(const std::vector<std::string>&);

    std::string copy();
    void clear();
    void clear_selection();
    std::string cut();
    void paste(std::string);
    bool has_selection() const;
};

#endif //GuiTextEdit_h
