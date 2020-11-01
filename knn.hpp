#ifndef KNN_HPP
#define KNN_HPP

#include"table.hpp"
#include"stats.hpp"

class knn {
public:
    knn(std::function<double( const row &, const row &)> metrics ,int k);
    void fit(const table& data,std::string tar);  
    table predict(const table& data);  
private:
    table training_table;
    std::function<double( const row &, const row &)> metrics;
    int k;
    std::string target;
};


#endif      
