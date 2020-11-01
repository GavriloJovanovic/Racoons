#include "knn.hpp"
#include <stdlib.h>

knn::knn(std::function<double( const row &, const row &)> metrics ,int k) : metrics(metrics),k(k) {
}
void knn::fit(const table& data,std::string tar) {
    training_table = data;
    target = tar;
}
table knn::predict(const table& data) {
    std::vector<std::string> labels;
    for(int i = 0; i < training_table.row_n();i++) {
        labels.push_back(training_table[target][i].get_string());
    }

    std::vector<std::string> class_labels;
    std::vector<std::string> classified_labels;
    std::for_each(training_table[target].begin(),training_table[target].end(),[&class_labels](auto& x){
        class_labels.push_back(x.get_string());
    });
    table table_test = data;
    table_test.pop(target);
    training_table.pop(target);
    table_test.pop("partition");
    training_table.pop("partition");

    for(int i=0;i<table_test.row_n();i++){
        std::vector<std::pair<int,double>> indices;
        for(int j=0;j<training_table.row_n();j++){
            indices.push_back(std::make_pair(j,metrics(training_table[j], table_test[i])));
        }
        std::sort(indices.begin(),indices.end(),[](auto x,auto y){return x.second<y.second;});

        std::vector<std::string> labels;
        for(int j=0;j<k;j++){
            labels.push_back(class_labels[indices[j].first]);
        }
        std::pair<std::string,int>winner=std::make_pair(labels[0],1);
        for(int j=1;j<k;j++){
            if(labels[j]==winner.first)
                winner.second++;
            else {
                winner.second--;
                if( winner.second==0)
                    winner=std::make_pair(labels[j],1);
            }
        }
        classified_labels.push_back(winner.first);
    }
    table_test.push("assigned");
    for(unsigned i=0;i<classified_labels.size();i++)
        table_test["assigned"][i]=entry(classified_labels[i]);
    return table_test;
}

