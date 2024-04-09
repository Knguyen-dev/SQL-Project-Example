#include <iostream>
#include <string>
#include "../source/DBConn.h";
#include "../source/SQLServerConn.h";
#include "../source/BandManager.h";
#include "../source/Band.h";

int main() {
    try {
        SQLServerConn connector;
        std::string connectionString = "DRIVER={SQL Server};SERVER=KN\\SQLEXPRESS;Trusted_Connection=yes;";
        
        connector.connect(connectionString);
        std::cout << "Connection to SQL Server successful." << std::endl;

        // At this point sql server has connected so create a DBConn instance 
        DBConn dbConn (connector.getHDBC());

        BandManager bandManager(dbConn, "bands");
        
        std::string dbName = "record_company";
        dbConn.useDatabase(dbName);

        Band band = bandManager.createBand("Ace Dreamers!");
        std::cout << band << std::endl;
        connector.disconnect();
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}