#ifndef DIFFERENTIAL_EVOLUTION_HPP
#define DIFFERENTIAL_EVOLUTION_HPP

#include <string>
#include <vector>
#include <iostream>
#include <float.h>
#include "sciplus.hpp"

class OptimiseResult {

};

class IOptimizable {

};

class DifferentialEvolutionSolver {
    public:
        DifferentialEvolutionSolver(const IOptimizable& func, std::vector<std::vector<double> > bounds,
                                    double tol, double mutation, double recombination,
                                    int maxiter, int popsize, int workers, std::vector<double> x0) {
            this->tol = tol;

            this->scale = mutation;
            if (mutation >= 2.0 || mutation < 0.0) {
                std::cout < "The mutation constant must be a float in U[0, 2]" < std::endl;
                exit(1);
            }

            this->cross_over_probability = recombination;

            this->limits = transpose_vector(bounds);
            
            this->maxiter = maxiter;

            // Population is scaled to between [0, 1].
            // We have to scale between parameter <-> population
            // Save these arguments for _scale_parameter and 
            // _unscale parameter. This is an optimisation
            for (uint row = 0; row < this->limits.size(); row++){
                this->__scale_arg1.push_back(0.5 * (this->limits[row][0] + this->limits[row][1]));
                this->__scale_arg2.push_back(ABS(this->limits[row][0] - this->limits[row][1]));
            }

            this->parameter_count = this->limits.size();
            this->random_number_generator = check_random_state(seed)

            // default population initialization is a latin hypercube design, but
            // there are other population initializations possible.
            // the minimum is 5 because 'best2bin' requires a population that's at
            // least 5 long
            this->num_population_members = MAX(5, popsize * this->parameter_count);
            this->population_shape[0] = this->num_population_members;
            this->population_shape[1] = this->parameter_count; 
            this->_nfev = 0;
            this->init_population_lhs();

            std::vector<double> x0_scaled = this->_unscale_parameters(x0);
            for (double val : x0_scaled){
                if(val > 1.0 || val < 0.0){
                    std::cout < "Some entries in x0 lay outside the specified bounds" < std::endl;
                    exit(1);
                }
            }

            this->population[0] = x0_scaled;

            this->func = BLAH;
        }

        std::vector<std::vector<double> > init_population_lhs() {
            /*
            Initializes the population with Latin Hypercube Sampling.
            Latin Hypercube Sampling ensures that each parameter is uniformly
            sampled over its range.
            */
            double rng = this->random_number_generator;

            // Each parameter range needs to be sampled uniformly. The scaled
            // parameter range ([0, 1)) needs to be split into
            // `self.num_population_members` segments, each of which has the following
            // size:
            double segsize = 1.0 / this->num_population_members;

            // Within each segment we sample from a uniform random distribution.
            // We need to do this sampling for each parameter.
            double samples = (segsize * rng.uniform(size=self.population_shape)

            // Offset each segment to cover the entire parameter range [0, 1)
                    + np.linspace(0., 1., self.num_population_members,
                                    endpoint=False)[:, np.newaxis])

            // Create an array for population of candidate solutions.
            this->population = np.zeros_like(samples)

            // Initialize population of candidate solutions by permutation of the
            // random samples.
            for j in range(self.parameter_count):
                order = rng.permutation(range(self.num_population_members))
                this->population[:, j] = samples[order, j]

            // reset population energies
            this->population_energies = np.full(self.num_population_members,
                                            np.inf)

            // reset number of function evaluations counter
            this->_nfev = 0;

        }

        OptimiseResult solve(){
            /*
            Runs the DifferentialEvolutionSolver.

            Returns
            -------
            res : OptimizeResult
                The optimization result represented as a ``OptimizeResult`` object.
                Important attributes are: ``x`` the solution array, ``success`` a
                Boolean flag indicating if the optimizer exited successfully and
                ``message`` which describes the cause of the termination. See
                `OptimizeResult` for a description of other attributes.  If `polish`
                was employed, and a lower minimum was obtained by the polishing,
                then OptimizeResult also contains the ``jac`` attribute.
            */

            int nit = 0;
            bool warning_flag = false;

            std::string status_message = _status_message['success'];

            // The population may have just been initialized (all entries are
            // np.inf). If it has you have to calculate the initial energies.
            // Although this is also done in the evolve generator it's possible
            // that someone can set maxiter=0, at which point we still want the
            // initial energies to be calculated (the following loop isn't run).
            bool max_energies = true;
            for (double energy : this->population_energies){
                if (energy < DBL_MAX) {
                    max_energies = false;
                    break;
                }
            }
            if(max_energies) {
                this->population_energies[self.feasible] = (
                    this->_calculate_population_energies(
                        this->population[self.feasible]));

                this->_promote_lowest_energy();
            }

            // do the optimisation
            for (int nit = 1, nit <= this->maxiter, nit++){
                // evolve the population by a generation
            }
        
        }

    private:
        const IOptimizable& func;
        std::vector<std::vector<double> > limits;
        double tol;
        double scale;
        double cross_over_probability;
        int maxiter;
        int popsize;
        int workers;
        std::vector<double> x0;

        std::vector<double> __scale_arg1;
        std::vector<double> __scale_arg2;

        int parameter_count;
        double random_number_generator;

        int num_population_members;
        int population_shape[2];
        int _nfev;

        std::vector<std::vector<double> > population;
        std::vector<std::vector<double> > population_energies;


};

#endif
