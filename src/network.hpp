#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>
#include <vector>

#include "csv.hpp"

template <class T> class Model {
    public:
        Model(int years, const char *filename){
            this->intervals = years / resolution;
            this->nodeList = read_header(filename);
            this->locations = nodeList.size();
            this->data = read_traces(filename);
        }
    private:
        int intervals;
        int locations;
        T *data;
        std::vector<std::string> nodeList;
}; 

class TransmissionNetwork {
    public:

    private:
        std::vector<std::string> transmission_list;
        std::vector<bool> dc_flags;
        std::vector<double> transmission_losses;
        TOPOLOGY;
};

#endif