#include "stats.hpp"


double column_mean(const collumn &c) {
    double sum = 0;
    int n = c.size();

    sum = std::accumulate(c.begin(), c.end(), 0.0, [] (auto x, const auto &y) {
        return x + y.get_double();
    });

    return sum/(double)n;
}

double column_mean2(const collumn &c){
    double sum = 0;
    int n = std::count_if(c.begin(), c.end(),[](auto x) {
        return x != entry("n/a");
    });

    sum = std::accumulate(c.begin(), c.end(), 0.0, [] (auto x, const auto &y) {
        return x + y.get_double();
    });

    return sum/(double)n;
}

double column_stdev(const collumn &c) {
    double mean = column_mean(c);
    double sum = 0;
    sum = std::accumulate(c.begin(), c.end(), 0.0, [mean] (auto x, const auto &y) {
        return x + (y.get_double() - mean)*(y.get_double() - mean);
    });
    int n = c.size();

    return sqrt(sum/(double)(n-1));
}

double column_variance(const collumn &c) {
    double dev = column_stdev(c);
    return dev*dev;
}

double column_covariance(const collumn &c1,  const collumn &c2){
    double c1_mean = column_mean(c1);
    double c2_mean = column_mean(c2);

    double sum = 0;
    int n = std::min(c1.size(), c2.size());

    for(int i = 0; i<n; i++) {
        sum += (c1[i].get_double() - c1_mean)*(c2[i].get_double() - c2_mean);
    }

    return (sum/(double)(n-1));
}

double column_correlation(const collumn &c1, const collumn &c2) {
    return column_covariance(c1, c2)/(column_stdev(c1)*column_stdev(c2));
}

//row
double row_mean(const row &r) {
    double sum = 0;
    int n = r.size();

    sum = std::accumulate(r.cbegin(), r.cend(), 0.0, [] (auto x, const auto &y) {
        return x + y.get_double();
    });

    return sum/(double)n;
}

double row_stdev(const row &r) {
    double mean = row_mean(r);
    double sum = 0;
    sum = std::accumulate(r.cbegin(), r.cend(), 0.0, [mean] (auto x, const auto &y) {
        return x + (y.get_double() - mean)*(y.get_double() - mean);
    });
    int n = r.size();

    return sqrt(sum/(double)(n-1));
}

//row metrics
double hamming_dist(const row &r1, const row &r2) {
    double sum = 0;
    for(auto it1 = r1.cbegin(), it2 = r2.cbegin(); it1 != r1.cend() && it2 != r2.cend(); ++it1, ++it2) {
        if(*it1 != *it2)
            sum++;
    }
    return sum;
}

double manhattan_dist(const row &r1, const row &r2) {
    double sum = 0;
    for(auto it1 = r1.cbegin(), it2 = r2.cbegin(); it1 != r1.cend() && it2 != r2.cend(); ++it1, ++it2) {
       sum += std::abs((*it1).get_double() - (*it2).get_double());
    }
    return sum;
}

double euclidean_dist(const row &r1, const row &r2) {
    double sum = 0;
    for(auto it1 = r1.begin(), it2 = r2.begin(); it1 != r1.end() && it2 != r2.end(); ++it1, ++it2) {
       sum += ((*it1).get_double() - (*it2).get_double())*((*it1).get_double() - (*it2).get_double());
    }
    return sqrt(sum);
}

double smc_dist(const row &r1, const row &r2) {
    double m00 = 0, m11 = 0, m01 = 0, m10 = 0;
    for(auto it1 = r1.cbegin(), it2 = r2.cbegin(); it1 != r1.cend() && it2 != r2.cend(); ++it1, ++it2) {
       if((*it1).get_double() == 0.0 && (*it2).get_double() == 0.0)
           m00++;
       if((*it1).get_double() == 1.0 && (*it2).get_double() == 0.0)
           m10++;
       if((*it1).get_double() == 1.0 && (*it2).get_double() == 1.0)
           m11++;
       if((*it1).get_double() == 0.0 && (*it2).get_double() == 1.0)
           m01++;
    }
    return (m00 + m11)/(m00 + m01 + m10 + m11);
}

double zakard_dist(const row &r1, const row &r2) {
    double m11 = 0, m01 = 0, m10 = 0;
    for(auto it1 = r1.cbegin(), it2 = r2.cbegin(); it1 != r1.cend() && it2 != r2.cend(); ++it1, ++it2) {

       if((*it1).get_double() == 1.0 && (*it2).get_double() == 0.0)
           m10++;
       if((*it1).get_double() == 1.0 && (*it2).get_double() == 1.0)
           m11++;
       if((*it1).get_double() == 0.0 && (*it2).get_double() == 1.0)
           m01++;
    }
    return (m11)/(m01 + m10 + m11);
}

double cos_dist(const row &r1, const row &r2) {
    double sum = 0;
    double l1 = 0, l2 = 0;
    for(auto it1 = r1.cbegin(), it2 = r2.cbegin(); it1 != r1.cend() && it2 != r2.cend(); ++it1, ++it2) {
        sum += ((*it1).get_double()*(*it2).get_double());
        l1 += (*it1).get_double()*(*it1).get_double();
        l2 += (*it2).get_double()*(*it2).get_double();
    }

    return sum/(sqrt(l1)*sqrt(l2));
}

//entry metrics
double nominal_sim(const entry &e1, const entry &e2) {
    if(e1 == e2) return 1.0;
    return 0;
}

double ordinal_sim(const entry &e1, const entry &e2, int n) {
    return 1.0 - std::abs((e1 - e2).get_double())/(double)(n-1);
}
double numeric_sim(const entry &e1, const entry &e2) {
    return -(std::abs((e1 - e2).get_double()));
}

//classification metrics
double accuracy_score(const table &data, const table &classified, std::string target) {
    int hits = 0;

    for(int i = 0; i<classified.row_n(); i++) {
        for(int j = 0; j<data.row_n(); j++) {
            if(data[j].r_name() == classified[i].r_name()) {
                if(data[target][j] == classified["assigned"][i]) {
                        hits++;
                }
            }
        }
    }

    return (double)hits/(classified.row_n());
}

double recall(const table &data, const table &classified, std::string target) {
   //TODO
    return 0;
}

table confusion_matrix(const table &data, const table &classified, std::string target) {
    std::set<std::string> unique;
    for(int i = 0; i<data.row_n(); i++) {
        unique.insert(data[target][i].get_string());
    }

    std::vector<std::string> classes;
    for(const auto& u : unique) {
        classes.push_back(u);
    }

    table res{};
    res.push(classes);
    std::unordered_map<std::string,int> helper;
    for(unsigned int i = 0; i<classes.size(); i++) {
        res.push_row();
        res[i]=entry(0.0);
        res[i].set_name(classes[i]);
        helper[classes[i]]=i;
    }

    for(int i=0;i<classified.row_n();i++){
        std::string predicted=classified["assigned"][i].get_string();
        int ind=data.row_by_name(classified[i].r_name());
        std::string acctual=data[target][ind].get_string();
        res[predicted][helper[acctual]]+=entry(1.0);
    }
    return res;
}
