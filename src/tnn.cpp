#include <iostream>

#include "tnn/Network.hpp"


int main()
{
    Network net;
    net.AddLayer(8, SIGMOID);
    net.AddLayer(4, SIGMOID);
    net.AddLayer(2, TANH);
    std::cout << "Hello world!" << std::endl;
    return 0;
}