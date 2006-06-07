#ifndef _MITK_VTK_SCALARMODE_PROPERTY__H_
#define _MITK_VTK_SCALARMODE_PROPERTY__H_

#include "mitkEnumerationProperty.h"

namespace mitk
{

/**
 * Encapsulates the enumeration vtkInterpolation. Valid values are 
 * (VTK constant/Id/string representation):
 * \li VTK_SCALAR_MODE_DEFAULT/0/Default, 
 * \li VTK_SCALAR_MODE_USE_POINT_DATA/1/PointData, 
 * \li VTK_SCALAR_MODE_USE_CELL_DATA/2/CellData
 * \li VTK_SCALAR_MODE_USE_POINT_FIELD_DATA/3/PointFieldData
 * \li VTK_SCALAR_MODE_USE_CELL_FIELD_DATA/4/CellFieldData
 */
class VtkScalarModeProperty : public EnumerationProperty
{
public:

  mitkClassMacro( VtkScalarModeProperty, EnumerationProperty );
  
  /**
   * Constructor. Sets the representation to a default value of surface(2)
   */
  VtkScalarModeProperty( );
  
  /**
   * \brief Sets the scalar mode to the given value. If it is not
   * valid, the scalar mode is set to default (0).
   * @param value the integer representation of the scalar mode
   */
  VtkScalarModeProperty( const IdType& value );
  
  /**
   * \brief Sets the scalar mode to the given value. If it is not
   * valid, the representation is set to default (0).
   * @param value the string representation of the scalar mode
   */
  VtkScalarModeProperty( const std::string& value );
  
  /**
   * Returns the current scalar mode value as defined by VTK constants.
   * @returns the current scalar mode as VTK constant.
   */
  virtual int GetVtkScalarMode();

  virtual void SetScalarModeToDefault();

  virtual void SetScalarModeToPointData();

  virtual void SetScalarModeToCellData();

  virtual void SetScalarModeToPointFieldData();

  virtual void SetScalarModeToCellFieldData();
  
protected:

  /**
   * this function is overridden as protected, so that the user may not add
   * additional invalid scalar mode types.
   */
  virtual bool AddEnum( const std::string& name, const IdType& id );

  /**
   * Adds the enumeration types as defined by vtk to the list of known 
   * enumeration values.
   */
  virtual void AddInterpolationTypes();
};

} // end of namespace mitk

#endif //_MITK_VTK_SCALARMODE_PROPERTY__H_

