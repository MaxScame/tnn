#include <iostream>

#include "tnn/Network.hpp"


int main()
{
    Network net;
    net.AddLayer(8);
    std::cout << "Hello world!" << std::endl;
    return 0;
}