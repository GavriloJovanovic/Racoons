#ifndef STATS_HPP
#define STATS_HPP
#include"table.hpp"
#include<cmath>
#include<set>
//column
double column_mean(const collumn &c);

double column_stdev(const collumn &c);

double column_variance(const collumn &c);

double column_covariance(const collumn &c1,  const collumn &c2);

double column_correlation(const collumn &c1, const collumn &c2);

//row
double row_mean(const row &r);

double row_stdev(const row &r);

//row metrics
double hamming_dist(const row &r1, const row &r2);

double manhattan_dist(const row &r1, const row &r2);

double euclidean_dist(const row &r1, const row &r2);

double smc_dist(const row &r1, const row &r2);

double zakard_dist(const row &r1, const row &r2);

double cos_dist(const row &r1, const row &r2);

//entry metrics
double nominal_sim(const entry &e1, const entry &e2);
double ordinal_sim(const entry &e1, const entry &e2, int n);
double numeric_sim(const entry &e1, const entry &e2);

//classification metrics
double accuracy_score(const table &data, const table &classified, std::string target);

double recall(const table &data, const table &classified, std::string target);

table confusion_matrix(const table &data, const table &classified, std::string target);


#endif // STATS_HPP
