//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================

#ifndef pybind_smtk_project_ResourceContainer_h
#define pybind_smtk_project_ResourceContainer_h

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "smtk/project/ResourceContainer.h"

#include "smtk/common/UUID.h"
#include "smtk/common/pybind11/PybindUUIDTypeCaster.h"
#include "smtk/resource/Resource.h"

namespace py = pybind11;

py::class_< smtk::project::ResourceContainer > pybind11_init_smtk_project_ResourceContainer(py::module &m)
{
  py::class_< smtk::project::ResourceContainer > instance(m, "ResourceContainer");
  instance
    .def(py::init<::smtk::project::ResourceContainer const &>())
    .def("deepcopy", (smtk::project::ResourceContainer & (smtk::project::ResourceContainer::*)(::smtk::project::ResourceContainer const &)) &smtk::project::ResourceContainer::operator=)
    .def("add", (bool (smtk::project::ResourceContainer::*)(::smtk::resource::ResourcePtr const &, ::std::string const &)) &smtk::project::ResourceContainer::add, py::arg("arg0"), py::arg("role") = std::string())
    .def("add", (bool (smtk::project::ResourceContainer::*)(::smtk::resource::Resource::Index const &, ::smtk::resource::ResourcePtr const &, ::std::string)) &smtk::project::ResourceContainer::add, py::arg("arg0"), py::arg("arg1"), py::arg("role") = std::string())
#if !defined(_WIN32)
    // These don't compile on windows (wish I knew why)
    .def("begin", (boost::multi_index::multi_index_container<std::shared_ptr<smtk::resource::Resource>, boost::multi_index::indexed_by<boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::IdTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const smtk::common::UUID &, &smtk::resource::detail::id>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::IndexTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, unsigned long, &smtk::resource::detail::index>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::NameTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, std::basic_string<char>, &smtk::resource::detail::name>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::LocationTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::resource::detail::location>, mpl_::na>, boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::RoleTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::project::detail::role>, mpl_::na>, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, std::allocator<std::shared_ptr<smtk::resource::Resource> > >::const_iterator (smtk::project::ResourceContainer::*)() const) &smtk::project::ResourceContainer::begin)
    .def("begin", (boost::multi_index::multi_index_container<std::shared_ptr<smtk::resource::Resource>, boost::multi_index::indexed_by<boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::IdTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const smtk::common::UUID &, &smtk::resource::detail::id>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::IndexTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, unsigned long, &smtk::resource::detail::index>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::NameTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, std::basic_string<char>, &smtk::resource::detail::name>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::LocationTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::resource::detail::location>, mpl_::na>, boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::RoleTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::project::detail::role>, mpl_::na>, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, std::allocator<std::shared_ptr<smtk::resource::Resource> > >::iterator (smtk::project::ResourceContainer::*)()) &smtk::project::ResourceContainer::begin)
#endif
    .def("clear", &smtk::project::ResourceContainer::clear)
    .def("empty", &smtk::project::ResourceContainer::empty)
#if !defined(_WIN32)
    // These don't compile on windows
    .def("end", (boost::multi_index::multi_index_container<std::shared_ptr<smtk::resource::Resource>, boost::multi_index::indexed_by<boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::IdTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const smtk::common::UUID &, &smtk::resource::detail::id>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::IndexTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, unsigned long, &smtk::resource::detail::index>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::NameTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, std::basic_string<char>, &smtk::resource::detail::name>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::LocationTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::resource::detail::location>, mpl_::na>, boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::RoleTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::project::detail::role>, mpl_::na>, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, std::allocator<std::shared_ptr<smtk::resource::Resource> > >::const_iterator (smtk::project::ResourceContainer::*)() const) &smtk::project::ResourceContainer::end)
    .def("end", (boost::multi_index::multi_index_container<std::shared_ptr<smtk::resource::Resource>, boost::multi_index::indexed_by<boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::IdTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const smtk::common::UUID &, &smtk::resource::detail::id>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::IndexTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, unsigned long, &smtk::resource::detail::index>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::NameTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, std::basic_string<char>, &smtk::resource::detail::name>, mpl_::na>, boost::multi_index::ordered_non_unique<boost::multi_index::tag<smtk::project::LocationTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::resource::detail::location>, mpl_::na>, boost::multi_index::ordered_unique<boost::multi_index::tag<smtk::project::RoleTag, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, boost::multi_index::global_fun<const std::shared_ptr<smtk::resource::Resource> &, const std::basic_string<char> &, &smtk::project::detail::role>, mpl_::na>, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na, mpl_::na>, std::allocator<std::shared_ptr<smtk::resource::Resource> > >::iterator (smtk::project::ResourceContainer::*)()) &smtk::project::ResourceContainer::end)
#endif
    .def("find", (std::set<std::shared_ptr<smtk::resource::Resource>, std::less<std::shared_ptr<smtk::resource::Resource> >, std::allocator<std::shared_ptr<smtk::resource::Resource> > > (smtk::project::ResourceContainer::*)(::std::string const &) const) &smtk::project::ResourceContainer::find, py::arg("arg0"))
    .def("find", (std::set<std::shared_ptr<smtk::resource::Resource>, std::less<std::shared_ptr<smtk::resource::Resource> >, std::allocator<std::shared_ptr<smtk::resource::Resource> > > (smtk::project::ResourceContainer::*)(::smtk::resource::Resource::Index const &) const) &smtk::project::ResourceContainer::find, py::arg("arg0"))
    .def("get", (smtk::resource::ResourcePtr (smtk::project::ResourceContainer::*)(::smtk::common::UUID const &)) &smtk::project::ResourceContainer::get, py::arg("id"))
    .def("get", (smtk::resource::ConstResourcePtr (smtk::project::ResourceContainer::*)(::smtk::common::UUID const &) const) &smtk::project::ResourceContainer::get, py::arg("id"))
    .def("get", (smtk::resource::ResourcePtr (smtk::project::ResourceContainer::*)(::std::string const &)) &smtk::project::ResourceContainer::get, py::arg("arg0"))
    .def("get", (smtk::resource::ConstResourcePtr (smtk::project::ResourceContainer::*)(::std::string const &) const) &smtk::project::ResourceContainer::get, py::arg("arg0"))
    .def("getByRole", (smtk::resource::ResourcePtr (smtk::project::ResourceContainer::*)(::std::string const &)) &smtk::project::ResourceContainer::getByRole, py::arg("arg0"))
    .def("getByRole", (smtk::resource::ConstResourcePtr (smtk::project::ResourceContainer::*)(::std::string const &) const) &smtk::project::ResourceContainer::getByRole, py::arg("arg0"))
    .def("manager", &smtk::project::ResourceContainer::manager)
    .def("registerResource", (bool (smtk::project::ResourceContainer::*)(::std::string const &)) &smtk::project::ResourceContainer::registerResource, py::arg("arg0"))
    .def("registerResource", (bool (smtk::project::ResourceContainer::*)(::smtk::resource::Resource::Index const &)) &smtk::project::ResourceContainer::registerResource, py::arg("arg0"))
    .def("registerResources", &smtk::project::ResourceContainer::registerResources, py::arg("arg0"))
    .def("remove", &smtk::project::ResourceContainer::remove, py::arg("arg0"))
    .def("resources", (smtk::project::ResourceContainer::Container const & (smtk::project::ResourceContainer::*)() const) &smtk::project::ResourceContainer::resources)
    .def("resources", (smtk::project::ResourceContainer::Container & (smtk::project::ResourceContainer::*)()) &smtk::project::ResourceContainer::resources)
    .def("setManager", &smtk::project::ResourceContainer::setManager, py::arg("manager"))
    .def("size", &smtk::project::ResourceContainer::size)
    .def("types", (std::set<std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::basic_string<char> > > const & (smtk::project::ResourceContainer::*)() const) &smtk::project::ResourceContainer::types)
    .def("types", (std::set<std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::basic_string<char> > > & (smtk::project::ResourceContainer::*)()) &smtk::project::ResourceContainer::types)
    .def("unregisterResource", (bool (smtk::project::ResourceContainer::*)(::std::string const &)) &smtk::project::ResourceContainer::unregisterResource, py::arg("arg0"))
    .def("unregisterResource", (bool (smtk::project::ResourceContainer::*)(::smtk::resource::Resource::Index const &)) &smtk::project::ResourceContainer::unregisterResource, py::arg("arg0"))
    ;
  return instance;
}

void pybind11_init_smtk_project_detail_role(py::module &m)
{
  m.def("role", &smtk::project::detail::role, "", py::arg("r"));
}

#endif