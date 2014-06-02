#ifndef __smtk_model_Bridge_h
#define __smtk_model_Bridge_h

#include "smtk/util/UUID.h"
#include "smtk/util/SharedFromThis.h"
#include "smtk/util/SystemConfig.h"

#include "smtk/SMTKCoreExports.h" // For SMTKCORE_EXPORT macro.
#include "smtk/SharedPtr.h"
#include "smtk/PublicPointerDefs.h"

#include "smtk/model/Cursor.h"
#include "smtk/model/Operator.h"

namespace smtk {
  namespace model {

class Bridge;
class Cursor;
class Operator;
typedef std::map<smtk::util::UUID,smtk::shared_ptr<Bridge> > UUIDsToBridges;
typedef smtk::shared_ptr<Bridge> (*BridgeConstructor)();
typedef std::pair<smtk::model::StringList,BridgeConstructor> StaticBridgeInfo;
typedef std::map<std::string,StaticBridgeInfo> BridgeConstructors;
typedef std::map<smtk::model::Cursor,int> DanglingEntities;

/**\brief Bit flags describing types of information bridged to Manager.
  *
  * Bridge classes should provide individual translation for
  * each piece of information, but are allowed to transcribe
  * additional information when it is efficient or necessary
  * to do so.
  * For example, it does not make sense for an Entity record's
  * relations to be populated but not the bit-flag describing
  * its type. Thus, requesting BRIDGE_ENTITY_RELATIONS usually
  * also results in BRIDGE_ENTITY_TYPE being transcribed.
  */
enum BridgedInformation
{
  // Basic types of information in smtk::model::Manager
  BRIDGE_ENTITY_TYPE            = 0x00000001, //!< Transcribe the Entity type.
  BRIDGE_ENTITY_RELATIONS       = 0x00000002, //!< Transcribe the Entity relationship vector.
  BRIDGE_ARRANGEMENTS           = 0x00000004, //!< Arrangement information for the relationships.
  BRIDGE_TESSELLATION           = 0x00000008, //!< Points and triangles used to render an entity.
  BRIDGE_FLOAT_PROPERTIES       = 0x00000010, //!< Floating-point properties.
  BRIDGE_STRING_PROPERTIES      = 0x00000020, //!< String properties.
  BRIDGE_INTEGER_PROPERTIES     = 0x00000040, //!< Integer properties.
  BRIDGE_ATTRIBUTE_ASSOCIATIONS = 0x00000080, //!< Attribute associations.

  // Common combinations
  BRIDGE_NOTHING                = 0x00000000, //!< Transcribe nothing.
  BRIDGE_ENTITY_RECORD          = 0x00000003, //!< Transcribe both entity type and relations.
  BRIDGE_ENTITY_ARRANGED        = 0x00000007, //!< Transcribe the entity record and all arrangement information.
  BRIDGE_PROPERTIES             = 0x00000070, //!< Transcribe all properties.
  BRIDGE_EVERYTHING             = 0x000000ff  //!< Transcribe all information about the entity.
};

/// Bit-vector combinations of BridgedInformation values for requesting information to transcribe.
typedef unsigned long BridgedInfoBits;

/**\brief Declare that a class implements a bridge to a solid modeling kernel.
 *
 * Invoke this macro inside every class definition inheriting smtk::model::Bridge.
 * Both smtk/model/DefaultBridge.{h,cxx} and smtk/cgm/Bridge.{h,cxx} are examples.
 * Note that you must invoke this macro in the global namespace!
 *
 * You must also use the smtkDeclareModelingKernel macro in your bridge's header.
 *
 * This macro takes 3 arguments:
 *
 * \a Comp      - A "short" name for the bridge. This is used as part of several function
 *                names, so it must be a valid variable name and should *not* be in quotes.
 * \a FileTypes - a pointer to a NULL-terminated array of strings containing file types
 *                that the bridge supports. Each type may be followed by a parentetical
 *                description of the file type, e.g., { "*.json (Native SMTK model)", NULL }.
 * \a Cls       - The name of the bridge class. The class must have a static method named
 *                "create" that constructs and instance and returns a shared pointer to it.
 */
#define smtkImplementsModelingKernel(Comp, FileTypes, Cls) \
  /* Adapt create() to return a base-class pointer */ \
  static smtk::model::BridgePtr baseCreate() { \
    return Cls ::create(); \
  } \
  /* Implement autoinit methods */ \
  void smtk_##Comp##_bridge_AutoInit_Construct() { \
    std::vector<std::string> fileTypes; \
    for (const char** ft = FileTypes; *ft; ++ft) \
      if (*ft[0]) \
        fileTypes.push_back(*ft); \
    smtk::model::BRepModel::registerBridge( \
      #Comp, /* Can't rely on bridgeName to be initialized yet */ \
      fileTypes, \
      baseCreate); \
  } \
  void smtk_##Comp##_bridge_AutoInit_Destruct() { \
    smtk::model::BRepModel::registerBridge( \
      Cls ::bridgeName, \
      std::vector<std::string>(), \
      NULL); \
  } \
  /* Declare the component name */ \
  std::string Cls ::bridgeName(#Comp)

/**\brief Boilerplate for classes that bridge to a solid modeling kernel.
 *
 * Invoke this macro inside every class definition inheriting smtk::model::Bridge.
 * Both smtk/model/DefaultBridge.{h,cxx} and smtk/cgm/Bridge.{h,cxx} are examples.
 * Note that you must invoke this macro in a public section of your class declaration!
 *
 * You must also use the smtkImplementsModelingKernel macro in your bridge's implementation.
 */
#define smtkDeclareModelingKernel() \
  static std::string bridgeName; \
  virtual std::string name() const { return bridgeName; }

/**\brief A base class for bridging modelers into SMTK.
  *
  * SMTK can act as a bridge between other (foreign) solid modelers
  * and client applications.
  * Either the bridge or the foreign modeler must provide techniques
  * for attaching UUIDs to foreign model entities and for obtaining
  * notification when foreign model entities are modified or
  * destroyed. In extreme cases, SMTK Manager must be reset after
  * each modeling operation to guarantee a consistent model.
  *
  * Bridges may provide SMTK with Operators that can be used to
  * modify models in storage.
  *
  * Register an instance of a Bridge subclass to a
  * model with Manager::bridgeModel(). Then, when an
  * entity cannot be resolved from a UUID created by
  * the bridge, the \a transcribe method will be invoked
  * to request that the bridge add an entry.
  *
  * This class is not intended for external use.
  * Public methods are intended for invocation by the
  * Manager instance which owns the bridge.
  * Protected methods are either called internally or
  * by subclasses in order to track UUIDs for which there
  * is only partial information in Manager.
  *
  * \sa smtk::model::BridgedInformation smtk::model::Operator
  */
class SMTKCORE_EXPORT Bridge : smtkEnableSharedPtr(Bridge)
{
public:
  smtkTypeMacro(Bridge);
  virtual std::string name() const;
  smtk::util::UUID sessionId() const;

  int transcribe(const Cursor& entity, BridgedInfoBits flags, bool onlyDangling = true);

  virtual BridgedInfoBits allSupportedInformation() const;

  StringList operatorNames() const;
  const Operators& operators() const;
  virtual OperatorPtr op(const std::string& opName, ManagerPtr manager) const;
  virtual void addOperator(OperatorPtr op);

  const DanglingEntities& danglingEntities() const;
  void declareDanglingEntity(const Cursor& ent, BridgedInfoBits present = 0);

protected:
  friend class ExportJSON;
  friend class ImportJSON;

  Bridge();

  virtual BridgedInfoBits transcribeInternal(const Cursor& entity, BridgedInfoBits flags);

  void setSessionId(const smtk::util::UUID& sessId);

  DanglingEntities m_dangling;
  Operators m_operators;
  smtk::util::UUID m_sessionId;
};

  } // namespace model
} // namespace smtk

#endif // __smtk_model_Bridge_h
