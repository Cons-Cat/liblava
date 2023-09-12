/**
 * @file         liblava/frame/argh.hpp
 * @brief        Json
 * @authors      Lava Block OÜ and contributors
 * @copyright    Copyright (c) 2018-present, MIT License
 */

#pragma once

#include "liblava/core/types.hpp"
#include "nlohmann/json.hpp"

namespace lava {

/// Json object
using json = nlohmann::json;

/// Reference to a json object
using json_ref = json const&;

/**
 * @brief Configurable interface
 */
struct configurable : interface {
    /**
     * @brief Set json config
     * @param j    Json file
     */
    virtual void set_json(json_ref j) = 0;

    /**
     * @brief Get json config
     * @return json    Json file
     */
    virtual json get_json() const = 0;
};

} // namespace lava
