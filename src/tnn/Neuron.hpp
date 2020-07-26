#include <iostream>
#include <vector>


class Neuron
{
private:
    std::vector<double> input;
    std::vector<double> weight;
    std::vector<double> output;

public:
    Neuron(size_t in,size_t out);
    ~Neuron();

    // Input func
    size_t getInputCount();
    void setInputCount(size_t size);
    std::pair<double, double> getInput(size_t index);

    // Output func
    size_t getOutputCount();
    void setOutputCount(size_t size);
};


Neuron::Neuron(size_t in,size_t out) : input(in, 0), weight(in, 1), output(out, 0) {}

Neuron::~Neuron()
{
    input.clear();
    weight.clear();
    output.clear();
}

size_t Neuron::getInputCount()
{
    return input.size();
}

void Neuron::setInputCount(size_t size)
{
    input.resize(size);
}

std::pair<double, double> Neuron::getInput(size_t index)
{
    return std::make_pair(input.at(index), weight.at(index));
}

size_t Neuron::getOutputCount()
{
    return output.size();
}

void Neuron::setOutputCount(size_t size)
{
    output.resize(size);
}