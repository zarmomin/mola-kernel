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

#include <sstream>
#include <string>

#include <mrpt/core/bits_math.h>
#include <mrpt/core/exceptions.h>
#include <yaml-cpp/yaml.h>

namespace mola
{
/** Parses: system run expressions `$(cmd)`, environment variables `${VAR}`.
 * \ingroup mola_kernel_grp
 */
std::string parseYaml(const std::string& text);

/** Converts a yamlcpp node into a string
 * \ingroup mola_kernel_grp
 */
template <class YAML_CLASS>
inline std::string yaml2string(const YAML_CLASS& cfg)
{
    std::stringstream ss;
    ss << cfg;
    return ss.str();
}

inline void ensureYamlEntryExists(const YAML::Node& n, const std::string& name)
{
  ASSERTMSG_(n[name], "Missing YAML required entry: " + name);
}

template <typename T>
inline void yamlLoadMemberOpt(const YAML::Node& cfg, const std::string& varname, T* out_var)
{
  *out_var = cfg[varname].as<T>();
}

template <typename T>
inline void yamlLoadMemberReq(const YAML::Node& cfg, const std::string& varname, T* out_var)
{
  ensureYamlEntryExists(cfg, varname);
  *out_var = cfg[varname].as<T>();
}

template <typename T>
inline void yamlLoadMemberOptDeg(const YAML::Node& cfg, const std::string& varname, T* out_var)
{
  *out_var = mrpt::DEG2RAD(cfg[varname].as<T>());
}

template <typename T>
inline void yamlLoadMemberReqDeg(const YAML::Node& cfg, const std::string& varname, T* out_var)
{
  ensureYamlEntryExists(cfg, varname);
  *out_var = mrpt::DEG2RAD(cfg[varname].as<T>());
}

}  // namespace mola
