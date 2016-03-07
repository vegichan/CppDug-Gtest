# CppDug-Gtest
Google C++ Testing Framework helps you write better C++ tests.

# Setting up Google Test #

To write a test program using Google Test, you need to compile Google
Test into a library and link your test with it. Download the newest package from `https://github.com/google/googletest`.
Install the package on mac os x or linux:
```
  cd gtest-1.7.0; 
  mkdir build;  
  cd build;  
  cmake ..;  
  make; 
```

# Executing this project #

This project is intended to be used on the CppDug Meetup. Personal explanation is required. The CMake file for this 
project has been provided.
```
  cd CppDug-Gtest; 
  mkdir build;  
  cd build;  
  cmake ..;  
  make; 
  ./runBasicTests;
```

Additional parameters can be provided to the basicTest suite such as `--gtest_also_run_disabled_tests`.