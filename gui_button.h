#ifndef  GuiButton_h
#define  GuiButton_h

// $ver 2020-02-27

#include "gui_object.h"

#if     __cplusplus < 201103L
#include <boost/function.hpp>
#else //__cplusplus >=201103L
#include <functional>
#endif//__cplusplus

// Элемента интерфейса "кнопка".
// Позволяет назначить действие, выполняемое при нажатии.
// 
// Зависимости: библиотека boost или Си++11 и новее
// 
class Button: public GuiObject
{
  bool m_pressed;
  
  // О std::function см. Мейерс
  #if     __cplusplus < 201103L
  boost::function<void()> m_function;
  #else //__cplusplus >=201103L
  std::function<void()> m_function;
  #endif//__cplusplus
  
  public:
    Button(size_t x, size_t y);
    
    void set_focus(bool);
    
    #if     __cplusplus < 201103L
    void set_function(boost::function<void()>);
    #else //__cplusplus >=201103L
    void set_function(std::function<void()>);
    #endif//__cplusplus
    
    void draw() const ;
    void mouse(unsigned int button, int x, int y);
    void keypress(unsigned int key);
};

#endif //GuiButton_h
