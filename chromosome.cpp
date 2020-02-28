//
// Created by knassar on 2020-02-28.
//

#include "chromosome.h"

int chromosome::nJobs;
int chromosome::nMachines;

chromosome::chromosome() {
    genes.resize(nJobs);
    for (int i = 0; i < nJobs; i++) {
        mutate(i);
    }
}

chromosome::chromosome(chromosome const & c) {
    genes = c.genes;
    fitness = c.fitness;
}

chromosome chromosome::mate(chromosome c) {
    chromosome offspring(*this);
    int idx = rand() % nJobs;
    for (int i = idx; i < nJobs; i++) {
        offspring.genes[i] = c.genes[i];
    }
    return offspring;
}

void chromosome::calcFitness(vector<pair<int, int>> machines, vector<pair<int, int>> jobs) {
    //first: cpu cores, second: memory
    int leftJobs = 0;
    float utilization = 0;
    vector<pair<int, int>> remainingPower = machines;
    for (int i = 0; i < nJobs; i++) {
        if (remainingPower[genes[i]].first >= jobs[i].first &&
            remainingPower[genes[i]].second + machines[genes[i]].second / 2 >= jobs[i].second) {
            remainingPower[genes[i]].first -= jobs[i].first;
            remainingPower[genes[i]].second -= jobs[i].second;
        } else {
            leftJobs++;
        }
    }
    for (int i = 0; i < nMachines; i++) {
        utilization += (1.0 * machines[i].first - remainingPower[i].first) / machines[i].first;
    }
    fitness = (utilization - 1.0 * leftJobs / nJobs);
}

void chromosome::mutate(int idx) {
    genes[idx] = (rand() % nMachines);
}

bool chromosome::operator<(const chromosome & c) {
    return fitness < c.fitness;
}

void chromosome::printChromosome() {
    cout << "Chromosome: ";
    for (int i = 0; i < nJobs; i++) cout << genes[i] << " ";
    cout << "\t" << "Fitness: " << fitness << endl;
}

void chromosome::setNumbers(int n, int m) {
    nJobs = n;
    nMachines = m;
}
