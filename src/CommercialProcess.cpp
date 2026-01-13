/*****************************************
 *  File_name : CommercialProcess.cpp
 *  상업지구 프로세스 구현
 ******************************************/
#include "CommercialProcess.h"
#include "Shop.h"

CommercialProcess::CommercialProcess() {}

void CommercialProcess::shop_process(Player &player)
{
    Shop shop;
    int c1 = 0, index = 0;
    bool is_success;

    while (true)
    {
        UI.print_shop_menu();
        c1 = safe_int_input();
        if (c1 == 0) 
            break;
        else if (c1 == 1) {
            while (true) {
                clear_screen();
                shop.list_items();
                player.get_inventory().list_inventory();
                UI.print_shop_buy_menu();
                index = safe_int_input();
                if (index == 0)
                    break;
                if (index < 0 || index > shop.slot_size) {
                    UI.print_error_screen();
                    continue;
                }
                is_success = player.buy_item(shop.get_item(index));
                UI.print_shop_buy_result(is_success);
            }
        } else if (c1 == 2) {
            while (true) {
                clear_screen();
                player.get_inventory().list_inventory();
                UI.print_shop_sell_menu();
                index = safe_int_input();
                if (index == 0)
                    break;
                if (index < 0 || index > (int)player.get_inventory().get_slots().size()) {
                    UI.print_error_screen();
                    continue;
                }
                UI.print_ask_sell_count();
                int sell_count = safe_int_input();
                if (sell_count == 0)
                    continue;
                is_success = player.sell_item(index, sell_count);
                UI.print_shop_sell_result(is_success);
            }
        } else {
            UI.print_error_screen();
        }
    }
}

void CommercialProcess::forge_process(Player &player)
{
    int c = 0, index = 0;
    while (true)
    {
        clear_screen();
        UI.print_forge_menu();
        c = safe_int_input();
        if (c == 0)
            break;
        else if (c == 1) {
            while (true)
            {
                clear_screen();
                player.get_inventory().list_inventory();
                UI.print_enhance_selection();
                index = safe_int_input();
                if (index == 0) 
                    break;
                EnhanceResult result = player.enhance_item(index);
                UI.print_forge_result(result);
            }
        }
    }
}

void CommercialProcess::run(Player &player)
{
    while (true)
    {
        clear_screen();
        UI.print_commercialArea_menu();
        CommercialSelect choice = static_cast<CommercialSelect>(safe_int_input());
        switch (choice)
        {
        case CommercialSelect::Exit :
            break;
        case CommercialSelect::Shop :
            shop_process(player);
            break;
        case CommercialSelect::Forge :
            forge_process(player);
            break;
        default :
            break;
        }
        if (choice == CommercialSelect::Exit) break;
    }
}