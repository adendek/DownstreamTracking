//
// Created by Adam Dendek on 26/09/16.
//

#include "gtest/gtest.h"
#include  "PatBBDTSeedClassifier.h"
#include <vector>

using namespace std;

class BBDTTestes : public ::testing::Test {
protected:


public:
    BBDTTestes() : Test() {
        bbdt = new PatBBDTSeedClassifier();
    }

    virtual ~BBDTTestes() {
        delete bbdt;
    }

    PatBBDTSeedClassifier * bbdt;
};

TEST_F(BBDTTestes, should_return_false_for_small_values_of_features)
{
  vector<double> testFeaturesVector = {1,1};
  double expected_value = 0.1;

   EXPECT_EQ(expected_value , bbdt->getMvaValue(testFeaturesVector));
}

TEST_F(BBDTTestes, should_return_true_for_big_first_and_small_second)
{
    vector<double> testFeaturesVector = {9,1};
    double expected_value = 0.9;

    EXPECT_EQ(expected_value , bbdt->getMvaValue(testFeaturesVector));
}


TEST_F(BBDTTestes, should_return_false_for_small_first_and_big_second)
{
vector<double> testFeaturesVector = {1,9};
double expected_value = 0.1;

EXPECT_EQ(expected_value , bbdt->getMvaValue(testFeaturesVector));
}


TEST_F(BBDTTestes, should_return_true_for_big_values_of_features)
{
vector<double> testFeaturesVector = {9,9};
double expected_value = 0.9;

EXPECT_EQ(expected_value , bbdt->getMvaValue(testFeaturesVector));
}
