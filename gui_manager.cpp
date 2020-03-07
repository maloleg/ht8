#include "gui_object.h"
#include "gui_manager.h"

// Статическое поле должно иметь определение
GuiManager* GuiManager::m_i=0;  // см. про 0, NULL и nullptr в Си++

// Конструктор умолчания
GuiManager::GuiManager()
  : m_focused(0)
{
  m_i = this;
}

// Глобальная точка доступа (см. паттерн Одиночка)
GuiManager* GuiManager::Instance()
{
  if(m_i==0) return new GuiManager();
  return m_i;
}

// Статический метод для связи с библиотекой zGL
void GuiManager::Draw()
{
  std::list<GuiObject*>::iterator i;
  for(i  = GuiManager::Instance()->m_l.begin(); 
      i != GuiManager::Instance()->m_l.end();
      ++i)
    if( (*i)->is_visible() ) (*i)->draw(); // рисуем видимые
}

// Статический метод для связи с библиотекой zGL
void GuiManager::Mouse(unsigned int button, int x, int y)
{
  bool miss=true;
  std::list<GuiObject*>::iterator i;
  for(i  = GuiManager::Instance()->m_l.begin(); 
      i != GuiManager::Instance()->m_l.end();
      ++i)
    if( (*i)->is_visible() && (*i)->is_inside(x,y) )
    { // элемент видим и мы попали в него
      
      //если фокус на другом елементе, снимаем с него фокус
      if(GuiManager::Instance()->m_focused &&
         GuiManager::Instance()->m_focused != (*i) )
        GuiManager::Instance()->m_focused->set_focus(false);
      
      (*i)->mouse(button,x,y); // передаем управление элементу
      miss=false;              // элемент обработан, фокус перемещен
      break;                   // игнеорируем остальные элементы
    }
  
  // если не попали ни в один элемент сбрасываем фокус
  if(miss) {
    if(GuiManager::Instance()->m_focused)
      GuiManager::Instance()->m_focused->set_focus(false);
    GuiManager::Instance()->m_focused=0;
  }
}

// Статический метод для связи с библиотекой zGL
void GuiManager::Keypress(unsigned int key)
{
  if( GuiManager::Instance()->m_focused )
    GuiManager::Instance()->m_focused->keypress(key);
}
