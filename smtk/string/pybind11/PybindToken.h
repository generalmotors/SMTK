//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================

#ifndef pybind_smtk_string_Token_h
#define pybind_smtk_string_Token_h

#include <pybind11/pybind11.h>

#include "smtk/string/Token.h"

namespace py = pybind11;

inline py::class_<smtk::string::Token> pybind11_init_smtk_string_Token(py::module &m)
{
  py::class_<smtk::string::Token> instance(m, "Token");
  instance
    .def_static("manager", &smtk::string::Token::manager)
    .def(py::init<const std::string &>())
    .def(py::init<smtk::string::Hash>())
    .def("data", &smtk::string::Token::data)
    .def("id", &smtk::string::Token::id)
    .def("__repr__", [](const smtk::string::Token& token)
      {
        return "<smtk.string.Token '" + token.data() + "'>";
      })
    ;
  return instance;
}

#endif
