#ifndef GENERATORS_HPP
#define GENERATORS_HPP

#include <vector>

class VariableGen {
    public:
        VariableGen(const char system_type){
            this->technology = system_type;
            if (system_type == 's'){
                // Solar
                this->annual_constraint = ;
            } else if (system_type == 'w') {
                // Wind
                this->annual_constraint = ;
            } else if (system_type == 'i') {
                // External interconnections
                this->annual_constraint = ;
            } else {
                //////// ERROR HANDLING
            }
        }
    private:
        std::vector<int> nodal_capacities_power;
        int annual_constraint;
        char technology;
        Model<double> generation_profiles;
};

class FlexibleGen {
    public:
        FlexibleGen(const char system_type){
            this->technology = system_type;
            if (system_type == 'h'){
                // Hydro
                this->annual_constraint = ;
            } else if (system_type == 'b') {
                // Bio
                this->annual_constraint = ;
            } else if (system_type == 'f') {
                // Legacy fossil fuels
                this->annual_constraint = ;
            } else if (system_type == 'H') {
                // Hydrogen via gas-peaker
                this->annual_constraint = ;
            } else {
                //////// ERROR HANDLING
            }
        }
        
    private:
        std::vector<int> nodal_capacities_power;
        int annual_constraint;
        char technology;
};

class EnergyStorage {
    public:
        EnergyStorage(const char system_type){
            this->technology = system_type;
            if (system_type == 'b'){
                // Batteries
                this->efficiency = batteryEff;
            } else if (system_type == 'p') {
                // Pumped hydro
                this->efficiency = phesEff;
            } else {
                //////// ERROR HANDLING
            }
        }
    private:
        double efficiency;
        std::vector<int> nodal_capacities_power;
        int capacity_energy;
        char technology;
};

#endif