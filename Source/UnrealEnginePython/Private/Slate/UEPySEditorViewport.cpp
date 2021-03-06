#if WITH_EDITOR

#include "UnrealEnginePythonPrivatePCH.h"

#include "UEPySViewport.h"



#define GET_s_editor_viewport SEditorViewport *s_editor_viewport = (SEditorViewport *)self->s_compound_widget.s_widget.s_widget

static PyObject *py_ue_seditor_viewport_enable_stereo_rendering(ue_PySEditorViewport *self, PyObject * args) {
	PyObject *py_bool;
	if (!PyArg_ParseTuple(args, "O:enable_stereo_rendering", &py_bool)) {
		return NULL;
	}

	GET_s_editor_viewport;

	s_editor_viewport->EnableStereoRendering(PyObject_IsTrue(py_bool) ? true : false);

	Py_INCREF(self);
	return (PyObject *)self;
}

static PyObject *ue_PySEditorViewport_str(ue_PySEditorViewport *self)
{
	return PyUnicode_FromFormat("<unreal_engine.SEditorViewport '%p'>",
		self->s_compound_widget.s_widget.s_widget);
}

static PyMethodDef ue_PySEditorViewport_methods[] = {
	{ "enable_stereo_rendering", (PyCFunction)py_ue_seditor_viewport_enable_stereo_rendering, METH_VARARGS, "" },
	{ NULL }  /* Sentinel */
};

PyTypeObject ue_PySEditorViewportType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"unreal_engine.SEditorViewport", /* tp_name */
	sizeof(ue_PySEditorViewport), /* tp_basicsize */
	0,                         /* tp_itemsize */
	0,       /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,                         /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)ue_PySEditorViewport_str,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,        /* tp_flags */
	"Unreal Engine SEditorViewport",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	0,                         /* tp_iternext */
	ue_PySEditorViewport_methods,             /* tp_methods */
};

void ue_python_init_seditor_viewport(PyObject *ue_module) {
	ue_PySEditorViewportType.tp_new = PyType_GenericNew;

	ue_PySEditorViewportType.tp_base = &ue_PySCompoundWidgetType;

	if (PyType_Ready(&ue_PySEditorViewportType) < 0)
		return;

	Py_INCREF(&ue_PySEditorViewportType);
	PyModule_AddObject(ue_module, "SEditorViewport", (PyObject *)&ue_PySEditorViewportType);
}


#endif