# Tiny Neural Network

Simple neural network implementation. Suitable for educational purposes.

Implementation allows you to add your own training methods, activation functions and network architecture.

## Usage:

All work with the network will be done inside the file `tnn.cpp`.

```
🚧 Work in progress 🚧
```

## Compile

I used `g++` to compile. All work was done on Windows 10 Enterprise x64.

### Windows

You can download `g++` as part of MinGW [here](https://github.com/JerryGoyal/MinGW64/releases).

Unpack it so that the path to `g++` looks like this
```
C:\\MinGW64\\bin\\g++.exe
```
or just edit the project settings in `.vscode/launch.json` and `.vscode/tasks.json` when you download it.


**After all, open it via VS Code and Run!**

### GNU/Linux

```
🚧 Work in progress 🚧
```

## Project tree

```bash
.
│   README.md             // This File
├───.vscode               // VS Code settings
│       launch.json
│       settings.json
│       tasks.json
├───bin
│       tnn.exe           // Output application file
├───doc                   // Docs folder
└───src
    │   tnn.cp           // Main file
    └───tnn              // Internal classes
            ActivationFuncSigmoid.hpp
            IActivationFunc.hpp
            IArch.hpp
            ILayer.hpp
            ILearnMethod.hpp
            Network.hpp
            Neuron.hpp
            SimpleLayer.hpp
```