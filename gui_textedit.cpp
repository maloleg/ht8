// Подключение заголовочного файла библиотеки zGL
#include "zgl.h"

#include "gui_textedit.h"

TextEdit::TextEdit(size_t x, size_t y)
  : GuiObject(x,y,200,100), m_cursor(0), m_line(0)
{
//  m_textlines.push_back("This is first line\n of big text.");
//  m_textlines.push_back("This is second line of big text.");
//  m_textlines.push_back("This is fird line of big text.");
//  m_textlines.push_back("This is fourth line of big text.");
//  m_textlines.push_back("This is fifth line of big text.");
//  m_textlines.push_back("This is sixth line of big text.");
//  m_textlines.push_back("This is seventh line of big text.");

    m_textlines.clear();
    m_textlines.push_back("");
}

void TextEdit::draw()
{
//  int k = 0;

 // std::vector<std::string> m_textlinesTemp;

//  m_textlinesTemp.resize(m_textlines.size());
//  for (int i = 0; i < m_textlines.size(); i++){
//      m_textlinesTemp.push_back(m_textlines[i]);
//
//      k = m_textlinesTemp.size();
//
//      for (int j = 0; j < m_textlines2.size()*8/m_w; j++){
//          m_textlinesTemp.push_back(m_textlinesTemp[k].substr(j*m_w/8, m_w/8 + j*m_w/8));
//      }
//  }


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
    zgl_DrawLine(fx+2+m_cursor,fy+m_line*16,fx+2+m_cursor,fy+(m_line+1)*16);

  }
  //
  zgl_SetFontColor(ZGL_BLACK);
  for(size_t line=0; line<m_textlines.size(); ++line) {

      /* if (m_textlines[line].size()*8 < m_w) zgl_DrawString(fx + 2, fy + line * 16, m_textlines[line].c_str());
      else{
          for (int i = 0; i < m_textlines[line].size()*8/m_w; i++){
               if (line*16 < m_h) zgl_DrawString(fx + 2, fy + line * 16, m_textlines[line].substr(i*m_w, m_w + i*m_w).c_str());
               std::cout << m_textlines[line].size()*8 << " " << m_w << std::endl;

          }
      }*/
      zgl_DrawString(fx + 2, fy + line * 16, m_textlines[line].c_str());

  }


}

void TextEdit::mouse(unsigned int button, int x, int y)
{
  GuiObject::set_focus(true);
}

void TextEdit::keypress(unsigned int key) {
    switch ((key & 0xFF)) {
        case ZK_UP:
            if (m_line > 0) m_line -= 1;
            break;
        case ZK_DOWN:
            if ((m_line + 1) * 16 + 16 < m_h) m_line += 1;
            break;
        case ZK_LEFT:
            if (m_cursor > 0) m_cursor -= 8;
            break;
        case ZK_RIGHT:
            if (m_cursor < m_w - 8) m_cursor += 8;
            break;
        case ZK_RETURN:
            m_textlines.push_back("");
            m_line++;
            m_cursor = 0;

        default:
            if (is_selected) {
                if (m_cursor < m_w) {
                    std::string s(1, TranslateCodeToSymbol(key));
                    m_textlines[m_line].insert(m_cursor/8, 1, TranslateCodeToSymbol(key));
                    m_cursor += 8;
                }
                else {
                    m_line++;
                    m_textlines.push_back("");
                    m_cursor = 0;
                    std::string s(1, TranslateCodeToSymbol(key));
                    m_textlines[m_line].insert(m_cursor/8, 1, TranslateCodeToSymbol(key));
                }
            }
    }
}

std::string TextEdit::copy(){
    if (is_selected){
        std::string temp = "";


        if (linefrom != lineto) {
            temp += m_textlines[linefrom].substr(selectedfrom, m_textlines[linefrom].size());

            for (int i = linefrom+1; i < lineto-1; i++) temp+=m_textlines[i];

            temp+= m_textlines[lineto].substr(0, lineto);
        }
        else temp += m_textlines[linefrom].substr(selectedfrom, selectedto - selectedfrom);
    }
    else return "";
};

void TextEdit::set_text(const std::vector<std::string> &) {

}

void TextEdit::clear() {m_textlines.clear();}

void TextEdit::clear_selection() {
    is_selected = 0;
    selectedfrom = 0;
    selectedto = 0;
    lineto = 0;
    linefrom = 0;
}



std::string TextEdit::cut(){

}




