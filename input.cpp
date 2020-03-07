#include "input.h"

SymbolType TranslateCodeToSymbol (CodeType code){
    CodeType symb = code & 0x000000FF;

    if (bool((1 << 12)&code) == 0 && bool((1 << 13)&code) == 0)
        switch (symb){
            case 0x13: return 0x30; break;
            case 0x0a: return 0x31; break;
            case 0x0b: return 0x32; break;
            case 0x0c: return 0x33; break;
            case 0x0d: return 0x34; break;
            case 0x0e: return 0x35; break;
            case 0x0f: return 0x36; break;
            case 0x10: return 0x37; break;
            case 0x11: return 0x38; break;
            case 0x12: return 0x39; break;
            case 0x2f: return 0x3b; break;
            case 0x15: return 0x3d; break;
            case 0x3b: return 0x2c; break;
            case 0x14: return 0x2d; break;
            case 0x3c: return 0x2e; break;
            case 0x3d: return 0x2f; break;
            case 0x31: return 0x60; break;
            case 0x22: return 0x5b; break;
            case 0x33: return 0x5c; break;
            case 0x23: return 0x5d; break;
            case 0x30: return 0x27; break;
//            -----------------------------------
            case 0x26: return 0x61; break;
            case 0x38: return 0x62; break;
            case 0x36: return 0x63; break;
            case 0x28: return 0x64; break;
            case 0x1a: return 0x65; break;
            case 0x29: return 0x66; break;
            case 0x2a: return 0x67; break;
            case 0x2b: return 0x68; break;
            case 0x1f: return 0x69; break;
            case 0x2c: return 0x6a; break;
            case 0x2d: return 0x6b; break;
            case 0x2e: return 0x6c; break;
            case 0x3a: return 0x6d; break;
            case 0x39: return 0x6e; break;
            case 0x20: return 0x6f; break;
            case 0x21: return 0x70; break;
            case 0x18: return 0x71; break;
            case 0x1b: return 0x72; break;
            case 0x27: return 0x73; break;
            case 0x1c: return 0x74; break;
            case 0x1e: return 0x75; break;
            case 0x37: return 0x76; break;
            case 0x19: return 0x77; break;
            case 0x35: return 0x78; break;
            case 0x1d: return 0x79; break;
            case 0x34: return 0x7a; break;
            case 0x24: return 0x0a; break;
            case 0x41: return 0x20; break;
        }

    if (bool((1 << 12)&code) == 1 && bool((1 << 13)&code) == 1)
        switch (symb){
            case 0x13: return 0x29; break;
            case 0x0a: return 0x21; break;
            case 0x0b: return 0x40; break;
            case 0x0c: return 0x23; break;
            case 0x0d: return 0x24; break;
            case 0x0e: return 0x25; break;
            case 0x0f: return 0x5e; break;
            case 0x10: return 0x26; break;
            case 0x11: return 0x2a; break;
            case 0x12: return 0x28; break;
            case 0x2f: return 0x3a; break;
            case 0x15: return 0x2b; break;
            case 0x3b: return 0x3c; break;
            case 0x14: return 0x5f; break;
            case 0x3c: return 0x3e; break;
            case 0x3d: return 0x3f; break;
            case 0x31: return 0x7e; break;
            case 0x22: return 0x7b; break;
            case 0x33: return 0x7c; break;
            case 0x23: return 0x7d; break;
            case 0x30: return 0x22; break;
//            ----------------------------------
            case 0x26: return 0x61; break;
            case 0x38: return 0x62; break;
            case 0x36: return 0x63; break;
            case 0x28: return 0x64; break;
            case 0x1a: return 0x65; break;
            case 0x29: return 0x66; break;
            case 0x2a: return 0x67; break;
            case 0x2b: return 0x68; break;
            case 0x1f: return 0x69; break;
            case 0x2c: return 0x6a; break;
            case 0x2d: return 0x6b; break;
            case 0x2e: return 0x6c; break;
            case 0x3a: return 0x6d; break;
            case 0x39: return 0x6e; break;
            case 0x20: return 0x6f; break;
            case 0x21: return 0x70; break;
            case 0x18: return 0x71; break;
            case 0x1b: return 0x72; break;
            case 0x27: return 0x73; break;
            case 0x1c: return 0x74; break;
            case 0x1e: return 0x75; break;
            case 0x37: return 0x76; break;
            case 0x19: return 0x77; break;
            case 0x35: return 0x78; break;
            case 0x1d: return 0x79; break;
            case 0x34: return 0x7a; break;
            case 0x24: return 0x0a; break;
            case 0x41: return 0x20; break;
        }

    if (bool((1 << 12)&code) == 1 && bool((1 << 13)&code) == 0)
        switch (symb){
            case 0x13: return 0x29; break;
            case 0x0a: return 0x21; break;
            case 0x0b: return 0x40; break;
            case 0x0c: return 0x23; break;
            case 0x0d: return 0x24; break;
            case 0x0e: return 0x25; break;
            case 0x0f: return 0x5e; break;
            case 0x10: return 0x26; break;
            case 0x11: return 0x2a; break;
            case 0x12: return 0x28; break;
            case 0x2f: return 0x3a; break;
            case 0x15: return 0x2b; break;
            case 0x3b: return 0x3c; break;
            case 0x14: return 0x5f; break;
            case 0x3c: return 0x3e; break;
            case 0x3d: return 0x3f; break;
            case 0x31: return 0x7e; break;
            case 0x22: return 0x7b; break;
            case 0x33: return 0x7c; break;
            case 0x23: return 0x7d; break;
            case 0x30: return 0x22; break;
//            -------------------------------------
            case 0x26: return 0x41; break;
            case 0x38: return 0x42; break;
            case 0x36: return 0x43; break;
            case 0x28: return 0x44; break;
            case 0x1a: return 0x45; break;
            case 0x29: return 0x46; break;
            case 0x2a: return 0x47; break;
            case 0x2b: return 0x48; break;
            case 0x1f: return 0x49; break;
            case 0x2c: return 0x4a; break;
            case 0x2d: return 0x4b; break;
            case 0x2e: return 0x4c; break;
            case 0x3a: return 0x4d; break;
            case 0x39: return 0x4e; break;
            case 0x20: return 0x4f; break;
            case 0x21: return 0x50; break;
            case 0x18: return 0x51; break;
            case 0x1b: return 0x52; break;
            case 0x27: return 0x53; break;
            case 0x1c: return 0x54; break;
            case 0x1e: return 0x55; break;
            case 0x37: return 0x56; break;
            case 0x19: return 0x57; break;
            case 0x35: return 0x58; break;
            case 0x1d: return 0x59; break;
            case 0x34: return 0x5a; break;
            case 0x24: return 0x0a; break;
            case 0x41: return 0x20; break;
        }

    if (bool((1 << 12)&code) == 0 && bool((1 << 13)&code) == 1)
        switch (symb){
            case 0x13: return 0x30; break;
            case 0x0a: return 0x31; break;
            case 0x0b: return 0x32; break;
            case 0x0c: return 0x33; break;
            case 0x0d: return 0x34; break;
            case 0x0e: return 0x35; break;
            case 0x0f: return 0x36; break;
            case 0x10: return 0x37; break;
            case 0x11: return 0x38; break;
            case 0x12: return 0x39; break;
            case 0x2f: return 0x3b; break;
            case 0x15: return 0x3d; break;
            case 0x3b: return 0x2c; break;
            case 0x14: return 0x2d; break;
            case 0x3c: return 0x2e; break;
            case 0x3d: return 0x2f; break;
            case 0x31: return 0x60; break;
            case 0x22: return 0x5b; break;
            case 0x33: return 0x5c; break;
            case 0x23: return 0x5d; break;
            case 0x30: return 0x27; break;

            case 0x26: return 0x41; break;
            case 0x38: return 0x42; break;
            case 0x36: return 0x43; break;
            case 0x28: return 0x44; break;
            case 0x1a: return 0x45; break;
            case 0x29: return 0x46; break;
            case 0x2a: return 0x47; break;
            case 0x2b: return 0x48; break;
            case 0x1f: return 0x49; break;
            case 0x2c: return 0x4a; break;
            case 0x2d: return 0x4b; break;
            case 0x2e: return 0x4c; break;
            case 0x3a: return 0x4d; break;
            case 0x39: return 0x4e; break;
            case 0x20: return 0x4f; break;
            case 0x21: return 0x50; break;
            case 0x18: return 0x51; break;
            case 0x1b: return 0x52; break;
            case 0x27: return 0x53; break;
            case 0x1c: return 0x54; break;
            case 0x1e: return 0x55; break;
            case 0x37: return 0x56; break;
            case 0x19: return 0x57; break;
            case 0x35: return 0x58; break;
            case 0x1d: return 0x59; break;
            case 0x34: return 0x5a; break;
            case 0x24: return 0x0a; break;
            case 0x41: return 0x20; break;
        }





        }
