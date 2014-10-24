//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
// .NAME vtkCommonSerializationHelper - Concrete serialization helper for
// Common package vtkObjects.
// .SECTION Description
// Concrete class for serialization of vtkObjects in the Common package using
// vtkXMLArchiveWriter and vtkXMLArchiveReader.  Only serialization of
// vtkTransform, vtkIdTypeArray, vtkIntArray, and vtkDoubleArray is currently
// implemented.
// .SECTION See Also
// vtkSerializationHelperMap vtkSerializationHelper

#ifndef __smtkdiscrete_vtkCommonSerializationHelper_h
#define __smtkdiscrete_vtkCommonSerializationHelper_h

#include "vtkSMTKDiscreteModelModule.h" // For export macro
#include "vtkSerializationHelper.h"


class vtkDataArray;
class vtkSerializer;
class vtkTransform;

class VTKSMTKDISCRETEMODEL_EXPORT vtkCommonSerializationHelper : public vtkSerializationHelper
{
public:
  static vtkCommonSerializationHelper *New();
  vtkTypeMacro(vtkCommonSerializationHelper, vtkSerializationHelper);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // This member registers ALL the classes supported by this helper with the
  // vtkSerializationHelperMap, which manages all the helpers.  Should be
  // called after construction unless you only want to enable support for
  // a subset (in which case it must be done "manually" by calling
  // vtkSerializationHelperMap::RegisterHelperForClass()
  virtual void RegisterWithHelperMap();

  // Description:
  // Unregister this helper (remove each class type/helper pair) with the
  // vtkSerializationHelperMap
  virtual void UnRegisterWithHelperMap();

  // Description:
  // Get the value for the "type" attribute of the specfied object type
  virtual const char *GetSerializationType(vtkObject *object);

  // Description:
  // Serialize the input object.  Returns 1 if successful.
  virtual int Serialize(vtkObject *object, vtkSerializer *serializer);

  //BTX
protected:
  vtkCommonSerializationHelper();
  ~vtkCommonSerializationHelper() {}

  // Description:
  // Serialize a vtkTransform
  void SerializeTransform(vtkTransform *transform, vtkSerializer *serializer);

  // Description:
  // Serialize vtkIdTypeArray, vtkIntArray, or vtkDoubleArray
  void SerializeDataArray(vtkDataArray *dataArray, vtkSerializer *serializer);

private:
  vtkCommonSerializationHelper(const vtkCommonSerializationHelper&);  // Not implemented.
  void operator=(const vtkCommonSerializationHelper&);  // Not implemented.
  //ETX
};

#endif
