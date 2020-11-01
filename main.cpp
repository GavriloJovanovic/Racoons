#include "table.hpp"
#include "file_reader.hpp"
#include "transformations.hpp"
#include "knn.hpp"
#include "stats.hpp"

int main()
{
    table tabela=loadFromFile("iris.csv");
    partition(tabela,0.7,1);
    table test = tabela[tabela.where("partition",[](auto x){ return  x == entry("test"); } ) ];
    table training = tabela[tabela.where("partition",[](auto x){ return x == entry("training"); })];
    binning_frequency(test,"petal_length",4);
    binning_boundry(test,"petal_length",4);
    std::cout << test << std::endl;
    return 0;
}
