# Copyright 2012 Douglas Linder
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
# 
#   http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os.path
from ctypes import *
from pytest import pytest

library = pytest()
pytest = CDLL(library)

# Create a wrapper around our functions:
class Printer(object):

  def __init__(self, native):
    self.native = native

    # int print_vertical(int *lengths, int count); 
    native.print_vertical.argtypes = [ POINTER(c_int), c_int ]
    native.print_vertical.restype = POINTER(c_int)

    # int print_vertical(int *lengths, int count);
    native.print_horizontal.argtypes = [ POINTER(c_int), c_int ]
    native.print_horizontal.restype = POINTER(c_int)

    # void print_total(int *value)
    native.print_total.argtypes = [ POINTER(c_int) ]

  def print_vertical(self, lengths):
    nl = (c_int * len(lengths))()
    for i in range(0, len(lengths)):
      nl[i] = lengths[i]
    rtn = self.native.print_vertical(nl, len(lengths))
    return rtn

  def print_horizontal(self, lengths):
    nl = (c_int * len(lengths))()
    for i in range(0, len(lengths)):
      nl[i] = lengths[i]
    rtn = self.native.print_horizontal(nl, len(lengths))
    return rtn

  def print_total(self, total):
    """ 
        There's no reason to pass the whole thing back to a 
        C function to print; this is function show off passing
        pointers around. If the return type was an int it 
        could just be printed by print(total) in python 
    """
    self.native.print_total(total)

lengths = [6, 2, 3, 4, 6]

p = Printer(pytest)

print("Vertical:\n")
total = p.print_vertical(lengths)
p.print_total(total)

print("Horizontal:\n")
total = p.print_horizontal(lengths)
p.print_total(total)
