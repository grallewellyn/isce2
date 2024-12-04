#!/usr/bin/env python3 


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Copyright 2014 California Institute of Technology. ALL RIGHTS RESERVED.
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
# Author: Piyush Agram
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

import xml.etree.ElementTree as ET
import datetime
import isceobj
from .BurstSLC import BurstSLC
from isceobj.Util import Poly1D, Poly2D
from isceobj.Planet.Planet import Planet
from isceobj.Orbit.Orbit import StateVector, Orbit
from isceobj.Planet.AstronomicalHandbook import Const
from iscesys.Component.Component import Component
from iscesys.Component.ProductManager import ProductManager
from iscesys.DateTimeUtil.DateTimeUtil import DateTimeUtil as DTUtil
import os
import glob
import numpy as np
import shelve
from osgeo import gdal

XML_LIST = Component.Parameter('xml',
        public_name = 'xml',
        default = [],
        container = list,
        type = str,
        doc = 'List of input XML files to stitch together')

TIFF_LIST = Component.Parameter('tiff',
        public_name = 'tiff',
        default = [],
        container = list,
        type = str,
        doc = 'List of input TIFF files to stitch together')

MANIFEST = Component.Parameter('manifest',
        public_name = 'manifest',
        default = [],
        container = list,
        type = str,
        doc = 'Manifest file with IPF version')

SAFE_LIST = Component.Parameter('safe',
        public_name = 'safe',
        default = [],
        container = list,
        type = str,
        doc = 'List of safe directories')

SWATH_NUMBER = Component.Parameter('swathNumber',
        public_name = 'swath number',
        default = None,
        type = int,
        mandatory = True,
        doc = 'Swath number to process')

POLARIZATION = Component.Parameter('polarization',
        public_name = 'polarization',
        default = 'vv',
        type = str,
        mandatory = True,
        doc = 'Polarization')

ORBIT_FILE = Component.Parameter('orbitFile',
        public_name = 'orbit file',
        default = None,
        type = str,
        doc = 'External orbit file with state vectors')

AUX_FILE = Component.Parameter('auxFile',
        public_name = 'auxiliary file',
        default = None,
        type = str,
        doc = 'External auxiliary file to use for antenna pattern')

ORBIT_DIR = Component.Parameter('orbitDir',
        public_name = 'orbit directory',
        default = None,
        type = str,
        doc = 'Directory to search for orbit files')

AUX_DIR = Component.Parameter('auxDir',
        public_name = 'auxiliary data directory',
        default = None,
        type = str,
        doc = 'Directory to search for auxiliary data')

OUTPUT = Component.Parameter('output',
        public_name = 'output directory',
        default = None,
        type = str,
        doc = 'Directory where bursts get unpacked')

ROI = Component.Parameter('regionOfInterest',
        public_name = 'region of interest',
        default = [],
        container = list,
        type = float,
        doc = 'User defined area to crop in SNWE')

####List of facilities
PRODUCT = Component.Facility('product',
        public_name='product',
        module = 'isceobj.Sensor.TOPS',
        factory='createTOPSSwathSLCProduct',
        args = (),
        mandatory = True,
        doc = 'TOPS SLC Swath product populated by the reader')


class Sentinel1(Component):
    """
    Sentinel-1A TOPS reader
    """

    family = 's1atops'
    logging = 'isce.sensor.S1A_TOPS'

    parameter_list = (XML_LIST,
                      TIFF_LIST,
                      MANIFEST,
                      SAFE_LIST,
                      ORBIT_FILE,
                      AUX_FILE,
                      ORBIT_DIR,
                      AUX_DIR,
                      OUTPUT,
                      ROI,
                      SWATH_NUMBER,
                      POLARIZATION)

    facility_list = (PRODUCT,)

    def __init__(self, name=''):
        super().__init__(family=self.__class__.family, name=name) 

        ####Number of swaths
        self.maxSwaths = 3

        ###Variables never meant to be controlled by user
        self._xml_root=None
        self._burstWidth = None    ###Common width
        self._burstLength = None   ###Common length
        self._numSlices = None     ###Number of slides
        self._parsed = False       ###If products have been parsed already
        self._tiffSrc = []

        ####Specifically used only for IPF 002.36
        ####Scotch tape fix
        self._elevationAngleVsTau = []  ###For storing time samples
        self._Geap = None    ###IQ antenna pattern
        self._delta_theta = None  ###Elevation angle increment

        return

    def extractImage(self):
        tiffToRead = "/vsizip//projects/S1B_IW_SLC__1SDV_20180423T161524_20180423T161551_010613_0135DD_33F0.zip/S1B_IW_SLC__1SDV_20180423T161524_20180423T161551_010613_0135DD_33F0.SAFE/measurement/s1b-iw1-slc-vv-20180423t161526-20180423t161551-010613-0135dd-004.tiff"
        src = gdal.Open(tiffToRead, gdal.GA_ReadOnly)
        print(src)

if __name__ == '__main__':
    print("graceal1 in the main function for file")
    obj = Sentinel1()
    obj.extractImage() 
    print("graceal1 done calling functions in main function")