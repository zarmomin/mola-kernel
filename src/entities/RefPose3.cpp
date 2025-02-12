/* -------------------------------------------------------------------------
 *   A Modular Optimization framework for Localization and mApping  (MOLA)
 * Copyright (C) 2018-2019 Jose Luis Blanco, University of Almeria
 * See LICENSE for license information.
 * ------------------------------------------------------------------------- */
/**
 * @file   RefPose3.cpp
 * @brief
 * @author Jose Luis Blanco Claraco
 * @date   Jan 08, 2019
 */

#include <mola-kernel/entities/RefPose3.h>
#include <mrpt/serialization/CArchive.h>

using namespace mola;

// arguments: classname, parent class, namespace
IMPLEMENTS_SERIALIZABLE_NS_PREFIX(RefPose3, EntityBase, mola);

// Implementation of the CSerializable virtual interface:
uint8_t RefPose3::serializeGetVersion() const { return 0; }
void    RefPose3::serializeTo(mrpt::serialization::CArchive& out) const
{
    baseSerializeTo(out);
}
void RefPose3::serializeFrom(mrpt::serialization::CArchive& in, uint8_t version)
{
    baseSerializeFrom(in);

    switch (version)
    {
        case 0:
        {
        }
        break;
        default:
            MRPT_THROW_UNKNOWN_SERIALIZATION_VERSION(version);
    };
}
