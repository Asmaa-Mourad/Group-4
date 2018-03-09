#include <iostream>
#include <Python.h>
static PyObject *extError;
int Hello(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Hello World!\n";
    }
    return 0;
}
static PyObject* ext_Hello(PyObject *self, PyObject *args) {
    int n = 0;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }
    return Py_BuildValue("i", Hello(n));
}
static PyMethodDef extMethods[] = {
    { "ext_Hello", (PyCFunction)ext_Hello, METH_VARARGS },
    { NULL, NULL, 0, NULL }
};
PyMODINIT_FUNC initext() {
    Py_InitModule("ext", extMethods);
}
