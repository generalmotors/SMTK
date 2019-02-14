//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================

#ifndef pybind_smtk_view_SelectionObserver_h
#define pybind_smtk_view_SelectionObserver_h

#include <pybind11/pybind11.h>

#include "smtk/attribute/Attribute.h"

#include "smtk/view/SelectionObserver.h"

namespace py = pybind11;

py::class_< smtk::view::SelectionObservers > pybind11_init_smtk_view_SelectionObservers(py::module &m)
{
  py::class_< smtk::view::SelectionObservers > instance(m, "SelectionObservers");
  instance
    .def(py::init<>())
    .def(py::init<::smtk::view::SelectionObservers const &>())
    .def("__call__", [](smtk::view::SelectionObservers& observers, const std::string& str, smtk::view::SelectionPtr sel) { return observers(str, sel); })
    .def("__len__", &smtk::view::SelectionObservers::size)
    .def("deepcopy", (smtk::view::SelectionObservers & (smtk::view::SelectionObservers::*)(::smtk::view::SelectionObservers const &)) &smtk::view::SelectionObservers::operator=)
    .def("erase", &smtk::view::SelectionObservers::erase)
    .def("insert", &smtk::view::SelectionObservers::insert, pybind11::keep_alive<1, 2>())
    .def("find", &smtk::view::SelectionObservers::find)
    ;
  return instance;
}

#endif
