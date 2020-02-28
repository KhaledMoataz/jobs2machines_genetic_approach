//
// Created by knassar on 2020-02-28.
//
#include <bits/stdc++.h>
using namespace std;

#ifndef ASSIGNMENT_2_CHROMOSOME_H
#define ASSIGNMENT_2_CHROMOSOME_H


class chromosome {
public:
    explicit chromosome();
    chromosome(chromosome const &);
    static void setNumbers(int n, int m);
    chromosome mate(chromosome);
    void mutate(int);
    void calcFitness(vector<pair<int, int>> machines, vector<pair<int, int>> jobs);
    void printChromosome();
    bool operator < (const chromosome &);
private:
    vector<int> genes;
    float fitness;

    static int nJobs;
    static int nMachines;
};


#endif //ASSIGNMENT_2_CHROMOSOME_H
