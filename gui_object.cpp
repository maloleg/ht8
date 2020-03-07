#include "gui_object.h"
#include "gui_manager.h"

// Конструктор умолчания
GuiObject::GuiObject()
  : m_x(0), m_y(0), m_w(0), m_h(0),
    m_visible(true), m_focus(false)
{
  GuiManager::Instance()->m_l.push_back(this);
}

// Конструктор копирования
GuiObject::GuiObject(const GuiObject & o)
  : m_x(o.m_x), m_y(o.m_y), m_w(o.m_w), m_h(o.m_h),
    m_visible(o.m_visible), m_focus(false) // фокус не копируется
{
  GuiManager::Instance()->m_l.push_back(this);
}

// Деструктор
GuiObject::~GuiObject()
{
  GuiManager::Instance()->m_l.remove(this);
  // Если установлен фокус, снимаем его
  if(m_focus) GuiManager::Instance()->m_focused=0;
}

// Конструктор общего вида
GuiObject::GuiObject(size_t x, size_t y, size_t w, size_t h)
  : m_x(x), m_y(y), m_w(w), m_h(h),
    m_visible(true), m_focus(false)
{
  GuiManager::Instance()->m_l.push_back(this);
}

// Методы для доступа к характеристикам GuiObject
size_t GuiObject::x() const {return m_x;}
size_t GuiObject::y() const {return m_y;}
size_t GuiObject::w() const {return m_w;}
size_t GuiObject::h() const {return m_h;}

// Принадлежность точки (x,y) описанному прямоугольнику
bool GuiObject::is_inside(size_t x, size_t y) const
{
  return ( x>m_x && y>m_y && x<(m_x+m_w) && y<(m_y+m_h) );
}

// Методы для изменения видимости и фокуса
bool GuiObject::is_visible() const {return m_visible;}
void GuiObject::set_visible(bool vis) {m_visible=vis;}
bool GuiObject::has_focus() const {return m_focus;}
void GuiObject::set_focus(bool foc)
{
  if(foc)         {m_focus=foc;   GuiManager::Instance()->m_focused=this;}
  else if(m_focus){m_focus=false; GuiManager::Instance()->m_focused=0;}
}
