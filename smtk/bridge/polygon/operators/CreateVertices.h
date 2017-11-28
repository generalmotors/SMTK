//=============================================================================
// Copyright (c) Kitware, Inc.
// All rights reserved.
// See LICENSE.txt for details.
//
// This software is distributed WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
// PURPOSE.  See the above copyright notice for more information.
//=============================================================================
#ifndef __smtk_session_polygon_CreateVertices_h
#define __smtk_session_polygon_CreateVertices_h

#include "smtk/bridge/polygon/Operator.h"

namespace smtk
{
namespace bridge
{
namespace polygon
{

/**\brief Create a face given a set of point coordinates or edges (but not both).
  *
  */
class SMTKPOLYGONSESSION_EXPORT CreateVertices : public Operator
{
public:
  smtkTypeMacro(CreateVertices);
  smtkCreateMacro(CreateVertices);
  smtkSharedFromThisMacro(smtk::operation::NewOp);
  smtkSuperclassMacro(Operator);

protected:
  Result operateInternal() override;
  virtual const char* xmlDescription() const override;
};

} // namespace polygon
} //namespace bridge
} // namespace smtk

#endif // __smtk_session_polygon_CreateVertices_h
