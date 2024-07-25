//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright 2010 California Institute of Technology. ALL RIGHTS RESERVED.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// 
// United States Government Sponsorship acknowledged. This software is subject to
// U.S. export control laws and regulations and has been classified as 'EAR99 NLR'
// (No [Export] License Required except when exporting to an embargoed country,
// end user, or in support of a prohibited end use). By downloading this software,
// the user agrees to comply with all applicable U.S. export laws and regulations.
// The user has the responsibility to obtain export licenses, or other export
// authority as may be required before exporting this software to any 'EAR99'
// embargoed foreign country or citizen of those countries.
//
// Author: Giangi Sacco
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




#ifndef resamp_onlymodule_h
#define resamp_onlymodule_h

#include <Python.h>
#include <stdint.h>
#include "resamp_onlymoduleFortTrans.h"

extern "C"
{
    void setStdWriter_f(uint64_t *);
    PyObject * setStdWriter_C(PyObject *, PyObject *);
    void resamp_only_f(uint64_t *,uint64_t *,uint64_t *,uint64_t *);
    PyObject * resamp_only_C(PyObject *, PyObject *);
    void setNumberFitCoefficients_f(int *);
    PyObject * setNumberFitCoefficients_C(PyObject *, PyObject *);
    void setNumberRangeBin_f(int *);
    PyObject * setNumberRangeBin_C(PyObject *, PyObject *);
    void setNumberLines_f(int *);
    PyObject * setNumberLines_C(PyObject *, PyObject *);
    void setFirstLineOffset_f(int *);
    PyObject * setFirstLineOffset_C(PyObject *, PyObject *);
    void setRadarWavelength_f(float *);
    PyObject * setRadarWavelength_C(PyObject *, PyObject *);
    void setSlantRangePixelSpacing_f(float *);
    PyObject * setSlantRangePixelSpacing_C(PyObject *, PyObject *);
    void setDopplerCentroidCoefficients_f(double *, int *);
    void allocate_dopplerCoefficients_f(int *);
    void deallocate_dopplerCoefficients_f();
    PyObject * allocate_dopplerCoefficients_C(PyObject *, PyObject *);
    PyObject * deallocate_dopplerCoefficients_C(PyObject *, PyObject *);
    PyObject * setDopplerCentroidCoefficients_C(PyObject *, PyObject *);
    void setLocationAcross1_f(double *, int *);
    void allocate_r_ranpos_f(int *);
    void deallocate_r_ranpos_f();
    PyObject * allocate_r_ranpos_C(PyObject *, PyObject *);
    PyObject * deallocate_r_ranpos_C(PyObject *, PyObject *);
    PyObject * setLocationAcross1_C(PyObject *, PyObject *);
    void setLocationAcrossOffset1_f(double *, int *);
    void allocate_r_ranoff_f(int *);
    void deallocate_r_ranoff_f();
    PyObject * allocate_r_ranoff_C(PyObject *, PyObject *);
    PyObject * deallocate_r_ranoff_C(PyObject *, PyObject *);
    PyObject * setLocationAcrossOffset1_C(PyObject *, PyObject *);
    void setLocationDown1_f(double *, int *);
    void allocate_r_azpos_f(int *);
    void deallocate_r_azpos_f();
    PyObject * allocate_r_azpos_C(PyObject *, PyObject *);
    PyObject * deallocate_r_azpos_C(PyObject *, PyObject *);
    PyObject * setLocationDown1_C(PyObject *, PyObject *);
    void setLocationDownOffset1_f(double *, int *);
    void allocate_r_azoff_f(int *);
    void deallocate_r_azoff_f();
    PyObject * allocate_r_azoff_C(PyObject *, PyObject *);
    PyObject * deallocate_r_azoff_C(PyObject *, PyObject *);
    PyObject * setLocationDownOffset1_C(PyObject *, PyObject *);
    void setSNR1_f(double *, int *);
    void allocate_r_sig_f(int *);
    void deallocate_r_sig_f();
    PyObject * allocate_r_sig_C(PyObject *, PyObject *);
    PyObject * deallocate_r_sig_C(PyObject *, PyObject *);
    PyObject * setSNR1_C(PyObject *, PyObject *);
    void setLocationAcross2_f(double *, int *);
    void allocate_r_ranpos2_f(int *);
    void deallocate_r_ranpos2_f();
    PyObject * allocate_r_ranpos2_C(PyObject *, PyObject *);
    PyObject * deallocate_r_ranpos2_C(PyObject *, PyObject *);
    PyObject * setLocationAcross2_C(PyObject *, PyObject *);
    void setLocationAcrossOffset2_f(double *, int *);
    void allocate_r_ranoff2_f(int *);
    void deallocate_r_ranoff2_f();
    PyObject * allocate_r_ranoff2_C(PyObject *, PyObject *);
    PyObject * deallocate_r_ranoff2_C(PyObject *, PyObject *);
    PyObject * setLocationAcrossOffset2_C(PyObject *, PyObject *);
    void setLocationDown2_f(double *, int *);
    void allocate_r_azpos2_f(int *);
    void deallocate_r_azpos2_f();
    PyObject * allocate_r_azpos2_C(PyObject *, PyObject *);
    PyObject * deallocate_r_azpos2_C(PyObject *, PyObject *);
    PyObject * setLocationDown2_C(PyObject *, PyObject *);
    void setLocationDownOffset2_f(double *, int *);
    void allocate_r_azoff2_f(int *);
    void deallocate_r_azoff2_f();
    PyObject * allocate_r_azoff2_C(PyObject *, PyObject *);
    PyObject * deallocate_r_azoff2_C(PyObject *, PyObject *);
    PyObject * setLocationDownOffset2_C(PyObject *, PyObject *);
    void setSNR2_f(double *, int *);
    void allocate_r_sig2_f(int *);
    void deallocate_r_sig2_f();
    PyObject * allocate_r_sig2_C(PyObject *, PyObject *);
    PyObject * deallocate_r_sig2_C(PyObject *, PyObject *);
    PyObject * setSNR2_C(PyObject *, PyObject *);
    void getAzimuthCarrier_f(double *, int *);
    void allocate_azimuthCarrier_f(int *);
    void deallocate_azimuthCarrier_f();
    PyObject * allocate_azimuthCarrier_C(PyObject *, PyObject *);
    PyObject * deallocate_azimuthCarrier_C(PyObject *, PyObject *);
    PyObject * getAzimuthCarrier_C(PyObject *, PyObject *);
    void getRangeCarrier_f(double *, int *);
    void allocate_rangeCarrier_f(int *);
    void deallocate_rangeCarrier_f();
    PyObject * allocate_rangeCarrier_C(PyObject *, PyObject *);
    PyObject * deallocate_rangeCarrier_C(PyObject *, PyObject *);
    PyObject * getRangeCarrier_C(PyObject *, PyObject *);

}

static PyMethodDef resamp_only_methods[] =
{
    {"setStdWriter_Py", setStdWriter_C, METH_VARARGS, " "},
    {"resamp_only_Py", resamp_only_C, METH_VARARGS, " "},
    {"setNumberFitCoefficients_Py", setNumberFitCoefficients_C, METH_VARARGS,
        " "},
    {"setNumberRangeBin_Py", setNumberRangeBin_C, METH_VARARGS, " "},
    {"setNumberLines_Py", setNumberLines_C, METH_VARARGS, " "},
    {"setFirstLineOffset_Py", setFirstLineOffset_C, METH_VARARGS, " "},
    {"setRadarWavelength_Py", setRadarWavelength_C, METH_VARARGS, " "},
    {"setSlantRangePixelSpacing_Py", setSlantRangePixelSpacing_C, METH_VARARGS,
        " "},
    {"allocate_dopplerCoefficients_Py", allocate_dopplerCoefficients_C,
        METH_VARARGS, " "},
    {"deallocate_dopplerCoefficients_Py", deallocate_dopplerCoefficients_C,
        METH_VARARGS, " "},
    {"setDopplerCentroidCoefficients_Py", setDopplerCentroidCoefficients_C,
        METH_VARARGS, " "},
    {"allocate_r_ranpos_Py", allocate_r_ranpos_C, METH_VARARGS, " "},
    {"deallocate_r_ranpos_Py", deallocate_r_ranpos_C, METH_VARARGS, " "},
    {"setLocationAcross1_Py", setLocationAcross1_C, METH_VARARGS, " "},
    {"allocate_r_ranoff_Py", allocate_r_ranoff_C, METH_VARARGS, " "},
    {"deallocate_r_ranoff_Py", deallocate_r_ranoff_C, METH_VARARGS, " "},
    {"setLocationAcrossOffset1_Py", setLocationAcrossOffset1_C, METH_VARARGS,
        " "},
    {"allocate_r_azpos_Py", allocate_r_azpos_C, METH_VARARGS, " "},
    {"deallocate_r_azpos_Py", deallocate_r_azpos_C, METH_VARARGS, " "},
    {"setLocationDown1_Py", setLocationDown1_C, METH_VARARGS, " "},
    {"allocate_r_azoff_Py", allocate_r_azoff_C, METH_VARARGS, " "},
    {"deallocate_r_azoff_Py", deallocate_r_azoff_C, METH_VARARGS, " "},
    {"setLocationDownOffset1_Py", setLocationDownOffset1_C, METH_VARARGS, " "},
    {"allocate_r_sig_Py", allocate_r_sig_C, METH_VARARGS, " "},
    {"deallocate_r_sig_Py", deallocate_r_sig_C, METH_VARARGS, " "},
    {"setSNR1_Py", setSNR1_C, METH_VARARGS, " "},
    {"allocate_r_ranpos2_Py", allocate_r_ranpos2_C, METH_VARARGS, " "},
    {"deallocate_r_ranpos2_Py", deallocate_r_ranpos2_C, METH_VARARGS, " "},
    {"setLocationAcross2_Py", setLocationAcross2_C, METH_VARARGS, " "},
    {"allocate_r_ranoff2_Py", allocate_r_ranoff2_C, METH_VARARGS, " "},
    {"deallocate_r_ranoff2_Py", deallocate_r_ranoff2_C, METH_VARARGS, " "},
    {"setLocationAcrossOffset2_Py", setLocationAcrossOffset2_C, METH_VARARGS,
        " "},
    {"allocate_r_azpos2_Py", allocate_r_azpos2_C, METH_VARARGS, " "},
    {"deallocate_r_azpos2_Py", deallocate_r_azpos2_C, METH_VARARGS, " "},
    {"setLocationDown2_Py", setLocationDown2_C, METH_VARARGS, " "},
    {"allocate_r_azoff2_Py", allocate_r_azoff2_C, METH_VARARGS, " "},
    {"deallocate_r_azoff2_Py", deallocate_r_azoff2_C, METH_VARARGS, " "},
    {"setLocationDownOffset2_Py", setLocationDownOffset2_C, METH_VARARGS, " "},
    {"allocate_r_sig2_Py", allocate_r_sig2_C, METH_VARARGS, " "},
    {"deallocate_r_sig2_Py", deallocate_r_sig2_C, METH_VARARGS, " "},
    {"setSNR2_Py", setSNR2_C, METH_VARARGS, " "},
    {"allocate_azimuthCarrier_Py", allocate_azimuthCarrier_C, METH_VARARGS,
        " "},
    {"deallocate_azimuthCarrier_Py", deallocate_azimuthCarrier_C, METH_VARARGS,
        " "},
    {"getAzimuthCarrier_Py", getAzimuthCarrier_C, METH_VARARGS, " "},
    {"allocate_rangeCarrier_Py", allocate_rangeCarrier_C, METH_VARARGS, " "},
    {"deallocate_rangeCarrier_Py", deallocate_rangeCarrier_C, METH_VARARGS,
        " "},
    {"getRangeCarrier_Py", getRangeCarrier_C, METH_VARARGS, " "},
    {NULL, NULL, 0, NULL}
};
#endif

// end of file
