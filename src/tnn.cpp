#include <iostream>

#include "tnn/Network.hpp"


int main()
{
    std::vector<double> input_data = { 1.f, 0.f, 1.f, 0.256f, 1.f, 0.f, 1.f, 0.f};
    Network net;
    net.AddLayer(8, SIGMOID);
    net.AddLayer(4, RELU);
    net.AddLayer(2, TANH);
    net.Input(input_data);
    net.Forward();
    std::cout << "Hello world!" << std::endl;
    return 0;
}