#include <iostream>
#include <vector>

#include "ActivationFunc.hpp"

#define IODefVal 0.f // I/O default value
#define WDefVal 1.f // Weight default value
#define CoeffDefVal -1.f // Activation function coefficient default value

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
    void SetInputs(std::vector<double>& Inputs);
    void SetWeights(std::vector<double>& Weights);
    double GetOutput();

    // Output func
    size_t getOutputCount();
    void setOutputCount(size_t size);

    void SetActFunc(double (*ActFunc)(double, double));
    void Calculate(double arg);
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

// Calculate func
void Neuron::Calculate(double arg = CoeffDefVal)
{
    double Z = 0.f;
    double Out = -1.f;
    for(size_t i = 0; i < input.size(); i++)
        Z += weight[i] * input[i]; // Sum of Wi*Xi
    Out = func(Z, arg); // Result of activation func
    for(auto& o : output)
        o = Out;
}

void Neuron::SetInputs(std::vector<double>& Inputs)
{
    for(size_t i = 0; i < input.size(); i++)
        input[i] = Inputs[i];
}

void Neuron::SetWeights(std::vector<double>& Weigths)
{
    for(size_t i = 0; i < weight.size(); i++)
        weight[i] = Weigths[i];
}

// Get calculated output
// @return Return only first element, because all elements are equal
double Neuron::GetOutput()
{
    return output.front();
}
