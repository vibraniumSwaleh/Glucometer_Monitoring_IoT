#include "Menu.hpp"
#include "EPD_Test.h"
#include "OLED_1in3_c.h"
#include "ImageData.h"
#include "GUI_Paint.h"


Welcome_Msg_0::Welcome_Msg_0(const std::string &msg0_1, const std::string &msg0_2, const std::string &msg0_3)
:welcome_0_1(msg0_1), welcome_0_2(msg0_2), welcome_0_3(msg0_3){}
void Welcome_Msg_0::Display_Message(){
    Paint_DrawString_EN(4, 19, welcome_0_1.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(57, 19, welcome_0_2.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(43, 34, welcome_0_3.c_str(), &Font12, WHITE, BLACK);
}

Welcome_Msg_1::Welcome_Msg_1(const std::string &msg1_1, const std::string &msg1_2, const std::string &msg1_3, const std::string &msg1_4, const std::string &msg1_5)
:welcome_1_1(msg1_1), welcome_1_2(msg1_2), welcome_1_3(msg1_3), welcome_1_4(msg1_4), welcome_1_5(msg1_5){}
void Welcome_Msg_1::Display_Message(){
    Paint_DrawString_EN(1, 1, welcome_1_1.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(9, 13, welcome_1_2.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(9, 25, welcome_1_3.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(9, 37, welcome_1_4.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawString_EN(9, 49, welcome_1_5.c_str(), &Font12, WHITE, BLACK);
}

Welcome_Msg_2::Welcome_Msg_2(const std::string &msg2_1, uint8_t *BI_2_1):welcome_2_1(msg2_1), BImage_2_1(BI_2_1){}
void Welcome_Msg_2::Display_Message(){
    Paint_DrawString_EN(8, 26, welcome_2_1.c_str(), &Font12, WHITE, BLACK);
    OLED_1in3_C_Display(BImage_2_1);
    DEV_Delay_ms(500);
    Paint_DrawPoint(90, 34, WHITE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    OLED_1in3_C_Display(BImage_2_1);
    DEV_Delay_ms(500);
    Paint_DrawPoint(94, 34, WHITE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    OLED_1in3_C_Display(BImage_2_1);
    DEV_Delay_ms(500);
    Paint_DrawPoint(98, 34, WHITE, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    OLED_1in3_C_Display(BImage_2_1);
    DEV_Delay_ms(500);
}

Menu_0::Menu_0(const std::string &menu0_1, const std::string &menu0_2, const std::string &menu0_3, const unsigned char *Graphicx_Array_0[2])
:menu_0_1(menu0_1),menu_0_2(menu0_1), menu_0_3(menu0_3), Graphicx_0{Graphicx_Array_0[0], Graphicx_Array_0[1]}{}
void Menu_0::Display_Menu(){
    Paint_DrawString_EN(1, 1, menu_0_1.c_str(), &Font12, WHITE, BLACK);
    Paint_DrawLine(0, 12, 128, 12, WHITE, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

    Paint_DrawString_EN(26, 21, menu_0_2.c_str(), &Font12, WHITE, BLACK);
    Paint_BmpWindows(5, 16, Graphicx[0], 15, 21);

    Paint_DrawString_EN(26, 46, menu_0_3.c_str(), &Font12, WHITE, BLACK);
    Paint_BmpWindows(2, 42, Graphicx[1], 21, 20);
};

