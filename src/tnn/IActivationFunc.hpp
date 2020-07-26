class IActivationFunc
{
public:
    IActivationFunc();
    virtual ~IActivationFunc() = 0;
    virtual double Apply() = 0;
};
