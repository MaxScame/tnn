#include <vector>

#include "Neuron.hpp"

class Layer
{
private:
    std::vector<Neuron*> neurons;

public:
    Layer* prev; // Prev layer
    Layer* next; // Next layer

    Layer(size_t n_count);
    ~Layer();
    void AddNeuron();
    void AddNeurons(size_t count);

    void RemoveNeuron(Neuron& n);

    void InputSet(size_t i_count);
};

// Ctor with creating *n_count* neurons
Layer::Layer(size_t n_count)
{
    for(size_t i = 0; i < n_count; i++)
    {
        neurons.push_back(new Neuron());
    }
}

Layer::~Layer()
{
    for(auto& n : neurons)
        n->~Neuron();
}

// Add new neuron
void Layer::AddNeuron()
{
    neurons.push_back(new Neuron());
}

// Add new *count* neurons
void Layer::AddNeurons(size_t count)
{
    for(size_t i = 0; i < count; i++)
    {
        neurons.push_back(new Neuron());
    }
}

// Remove one(last) neuron from layer
void Layer::RemoveNeuron(Neuron& n)
{
    neurons.pop_back();
}

// Set input count for neurons in layer
void Layer::InputSet(size_t i_count)
{
    for(auto& n : neurons)
    {
        n->setInputCount(i_count);
    }
}