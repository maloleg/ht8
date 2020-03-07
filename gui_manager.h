#ifndef  GuiManager_h
#define  GuiManager_h

// $ver 2020-02-27

#include <list>

class GuiObject;

// Класс GuiManager контролирует все объекты класса GuiObject и
// осуществляет связь с библиотекой zGL посредством функций:
//   Draw()      - выполняет отрисовку всех созданных GuiObject
//   Mouse()     - передает событие мыши от zGL в GuiObject
//   Keyypress() - передает событие клавиатуры от zGL в GuiObject
//
// Реализует паттерн Одиночка (см. [Гамма, Хелм, Джонсон, Влиссидес])
//
class GuiManager
{
  friend class GuiObject;    // Для упрощения кода класса GuiManager
  
  static GuiManager *m_i;    // Указатель на единственный объект класса
  GuiManager();	             // Закрытый конструктор умолчания
  
  std::list<GuiObject*> m_l; // Список всех созданных объектов GuiObject
                             // см. конструктор/деструктор GuiObject
  
  GuiObject *m_focused;      // Элемент с установленным фокусом
  
  public:
    static GuiManager* Instance();  // Глобальная точка доступа к объекту
    
    // см. gui_manager.cpp и main.cpp
    static void Draw();
    static void Mouse(unsigned int button, int x, int y);
    static void Keypress(unsigned int key);
};

#endif //GuiManager_h
