#include <vector>
#include "differential_evolution.hpp"

std::vector<double> differential_evolution(const IOptimizable& func, std::vector<std::vector<double> > bounds,
                                            double tol, std::vector<double> mutation, double recombination,
                                            int maxiter, int popsize, int workers, std::vector<double> x0) {
    DifferentialEvolutionSolver solver = DifferentialEvolutionSolver(func, bounds, maxiter=maxiter, popsize=popsize,
                                            mutation=mutation,recombination=recombination,workers=workers,x0=x0);
    
    std::vector<double> to_return = solver.solve();

    return to_return;
}