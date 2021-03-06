/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/
#ifndef _MITK_CONTOURMODEL_READER__H_
#define _MITK_CONTOURMODEL_READER__H_

// MITK
#include <mitkAbstractFileReader.h>
#include <mitkBaseData.h>
#include <mitkContourModel.h>
#include <mitkMimeType.h>

#include <stack>
#include <string>
#include <tinyxml.h>
#include <vtkXMLParser.h>

namespace mitk
{
  /**
   * @brief
   * @ingroup MitkContourModelModule
  */
  class ContourModelReader : public mitk::AbstractFileReader
  {
  public:
    ContourModelReader(const ContourModelReader &other);

    ContourModelReader();

    ~ContourModelReader() override;

    using AbstractFileReader::Read;
    std::vector<itk::SmartPointer<BaseData>> Read() override;

  protected:
    virtual void ReadPoints(mitk::ContourModel::Pointer newContourModel,
                            TiXmlElement *currentTimeSeries,
                            unsigned int currentTimeStep);

  private:
    ContourModelReader *Clone() const override;

    us::ServiceRegistration<mitk::IFileReader> m_ServiceReg;
  };
}

#endif
