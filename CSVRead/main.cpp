#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "OrderBookEntry.h"
#include "MerkelMain.h"


int main()
{
    // std::map<int, void (*)()> menu;
    // menu[1] = printHelp;
    // menu[2] = printMarketStats;
    // menu[3] = enterAsk;
    // menu[4] = enterBid;
    // menu[5] = printWallet;
    // menu[6] = gotoNextTimeframe;

    // OrderBookEntry obe1(0.02187307, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid);
    // obe1.price = 0.125;
    // OrderBookEntry obe2(0.02187307, 3.467434, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid);
    // obe2.price = 0.5;

    // std::vector<OrderBookEntry> entries;
    // entries.push_back(obe1);
    // entries.push_back(obe2);

    // std::cout << entries[0].price << std::endl;
    // for (OrderBookEntry &e : entries)
    // {
    //     std::cout << e.price << std::endl;
    // }

    // double ave = computeAveratePrice(entries);
    // std::cout << ave << std::endl;

    // double high = computeHighPrice(entries);
    // std::cout << high << std::endl;

    // double low = computeLowPrice(entries);
    // std::cout << low << std::endl;

    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     //processUserOption(userOption);
    //     menu[userOption]();

    //     double example = 0.0111;
    //     std::cout << "example is " << example << std::endl;
    // }
    
    MerkelMain app{};

    app.init();

    return 0;
}