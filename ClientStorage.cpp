/* 
 * File:   ClientStorage.cpp
 * Author: maxim
 */

#include "ClientStorage.h"

ClientStorage* ClientStorage::instance = nullptr;

ClientStorage* ClientStorage::get_instance() {
        if(instance == 0){
           instance = new ClientStorage;
        }
        return instance;
}