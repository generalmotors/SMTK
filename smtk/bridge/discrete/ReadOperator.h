//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================

#ifndef __smtk_bridge_discrete_ReadOperator_h
#define __smtk_bridge_discrete_ReadOperator_h

#include "smtk/bridge/discrete/discreteBridgeExports.h"
#include "smtk/model/Operator.h"
#include "vtkCMBModelReadOperator.h"
#include "vtkNew.h"

namespace smtk {
  namespace bridge {
    namespace discrete {

class Bridge;

/**\brief Read a CMB discrete model file.
  *
  * This requires the file to be of type/extension "cmb" (which
  * is really just a VTK XML polydata file).
  */
class SMTKDISCRETEBRIDGE_EXPORT ReadOperator : public smtk::model::Operator
{
public:
  smtkTypeMacro(ReadOperator);
  smtkCreateMacro(ReadOperator);
  smtkSharedFromThisMacro(Operator);
  smtkDeclareModelOperator();

  virtual bool ableToOperate();

protected:
  ReadOperator();
  virtual smtk::model::OperatorResult operateInternal();
  Bridge* discreteBridge() const;

  vtkNew<vtkCMBModelReadOperator> m_op;
};

    } // namespace discrete
  } // namespace bridge
} // namespace smtk

#endif // __smtk_bridge_discrete_ReadOperator_h
