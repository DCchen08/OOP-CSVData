#pragma once
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "Orderbook.h"
#include "csvread.h"


class MerkelMain{
    public:
        MerkelMain();
        void init();
    private:
        // void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        int getUserOption();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void wrongAnswer();
        void processUserOption(int userOption);

        //* before calling the MerkeMain constructor, we will call OrderBook first /
        OrderBook orderbook{"1.csv"};

        //* initial the current time /
        std::string currenttime;

        // std::vector<OrderBookEntry> orders;
        double computeAveratePrice(std::vector<OrderBookEntry> &orders);
        double computeHighPrice(std::vector<OrderBookEntry> &entries);
        double computeLowPrice(std::vector<OrderBookEntry> &entries);
};
