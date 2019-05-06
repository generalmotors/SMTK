//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
// .NAME qtItem - an abstract UI class for attribute item
// .SECTION Description

#ifndef __smtk_extension_qtAttributeItemInfo_h
#define __smtk_extension_qtAttributeItemInfo_h

#include "smtk/PublicPointerDefs.h"
#include "smtk/extension/qt/Exports.h"
#include "smtk/view/View.h"
#include <QObject>
#include <QPointer>

namespace smtk
{
namespace extension
{
class qtBaseView;
class qtUIManager;

/// \brief Class used to generate widgets for Attribute Items.
///
/// This class is used by the qtUIManager to construct qtItem instances using registered factory methods.
/// This information includes the following:
/// - a smtk::attribute:Item that the qtItem is being created for
/// - a smtk::view::View::Component that describes how the item (and optionally its children) should be displayed
/// - a Widget that is to be used as the parent for the item widget
/// - a qtBaseView that is the origin for being the item widget

class SMTKQTEXT_EXPORT qtAttributeItemInfo
{
public:
  qtAttributeItemInfo(smtk::attribute::ItemPtr item, smtk::view::View::Component itemComp,
    QPointer<QWidget> parent, QPointer<qtBaseView> bview);

  qtAttributeItemInfo() {}
  virtual ~qtAttributeItemInfo() {}

  /// @{
  /// \brief Methods to set and retrieve the item to be used by the generated qtItem
  void setItem(smtk::attribute::ItemPtr& item) { m_item = item; }
  smtk::attribute::ItemPtr item() const { return m_item.lock(); }
  template <typename ItemType>
  std::shared_ptr<ItemType> itemAs() const
  {
    return std::dynamic_pointer_cast<ItemType>(this->item());
  }
  ///@}

  /// @{
  /// \brief Methods to set and retrieve the Component Style Information to be used to generate a qtItem
  void setComponent(const smtk::view::View::Component& comp) { m_component = comp; }
  smtk::view::View::Component component() const { return m_component; }
  ///@}

  /// @{
  /// \brief Methods to set and retrieve the widget to be used as the parent for the generated qtItem
  void setParentWidget(QPointer<QWidget> widget) { m_parentWidget = widget; }
  QPointer<QWidget> parentWidget() const { return m_parentWidget; }
  ///@}

  /// \brief Methd to return the qtBaseView that requested the creation of the qtItem
  QPointer<qtBaseView> baseView() const { return m_baseView; }

  /// \brief Method to return the qtUIManager that is being used to generate the UI.
  ///
  /// Note that the manager is retrived via the qtBaseView assigned.  If the view does not have a manager
  /// or if the view is not set then this method will return nullptr.
  qtUIManager* uiManager() const;

  /// \brief Method to return the style information for the item's children.
  ///
  /// The key string represents a path to an item's child and the corresponding
  /// Component represents the style infomation that is to be used to generate its qtItem
  std::map<std::string, smtk::view::View::Component>& childrenViewInfo() const;

  /// \brief A helper method that can construct a dictionary from a View Component
  /// representing a block of Item Styles
  ///
  /// Each child Component of comp represents an item either using an Item attribute (Old Style)
  /// or a Path attribute (New Style). For each child Component, the root item is extracted.
  /// If the root item is not in the dictionary then a new qtAttributeItemInfo is inserted using
  /// the root item name as the key and sets its baseView.  If the remainder of the path is empty
  /// the child Component is assigned to the corresponding qtAttributeItemInfo, else
  /// the new path and the child Component are inserted into the qtAttributeItemInfo's
  /// children view information.
  static bool buildFromComponent(smtk::view::View::Component comp, QPointer<qtBaseView> view,
    std::map<std::string, qtAttributeItemInfo>& dict);

  /// \brief A  method that can construct a dictionary from the qtAttributeItemInfo's
  /// children view infromation.
  ///
  /// For each entry in m_childViewInfo, the root item is extracted from the key.
  /// If the root item is not in the new dictionary then a new qtAttributeItemInfo is inserted using
  /// the root item name as the key and sets its baseView.  If the remainder of the path is empty
  /// the associated Component is assigned to the corresponding qtAttributeItemInfo, else
  /// the new path and the Component are inserted into the qtAttributeItemInfo's
  /// children view information.

  bool createNewDictionary(std::map<std::string, qtAttributeItemInfo>& dict);

protected:
  smtk::attribute::WeakItemPtr m_item;     ///< Pointer to the attribute Item
  smtk::view::View::Component m_component; ///< qtItem Component Definition
  QPointer<QWidget> m_parentWidget;        ///< Parent Widget of the qtItem
  QPointer<qtBaseView> m_baseView;         ///<  View Definition
  /// Dictionary of component information for child of the item
  std::map<std::string, smtk::view::View::Component> m_childrenViewInfo;
}; // class
}; // namespace extension
}; // namespace smtk

#endif