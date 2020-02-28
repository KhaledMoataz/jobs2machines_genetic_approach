#include "chromosome.h"

const int POPULATION_SIZE = 20;
const int GENERATIONS = 10;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //--------Reading input--------
    //number of machines, jobs
    //first: number of cores, second: memory
    freopen("test1.in", "r", stdin);
    int nJobs, nMachines;
    vector<pair<int, int>> jobs, machines;
    cin >> nMachines >> nJobs;
    machines.resize(nMachines);
    jobs.resize(nJobs);
    for (int i = 0; i < nMachines; i++) {
        cin >> machines[i].first >> machines[i].second;
    }
    for (int i = 0; i < nJobs; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    //--------Creating First Generation--------
    chromosome::setNumbers(nJobs, nMachines);
    vector<chromosome>generation;
    for (int i=0; i<POPULATION_SIZE; i++){
        chromosome c;
        c.calcFitness(machines, jobs);
        generation.emplace_back(c);
    }

    //--------Creating New Generations--------
    for (int i=0; i<GENERATIONS; i++){
        sort(generation.rbegin(), generation.rend());
        cout<< "Generation: " << i+1 << "\t";
        generation[0].printChromosome();
        if (i+1 == GENERATIONS) break;

        vector<chromosome> newGeneration;
        int elite = 10 * POPULATION_SIZE / 100;
        for (int j=0; j<elite; j++){
            newGeneration.emplace_back(generation[j]);
        }

        for (int j=0; j<POPULATION_SIZE - elite; j++){
            int parent1 = rand() % POPULATION_SIZE / 2;
            int parent2 = rand() % POPULATION_SIZE / 2;
            chromosome c = generation[parent1].mate(generation[parent2]);
            int mut_idx = rand() % nJobs;
            c.mutate(mut_idx);
            c.calcFitness(machines, jobs);
            newGeneration.emplace_back(c);
        }
        
        generation.clear();
        generation = newGeneration;
    }
    return 0;
}