#include <vector>

#include "Layer.hpp"

#define DEFAULT ActivationFuncSigmoid
#define SIGMOID ActivationFuncSigmoid
#define TANH ActivationFuncTanh

// Neural Network class
class Network
{
private:
    // Vector with all layers
    std::vector<Layer*> layers;

public:
    Network(/* args */);
    ~Network();

    void AddLayer(size_t neuron_count, double (*ActFunc)(double, double));

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
void Network::AddLayer(size_t neuron_count, double (*ActFunc)(double, double))
{
    layers.push_back(new Layer(neuron_count));
    size_t size = layers.size();
    
    if(size == 0) return; // Error handling needed

    layers.at(size - 1)->SetActFunc(ActFunc); // Set Activation func for layer

    if(size == 1) // If first layer added
    {
        layers.at(0)->InputSet(1); // Because layer first, use 1 input for 1 neurons
    }
    else
    {
        layers.at(size - 2)->SetNextLayer(layers.at(size - 1)); // Setting next for prev layer
        layers.at(size - 1)->SetPrevLayer(layers.at(size - 2)); // Setting prev for this layer
    }

}