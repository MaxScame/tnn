#include <vector>

#include "ILayer.hpp"

class Network
{
private:
    std::vector<ILayer> layers;
public:
    Network(/* args */);
    ~Network();
};

Network::Network(/* args */)
{
}

Network::~Network()
{
}