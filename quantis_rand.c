#include <Python.h>

#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <limits.h>

#include "Quantis.h"

static PyObject* random_float(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  float d;
    
  static char* argnames[] = {"retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|i", argnames, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
  result = -1;
  do
    {
      retries--;
      result = QuantisReadFloat_01(QUANTIS_DEVICE_USB, 0, &d);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("f", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}

static PyObject* random_double(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  double d;
    
  static char* argnames[] = {"retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|i", argnames, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
  result = -1;
  do
    {
      retries--;
      result = QuantisReadDouble_01(QUANTIS_DEVICE_USB, 0, &d);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("d", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}

static PyObject* random_short(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  short d;
    
  static char* argnames[] = {"retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|i", argnames, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
  result = -1;
  do
    {
      retries--;
      result = QuantisReadShort(QUANTIS_DEVICE_USB, 0, &d);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("h", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}

static PyObject* random_int(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  int d;
    
  static char* argnames[] = {"retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|i", argnames, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
  result = -1;
  do
    {
      retries--;
      result = QuantisReadInt(QUANTIS_DEVICE_USB, 0, &d);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("i", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}


static PyObject* scaled_float(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  float d;
  float rand_min = 0.0;
  float rand_max = 1.0;
    
  static char* argnames[] = {"rand_min", "rand_max", "retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|ffi", argnames, &rand_min, &rand_max, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
      
  result = -1;
  do
    {
      retries--;
      result = QuantisReadScaledFloat(QUANTIS_DEVICE_USB, 0, &d, rand_min, rand_max);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("f", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}


static PyObject* scaled_double(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  double d;
  double rand_min = 0.0;
  double rand_max = 1.0;
    
  static char* argnames[] = {"rand_min", "rand_max", "retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|ddi", argnames, &rand_min, &rand_max, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
      
  result = -1;
  do
    {
      retries--;
      result = QuantisReadScaledDouble(QUANTIS_DEVICE_USB, 0, &d, rand_min, rand_max);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("d", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}

static PyObject* scaled_short(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  short d;
  short rand_min = SHRT_MIN + 1;
  short rand_max = SHRT_MAX - 1;
    
  static char* argnames[] = {"rand_min", "rand_max", "retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|hhi", argnames, &rand_min, &rand_max, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
  result = -1;
  do
    {
      retries--;
      result = QuantisReadScaledShort(QUANTIS_DEVICE_USB, 0, &d, rand_min, rand_max);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("h", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}


static PyObject* scaled_int(PyObject* self, PyObject* args, PyObject* kwds)
{
  int result; 
  int retries = 3;
  int d;
  int rand_min = INT_MIN + 1;
  int rand_max = INT_MAX - 1;
    
  static char* argnames[] = {"rand_min", "rand_max", "retries", NULL};
  
  if(!PyArg_ParseTupleAndKeywords(args, kwds, "|iii", argnames, &rand_min, &rand_max, &retries))
    {
      PyErr_SetString(PyExc_ValueError, "Invalid arguments");
      return NULL;
    }
  
      
  result = -1;
  do
    {
      retries--;
      result = QuantisReadScaledInt(QUANTIS_DEVICE_USB, 0, &d, rand_min, rand_max);
      if(result < 0)
	{
	  printf("Warning, sampling repeated due to error ");
	  printf("%s\n", QuantisStrError(result));
	  sleep(1);
	}
    }
  while (retries > 0 && result < 0);
    
  if(result==0)
    return Py_BuildValue("i", d);
  else
    {
      PyErr_SetString(PyExc_IOError, QuantisStrError(result));
      return NULL;
    }
}


static PyMethodDef quantis_randMethods[] = {
  { "random", (PyCFunction)random_float, METH_VARARGS | METH_KEYWORDS, "A float in [0,1] read from Quantis USB 0" },
  { "drandom", (PyCFunction)random_double, METH_VARARGS | METH_KEYWORDS, "A double in [0,1] read from Quantis USB 0" },
  { "randshort", (PyCFunction)random_short, METH_VARARGS | METH_KEYWORDS, "A short read from Quantis USB 0" },
  { "randint", (PyCFunction)random_int, METH_VARARGS | METH_KEYWORDS, "A integer read from Quantis USB 0." },
  { "scaled_float", (PyCFunction)scaled_float, METH_VARARGS | METH_KEYWORDS, "A scaled float read from Quantis USB 0, set the minimum and maximum as the first and second arguments." },
  { "scaled_double", (PyCFunction)scaled_double, METH_VARARGS | METH_KEYWORDS, "A scaled double read from Quantis USB 0, set the minimum and maximum as the first and second arguments." },
  { "scaled_short",  (PyCFunction)scaled_short, METH_VARARGS | METH_KEYWORDS, "A scaled short integer read from Quantis USB 0, set the minimum and maximum as the first and second arguments." },
  { "scaled_int",  (PyCFunction)scaled_int, METH_VARARGS | METH_KEYWORDS, "A scaled integer from Quantis USB 0, set the minimum and maximum as the first and second arguments." },

    { NULL, NULL, 0, NULL }
};


// Our Module Definition struct
static struct PyModuleDef quantis_randModule = {
    PyModuleDef_HEAD_INIT,
    "quantis_randModule",
    "Quantis Random Module",
    -1,
    quantis_randMethods,
    NULL
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_quantis_rand(void)
{
  Py_Initialize();
  return PyModule_Create(&quantis_randModule);
};

