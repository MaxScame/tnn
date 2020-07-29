#include <cmath>

#define DEFAULT ActivationFuncSigmoid
#define LINEAR ActivationFuncLinear
#define SIGMOID ActivationFuncSigmoid
#define TANH ActivationFuncTanh
#define ELU ActivationFuncELU
#define RELU ActivationFuncReLU
#define LEAKY_RELU ActivationFuncLeakyReLU

class ActivationFunc
{
public:
    ActivationFunc();
    ~ActivationFunc();
    static double ActivationFuncLinear(double Z, double m);
    static double ActivationFuncSigmoid(double Z, double no);
    static double ActivationFuncTanh(double Z, double no);
    static double ActivationFuncELU(double Z, double alpha);
    static double ActivationFuncReLU(double Z, double no);
    static double ActivationFuncLeakyReLU(double Z, double alpha);
};

// Linear activation fuction
// @param Z Sum
// @param m Coefficient before Z
// @return value in range (-INF;INF)
static double ActivationFuncLinear(double Z, double m)
{
    return Z * m;
}

// Sigmoid activation fuction
// @param Z Sum
// @param no Fictive arg for simplify refer to func
// @return value in range (0;1)
static double ActivationFuncSigmoid(double Z, double no)
{
    return 1.f / (1 + exp(-Z));
}

// Tanh activation fuction
// @param Z Sum
// @param no Fictive arg for simplify refer to func
// @return value in range [-1;1]
static double ActivationFuncTanh(double Z, double no)
{
    return (exp(Z) - exp(-Z)) / (exp(Z) + exp(-Z));
}

// ELU activation fuction
// @param Z Sum
// @param alpha Coefficient before exp
// @return value in range (-alpha;INF)
static double ActivationFuncELU(double Z, double alpha)
{
    return Z >= 0 ? Z : alpha * (exp(Z) - 1);
}

// ReLU activation fuction
// @param Z Sum
// @param no Fictive arg for simplify refer to func
// @return value in range [0;INF)
static double ActivationFuncReLU(double Z, double no)
{
    return Z > 0 ? Z : 0;
}

// Leaky ReLU activation fuction
// @param Z Sum
// @param alpha Coefficient before Z
// @return value in range (-INF;INF)
static double ActivationFuncLeakyReLU(double Z, double alpha)
{
    return Z > 0 ? Z : alpha * Z;
}