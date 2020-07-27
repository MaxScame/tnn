#include <vector>

#include "Layer.hpp"

class Network
{
private:
    std::vector<Layer*> layers;
public:
    Network(/* args */);
    ~Network();

    void AddLayer(size_t neuron_count);
};

Network::Network(/* args */)
{
}

Network::~Network()
{
    layers.clear();
}

void Network::AddLayer(size_t neuron_count)
{
    layers.push_back(new Layer(neuron_count));

    if(layers.size() == 1) // If first layer added
    {
        layers.at(0)->InputSet(1); // Because layer first, use 1 input for 1 neurons
    }
}