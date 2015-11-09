/* 
 * File:   ClientStorage.h
 * Author: maxim
 */

#ifndef CLIENTSTORAGE_H
#define	CLIENTSTORAGE_H

#include <unordered_map>
#include <string>
#include "Client.h"

class ClientStorage {
    static ClientStorage * instance;
public:
    static ClientStorage* get_instance();
    
    Client& get_client(std::string cl_name){
        return m_client_storage[cl_name];
    }
    
    

private:
    std::unordered_map<std::string, Client> m_client_storage;
    ClientStorage(){};
    ClientStorage(const ClientStorage& orig);
    //virtual ~ClientStorage();

};

#endif	/* CLIENTSTORAGE_H */

