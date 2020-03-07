// Подключение заголовочного файла библиотеки zGL
#include "zgl.h"

#include "gui_button.h"

Button::Button(size_t x, size_t y)
  : GuiObject(x,y,80,25), m_pressed(false)
{}

void Button::set_focus(bool foc)
{
  if( m_pressed && foc==false) m_pressed=false;
  GuiObject::set_focus(foc);
}

#if     __cplusplus < 201103L
void Button::set_function(boost::function<void()> f)
#else //__cplusplus >=201103L
void Button::set_function(std::function<void()> f)
#endif//__cplusplus
{
  m_function = f;
}

void Button::draw() const 
{
  // линии окантовки: белая, серая
  size_t wx,wy,ww,wh;
  size_t gx,gy,gw,gh;
  // фон кнопки
  size_t bx,by,bw,bh;
  // рамка фокуса (с отступом по 1 пикселу от окантовки)
  size_t fx,fy,fw,fh;
  
  if(m_pressed==false){
    // линии окантовки: белая, черная, серая
    wx=m_x;   wy=m_y;   ww=m_w-1; wh=m_h-1;
    gx=m_x+1; gy=m_y+1; gw=m_w-2; gh=m_h-2;
    bx=m_x+1; by=m_y+1; bw=m_w-2; bh=m_h-2;
    // рамка фокуса (с отступом по 1 пикселу от окантовки)
    fx=m_x+2; fy=m_y+2; fw=m_w-5; fh=m_h-5;
  }
  else {
    // линии окантовки: белая, черная, серая
    wx=m_x+1; wy=m_y+1; ww=m_w-1; wh=m_h-1;
    gx=m_x+1; gy=m_y+1; gw=m_w-2; gh=m_h-2;
    bx=m_x+2; by=m_y+2; bw=m_w-2; bh=m_h-2;
    // рамка фокуса (с отступом по 1 пикселу от окантовки)
    fx=m_x+3; fy=m_y+3; fw=m_w-5; fh=m_h-5;
  }
  
  // Окантовка
  zgl_SetDrawColor(ZGL_BLACK);       zgl_DrawRect(m_x,m_y,m_w,m_h);
  zgl_SetDrawColor(ZGL_BRIGHTWHITE); zgl_DrawRect(wx,wy,ww,wh);
  zgl_SetDrawColor(ZGL_DARKGRAY);    zgl_DrawRect(gx,gy,gw,gh);
  // Фон кнопки
  zgl_SetDrawColor(ZGL_GRAY);        zgl_FillRect(bx,by,bw,bh);
  // Рамка фокуса
  if(m_pressed==false && m_focus){
    zgl_SetDrawColor(ZGL_BLACK);
    zgl_DrawRect(fx,fy,fw,fh);
  }
}

void Button::mouse(unsigned int button, int x, int y)
{
  if(m_pressed){
    if( m_function ) //оператор bool возвращает false если объект не назначен
    {
      try {
        m_function();
      }
      #if     __cplusplus < 201103L
      catch(boost::bad_function_call &e)
      #else //__cplusplus >=201103L
      catch(std::bad_function_call &e)
      #endif//__cplusplus
      {
        //Произошла ошибка, игнорируем
      }
    }
  }
  m_pressed=!m_pressed;
  set_focus(true);
}

void Button::keypress(unsigned int key)
{}

