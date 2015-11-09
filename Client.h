/* 
 * File:   Client.h
 * Author: maxim
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <queue>
#include <math.h>
#include "BrokerHandler.h"

struct Transaction{
    int amount;
    double price;
    Transaction(int a, double p):amount(a), price(p){};
};

typedef std::vector<Transaction> op_trace;

struct Client{
    
    double buy_coins(int amount){
        auto price = place_transaction(amount);;
        m_tr.push_back(std::move(Transaction(amount, price)));   
        return price;
    }
    
    double sell_coins(int amount){
        auto price = place_transaction(amount);
        m_tr.push_back(std::move(Transaction(-amount, price)));   
        return price;
    }
    
    double report_net(){
        double avg = 0;
        int sum = 0;
        for(auto a: m_tr){
            avg += (a.price / abs(a.amount));
            sum += a.amount;
        }
        
        avg /= m_tr.size();
        avg *= sum;
        return (round(avg * 1000.0) / 1000.0);
    }
   
    op_trace m_tr;
    
private:
    double place_transaction(int amount){
        double sum = 0;
        int amount_left = amount;
        auto bh = BrokerHandler::get_instance();
        
        while(amount_left > MAX_AMOUNT){
            sum += bh->buy_best_rate(MAX_AMOUNT);
            amount_left -= MAX_AMOUNT;
        }
        
        sum += bh->buy_best_rate(amount_left);
        bh->finish_transaction();
        
        return sum;
    }
};

#endif	/* CLIENT_H */

