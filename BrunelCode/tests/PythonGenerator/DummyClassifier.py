import numpy
import pandas
from sklearn.base import ClassifierMixin, BaseEstimator

__author__ = 'Adam Dendek'


class DummyClassifier(BaseEstimator, ClassifierMixin):
    def __init__(self):
        self.threshold = 0.5

    def fit(self, X, y, sample_weight=None):
        pass

    def predict_proba(self, X):
        if X[:,0] > self.threshold:
            return 0.9
        else:
            return 0.1