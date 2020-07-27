#include <vector>

#include "Layer.hpp"

// Neural Network class
class Network
{
private:
    // Vector with all layers
    std::vector<Layer*> layers;

public:
    Network(/* args */);
    ~Network();

    void AddLayer(size_t neuron_count);

    //void LoadNetwork(std::string filename);
    //void SaveNetwork(std::string filename);
};

Network::Network(/* args */)
{
}

Network::~Network()
{
    layers.clear();
}

// Add new layer to network
void Network::AddLayer(size_t neuron_count)
{
    layers.push_back(new Layer(neuron_count));

    if(layers.size() == 1) // If first layer added
    {
        layers.at(0)->InputSet(1); // Because layer first, use 1 input for 1 neurons
        layers.at(0)->prev = nullptr; // No prev layer
    }
}