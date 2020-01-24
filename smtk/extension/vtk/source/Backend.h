//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
#ifndef smtk_vtk_Backend_h
#define smtk_vtk_Backend_h

#include "smtk/extension/vtk/source/vtkSMTKSourceExtModule.h"
#include "smtk/geometry/Backend.h"
#include "smtk/geometry/GeometryForBackend.h"

#include "vtkSmartPointer.h"

#include <memory>
#include <string>

class vtkDataObject;

namespace smtk
{
namespace extension
{
namespace vtk
{
namespace source
{

class Geometry;

/**\brief This class is used to indicate VTK exists as a consumer of renderable geometry.
  *
  * You may optionally construct the backend with a geometry provider and
  * avoid the cost of dynamic casting each time geometry is requested for an object.
  */
class VTKSMTKSOURCEEXT_EXPORT Backend : public smtk::geometry::Backend
{
public:
  Backend();
  Backend(const std::unique_ptr<smtk::geometry::Geometry>& provider);
  Backend(const Geometry* provider);
  virtual ~Backend() = default;

  using format_t = vtkSmartPointer<vtkDataObject>;

  virtual std::string name() const override { return "VTK"; }

  format_t& geometry(const smtk::resource::PersistentObject::Ptr& obj);
  format_t& geometry(const std::unique_ptr<smtk::geometry::Geometry>& p,
    const smtk::resource::PersistentObject::Ptr& obj);

protected:
  static format_t s_empty;
  const Geometry* m_provider;
};

} // namespace source
} // namespace vtk
} // namespace extension
} // namespace smtk

#endif // smtk_vtk_Backend_h