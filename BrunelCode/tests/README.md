# Brunel code unit tests
This directory contains sources files of the new Brunel Classifiers Unit Tests.

## Testing strategy 
1. create dummy classifier (python class inherit from Sklearn.BaseClassifer). This classifiers returns predicted probas 0.1 for small value of first feature and 0.9 otherwise.   
2. Generate lookup table with 2 bins. Now I am sure what should be the values of each particular bins.  
3. Generate C++ code of lookup Classifier with base = DummyClassifier.   
  This steps are performed via scripts from [PythonGenerator](https://github.com/adendek/DownstreamTracking/tree/master/BrunelCode/tests/) directory. 

4. create gtest based suite of Unit tests to verify correctness of the c++ 
