Problem Definition
==================

Distributing jobs to be executed on different machines is a very
interesting problem. Where we have _n_ machines having different number
of cores and different memory sizes. On the other side, We have _m_ jobs
each requires a certain number of cores and occupies a different memory
capacity than other jobs. The problem is to distribute these jobs on the
machines in a such a way that maximizes the machines utilization and
minimizes the number of left jobs.

The cpu cores is a hard constraint that we can’t violate, while memory
is a soft constraint that can be violated with maximum of half of the
actual memory of the machine.

Proposed Method
===============
This is an optimization problem that can be solved using genetic
algorithms.

Genetic algorithm, which is proposed by John Holland (in 1960), is a
search heuristic that is inspired by Charles Darwin’s theory of
evolution by natural selection. The theory is sometimes described as the
“Survival of the fittest”, where individuals having higher fitness and
better adaptation to the environment are able to survive and produce new
generations with better characteristics and higher chance of surviving.

Genetic algorithms has the capability of finding optimal solutions in
evaluation space while working in the coding space, where the coding
space represents chromosomes which are evolving with generations and the
fitness of these chromosomes is evaluated in the evaluation space. The
evolution is based on concepts as selection, crossover and mutation.

Encoding
--------

We represent the chromosome as a vector of size _m_ (where _m_ is the
number of jobs), each element takes a value from 0 to _n-1_ (where _n_
is the number of machines) which represents which machine this jobs will
be assigned to.

Selection
---------

We pass the fittest 10% in our population to the next generation without
crossover or mutation to make sure we don’t get a worse result in the
new generation. Those are know as the elite parents. Then we randomly
choose two parents from the fittest 50% of the population to do
crossover and mutation on.

Crossover
---------

Mating between parents is done through one point crossover. Where we
randomly choose an index in our vector and swap the remaining elements
between the two parents.

Mutation
--------

Mutation is done by randomly choosing an index in our vector, and assign
this job to a new random machine.

Fitness Calculation
-------------------

Fitness is calculated based on the number of used cores on each machine
and on the other hand not having an idle machine. Also we consider not
leaving jobs as much as possible.

The fitness function can be formulated as follows:

![CodeCogsEqn](https://user-images.githubusercontent.com/32196766/76359005-18d77500-6323-11ea-8f3a-9f0f248e52a6.gif) 
