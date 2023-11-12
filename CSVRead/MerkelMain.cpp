#include <iostream>
#include "MerkelMain.h"


MerkelMain::MerkelMain(){
    std::cout << "Call MerkelMain constructor" << std::endl;
}

void MerkelMain::init(){
    // loadOrderBook();
    // orders = csvread::csvReader(filename);
    currenttime = OrderBook::getEarliesetTime();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

// void MerkelMain::loadOrderBook(){
    // orders.push_back(OrderBookEntry{1000,
    //                                 0.02,
    //                                 "2020/03/17 17:01:24.884492",
    //                                 "BTC/USDT",
    //                                 OrderBookType::bid});
                                    
    // orders.push_back(OrderBookEntry{2000,
    //                                 0.02,
    //                                 "2020/03/17 17:01:24.884492",
    //                                 "BTC/USDT",
    //                                 OrderBookType::bid});
    // orders = csvread::csvReader("1.csv");
    // std::cout << "Order Size from MerkelMain::LoadOrderBook is " << orders.size() << std::endl;

// }

double MerkelMain::computeAveratePrice(std::vector<OrderBookEntry> &entries)
{
    std::cout << "average work" << std::endl;
    double average = 0;
    double sum = 0;
    double counter = 0;
    for (OrderBookEntry &e : entries)
    {
        sum += e.price;
        counter += 1;
    }
    average = sum / counter;
    return average;
}

double MerkelMain::computeHighPrice(std::vector<OrderBookEntry> &entries)
{
    std::cout << "High price work" << std::endl;
    double highest = 0;
    for (OrderBookEntry &e : entries)
    {
        if (e.price > highest)
        {
            highest = e.price;
        }
    }
    return highest;
}

double MerkelMain::computeLowPrice(std::vector<OrderBookEntry> &entries)
{
    std::cout << "Low price work" << std::endl;
    double lowest = 1000000000;
    for (OrderBookEntry &e : entries)
    {
        if (e.price < lowest)
        {
            lowest = e.price;
        }
    }
    return lowest;
}

void MerkelMain::printMenu()
{
    std::cout << "1. Print for help" << std::endl;
    std::cout << "2. Print exchange stats" << std::endl;
    std::cout << "3. Make an offer" << std::endl;
    std::cout << "4. Make a bid" << std::endl;
    std::cout << "5. Print wallet" << std::endl;
    std::cout << "6. Print for help" << std::endl;

    std::cout << "=======================" << std::endl;
    std::cout << "Type in 1-6" << std::endl;
}

int MerkelMain::getUserOption()
{
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}

void MerkelMain::printMarketStats()
{
    // std::cout << "this is the exchange stats" << std::endl;
    std::cout << "Calling printMartketStats function" << std::endl;
    for (std::string const& s: orderbook.getKnownProject()){
        std::vector<OrderBookEntry> entries = orderbook.getOrders(OrderBookType::ask,
                                                                  s,
                                                                  "2020/03/17 17:01:30.099017");
        std::cout << "Products: " << s << std::endl;
        std::cout << "Asked: " << entries.size() << std::endl;
        std::cout << "Max ask " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask " << OrderBook::getLowPrice(entries) << std::endl;
    }
}

void MerkelMain::enterAsk()
{
    std::cout << "This is the what you ask for" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Here is the bid" << std::endl;

}

void MerkelMain::printWallet()
{
    std::cout << "Here is the Bid" << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Continue" << std::endl;

}

void MerkelMain::wrongAnswer()
{
    std::cout << "Wrong number" << std::endl;
}
void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 1)
    {
        printHelp();
    }

    if (userOption == 2)
    {
        printMarketStats();
    }

    if (userOption == 3)
    {
        enterAsk();
    }

    if (userOption == 4)
    {
        enterBid();
    }

    if (userOption == 5)
    {
        printWallet();
    }

    if (userOption == 6)
    {
        gotoNextTimeframe();
    }
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
}