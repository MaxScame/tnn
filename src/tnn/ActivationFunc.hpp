#include <cmath>

class ActivationFunc
{
public:
    ActivationFunc();
    ~ActivationFunc();
    static double ActivationFuncSigmoid(double Z, double no);
    static double ActivationFuncTanh(double Z, double no);
};

// Sigmoid activation fuction
// @param Z Sum
// @param no Fictive arg for simplify refer to func
// @return value in range (0,1)
static double ActivationFuncSigmoid(double Z, double no)
{
    return 1.f / (1 + exp(-Z));
}

// Tanh activation fuction
// @param Z Sum
// @param no Fictive arg for simplify refer to func
// @return value in range [-1,1]
static double ActivationFuncTanh(double Z, double no)
{
    return (exp(Z) - exp(-Z)) / (exp(Z) + exp(-Z));
}