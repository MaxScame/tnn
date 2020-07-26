#include <vector>

#include "Neuron.hpp"

class ILayer
{
private:
    std::vector<Neuron> neurons;

public:
    ILayer(/* args */);
    virtual ~ILayer() = 0;
    void AddNeuron(Neuron n);
};

ILayer::ILayer(/* args */)
{
}

ILayer::~ILayer()
{
}

void ILayer::AddNeuron(Neuron n)
{
    neurons.push_back(n);
}