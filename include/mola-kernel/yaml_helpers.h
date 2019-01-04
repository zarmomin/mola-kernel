/* -------------------------------------------------------------------------
 *   A Modular Optimization framework for Localization and mApping  (MOLA)
 * Copyright (C) 2018-2019 Jose Luis Blanco, University of Almeria
 * See LICENSE for license information.
 * ------------------------------------------------------------------------- */
/**
 * @file   yaml_helpers.h
 * @brief  YAML processing helper utilities
 * @author Jose Luis Blanco Claraco
 * @date   Nov 30, 2018
 */
#pragma once

#include <string>

namespace mola
{
/** Replaces `${VAR}` expressions with their values from environment vars.
 * \ingroup mola_kernel_grp
 */
std::string parseEnvVars(const std::string& text);

#define ENSURE_YAML_ENTRY_EXISTS(_c, _name) \
    ASSERTMSG_(_c[_name], "Missing YAML required entry: `" _name "`")

/** Loads (optional) variable named "_varname" from the YAML config named `cfg`
 * into the variable `_param_str._varname` */
#define YAML_LOAD_OPT(_param_str, _varname, _type) \
    _param_str._varname = cfg[#_varname].as<_type>(_param_str._varname)

/** Loads (required) variable named "_varname" from the YAML config named `cfg`
 * into the variable `_param_str._varname` */
#define YAML_LOAD_REQ(_param_str, _varname, _type) \
    ENSURE_YAML_ENTRY_EXISTS(cfg, #_varname);      \
    YAML_LOAD_OPT(_param_str, _varname, _type)

/** like YAML_LOAD_OPT, values in the YAML file in "degrees" stored in rads */
#define YAML_LOAD_OPT_DEG(_param_str, _varname, _type)        \
    _param_str._varname = mrpt::RAD2DEG(_param_str._varname); \
    YAML_LOAD_OPT(_param_str, _varname, _type);               \
    _param_str._varname = mrpt::DEG2RAD(_param_str._varname)

/** like YAML_LOAD_REQ, values in the YAML file in "degrees" stored in rads */
#define YAML_LOAD_REQ_DEG(_param_str, _varname, _type)        \
    _param_str._varname = mrpt::RAD2DEG(_param_str._varname); \
    YAML_LOAD_REQ(_param_str, _varname, _type);               \
    _param_str._varname = mrpt::DEG2RAD(_param_str._varname)

}  // namespace mola