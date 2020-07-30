
#include <algorithm>
#include <chrono>
#include <vector>

#include "Layer.hpp"

// Neural Network class
class Network
{
private:
    // Vector with all layers
    std::vector<Layer *> layers;

public:
    Network(/* args */);
    ~Network();

    void AddLayer(size_t neuron_count, double (*ActFunc)(double, double));

    void Input(std::vector<double> &Inputs, size_t num);
    void SetLayerWeights(size_t layer_num, std::vector<double> weights);

    void Forward();
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

    if (size == 0)
        return; // Error handling needed

    layers.at(size - 1)->SetActFunc(ActFunc); // Set Activation func for layer

    if (size == 1)                 // If first layer added
        layers.at(0)->InputSet(1); // Because layer first, use 1 input for 1 neurons
    else
    {
        layers.at(size - 2)->SetNextLayer(layers.at(size - 1)); // Setting next for prev layer
        layers.at(size - 1)->SetPrevLayer(layers.at(size - 2)); // Setting prev for this layer

        layers.at(size - 1)->InputSet(layers.at(size - 2)->NeuronCount()); // Setting the number of inputs by prev layer

        // Setting the number of outputs by next layer neuron num
        layers.at(size - 2)->OutputSet(layers.at(size - 1)->NeuronCount());
        layers.at(size - 1)->OutputSet(1); // Setting the number of inputs in last layer = 1
    }
}

void Network::Input(std::vector<double> &Inputs, size_t num = 0)
{
    if (Inputs.size() != layers.at(num)->NeuronCount())
    {
        std::cout << "Too many inputs data" << std::endl;
        return;
    }

    layers.at(num)->SetInputData(Inputs);
}

void Network::SetLayerWeights(size_t layer_num = 0, std::vector<double> weights = {})
{
    if (layer_num == 0)
    {
        if (!weights.size())
            return;
        layers.at(layer_num)->SetWeights(weights);
        return;
    }

    if (!weights.size())
    {
        srand(unsigned(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()));
        std::vector<double> random_weights(layers.at(layer_num)->NeuronCount() * layers.at(layer_num)->GetInputCount());
        std::generate(random_weights.begin(), random_weights.end(), []() { return double(rand() % 10000 + 1) / 10000; });
        layers.at(layer_num)->SetWeights(random_weights);
    }
}

void Network::Forward()
{
    for (size_t i = 0; i < layers.size(); i++)
    {
        if (i > 0)
            layers.at(i)->SetInputData(layers.at(i - 1)->GetOutputData());
        layers.at(i)->Calculate();
    }
}