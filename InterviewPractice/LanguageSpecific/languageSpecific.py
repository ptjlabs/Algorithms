#----------------------------------------------------------------------------------------------------------------------------------
# Installation
#-------------------------
# Installing pip
sudo apt-get update
sudo apt-get install pip # Installing any library
sudo pip install tensorflow
sudo pip install anyPythonLibraryName
# Installing from a requirements.txt
sudo pip install -r requirements.txt 
# Installing from setup.py
sudo pip install .

#----------------------------------------------------------------------------------------------------------------------------------
# Working with new libraries
#-------------------------
import libraryName
help(libraryName)
print dir(libraryName) # List all methods for the library
help(libraryName.methodName)

# To print all variables of a class object
from pprint import pprint
pprint(vars(classInstance))
#----------------------------------------------------------------------------------------------------------------------------------
# Headers and Libraries
#-------------------------
# Built-in
import os
import random
# Testing
import unittest
import mock
import traceback # For tracing exception handlers
import pdb # For debugging
import pytest
import nose
import github # pip install PyGithub, to be able to work with student's Github Repositories directly
# File I/O
import pickle # Serialization and De-serialization (python's version of json)
import cPickle # Reading files
import gzip # Opening .gz files
import json # Working with json files
import simplejson # Better error message if something goes wrong when working wth json files
import io # Opening files, reading and writing
# Extract
import zipfile # To extract zipfiles
import tarfile # To extract tarfiles
# Parsing
import shlex # Lexical Analyzer
# Concurrency
import threading # Threading, thread setting events
import subprocess # To spawn new process and connect pipes
import signal # Handles signals such as SIGKILL
# Databases
import sqlalchemy # For working with sql
import pymongo # Working with mongoDB
# Compilation to other languages
import Cython # Convert python to C++ 
import Jython # Convert python to Java
import IronPython # Convert python to C#
# Web Framework
import django # Web Framework
import scrapy # Web scraper
import mechanize # For automating client browser interaction
import flask # Simplest web framework 
# Plotting
import matplotlib # For plotting
import panda # For plotting
import seaborn # For plotting
# Machine Learning
import numpy as np # Working with matrices, numerical python
import tensorflow as tf # Working with Machine Learning
import keras # tensorflow or pytorch
import sklearn # A lot of ML algorithms
import gensim # Working with Word2Vec
import skgarden # Working with decision trees
import pyro # Probabilistic programming using pytorch
import edward # Probabilistic Programming using tensorflow 
# Images
import PIL # resize, scale, crop, rotate, translate, flip
import opencv2 # A lot of image processing algorithms
import skimage # A lot of image processing algorithms
# Cloud Storage
import boto3 # API for Amazon Web Services using python
# Time
import datetime
# Languages
import enchant # pip install pyenchant
#----------------------------------------------------------------------------------------------------------------------------------
# Exceptions
#-------------------------
raise NotImplementedError

#----------------------------------------------------------------------------------------------------------------------------------
# Classes
#-------------------------
# Object is a special variable in python that must be inherited by all base classes in python
class NameOfClass(object):

  # Private member variables must be preceded with "__"
  __firstPrivateVariable = 0

  # Protected member variable
  firstProtectedVariable = 0

  # The constructor is called init
  def __init__(self, firstVariable, secondVariable):
    # self is a pointer to the current instance, similar to 'this' in C++
    self.firstMemberVariable = firstVariable
    self.secondMemberVariable = secondVariable
    # A static variable that counts the number of instances created for this class
    NameOfClass.counter += 1

  def getFirstVariable(self):
    return self.firstMemberVariable

  def getSecondVariable(self):
    return self.secondMemberVariable

  # Similar to toString() in Java
  def __str__(self):
    return "%s , %s" % (self.firstMemberVariable, self.secondMemberVariable)

  # Returns next iterator
  def __next__(self):
      raise NotImplementedError

# Defining a child class
class ChildClass(NameOfClass):
  def __init__(self, firstVariable, secondVariable, childVariable):
    NameOfClass.__init__(self, firstVariable, secondVariable)
    self.thirdVariable = childVariable
    self.firstProtectedVariable = 1000
  def getThirdVariable(self):
    return self.thirdVariable
#---------------------------------------------------------------------------------------------------
# Performance
#-------------------------
# Matrix Operations > Vectors > For Loops
#    For loops in python is slow
#    Vector operations using numpy is fast as it is implemented in C and uses parallel programming.
#    Matrix operation is faster than looping through vectors to perform operation

# Broadcasting => Uses C for loops instead of python for loops
# Works when:
    # one of them is a scalar
    [4,3,2] & [1] => [4, 3, 2]
    # Either one of the dimension is 1
    [4, 3] & [4, 1] => [4, 3]
    [4, 1] & [1,3] => [4, 3]
    # Both dimensions are equal
    [4, 3] & [4, 3] => [4, 3]
    # Combining them 
    [4, 3] & [1, 3] => [4, 3]

#----------------------------------
# Iterables vs Generators
#------------------------
# For each loop
for curr in arr:
    print(curr)
# Indexing for loop:
for index in range(arr.size):
    print(arr[index])
# To access 2 elements
for currA, currB in zip(arrA, arrB):
    print(currA)
    print(currB)
for currA in arrA:
    print(currA)
    print(arrB[0])
    arrB = arrB[1:] # ugly, but can be used for python

# Iterables => stores everything in memory, can iterate as many times
# Generator => do not store all values in memory, can only iterate each data once, generates on the fly
    yield # This acts similar keyword 'return', difference is that it only executes last call
          # to yield statement the next time it is called. 
    # Benefits 
        # Allows one to do heavy processing for storage in memory on the fly, no large in memory objects.
        # Allows one to perform data augmentation for machine learning in keras
#---------------------------------------------------------------------------------------------------
# Concurrency
#-------------------------
#---------------------------------------------------------------------------------------------------
# Jupyter Notebook
#-------------------------
An advantage of jupyter notebook, which behaves like MatLab. 
So lets just say it’s training while reading variables batchSize, learningRate, etc. 
You can run the model.train code in a different terminal window in jupyter notebook. Then, pause the execution of the model.train code, then re-run the terminal that defines the values of variables batchSize, learningRate, etc, which is in a different terminal window than model.train, then resume model.train code, it will now read the latest variable values that were defined. 
Also, it is a great resource for interactive code examples.
#---------------------------------------------------------------------------------------------------
