#!/usr/bin/env python3 

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Copyright 2010 California Institute of Technology. ALL RIGHTS RESERVED.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# 
# United States Government Sponsorship acknowledged. This software is subject to
# U.S. export control laws and regulations and has been classified as 'EAR99 NLR'
# (No [Export] License Required except when exporting to an embargoed country,
# end user, or in support of a prohibited end use). By downloading this software,
# the user agrees to comply with all applicable U.S. export laws and regulations.
# The user has the responsibility to obtain export licenses, or other export
# authority as may be required before exporting this software to any 'EAR99'
# embargoed foreign country or citizen of those countries.
#
# Author: Giangi Sacco
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





from __future__ import print_function
import sys
import os
import math
from iscesys.Component.Component import Component
from iscesys.Compatibility import Compatibility
Compatibility.checkPythonVersion()
from mroipac.looks import nbymhgt

class Nbymhgt(Component):

    def nbymhgt(self):
        dictionary = self.createOptionalArgDictionary()
        if(dictionary):
            nbymhgt.nbymhgt_Py(self.inputImage,self.outputImage,self.width,self.rangeLook,self.azimuthLook,dictionary)
        else:
            nbymhgt.nbymhgt_Py(self.inputImage,self.outputImage,self.width,self.rangeLook,self.azimuthLook)
        
        return



    def createOptionalArgDictionary(self):
        retDict = {}
        optPos = 2
        varPos = 0
        for key,val in self.dictionaryOfVariables.items():
            if val[optPos] == 'optional':
                isDef = True
                exec ('if( not (' + val[varPos] + ' == 0) and not (' + val[varPos] + ')):isDef = False')  
                if isDef:
                    exec ('retDict[\'' + key +'\'] =' + val[varPos])
        return retDict

    def setRangeLook(self,var):
        self.rangeLook = int(var)
        return

    def setAzimuthLook(self,var):
        self.azimuthLook = int(var)
        return

    def setWidth(self,var):
        self.width = int(var)
        return

    def setLength(self,var):
        self.length = int(var)
        return
    '''
    def setLookType(self,var):
        self.lookType = str(var)
        return
    '''
    def setInputImage(self,var):
        self.inputImage = str(var)
        return
    
    def setUndefinedPixel(self,var):
        self.undefinedPixel = str(var)
        return

    def setOutputImage(self,var):
        self.outputImage = str(var)
        return

    def setInputEndianness(self,var):
        self.inEndianness = str(var)
        return
    
    def setOutputEndianness(self,var):
        self.outEndianness = str(var)
        return





    def __init__(self):
        Component.__init__(self)
        self.rangeLook = None
        self.rangeLook = None
        self.azimuthLook = None
        self.phaseRange = None
        self.phaseAzimuth = None
        self.width = None
        self.length = None
        self.undefinedPixel = None
        self.inEndianness = ''
        self.outEndianness = ''
        self.inputImage = ''
        self.outputImage = ''
        self.dictionaryOfVariables = {'RANGE_LOOK' : ['self.rangeLook', 'int','mandatory'], \
                                      'AZIMUTH_LOOK' : ['self.azimuthLook', 'int','mandatory'], \
                                      'WIDTH' : ['self.width', 'int','mandatory'], \
                                      'UNDEFINED_PIXEL' : ['self.undefinedPixel', 'int','optional'], \
                                      'LENGTH' : ['self.length', 'int','optional'], \
                                      'INPUT_ENDIANNESS' : ['self.inEndianness', 'str','optional'], \
                                      'OUTPUT_ENDIANNESS' : ['self.outEndianness', 'str','optional'], \
                                      'INPUT_IMAGE' : ['self.inputImage', 'str','mandatory'], \
                                      'OUTPUT_IMAGE' : ['self.outputImage', 'str','mandatory']}
        self.descriptionOfVariables = {}
        self.mandatoryVariables = []
        self.optionalVariables = []
        typePos = 2
        for key , val in self.dictionaryOfVariables.items():
            if val[typePos] == 'mandatory':
                self.mandatoryVariables.append(key)
            elif val[typePos] == 'optional':
                self.optionalVariables.append(key)
            else:
                print('Error. Variable can only be optional or mandatory')
                raise Exception
        return





#end class


def main(cmd):
    nbymh = Nbymhgt()
    nbymh.inputImage = cmd[1]
    nbymh.outputImage = cmd[2]
    nbymh.width = cmd[3]
    nbymh.rangeLooks = cmd[4]
    nbymh.azimuthLooks = cmd[5]
    nbymh.nbymhgt()

if __name__ == "__main__":
    if len(sys.argv) < 5:
        print("Usage: Nbymhgt.py infile outfile width rangeLooks [azimuthLooks]")
        print("       azimuthLooks = rangeLooks if not given on command line.")
        print("       file type is band interleaved by line, or rmg.")
        sys.exit()

    sys.exit(main(sys.argv))
