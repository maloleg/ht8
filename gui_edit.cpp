// Подключение заголовочного файла библиотеки zGL
#include "zgl.h"

#include "gui_edit.h"

Edit::Edit(size_t x, size_t y)
  : GuiObject(x,y,80,25), m_cursor(0)
{}

void Edit::draw() const 
{
  // линии окантовки: белая, серая
  size_t wx,wy,ww,wh;
  size_t gx,gy,gw,gh;
  // фон 
  size_t bx,by,bw,bh;
  // рамка фокуса (с отступом по 1 пикселу от окантовки)
  size_t fx,fy,fw,fh;
  
  // линии окантовки: белая, черная, серая
  wx=m_x;   wy=m_y;   ww=m_w;   wh=m_h;
  gx=m_x+1; gy=m_y+1; gw=m_w-2; gh=m_h-2;
  bx=m_x+2; by=m_y+2; bw=m_w-3; bh=m_h-3;
  // рамка фокуса (с отступом по 1 пикселу от окантовки)
  fx=m_x+2; fy=m_y+2; fw=m_w-4; fh=m_h-4;
  
  // Окантовка
  zgl_SetDrawColor(ZGL_DARKGRAY);    zgl_DrawRect(wx,wy,ww,wh);
  zgl_SetDrawColor(ZGL_BRIGHTWHITE); zgl_DrawRect(m_x+1,m_y+1,m_w-1,m_h-1);
  zgl_SetDrawColor(ZGL_BLACK);       zgl_DrawRect(gx,gy,gw,gh);
  zgl_SetDrawColor(ZGL_GRAY);        zgl_DrawRect(gx+1,gy+1,gw-1,gh-1);
  // Фон 
  zgl_SetDrawColor(ZGL_BRIGHTWHITE); zgl_FillRect(bx,by,bw,bh);
  // Рамка фокуса
  if(m_focus){
    zgl_SetDrawColor(ZGL_BLACK);
    //zgl_DrawRect(fx,fy,fw,fh);
    zgl_DrawLine(fx+2+m_cursor,fy,fx+2+m_cursor,fy+fh);
  }
  //
  zgl_SetFontColor(ZGL_BLACK);
  zgl_DrawString(fx+2,fy,"H");
  zgl_SetFontColor(ZGL_BRIGHTWHITE);
  zgl_DrawString(fx+2+8,fy,"ell");
  zgl_SetFontColor(ZGL_BLACK);
  zgl_DrawString(fx+2+8+24,fy,"o, World!");
  zgl_SetDrawColor(ZGL_LIGHTBLUE); 
  zgl_FillRect(fx+2+8,fy,24,16);
}

void Edit::mouse(unsigned int button, int x, int y)
{
  GuiObject::set_focus(true);
}

void Edit::keypress(unsigned int key)
{
  if((key&0xFF)==ZK_BACKSPACE) {if(m_cursor>0)     m_cursor-=8;}
  else                         {if(m_cursor<m_w-8) m_cursor+=8;}
}

