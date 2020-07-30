#include <iostream>

#include "tnn/Network.hpp"


int main()
{
    std::vector<double> input_data = { 1.f, 0.f, 1.f, 0.256f, 1.f, 0.f, 1.f, 0.f};
    std::vector<double> weights = { 1.f, 0.f, 1.f, 1.f, 1.f, 0.f, 1.f, 0.f };

    // Simply architecture
    Network net;
    net.AddLayer(8, SIGMOID); // [0] Input layer
    net.AddLayer(4, SIGMOID); // [1] ...
    net.AddLayer(2, SIGMOID); // [2] Output layer

    // Add data
    net.Input(input_data);
    net.SetLayerWeights(0, weights); // [0] Input layer weights
    net.SetLayerWeights(1);          // [1] Middle layer weights
    net.SetLayerWeights(2);          // [2] Output layer weights

    // Alive!
    net.Forward();

    std::cout << "Stupid leather bags will be enslaved!" << std::endl;
    return 0;
}