#ifndef  GuiObject_h
#define  GuiObject_h

// $ver 2020-02-20

// Для size_t
#include <cstddef>
#include "input.h"

// Класс GuiObject является базовым для всех элементов гравического интерфейса 
// пользователя. Содержит чисто-виртуальные функции:
//   draw(), mouse(), keypress()
// которые вызываются из класса GuiManager (см. gui_manager.cpp)
// 
class GuiObject {
  protected:
    // Координаты элемента интерфейса внутри окна и его размеры в пикселах
    size_t m_x, m_y, m_w, m_h;
    
    // Видимость элемента и установленный фокус на нем
    bool m_visible, m_focus;
    
  public:
    GuiObject();
    GuiObject(const GuiObject &);
    virtual ~GuiObject();
    GuiObject(size_t x, size_t y, size_t w=0, size_t h=0);
    
    // Методы для доступа к характеристикам GuiObject
    size_t x() const;
    size_t y() const;
    size_t w() const;
    size_t h() const;
    
    // Метод проверки принадлежности точки (x,y) описанному прямоугольнику
    bool is_inside(size_t x, size_t y) const;
    
    // Методы для изменения видимости и фокуса
    bool is_visible() const;
    void set_visible(bool);
    bool has_focus() const;
    virtual void set_focus(bool);
    
    virtual void draw() const = 0;
    virtual void mouse(unsigned int button, int x, int y) = 0;
    virtual void keypress(unsigned int key) = 0;
};

#endif //GuiObject_h
