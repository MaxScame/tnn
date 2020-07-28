#include <iostream>
#include <vector>

#include "ActivationFunc.hpp"

#define IODefVal 0.f // I/O default value
#define WDefVal 1.f // Weight default value

class Neuron
{
private:
    std::vector<double> input;
    std::vector<double> weight;
    std::vector<double> output;
    double (*func)(double, double);
public:
    Neuron();
    Neuron(size_t in,size_t out);
    ~Neuron();

    // Input func
    size_t getInputCount();
    void setInputCount(size_t size);
    std::pair<double, double> getInput(size_t index);

    // Output func
    size_t getOutputCount();
    void setOutputCount(size_t size);

    void SetActFunc(double (*ActFunc)(double, double));
};


Neuron::Neuron()
{
}

// Ctor with init
Neuron::Neuron(size_t in,size_t out) : input(in, IODefVal), weight(in, WDefVal), output(out, IODefVal) {}

Neuron::~Neuron()
{
    input.clear();
    weight.clear();
    output.clear();
}

// Get count of input for one neuron
size_t Neuron::getInputCount()
{
    return input.size();
}

// (Re-)Set input count with default init
void Neuron::setInputCount(size_t size)
{
    input.resize(size, IODefVal);
    weight.resize(size, WDefVal);
}

// Get pair of input and weight values
std::pair<double, double> Neuron::getInput(size_t index)
{
    return std::make_pair(input.at(index), weight.at(index));
}

// Get output count
size_t Neuron::getOutputCount()
{
    return output.size();
}

// Set output count to *size* with default init
void Neuron::setOutputCount(size_t size)
{
    output.resize(size, IODefVal);
}

// Setter for Activation function
void Neuron::SetActFunc(double (*ActFunc)(double, double))
{
    func = ActFunc;
}
