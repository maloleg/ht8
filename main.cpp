// Подключение заголовочного файла библиотеки zGL
#include "zgl.h"

// Заголовочные файлы системы графического интерфейса пользователя
#include "gui_object.h"
#include "gui_manager.h"

// Класс Label
#include "gui_label.h"
// Класс Button
#include "gui_button.h"
// Класс Edit
#include "gui_edit.h"
// Класс TextEdit
#include "gui_textedit.h"

// для exit() и atexit()
#include <cstdlib>


// Пользовательские функции, вызываемые библиотекой zGL (см. main())
void Draw(void);
void Mouse(unsigned int button, int x, int y);
void Keypress(unsigned int key);


#include <iostream>
void exit_message() { std::cout << "exit() called" << std::endl; }
void btn_function() { std::cout << "Button click!" << std::endl; }
class TestClass {
  public:
    void TestFunction()
    {
      std::cout << "Button called TesClass::TestFunction()" << std::endl;
    }
};
// О std::bind см. Джосаттис (Стандартная библиотека)
#if     __cplusplus < 201103L
#include <boost/bind.hpp>
#endif


// Основная функция программы
int main()
{
  // регистрация функции exit_message() для вызова
  // перед завершением программы с помощью exit()
  atexit(exit_message);
  
  // Создание окна, в котором будет происходить отрисовка
  zgl_CreateWindow ( 640, 480, "The Window" ) ;
  
  // Задание цветов для фона окна, текста, отрисовки
  zgl_SetWindowColor( ZGL_GRAY );
  zgl_SetFontColor( ZGL_BLACK );
  zgl_SetDrawColor( ZGL_BLACK );

  
  // Задание пользовательской функции Draw() для отрисовки в окне
  // см. указатели на функцию в Си++
  zgl_SetUserDrawFunction(Draw);
  //zgl_SetUserDrawFunction(&GuiManager::Draw);
  
  // Задание пользовательской функции Mouse() для обработки событий мыши
  // см. указатели на функцию в Си++
  zgl_SetUserMouseFunction(Mouse);
  //zgl_SetUserMouseFunction(&GuiManager::Mouse);
  
  // Задание пользовательской функции Type() для обработки событий клавиатуры
  // см. указатели на функцию в Си++
  zgl_SetUserKeyboardFunction(Keypress);
  //zgl_SetUserKeyboardFunction(&GuiManager::Keypress);
  
  // Загрузка шрифта должна выполняться строго перед отрисовкой текста
  zgl_LoadFont("KOI8-R");
  
  // Создание экземпляров Label
  Label *l1 = new Label(10,10,"Hello, World!");
  Label *l2 = new Label(10,26,32,16,"Hello, World!");
  
  // Создание экземпляра Button и назначение ему простой функции
  Button *b1 = new Button(100,100);
  // О std::function см. Мейерс
  b1->set_function( btn_function );
  
  // Создание экземпляра Button и назначение метода класса экземпляра t
  Button *b2 = new Button(200,100);
  TestClass t;
  // О std::bind см. Джосаттис (Стандартная библиотека)
  #if     __cplusplus < 201103L
  b2->set_function( boost::bind(&TestClass::TestFunction, &t) );
  #else //__cplusplus >=201103L
  b2->set_function( std::bind(&TestClass::TestFunction, &t) );
  #endif//__cplusplus
  
  // Создание экземпляра Edit
  Edit   *e = new Edit(150,10);
  
  // Создание экземпляра TextEdit
  TextEdit *te = new TextEdit(10,200);
  
  // Запуск основного цикла обработки событий ввода/вывода библиотеки zGL
  return zgl_Main();
}


// Пользовательские функции
void Mouse(unsigned int button, int x, int y)
{
  GuiManager::Mouse(button,x,y);
}

void Keypress(unsigned int key)
{
  if( (key&0xFF) == ZK_ESCAPE ) exit(0);
  
  GuiManager::Keypress(key);
}

void Draw(void)
{
  GuiManager::Draw();
}
