# Project Game Technology - Team 6 (SPEK)

![logo](img/logo.png)

Project Game Technology Minor Project

[![Build Status](http://137.116.249.74:8080/job/PGT-CICD/badge/icon)](http://137.116.249.74:8080/job/PGT-CICD/)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

## Code Conventions
For consistency amongst the project members, code conventions have been applied. These conventions have been documented below and in Resharper. With these conventions the coding style will stay consistent.

Types - UpperCamelCase

```cpp
ITileObject(const AHexActor::Hex& hex, const UINT32 starCost, ...)
```

Parameters - lowerCamelCase

```cpp
MineralBasicTile(const AHexActor::Hex& hex)
```

Common Variables - lowerCamelCase

```cpp
	int _energy;
```
Struct Data Members - _lowerCamelCase

```cpp
struct Resources
{
	int _energy;
	int _minerals;
    ...
};
```
Class Data Members - _lowerCamelCase

```cpp
public:
	int32 PopulationHousingValue = 10;
	int EnergyUpkeep = 10;
	int Disdain = 0;
```
Constants - kUpperCamelCase

```cpp
enum class EBuildingType
{
	Mineral,
	Energy,
	House,
	Road
};
```
Functions - UpperCamelCase[all_lower]

```cpp
ITileObject(const AHexActor::Hex& hex, const UINT32 starCost, ...)
```
Class, Struct, Union & Enum - UpperCamelCase

```cpp
class PGTPROJECT_API ToolbarGraphics : public SCompoundWidget
```
Namespaces - all_lower

```cpp
using namespace std;
```
Macros - ALL_UPPER

```cpp
#define _USE_MATH_DEFINES
```

## CICD Deployment

Please read [DEPLOYMENT.MD](CICD/Deployment.md) for details about automated builds and hosting the build system in the cloud.

## Built With

* [Unreal](https://www.unrealengine.com/) - The game engine
* [Visual Studio](https://visualstudio.microsoft.com/) - Code Editor
* [ReSharper C++](https://www.jetbrains.com/resharper-cpp/) - Code Quality Tools
* [Jenkins](https://jenkins.io/) - CICD Tool
* [Doxygen](http://www.doxygen.nl/) - Automated Documentation Tool
* [Ludoscope]() - Generative Grammar Tool - [Joris Dormans](https://nl.linkedin.com/in/joris-dormans-39a5343)


## Versioning

We use [git](https://git-scm.com/) for versioning and [GitKraken](https://www.gitkraken.com/) for it's excellent UI and integrations.

## Authors

* **Aleksej Horvat** - *Initial work*
* **Dylan Piera** - *Initial work*
* **Gabriella Gutierrez** - *Initial work*
* **Martijn van der Meer** - *Initial work*
* **Stefan Djordjevic** - *Initial work*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Thanks to Amit from [Red Blob Games](www.redblobgames.com) for his excellent writeup on [Hexagonal Grids](https://www.redblobgames.com/grids/hexagons/).
* Thanks to Unreal for making our lives just that much _harder_.
* Thanks to Unity for letting us know that there is a _better way_.
