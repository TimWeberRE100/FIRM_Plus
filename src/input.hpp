#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <vector>

#include "generators.hpp"
#include "network.hpp"

class Solution {
    public:
        Solution(std::vector<double> decision_variables){
            this->MLoad
            this->
        }
    private:
        Model<double> MLoad;
        Model<double> baseload;

        VariableGen solar;
        VariableGen wind;
        VariableGen inter;

        FlexibleGen hydro;
        FlexibleGen bio;
        FlexibleGen fossil;
        FlexibleGen hydrogen;

        EnergyStorage phes;
        EnergyStorage battery;

};

class StaticInputs {
    public:

    private:
        std::vector<int> decision_variable_ub;
        std::vector<std::string> node_list;
        std::vector<std::string> pv_list;
        std::vector<std::string> wind_list;
        std::vector<std::string> inter_list;

        TransmissionNetwork transmission;

        int first_year;
        int final_year;
        int annual_intervals = int(8760 / resolution);
        int years = final_year - first_year + 1;
        int total_intervals = years*8760*resolution;

        int pidx, phidx, bidx;
        int iidx;
        int hidx;
};

#endif