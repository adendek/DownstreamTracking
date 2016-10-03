# Brunel code tests
This directory contains sources files of the Classifier's Unit Tests suites.

The tests are based on gtest framework.

## Test strategy
1. Create LookupClassifier as a wrapper of DecisionTree with dummy features. 
2. Convert lookup table to NTuple.
3. Generate the C++ code. Above steps are performed via [this](https://github.com/adendek/DownstreamTracking/blob/master/BrunelCode/tests/PythonGenerator/TableGenerator.ipynb) script
4. Compile C++ project. Type: make
5. Run test suite : ./BBDTtests




