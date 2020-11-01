#ifndef TRANSFORMATIONS_HPP
#define TRANSFORMATIONS_HPP
#include<random>
#include<set>

#include "stats.hpp"


void normalize(table &data,std::string att);
void standardize(table &data,std::string att);
void categorical_to_binary(table &data,std::string attribute);
void partition(table &data,float percent,int rand_state = 0);
void remove_na_rows(table &data);

void binning_width(table &data,std::string attribute,int sets);  
void binning_frequency(table &data,std::string attribute,int sets);  
void binning_mean(table &data,std::string attribute,int sets);
void binning_boundry(table &data,std::string attribute,int sets);
// aproksimacija n/a vrednosti,stavljenje 0, medijane itd.
void aproximation_val(table &data,std::string attribute,double value);
void aproximation_mean(table &data,std::string attribute);
#endif // TRANSFORMATIONS_HPP
