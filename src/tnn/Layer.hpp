#include <vector>

#include "Neuron.hpp"

class Layer
{
private:
    std::vector<Neuron*> neurons;
    Layer* prev; // Prev layer
    Layer* next; // Next layer

public:
    Layer(size_t n_count);
    ~Layer();

    void SetPrevLayer(Layer* l);
    Layer* PrevLayer();

    void SetNextLayer(Layer* l);
    Layer* NextLayer();

    void SetActFunc(double (*ActFunc)(double, double));

    void AddNeuron();
    void AddNeurons(size_t count);

    void RemoveNeuron(Neuron& n);

    void InputSet(size_t i_count);
};

// Ctor with creating *n_count* neurons
Layer::Layer(size_t n_count)
{
    prev = nullptr;
    next = nullptr;

    for(size_t i = 0; i < n_count; i++)
    {
        neurons.push_back(new Neuron());
    }
}

Layer::~Layer()
{
    for(auto& n : neurons)
        n->~Neuron();
    delete prev;
    delete next;
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

// Setter for previous layer
void Layer::SetPrevLayer(Layer* l)
{
    prev = l;
}

// Getter for previous layer
Layer* Layer::PrevLayer()
{
    return prev;
}

// Setter for next layer
void Layer::SetNextLayer(Layer* l)
{
    next = l;
}

// Getter for next layer
Layer* Layer::NextLayer()
{
    return next;
}

void Layer::SetActFunc(double (*ActFunc)(double, double))
{
    for(auto& n : neurons)
        n->SetActFunc(ActFunc);
}