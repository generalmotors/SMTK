<?xml version="1.0" encoding="utf-8" ?>
<!-- Description of the mesh "Transform" Operation -->
<SMTK_AttributeResource Version="3">
  <Definitions>
    <include href="smtk/operation/Operation.xml"/>
    <AttDef Type="transform mesh" BaseType="operation" Label="Mesh - Transform">
      <BriefDescription>
        Transform a mesh.
      </BriefDescription>
      <AssociationsDef Name="mesh" LockType="Read"
                       NumberOfRequiredValues="1" Extensible="true" HoldReference="true">
        <Accepts><Resource Name="smtk::mesh::Resource" Filter="meshset"/></Accepts>
      </AssociationsDef>
      <ItemDefinitions>
        <Double Name="scale" NumberOfRequiredValues="3">
          <BriefDescription>
            Scale mesh? If so, specify a scale factor for each axis.
          </BriefDescription>
          <DetailedDescription>
            Enabling this item allows you to specify a scale factor per axis for the
            mesh.
            Scaling is performed about the origin before rotation and translation.
          </DetailedDescription>
          <DefaultValue>1, 1, 1</DefaultValue>
        </Double>
        <Double Name="rotate" NumberOfRequiredValues="3">
          <BriefDescription>
            Rotate mesh? If so, specify angles about each axis in degrees.
          </BriefDescription>
          <DetailedDescription>
            Enabling this item allows you to specify angles (in degrees) about which to rotate
            the mesh. Angles are specified about the origin and rotation is applied
            before translation.
          </DetailedDescription>
          <DefaultValue>0, 0, 0</DefaultValue>
        </Double>
        <Double Name="translate" NumberOfRequiredValues="3">
          <BriefDescription>Translate mesh? If so, specify a vector.</BriefDescription>
          <DetailedDescription>
            Enabling this item allows you to specify a vector to add to each original point
            of the mesh.
            Translation is applied after scaling and rotation;
            therefore the vector is not modified by the specifed scaling and rotation (if any).
          </DetailedDescription>
          <DefaultValue>0, 0, 0</DefaultValue>
        </Double>
        </ItemDefinitions>
    </AttDef>
    <!-- Result -->
    <include href="smtk/operation/Result.xml"/>
    <AttDef Type="result(transform mesh)" BaseType="result">
      <ItemDefinitions>
        <Component Name="tess_changed" NumberOfRequiredValues="0"
                     Extensible="true" AdvanceLevel="11">
          <Accepts><Resource Name="smtk::model::Resource" Filter=""/></Accepts>
        </Component>
      </ItemDefinitions>
    </AttDef>
  </Definitions>
</SMTK_AttributeResource>
