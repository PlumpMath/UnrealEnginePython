#if WITH_EDITOR

#include "UnrealEnginePythonPrivatePCH.h"

#include "UEPySBoxPanel.h"


#define GET_s_box_panel SBoxPanel *s_box_panel = (SBoxPanel*)self->s_panel.s_widget.s_widget;

static PyObject *py_ue_sbox_panel_clear_children(ue_PySGridPanel *self, PyObject * args) {
	GET_s_box_panel;

	s_box_panel->ClearChildren();

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *ue_PySBoxPanel_str(ue_PySBoxPanel *self)
{
	return PyUnicode_FromFormat("<unreal_engine.SBoxPanel '%p'>",
		self->s_panel.s_widget.s_widget);
}

static PyMethodDef ue_PySBoxPanel_methods[] = {
	{ "clear_children", (PyCFunction)py_ue_sbox_panel_clear_children, METH_VARARGS, "" },
	{ NULL }  /* Sentinel */
};

PyTypeObject ue_PySBoxPanelType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"unreal_engine.SBoxPanel", /* tp_name */
	sizeof(ue_PySBoxPanel), /* tp_basicsize */
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
	(reprfunc)ue_PySBoxPanel_str,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,        /* tp_flags */
	"Unreal Engine SBoxPanel",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	0,                         /* tp_iternext */
	ue_PySBoxPanel_methods,             /* tp_methods */
};

void ue_python_init_sbox_panel(PyObject *ue_module) {
	ue_PySBoxPanelType.tp_new = PyType_GenericNew;

	ue_PySBoxPanelType.tp_base = &ue_PySPanelType;

	if (PyType_Ready(&ue_PySBoxPanelType) < 0)
		return;

	Py_INCREF(&ue_PySGridPanelType);
	PyModule_AddObject(ue_module, "SBoxPanel", (PyObject *)&ue_PySBoxPanelType);
}


#endif