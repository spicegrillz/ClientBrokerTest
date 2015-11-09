/* 
 * File:   BrokerHandler.h
 * Author: maxim
 */

#include "BrokerHandler.h"

BrokerHandler* BrokerHandler::instance = nullptr;

BrokerHandler* BrokerHandler::get_instance(){
        if(instance == 0){
           instance = new BrokerHandler;
        }
        return instance;
    }

double BrokerHandler::buy_best_rate(int amount){
    double min = 0, curr;
    int br_id = 0, min_id = 0;
    for(auto br: broker_storage){
        curr = br.get_rate(amount);
        if((curr < min || min == 0) && marked_brokers.count(br_id) == 0){
            min = curr;
            min_id = br_id;
        }
        ++br_id;
    }
    marked_brokers.insert(br_id);
    return broker_storage[min_id].buy_coins(amount);
}

void BrokerHandler::add_broker(Broker br){
    broker_storage.push_back(std::move(br));
}

void BrokerHandler::finish_transaction(){
    marked_brokers.clear();
}

void BrokerHandler::clear_brokers(){
    broker_storage.clear();
}

std::vector<int> BrokerHandler::get_total(){
    std::vector<int> res;
    for(auto br: broker_storage)
        res.push_back(br.total);
    return res;
}