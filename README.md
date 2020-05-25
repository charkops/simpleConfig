# simpleConfig

* A ( very ) simple config library for c++

* No external dependencies
* Simple txt based config files
* Single value configurations


``` c++

  using namespace simpleConfig;

  // Initialize 
  SimpleConfig config ("../config/test.config"); // Some valid config file, throws if it doesn't exist
  int value = config.getValue<int>("nameOfSomeInt");
  // Value of "nameOfSomeInt" is stored in ${value}
  // Messing up the template instantiation will probably mess up the programm, take care

```