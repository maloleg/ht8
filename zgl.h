/* zgl.h -- interface of the 'zgl' general purpose graphics library
  version 0.4.2, February 2nd, 2020

  Copyright (C) 2010-2020 Stanislav A. Bulgakov

  This program is freely distributable without licensing fees and is
  provided without guarantee or warrantee expressed or implied. This
  program is -not- in the public domain.
*/

#ifndef ZGL_H
#define ZGL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(WIN32) || defined(_MSC_VER)
#define ZGL_SHARED
#endif

#ifdef    ZGL_SHARED
# define  ZGL_EXPORT __stdcall
# ifndef  ZGL_IMPORT
#  define ZGL_EXTERN extern __declspec(dllimport)
# else  /*ZGL_IMPORT*/
#  define ZGL_EXTERN extern __declspec(dllexport)
# endif /*ZGL_IMPORT*/
#endif  /*ZGL_SHARED*/


#ifndef   ZGL_EXTERN
# define  ZGL_EXTERN extern
#endif  /*ZGL_EXTERN*/
#ifndef   ZGL_EXPORT
# define  ZGL_EXPORT
#endif  /*ZGL_EXPORT*/


#define ZGL_VERSION "0.4.2.10"
#define ZGL_VERNUM 0x042A
#define ZGL_VER_MAJOR 0
#define ZGL_VER_MINOR 4
#define ZGL_VER_REVISION 2
#define ZGL_VER_SUBREVISION 10



ZGL_EXTERN int ZGL_EXPORT zgl_CreateWindow(int width, int height,
                                                      const char *title);
ZGL_EXTERN int ZGL_EXPORT zgl_WindowWidth(void);
ZGL_EXTERN int ZGL_EXPORT zgl_WindowHeight(void);

ZGL_EXTERN int ZGL_EXPORT zgl_Main(void);

ZGL_EXTERN void ZGL_EXPORT zgl_LoadFont(const char * name);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawString(int x, int y, const char *str);



enum ZGL_COLORS
{
  ZGL_BLACK           = 0x00 ,
  ZGL_BLUE            = 0x01 ,
  ZGL_GREEN           = 0x02 ,
  ZGL_CYAN            = 0x03 ,
  ZGL_RED             = 0x04 ,
  ZGL_MAGENTA         = 0x05 ,
  ZGL_BROWN           = 0x06 ,
  ZGL_GRAY            = 0x07 ,
  ZGL_DARKGRAY        = 0x08 ,
  ZGL_LIGHTBLUE       = 0x09 ,
  ZGL_LIGHTGREEN      = 0x0A ,
  ZGL_LIGHTCYAN       = 0x0B ,
  ZGL_LIGHTRED        = 0x0C ,
  ZGL_LIGHTMAGENTA    = 0x0D ,
  ZGL_YELLOW          = 0x0E ,
  ZGL_BRIGHTWHITE     = 0x0F
};



ZGL_EXTERN void ZGL_EXPORT zgl_SetFontColor(enum ZGL_COLORS color);
ZGL_EXTERN void ZGL_EXPORT zgl_SetWindowColor(enum ZGL_COLORS color);
ZGL_EXTERN void ZGL_EXPORT zgl_SetDrawColor(enum ZGL_COLORS color);

ZGL_EXTERN void ZGL_EXPORT zgl_DrawLine(int x1, int y1, int x2, int y2);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawCircle(int cx, int cy, int r);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawArc(int cx, int cy, int r,
                                                       int deg1, int deg2);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawRect(int x1, int y1, int w, int h);
ZGL_EXTERN void ZGL_EXPORT zgl_FontTable(int x, int y, const char *str);

ZGL_EXTERN void ZGL_EXPORT zgl_FillRect(int x1, int y1, int w, int h);
ZGL_EXTERN void ZGL_EXPORT zgl_FillCircle(int cx, int cy, int r);
ZGL_EXTERN void ZGL_EXPORT zgl_FillArc(int cx, int cy, int r,
                                                       int deg1, int deg2);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawPictureGrey(int x, int y, int w, int h,
                                               const unsigned char *grey);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawPictureRGB(int x, int y, int w, int h,
                                              const unsigned char *rgb);
ZGL_EXTERN void ZGL_EXPORT zgl_DrawPictureRGBA(int x, int y, int w, int h,
                                               const unsigned char *rgba);

ZGL_EXTERN void ZGL_EXPORT zgl_SetTimer(unsigned int ms, void (*f)(void));

ZGL_EXTERN void ZGL_EXPORT zgl_SetUserDrawFunction(void (*f)(void));

#define ZM_PRESSED      0x80
#define ZM_TRAFFIC      0x40
#define ZM_LBUTTON      0x01
#define ZM_RBUTTON      0x02
#define ZM_MBUTTON      0x04

ZGL_EXTERN void ZGL_EXPORT zgl_SetUserMouseFunction(
                                 void (*f)(unsigned int button, int x, int y));
ZGL_EXTERN void ZGL_EXPORT zgl_SetUserMouseMoveFunction(
                                 void (*f)(unsigned int button, int x, int y));

#define ZK_BACKSPACE    0x16
#define ZK_TAB          0x17
#define ZK_RETURN       0x24
#define ZK_SHIFT        0x32
#define ZK_CONTROL      0x25
#define ZK_ALT          0x40
#define ZK_PAUSE        0x7F
#define ZK_CAPSLOCK     0x42
#define ZK_ESCAPE       0x09
#define ZK_SPACE        0x41
#define ZK_PAGEUP       0x70
#define ZK_PAGEDOWN     0x75
#define ZK_END          0x73
#define ZK_HOME         0x6E
#define ZK_LEFT         0x71
#define ZK_UP           0x6F
#define ZK_RIGHT        0x72
#define ZK_DOWN         0x74
#define ZK_PRINTSCREEN  0x6B
#define ZK_INSERT       0x76
#define ZK_DELETE       0x77
/* ---------------------- */
#define ZK_0            0x13
#define ZK_1            0x0A
#define ZK_2            0x0B
#define ZK_3            0x0C
#define ZK_4            0x0D
#define ZK_5            0x0E
#define ZK_6            0x0F
#define ZK_7            0x10
#define ZK_8            0x11
#define ZK_9            0x12
/* ---------------------- */
#define ZK_A            0x26
#define ZK_B            0x38
#define ZK_C            0x36
#define ZK_D            0x28
#define ZK_E            0x1A
#define ZK_F            0x29
#define ZK_G            0x2A
#define ZK_H            0x2B
#define ZK_I            0x1F
#define ZK_J            0x2C
#define ZK_K            0x2D
#define ZK_L            0x2E
#define ZK_M            0x3A
#define ZK_N            0x39
#define ZK_O            0x20
#define ZK_P            0x21
#define ZK_Q            0x18
#define ZK_R            0x1B
#define ZK_S            0x27
#define ZK_T            0x1C
#define ZK_U            0x1E
#define ZK_V            0x37
#define ZK_W            0x19
#define ZK_X            0x35
#define ZK_Y            0x1D
#define ZK_Z            0x34
/* ---------------------- */
#define ZK_NUM_0        0x5A
#define ZK_NUM_1        0x57
#define ZK_NUM_2        0x58
#define ZK_NUM_3        0x59
#define ZK_NUM_4        0x53
#define ZK_NUM_5        0x54
#define ZK_NUM_6        0x55
#define ZK_NUM_7        0x4F
#define ZK_NUM_8        0x50
#define ZK_NUM_9        0x51
#define ZK_NUM_MUL      0x3F
#define ZK_NUM_ADD      0x56
#define ZK_NUM_SUB      0x52
#define ZK_NUM_DECIMAL  0x5B
#define ZK_NUM_DIV      0x6A
/* ---------------------- */
#define ZK_F1           0x43
#define ZK_F2           0x44
#define ZK_F3           0x45
#define ZK_F4           0x46
#define ZK_F5           0x47
#define ZK_F6           0x48
#define ZK_F7           0x49
#define ZK_F8           0x4A
#define ZK_F9           0x4B
#define ZK_F10          0x4C
#define ZK_F11          0x5F
#define ZK_F12          0x60
/* ---------------------- */
#define ZK_NUMLOCK      0x4D
#define ZK_SCROLLLOCK   0x4E
/* ---------------------- */
#define ZK_COLON        0x2F
#define ZK_EQUAL        0x15
#define ZK_COMMA        0x3B
#define ZK_MINUS        0x14
#define ZK_PERIOD       0x3C
#define ZK_SLASH        0x3D
#define ZK_TILDE        0x31
#define ZK_LBRACKET     0x22
#define ZK_BACKSLASH    0x33
#define ZK_RBRACKET     0x23
#define ZK_QUOTE        0x30

ZGL_EXTERN void ZGL_EXPORT zgl_SetUserKeyboardFunction(
                                                     void (*f)(unsigned int) );

ZGL_EXTERN const char * ZGL_EXPORT zgl_Version(void);
ZGL_EXTERN unsigned int ZGL_EXPORT zgl_CompileFlags(void);

#ifdef __cplusplus
}
#endif

#endif/*ZGL_H*/

